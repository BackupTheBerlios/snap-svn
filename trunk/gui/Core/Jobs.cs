using System;
using System.IO;
using System.Diagnostics;
using System.Collections.Generic;

namespace SNAP.Resources
{
    #region Script

    public class Script : SNAP.Util.IChild <ResourceType>
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
            this.Steps = new SNAP.Util.ChildList<IStep, Script>(this);
        }

        #endregion Constructor

        #region Interfaces

        #region IStep

        public interface IStep : SNAP.Util.IChild<Script>
        {
            /// <summary>
            /// Executes the step for the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            void Execute(Resource resource);
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
            /// Gets the fields.
            /// </summary>
            /// <value>The fields.</value>
            SNAP.Util.IChildList<IExportField, IExportStep> Fields
            {
                get;
            }
        }

        #endregion IExport

        #region IExportField

        /// <summary>
        /// 
        /// </summary>
        internal interface IExportField : SNAP.Util.IChild<IExportStep>
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
            string GetValue(Resource resource);
        }

        #endregion IExportField

        #endregion Interfaces

        #region Interface Implementations

        #region ParamsExport

        /// <summary>
        /// 
        /// </summary>
        internal class ParamsExport : IExportStep
        {
            #region Privates

            private Script _script = null;
            private string _filename;
            protected SNAP.Util.ChildList<IExportField, IExportStep> _fields;

            #endregion Privates

            #region Ctor

            public ParamsExport(string filename)
            {
                _fields = new SNAP.Util.ChildList<IExportField, IExportStep>(this);
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

            public SNAP.Util.IChildList<IExportField, IExportStep> Fields
            {
                get
                {
                    return _fields;
                }
            }

            #endregion

            #region IStep Members

            /// <summary>
            /// Executes the step for the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            public void Execute(Resource resource)
            {
                string fullFilename = System.IO.Path.Combine(
                    Util.GetExecutionFolder(this.MyParent.Name, resource), Filename);

                System.IO.Directory.GetParent(fullFilename).Create();

                /// create the file
                using (StreamWriter writer = new StreamWriter(fullFilename))
                {

                    /// write all fields to file
                    foreach (IExportField field in this._fields)
                    {
                        /// since params files are being used in unix environment
                        /// we use unix-style line endings (\n) 
                        /// instead of window-style line endings (\r\n)
                        writer.Write(field.Name);
                        writer.Write('\n');

                        /// we interpret the value of the field
                        /// TODO: fix Interepret prototype to make this general
                        //string value = Execution.Interpret(_script.Name, field.Value, resource);
                        writer.Write(field.GetValue(resource));
                        writer.Write('\n');
                    }

                    writer.Flush();
                }
            }

            #endregion

            #region IChild<Script> Members

            /// <summary>
            /// Gets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public Script MyParent
            {
                get
                {
                    return _script;
                }
            }

            /// <summary>
            /// Sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            Script SNAP.Util.IChild<Script>.MyParent
            {
                get
                {
                    return _script;
                }
                set
                {
                    _script = value;
                }
            }

            #endregion
        }

        #endregion ParamsExport

        #region PathExportField

        internal class PathExportField : IExportField
        {
            #region Privates

            private readonly string _name;
            private readonly string _value;
            private IExportStep _parent;

            #endregion Privates

            #region Ctor

            /// <summary>
            /// Initializes a new instance of the <see cref="T:PathExportField"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            /// <param name="value">The value.</param>
            public PathExportField(string name, string value)
            {
                _name = name;
                _value = value;
            }

            #endregion Ctor

            #region IExportField Members

            /// <summary>
            /// Gets the name.
            /// </summary>
            /// <value>The name.</value>
            public string Name
            {
                get {
                    return _name;
                }
            }

            /// <summary>
            /// Gets the value.
            /// </summary>
            /// <value>The value.</value>
            public string GetValue (Resource resource)
            {
                /// retrieve the path
                string result = Util.Interpret(MyParent.MyParent.Name, _value, resource);

                /// TODO: allow basing the path on some directory, resulting in 
                /// a relative path instead of an absolute path
                
                /// we use unix-style paths, with a '/' separator instead of a '\' separator
                result = result.Replace('\\', '/');

                /// we replace a space character ' ' with a space escape sequence "\ "
                result = result.Replace (" ", @"\ ");
                return result;
            }

            #endregion

            #region IChild<IExport> Members

            /// <summary>
            /// Gets or sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            IExportStep SNAP.Util.IChild<IExportStep>.MyParent
            {
                get
                {
                    return _parent;
                }
                set
                {
                    _parent = value;
                }
            }

            /// <summary>
            /// Gets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public IExportStep MyParent
            {
                get
                {
                    return _parent;
                }
            }

            #endregion
        }

        #endregion PathExportField

        #region TextExportField

        internal class TextExportField : IExportField
        {
            #region Privates

            private readonly string _name;
            private readonly string _value;
            private IExportStep _parent;

            #endregion Privates

            #region Ctor

            /// <summary>
            /// Initializes a new instance of the <see cref="T:PathExportField"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            /// <param name="value">The value.</param>
            public TextExportField(string name, string value)
            {
                _name = name;
                _value = value;
            }

            #endregion Ctor

            #region IExportField Members

            /// <summary>
            /// Gets the name.
            /// </summary>
            /// <value>The name.</value>
            public string Name
            {
                get
                {
                    return _name;
                }
            }

            /// <summary>
            /// Gets the value.
            /// </summary>
            /// <value>The value.</value>
            public string GetValue(Resource resource)
            {
                return Util.Interpret(MyParent.MyParent.Name, _value, resource);
            }

            #endregion

            #region IChild<IExport> Members

            /// <summary>
            /// Gets or sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            IExportStep SNAP.Util.IChild<IExportStep>.MyParent
            {
                get
                {
                    return _parent;
                }
                set
                {
                    _parent = value;
                }
            }

            /// <summary>
            /// Gets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public IExportStep MyParent
            {
                get
                {
                    return _parent;
                }
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
            public void Execute(Resource resource)
            {
                Util.Run(this, resource);
            }

            #endregion

            #region IChild<Script> Members

            /// <summary>
            /// Gets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public Script MyParent
            {
                get
                {
                    return _parent;
                }
            }

            /// <summary>
            /// Gets or sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            Script SNAP.Util.IChild<Script>.MyParent
            {
                get
                {
                    return _parent;
                }
                set
                {
                    _parent = value;
                }
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
            public void Execute(Resource resource)
            {
                string executionFolder = SNAP.Resources.Script.Util.GetExecutionFolder(MyParent.Name, resource);

                Controller.CurrentResources.LoadAdditionalResources(
                    resource,
                    Path.Combine(executionFolder, this.Filename)
                    );
            }

            #endregion

            #region IChild<Script> Members

            /// <summary>
            /// Gets or sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            Script SNAP.Util.IChild<Script>.MyParent
            {
                get
                {
                    return _parent;
                    
                }
                set
                {
                    _parent = value;
                }
            }

            /// <summary>
            /// Gets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public Script MyParent
            {
                get
                {
                    return _parent;

                }
            }

            #endregion
        }
        
        #endregion ImportStep

        internal class ConditionalStep : IStep
        {
            private Script _parent;
            private readonly Conjunction _if;
            private readonly SNAP.Util.ChildList<IStep, Script> _then;
            private readonly IStep _else;

            #region IStep Members

            /// <summary>
            /// Executes the step for the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            public void Execute(Resource resource)
            {
                if (_if.Process (resource)) {
                    foreach (IStep step in _then)
                    {
                        step.Execute(resource);
                    }
                }
                else {
                    if (_else != null)
                        _else.Execute (resource);
                }

                throw new Exception("The method or operation is not implemented.");
            }

            #endregion

            #region IChild<Script> Members

            /// <summary>
            /// Gets or sets my parent.
            /// </summary>
            /// <value>My parent.</value>
            public Script MyParent
            {
                get
                {
                    return _parent;
                }
                set
                {
                    _parent = value;
                }
            }

            #endregion
        }

        #endregion Interface Implementations

        #region Util

        internal static class Util
        {
            /*
            /// <summary>
            /// Runs the specified execution.
            /// </summary>
            /// <param name="name">The execution name.</param>
            /// <param name="resource">The resource.</param>
            public static void Run(string name, Resource resource)
            {
                Script execType = resource.ResourceType.Executions[name];
                foreach (Script.ExecuteStep step in execType.Steps)
                {
                    Run(step, resource);
                }
            }
             */

            /// <summary>
            /// Runs the specified step.
            /// </summary>
            /// <param name="step">The step.</param>
            public static void Run(Script.ExecuteStep step, Resource resource)
            {
                Script execType = step.MyParent;

                string parameters = Interpret(
                    execType.Name,
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
                    DirectoryInfo executionFolder = Directory.CreateDirectory(GetExecutionFolder(execType.Name, resource));

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
                    else if (File.Exists (System.IO.Path.Combine(SNAP.Controller.PluginFolder, binFile))) {
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

            public static string GetExecutionFolder(string executionName, Resource resource)
            {
                System.IO.DirectoryInfo jobsFolder =
                    new System.IO.DirectoryInfo(Controller.JobFolder);

                string resourceFolderName = System.IO.Path.Combine(jobsFolder.FullName, resource.QualifiedName);
                string executionFolderName = resourceFolderName + "." + executionName;

                return executionFolderName;
            }

            /// <summary>
            /// Interprets the specified parameters.
            /// </summary>
            /// <param name="parameters">The parameters.</param>
            /// <param name="resource">The resource.</param>
            /// <returns></returns>
            public static string Interpret(string executionName, string parameters, Resource resource)
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
                            varValue = GetExecutionFolder(executionName, resource);
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
                            varValue = GetExecutionFolder(executionName, resource);
                            varValue = varValue.Replace('\\', '/');
                            varValue = varValue.Replace(" ", @"\ ");
                            varValue = varValue.TrimEnd('/');
                            break;

                        default:    {
                                string[] varNameParts = completeVarName.Split('.');

                                /// follow the inner structure to the last internal reference
                                IResourceValue currentResource = resource;
                                for (int i = 0; i < varNameParts.Length; ++i)
                                {
                                    currentResource = currentResource.GetDynamicProperty (varNameParts[i]);
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

        #region Properties

        // TODO: make this imutable
        //public readonly List<string> DynamicOutputFiles = new List<string>();
        public readonly SNAP.Util.ChildList<IStep, Script> Steps;
        //public readonly List<string> DynamicOutputFiles = new List<string>();

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

        public void Execute(Resource resource)
        {
            foreach (IStep step in Steps)
            {
                step.Execute(resource);
            }
        }
    }

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

                Process process = SNAP.Resources.Script.Util.Run (
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

