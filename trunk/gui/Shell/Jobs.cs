using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    internal class Jobs {
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
