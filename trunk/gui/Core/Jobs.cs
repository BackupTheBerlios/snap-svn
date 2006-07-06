using System;
using System.IO;
using System.Diagnostics;
using System.Collections.Generic;
using System.Xml;

using SNAP.Resources;

namespace SNAP.Scripts
{
    #region Interfaces

    #region IStep

    public interface IStepArgs
    {
        Resource MyResource
        {
            get;
        }

        Script MyScript
        {
            get;
        }
    }

    public class StepArgs : IStepArgs
    {
        #region Privates

        private readonly Resource _resource;
        private readonly Script _script;

        #endregion Privates

        #region Ctor

        public StepArgs (Resource resource, Script script)
        {
            _resource = resource;
            _script = script;
        }

        #endregion Ctor

        #region IStepArgs Members

        public Resource  MyResource
        {
            get
            {
               return _resource;
            }
        }

        public Script MyScript
        {
	        get { 
                return _script;
            }
        }

        #endregion
    }

    public interface IStep
    {
        /// <summary>
        /// Executes the step for the specified resource.
        /// </summary>
        /// <param name="resource">The resource.</param>
        void Execute(IStepArgs resource);
    }

    #endregion IStep

    #region IExport

    /// <summary>
    /// This class implements the functionality offered in the "export" statement
    /// in the resource.types.xml
    /// </summary>
    internal interface IExportStep : IStep
    {
        /// <summary>
        /// Gets the filename.
        /// </summary>
        /// <value>The filename.</value>
        string Filename
        {
            get;
        }

        /// <summary>
        /// the subterms of an export step may be instances of IFieldExportStep or ConditionalStep
        /// </summary>
        /// <value>The fields.</value>
        IList <IStep> SubTerms
        {
            get;
        }
    }

    #endregion IExport

    #region IFieldExportStep

    #region interface IFieldExportStep 

    /// <summary>
    /// 
    /// </summary>
    internal interface IFieldExportStep : IStep
    {
        /// <summary>
        /// Gets the name.
        /// </summary>
        /// <value>The name.</value>
        string Name
        {
            get;
        }

        /// <summary>
        /// Gets the value.
        /// </summary>
        /// <param name="resource">The resource.</param>
        /// <returns></returns>
        string GetValue(IStepArgs resource);
    }

    #endregion IFieldExportStep

    #region interface IFieldExportStepArgs 

    internal interface IFieldExportStepArgs : IStepArgs 
    {
        /// <summary>
        /// callback method, which exports the field
        /// </summary>
        /// <param name="step">The step.</param>
        void FieldExportCallback (IFieldExportStep step);
    }

    #endregion interface IFieldExportStepArgs 

    #region class AbstractFieldExportStep

    internal abstract class AbstractFieldExportStep : IFieldExportStep
    {
        #region Privates

        private readonly string _name;

        #endregion Privates

        #region Ctor

        protected AbstractFieldExportStep (string name)
        {
            _name = name;
        }

        #endregion Ctor
            
        #region IFieldExportStep Members

        public string Name
        {
            get
            {
                return _name;
            }
        }

        public abstract string GetValue(IStepArgs resource);    

        #endregion

        #region IStep Members

        void IStep.Execute(IStepArgs args)
        {
            Execute ((IFieldExportStepArgs) args);
        }

        public void Execute (IFieldExportStepArgs args)
        {
            args.FieldExportCallback (this);
        }

        #endregion
    }

    #region class AbstractFieldExportStep

    #endregion IFieldExportStep

    #endregion Interfaces

    #endregion IFieldExportStep

    #endregion Interfaces

    #region Interface Implementations

    class CompositeStep : IStep
    {
        public readonly List <IStep> SubSteps = new List<IStep> ();

        #region IStep Members

        public void Execute(IStepArgs args)
        {
            foreach (IStep step in SubSteps)
                step.Execute(args);
        }

        #endregion
    }

    #region ParamsExportStep

    /// <summary>
    /// 
    /// </summary>
    internal class ParamsExportStep : IExportStep
    {
        #region Privates

        private Script _script = null;
        private readonly string _filename;
        private readonly List <IStep> _fields;

        #endregion Privates

        #region Ctor

        public ParamsExportStep(string filename)
        {
            _fields = new List<IStep>();
            _filename = filename;
        }

        #endregion Ctor

        #region IExport Members

        /// <summary>
        /// Gets the filename.
        /// </summary>
        /// <value>The filename.</value>
        public string Filename
        {
            get
            {
                return _filename;
            }
        }

        public IList<IStep> SubTerms
        {
            get
            {
                return _fields;
            }
        }

