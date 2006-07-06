using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP.Resources
{
    interface IResourceTypeFactory
    {
        SortedDictionary<string, ResourceType> CreateResourceTypes();
    }

    class XMLResourceTypeFactory : IResourceTypeFactory
    {
        public readonly string Filename;
        
        public XMLResourceTypeFactory(string filename)
        {
            Filename = filename;
        }


        #region IResourceTypeFactory Members

        public SortedDictionary<string, ResourceType> CreateResourceTypes()
        {
            SortedDictionary<string, ResourceType> list = new SortedDictionary<string, ResourceType>();

            System.Xml.XmlDocument document = new System.Xml.XmlDocument();
            document.Load(Filename);

            System.Xml.XmlNode rootNode = document.ChildNodes[1];
            foreach (System.Xml.XmlNode resourceNode in rootNode.ChildNodes)
            {
                try
                {
                    if (resourceNode.Name == "resource_type")
                    {
                        ResourceType resourceType = LoadResourceType(resourceNode);
                        list.Add(resourceType.Name, resourceType);
                    }
                }
                catch (Exception x)
                {
                    SNAP.Controller.ShowException(x);
                }
            }
            return list;
        }

        #endregion

        #region LoadResourceField

        private static IResourceType LoadResourceField(System.Xml.XmlNode fieldNode)
        {
            IResourceType field = null;
            switch (fieldNode.Name)
            {
                case "text":
                    field = new TextFieldType();
                    break;

                case "internal_ref":
                    field = new InternalRefFieldType();
                    break;


                case "external_ref":
                    field = new ExternalRefFieldType();
                    break;

                case "numeric":
                    field = new NumericFieldType();
                    break;

                case "enum":
                    field = new EnumFieldType();
                    break;
            }

            if (field != null)
                field.LoadFromXML(fieldNode);

            return field;
        }

        #endregion LoadResourceField

        #region LoadResourceFields

        public static void CreateResourceTypeFields(IDictionary<string, IResourceType> container, XmlNode fieldParentNode)
        {
            foreach (System.Xml.XmlNode node in fieldParentNode.ChildNodes)
            {
                IResourceType fieldType = LoadResourceField(node);
                if (fieldType != null)
                    container.Add(fieldType.Name, fieldType);
            }
        }

        #endregion LoadResourceFields

        #region LoadResourceType

        private static ResourceType LoadResourceType(System.Xml.XmlNode resourceNode)
        {
            System.Diagnostics.Debug.Assert(resourceNode.Name == "resource_type");
            ResourceType resourceType = new ResourceType();
            resourceType.LoadFromXML(resourceNode);
            return resourceType;
        }

        #endregion LoadResourceType

        #region LoadFromXML

        /// <summary>
        /// Loads from XML, the common properties which all resource types share
        /// </summary>
        /// <param name="resourceType">Type of the resource.</param>
        public static void LoadFromXML(XmlNode node, IResourceType resourceType)
        {
            if (node.Attributes["name"] == null)
                throw new System.Xml.XmlException("The resource_type node does not contain a 'name' attribute at " + node.BaseURI);

            resourceType.Name = node.Attributes["name"].Value;

            if (node.Attributes["help"] != null)
                resourceType.Help = node.Attributes["help"].Value;
            else
            {
                resourceType.Help = string.Empty;
            }

            if (node.Attributes["display_name"] != null)
                resourceType.DisplayName = node.Attributes["display_name"].Value;
            else
                resourceType.DisplayName = resourceType.Name;
        }

        #endregion LoadFromXML
    }

    class XMLScriptFactory
    {
        enum ConditionalContext {
            TopLevel,
            ExportSection
        }

        #region CreateScript

        public static Scripts.Script CreateScript(XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name == "execute");
            string name = node.Attributes["name"].Value;
            string help = node.Attributes["help"].Value;

            Scripts.Script script = new Scripts.Script(name, help);
            foreach (XmlNode stepNode in node.ChildNodes)
            {
                script.Steps.Add (CreateStep (stepNode));
            }

            return script;
        }

        #endregion CreateScript

        #region CreateExportSubStep

        private static Scripts.IStep CreateExportSubStep(XmlNode node)
        {
            switch (node.Name)
            {
                case "path":
                    {
                        string name = node.Attributes["name"].Value;
                        string value = node.Attributes["value"].Value;
                        return new Scripts.PathFieldExportStep (name, value);
                    }

                case "text":
                    {
                        string name = node.Attributes["name"].Value;
                        string value = node.Attributes["value"].Value;
                        return new Scripts.TextFieldExportStep (name, value);
                    }

                case "conditional":
                    return CreateConditionalStep(ConditionalContext.ExportSection, node);
            }

            throw new System.ArgumentException("The export type " + node.Name + " is invalid");
        }

        #endregion CreateExportSubStep

        #region CreateExportStep

        private static Scripts.IExportStep CreateExportStep(XmlNode exportNode)
        {
            System.Diagnostics.Debug.Assert(exportNode.Name.Equals("export"));
            string type = exportNode.Attributes["type"].Value;

            Scripts.IExportStep export = null;
            if (type.Equals("params"))
            {
                string filename = exportNode.Attributes["name"].Value;
                export = new Scripts.ParamsExportStep(filename);
            }
            else
            {
                throw new System.ArgumentException("The export type " + type + " is invalid");
            }
            
            foreach (XmlNode fieldNode in exportNode.ChildNodes)
                export.SubTerms.Add (CreateExportSubStep (fieldNode));

            return export;
        }

        #endregion CreateExportStep

        #region CreateConditionalSubStep

        private static Scripts.Logic.Conditional CreateConditionalSubStep(XmlNode node)
        {
            switch (node.Name)
            {
                case "equals": {
                        /// must have two attributes. their names are unimportants
                        string A = node.Attributes[0].Value;
                        string B = node.Attributes[1].Value;
                        return new Scripts.EqualityConditional(A, B);
                    }

                case "and":
                    {
                        Scripts.Logic.Conjunction conjunction = new SNAP.Scripts.Logic.Conjunction();
                        foreach (XmlNode childNode in node.ChildNodes)
                        {
                            conjunction.SubTerms.Add(CreateConditionalSubStep(childNode));
                        }

                        return conjunction;
                    }

                case "or":
                    {
                        Scripts.Logic.Conjunction conjunction = new SNAP.Scripts.Logic.Conjunction();
                        foreach (XmlNode childNode in node.ChildNodes)
                        {
                            conjunction.SubTerms.Add(CreateConditionalSubStep(childNode));
                        }

                        return conjunction;
                    }

                case "not":
                    System.Diagnostics.Debug.Assert(node.ChildNodes.Count == 1);
                    return new Scripts.Logic.Negation(CreateConditionalSubStep(node.FirstChild));
            }

            throw new System.ArgumentException("The conditional type " + node.Name + " is invalid");
        }

        #endregion CreateConditionalSubStep

        #region CreateConditionalStep

        private static Scripts.ConditionalStep CreateConditionalStep(ConditionalContext context, XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals("conditional"));
            
            System.Diagnostics.Debug.Assert(node.FirstChild.Name.Equals("if"));

            /// first: read the conditionals (the "if" part)
            /// the terms are in an implicit conjunction
            Scripts.Logic.Conditional conditional = new Scripts.Logic.Conjunction ();
            foreach (XmlNode childNode in node.ChildNodes[0].ChildNodes)
                conditional.SubTerms.Add(CreateConditionalSubStep(childNode));

            /// second: read the steps (the "then" part)
            System.Diagnostics.Debug.Assert(node.ChildNodes [1].Name.Equals("then"));

            Scripts.CompositeStep thenStep = new Scripts.CompositeStep();
            switch (context)
            {
                case ConditionalContext.TopLevel:
                    foreach (XmlNode childNode in node.ChildNodes[1].ChildNodes)
                        thenStep.SubSteps.Add(CreateStep(childNode));
                    break;

                case ConditionalContext.ExportSection:
                    foreach (XmlNode childNode in node.ChildNodes[1].ChildNodes)
                        thenStep.SubSteps.Add(CreateExportSubStep(childNode));
                    break;
            }

            /// lastly: read the else section (if it exists)
            Scripts.CompositeStep elseStep = new Scripts.CompositeStep();
            if (node.ChildNodes [2] != null)
            {
                System.Diagnostics.Debug.Assert(node.ChildNodes [1].Name.Equals("else"));
                switch (context)
                {
                    case ConditionalContext.TopLevel:
                        foreach (XmlNode childNode in node.ChildNodes[1].ChildNodes)
                            elseStep.SubSteps.Add(CreateStep(childNode));
                        break;

                    case ConditionalContext.ExportSection:
                        foreach (XmlNode childNode in node.ChildNodes[1].ChildNodes)
                            elseStep.SubSteps.Add(CreateExportSubStep(childNode));
                        break;

                }
            }

            return new Scripts.ConditionalStep(conditional, thenStep, elseStep);
        }
        
        #endregion CreateConditionalStep

        #region CreateStep

        private static Scripts.IStep CreateStep(XmlNode stepNode)
        {
            switch (stepNode.Name)
            {
                case "run":
                    {
                        string bin = stepNode.Attributes["bin"].Value;
                        string parameters = stepNode.Attributes["params"].Value;
                        return new Scripts.ExecuteStep(bin, parameters);
                    }

                case "import":
                    {
                        string filename = stepNode.Attributes["name"].Value;
                        return new Scripts.ImportStep(filename);
                    }

                case "export":
                    return CreateExportStep (stepNode);

                case "conditional":
                    return CreateConditionalStep (ConditionalContext.TopLevel, stepNode);

                default:
                    throw new System.ArgumentException("The step type " + stepNode.Name + " is invalid");
            }
        }

        #endregion CreateStep
    }
}
