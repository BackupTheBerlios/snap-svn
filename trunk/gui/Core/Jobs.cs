using System.IO;

namespace SNAP.Resources
{
    public class Execution
    {
        /// <summary>
        /// Runs the specified execution.
        /// </summary>
        /// <param name="name">The execution name.</param>
        /// <param name="resource">The resource.</param>
        public static void Run(string name, Resource resource)
        {
            ExecutionType execType = resource.ResourceType.Executions[name];
            string parameters = Interpret(name, execType.Params, resource);

            if (!execType.CreateFolder)
            {
                System.Diagnostics.Process.Start(execType.Bin, parameters);
            }
            else {
                /// create a directory for the files
                DirectoryInfo executionFolder = Directory.CreateDirectory(GetExecutionFolder (name, resource));

                /// run the job
                System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo(execType.Bin, parameters);
                startInfo.WorkingDirectory = SNAP.Controller.JobFolder;
                
                startInfo.FileName = execType.Bin;
                if (!System.IO.Path.IsPathRooted(startInfo.FileName))
                {
                    /// it is a path relative to the bin directory of SNAP
                    if (File.Exists (System.IO.Path.Combine(SNAP.Controller.BinFolder, startInfo.FileName ))) {
                        startInfo.FileName = System.IO.Path.Combine(SNAP.Controller.BinFolder, startInfo.FileName);
                    }
                }

                startInfo.UseShellExecute = false;
                startInfo.RedirectStandardError = true;
                startInfo.RedirectStandardOutput = true;
                System.Diagnostics.Process process = 
                    System.Diagnostics.Process.Start(startInfo);

                // TODO: show a message that work is in progress
                Controller.WaitForExit(process);
                if (process.ExitCode == 0)
                {
                    /// process the dynamic output files
                    foreach (string filename in execType.DynamicOutputFiles)
                    {
                        Controller.CurrentResources.LoadAdditionalResources(
                            Path.Combine(executionFolder.FullName, filename));
                    }
                }
                else
                {
                    /// the process didnt work
                }
            }
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
                        @"\$([a-zA-Z0-9 ]+(?:\.[a-zA-Z0-9 ]+)*)"
                        );

                if (match == null || !match.Success)
                    break;

              
                /// break the variable name into its inner structure
                /// For instance: Sequence File.File
                string completeVarName = match.Groups[1].Captures[0].Value;
                string[] varNameParts = completeVarName.Split('.');

                /// follow the inner structure to the last internal reference
                Resource currentResource = resource;
                for (int i = 0 ; i <varNameParts.Length - 1 ; ++i) {
                    /// this field must exists, and it must be an internal_ref, and it has to have more than one value
                    System.Diagnostics.Trace.Assert (currentResource.Fields.ContainsKey (varNameParts [i]));
                    System.Diagnostics.Trace.Assert (currentResource.Fields [varNameParts [i]].Type.Type.Equals ("internal_ref"));
                    System.Diagnostics.Trace.Assert (currentResource.Fields [varNameParts [i]].Values.Count > 0);

                    object value = currentResource.Fields [varNameParts [i]].Values [0];
                    if (value is string)
                        currentResource = Controller.CurrentResources.FindResource((string)value);
                    else
                        currentResource = (SNAP.Resources.Resource)value;
                }

                string varName = varNameParts[varNameParts.Length - 1];
                string varValue = null;
                if (currentResource.Fields.ContainsKey(varName))
                {
                    /// this is a user-defined field
                    varValue = currentResource.Fields[varName].Values[0].ToString();
                }
                else
                {
                    /// maybe it is a mandatory field
                    switch (varName)
                    {
                        case "Name":
                            varValue = resource.Name;
                            break;

                        case "ID":
                            varValue = resource.ID.ToString();
                            break;

                        case "Family":
                            varValue = resource.Parent.QualifiedName;
                            break;

                        case "Folder":
                            // TODO: return the folder of the resource
                            break;

                        case "ExecutionFolder":
                            varValue = GetExecutionFolder(executionName, resource);
                            break;

                        default:
                            // TODO: give a more thoughtful error message
                            System.Diagnostics.Debug.Fail("unknown variable " + varName);
                            break;
                    }
                }
                
                result = System.Text.RegularExpressions.Regex.Replace(
                    result, @"\$" + completeVarName + @"\$", varValue);
            }
            while (true);

            return result;
        }

    }

}


#if false 

using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    public class Jobs {
        /// <summary>
        /// Creates the job.
        /// </summary>
        /// <param name="seq">The seq.</param>
        /// <param name="wgt">The WGT.</param>
        /// <param name="name">The name.</param>
        /// <param name="confFile">The conf file.</param>
        public static void CreateJob(
            string family, //Resources.CompositeResource family,
            Resources.SeqFileResource seq,
            Resources.WgtFileResource wgt,
            string name,
            string confFile) {
            /// create a new folder for the job
            System.IO.DirectoryInfo jobsFolder = 
                new System.IO.DirectoryInfo(Program.CurrentOptions.JobFolder);

            System.IO.DirectoryInfo jobFolder = 
                jobsFolder.CreateSubdirectory(family.Replace('.', '\\'));

            System.IO.DirectoryInfo jobDataFolder =
                jobFolder.CreateSubdirectory ("data");

            /// now copy the conf, seq, and wgt files to the directory
            System.IO.File.Copy (
                seq.Filename,
                System.IO.Path.Combine (jobDataFolder.FullName, "sequence.fasta")
                );

            System.IO.File.Copy(
                wgt.Filename,
                System.IO.Path.Combine(jobDataFolder.FullName, "sequence.wgt")
                );

            System.IO.File.Copy(
                confFile,
                System.IO.Path.Combine(jobDataFolder.FullName, "seed.conf")
                );

            System.IO.File.Copy (
                System.IO.Path.Combine (Program.CurrentOptions.DataFolder, "RunMe.bat"),
                System.IO.Path.Combine(jobFolder.FullName, "RunMe.bat")
                );

            System.Environment.CurrentDirectory = jobFolder.FullName;
            System.Diagnostics.Process process = 
                System.Diagnostics.Process.Start(System.IO.Path.Combine(jobFolder.FullName, "RunMe.bat"));

            process.WaitForExit();
            int exitCode = process.ExitCode;
        }
    }
}

#endif // 0