        #endregion

        #region IStep Members

        class FieldExportStepArgs : IFieldExportStepArgs
        {
            #region Privates

            private readonly StreamWriter _writer;

            #endregion Privates

            #region Properties

            public readonly IStepArgs InnerArgs;

            #endregion Properties

            #region Ctor

            public FieldExportStepArgs(StreamWriter writer, IStepArgs args)
            {
                _writer = writer;
                InnerArgs = args;
            }

            #endregion Ctor

            #region IFieldExportStepArgs Members

            public void FieldExportCallback(IFieldExportStep step)
            {
                /// since params files are being used in unix environment
                /// we use unix-style line endings (\n) 
                /// instead of window-style line endings (\r\n)
                _writer.Write(step.Name);
                _writer.Write('\n');

                /// we interpret the value of the field
                /// TODO: fix Interepret prototype to make this general
                //string value = Execution.Interpret(_script.Name, field.Value, resource);
                _writer.Write(step.GetValue(this));
                _writer.Write('\n');
            }

            #endregion

            #region IStepArgs Members

            public Resource MyResource
            {
                get
                {
                    return InnerArgs.MyResource;
                }
            }

            public Script MyScript
            {
                get
                {
                    return InnerArgs.MyScript;
                }
            }

            #endregion
        }


        /// <summary>
        /// Executes the step for the specified resource.
        /// </summary>
        /// <param name="resource">The resource.</param>
        public void Execute(IStepArgs args)
        {
            Resource resource = args.MyResource;
            string fullFilename = System.IO.Path.Combine(
                Util.GetExecutionFolder(args.MyScript, resource), Filename);

            System.IO.Directory.GetParent(fullFilename).Create();

            /// create the file
            using (StreamWriter writer = new StreamWriter(fullFilename))
            {
                FieldExportStepArgs fieldExportArgs = new FieldExportStepArgs(writer, args);

                /// write all fields to file
                foreach (IStep step in this._fields)
                    step.Execute(fieldExportArgs);

                writer.Flush();
            }
        }

        #endregion
    }

    #endregion ParamsExport

    #region PathExportField

    internal class PathFieldExportStep : AbstractFieldExportStep
    {
        #region Privates

        private readonly string _value;

        #endregion Privates

        #region Ctor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:PathExportField"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="value">The value.</param>
        public PathFieldExportStep(string name, string value)
            : base (name)
        {
            _value = value;
        }

        #endregion Ctor

        #region IExportField Members

        /// <summary>
        /// Gets the value.
        /// </summary>
        /// <value>The value.</value>
        public override string GetValue(IStepArgs args)
        {
            /// retrieve the path
            string result = Util.Interpret(args.MyScript, _value, args.MyResource);

            /// TODO: allow basing the path on some directory, resulting in 
            /// a relative path instead of an absolute path

            /// we use unix-style paths, with a '/' separator instead of a '\' separator
            result = result.Replace('\\', '/');

            /// we replace a space character ' ' with a space escape sequence "\ "
            result = result.Replace(" ", @"\ ");
            return result;
        }

        #endregion
    }

    #endregion PathExportField

    #region TextExportField

    internal class TextFieldExportStep : AbstractFieldExportStep
    {
        #region Privates

        private readonly string _value;

        #endregion Privates

        #region Ctor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:PathExportField"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="value">The value.</param>
        public TextFieldExportStep(string name, string value)
            : base(name)
        {
            _value = value;
        }

        #endregion Ctor

        #region IExportField Members

        /// <summary>
        /// Gets the value.
        /// </summary>
        /// <value>The value.</value>
        public override string GetValue(IStepArgs args)
        {
            return Util.Interpret(args.MyScript, _value, args.MyResource);
        }

        #endregion
    }

    #endregion TextExportField

    #region class ExecuteStep

    public class ExecuteStep : IStep
    {
        #region Ctor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:Step"/> class.
        /// </summary>
        /// <param name="bin">The bin.</param>
        /// <param name="parameters">The parameters.</param>
        public ExecuteStep(string bin, string parameters)
        {
            this.Bin = bin;
            this.Params = parameters;
        }

        #endregion Ctor

        #region Properties

        public readonly string Bin;
        public readonly string Params;
        public readonly string OutputRedirectionFile;

        #endregion Properties

        #region Privates

        private Script _parent;

        #endregion Privates

        #region IStep Members

        /// <summary>
        /// Executes the step for the specified resource.
        /// </summary>
        /// <param name="resource">The resource.</param>
        public void Execute(IStepArgs args)
        {
            Util.Run(this, args.MyResource, args.MyScript);
        }

