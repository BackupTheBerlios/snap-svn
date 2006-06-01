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
                System.Diagnostics.Process.Start(execType.Bin, parameters);

                /// process the dynamic output files
                foreach (string filename in execType.DynamicOutputFiles)
                {
                    Controller.CurrentResources.LoadAdditionalResources (
                        Path.Combine (executionFolder.FullName, filename));
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
                    System.Text.RegularExpressions.Regex.Match(result, @"\$([a-zA-Z0-9]*)\$");

                if (match == null || !match.Success)
                    break;

                string varName = match.Groups[1].Captures[0].Value;
                string varValue = null;
                if (resource.Fields.ContainsKey(varName))
                {
                    /// this is a user-defined field
                    varValue = resource.Fields[varName].Values[0].ToString();
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
                    result, @"\$" + varName + @"\$", varValue);
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