        #endregion
    }

    #endregion Step

    #region ImportStep

    internal class ImportStep : IStep
    {
        #region Privates

        private Script _parent;

        #endregion Privates

        #region Properties

        public readonly string Filename;

        #endregion Properties

        #region Ctor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:ImportStep"/> class.
        /// </summary>
        /// <param name="filename">The filename.</param>
        public ImportStep(string filename)
        {
            Filename = filename;
        }

        #endregion

        #region IStep Members

        /// <summary>
        /// Executes the step for the specified resource.
        /// </summary>
        /// <param name="resource">The resource.</param>
        public void Execute(IStepArgs args)
        {
            string executionFolder = Scripts.Util.GetExecutionFolder(args.MyScript, args.MyResource);

            Controller.CurrentResources.LoadAdditionalResources(
                args.MyResource,
                Path.Combine(executionFolder, this.Filename)
                );
        }

        #endregion
    }

    #endregion ImportStep

    #endregion Interface Implementations

    #region Script

    public class Script : IStep, SNAP.Util.IChild <ResourceType>
    {
        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:ExecutionType"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="help">The help.</param>
        public Script(string name, string help)
        {
            Name = name;
            Help = help;
            this.Steps = new List <IStep> ();
        }

        #endregion Constructor

        #region Properties

        public readonly IList<IStep> Steps;
        public readonly string Name;
        public readonly string Help;
        private ResourceType _resourceType;

        /// <summary>
        /// Gets a value indicating whether [create folder].
        /// </summary>
        /// <value><c>true</c> if [create folder]; otherwise, <c>false</c>.</value>
        public bool CreateFolder
        {
            get
            {
                //return DynamicOutputFiles.Count > 0;
                return true;
            }
        }

        #endregion Properties

        #region IChild<ResourceType> Members

        /// <summary>
        /// Gets my parent.
        /// </summary>
        /// <value>My parent.</value>
        public ResourceType MyParent
        {
            get
            {
                return _resourceType;
            }
        }

        /// <summary>
        /// Gets or sets my parent.
        /// </summary>
        /// <value>My parent.</value>
        ResourceType SNAP.Util.IChild<ResourceType>.MyParent
        {
            get
            {
                return _resourceType;
            }
            set
            {
                _resourceType = value;
            }
        }

        #endregion

        public void Execute(IStepArgs args)
        {
            foreach (IStep step in Steps)
            {
                step.Execute(args);
            }
        }
    }

    #region Util

    internal static class Util
    {
        /// <summary>
        /// Runs the specified step.
        /// </summary>
        /// <param name="step">The step.</param>
        public static void Run(Scripts.ExecuteStep step, Resource resource, Script execType)
        {
            string parameters = Interpret(
                execType,
                step.Params,
                resource
                );

            if (!execType.CreateFolder)
            {
                System.Diagnostics.Process.Start(step.Bin, parameters);
            }
            else
            {
                /// create a directory for the files
                DirectoryInfo executionFolder = Directory.CreateDirectory(GetExecutionFolder(execType, resource));

                /// run the job
                Process process = Run(step.Bin, parameters, step.OutputRedirectionFile, executionFolder);
                int exitCode = process.ExitCode;

                if (exitCode == 0)
                {
                }
                else
                {
                    Controller.ShowException(new System.Exception("The process returned an exit code of " + exitCode));
                    /// the process didnt work
                }
            }
        }

        /// <summary>
        /// Runs the specified bin file.
        /// </summary>
        /// <param name="binFile">The bin file.</param>
        /// <param name="parameters">The parameters.</param>
        /// <param name="outputRedirectionFile">The output redirection file.</param>
        /// <param name="executionFolder">The execution folder.</param>
        internal static Process Run(
            string binFile,
            string parameters,
            string outputRedirectionFile,
            DirectoryInfo executionFolder)
        {
            if (!System.IO.Path.IsPathRooted(binFile))
            {
                /// it is a path relative to the bin directory of SNAP
                if (File.Exists(System.IO.Path.Combine(SNAP.Controller.BinFolder, binFile)))
                {
                    binFile = System.IO.Path.Combine(SNAP.Controller.BinFolder, binFile);
                }
                else if (File.Exists(System.IO.Path.Combine(SNAP.Controller.PluginFolder, binFile)))
                {
                    binFile = System.IO.Path.Combine(SNAP.Controller.PluginFolder, binFile);
                }
            }

            System.Diagnostics.ProcessStartInfo startInfo;
            if (string.IsNullOrEmpty(outputRedirectionFile))
            {
                startInfo = new ProcessStartInfo(binFile, parameters);
            }
            else
            {
                startInfo = new ProcessStartInfo(
                    System.IO.Path.Combine(Controller.BinFolder, "SNAP.RedirectionHelper.bat"),
                    outputRedirectionFile + " " + binFile + " " + parameters
                    );
            }

            startInfo.WorkingDirectory = executionFolder.FullName;
            startInfo.UseShellExecute = false;
            /// TODO: remove hack that uses a hard-coded path to cygwin
            startInfo.EnvironmentVariables["path"] =
                @"c:\cygwin\bin;c:\cygwin\usr\bin;c:\cygwin\usr\X11R6\bin;" +
                startInfo.EnvironmentVariables["path"];

            System.Diagnostics.Process process =
                System.Diagnostics.Process.Start(startInfo);

            // TODO: show a message that work is in progress
            //Controller.WaitForExit(process);
            process.WaitForExit();
            return process;
        }

        public static string GetExecutionFolder(Script script, Resource resource)
        {
            System.IO.DirectoryInfo jobsFolder =
                new System.IO.DirectoryInfo(Controller.JobFolder);

            string resourceFolderName = System.IO.Path.Combine(jobsFolder.FullName, resource.QualifiedName);
            string executionFolderName = resourceFolderName + "." + script.Name;

            return executionFolderName;
        }

        /// <summary>
        /// Interprets the specified parameters.
        /// </summary>
        /// <param name="parameters">The parameters.</param>
        /// <param name="resource">The resource.</param>
        /// <returns></returns>
        public static string Interpret(Script script, string parameters, Resource resource)
        {
            string result = parameters;
            do
            {
                System.Text.RegularExpressions.Match match =
                    System.Text.RegularExpressions.Regex.Match(result,
                        @"\$([a-zA-Z0-9 ]+(?:\.[a-zA-Z0-9 ]+)*)\$"
                        );

                if (match == null || !match.Success)
                    break;


                /// break the variable name into its inner structure
                /// For instance: Sequence File.File
                string varValue = null;
                string completeVarName = match.Groups[1].Captures[0].Value;

                switch (completeVarName)
                {
                    case "ExecutionFolder":
                        varValue = GetExecutionFolder(script, resource);
                        varValue = varValue.TrimEnd('/');
                        break;

                    case "PluginFolder":
                        varValue = Controller.PluginFolder;
                        varValue = varValue.TrimEnd('/');
                        break;

                    /// TODO: make this more general
                    case "PluginFolder.Unix":
                        varValue = Controller.PluginFolder;
                        varValue = varValue.Replace('\\', '/');
                        varValue = varValue.Replace(" ", @"\ ");
                        varValue = varValue.TrimEnd('/');
                        break;

                    case "ExecutionFolder.Unix":
                        varValue = GetExecutionFolder(script, resource);
                        varValue = varValue.Replace('\\', '/');
                        varValue = varValue.Replace(" ", @"\ ");
                        varValue = varValue.TrimEnd('/');
                        break;

                    default:
                        {
                            string[] varNameParts = completeVarName.Split('.');

                            /// follow the inner structure to the last internal reference
                            IResourceValue currentResource = resource;
                            for (int i = 0; i < varNameParts.Length; ++i)
                            {
                                currentResource = currentResource.GetDynamicProperty(varNameParts[i]);
                            }

                            varValue = currentResource.ToString();
                        }
                        break;
                }

                /// replace the $variable$ with the value
                result = System.Text.RegularExpressions.Regex.Replace(
                    result, @"\$" + completeVarName + @"\$", varValue);
            }
            while (true);

            return result;
        }

    }

    #endregion Util

    #endregion Script

    

    namespace Tests {
        [NUnit.Framework.TestFixture]
        public class ExecutionTests
        {
            [NUnit.Framework.Test]
            public void TestRedirection()
            {
                string testFilename = @"c:\test.test";
                if (System.IO.File.Exists (testFilename))
                    System.IO.File.Delete (testFilename);

                NUnit.Framework.Assert.IsFalse (System.IO.File.Exists (testFilename));

                Process process = Scripts.Util.Run(
                    @"C:\windows\system32\command.com",
                    "/C echo hello word",
                    testFilename,
                    new System.IO.DirectoryInfo (@"c:\")
                    );

                NUnit.Framework.Assert.IsTrue (process.WaitForExit(1000));
                NUnit.Framework.Assert.IsTrue(process.ExitCode == 0);
                NUnit.Framework.Assert.IsTrue (System.IO.File.Exists (testFilename));
            }
        }
    }

}

