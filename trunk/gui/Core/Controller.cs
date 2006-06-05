using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    public class Controller {
        public static void ShowException(System.Exception x) {
            Implementation.ShowException(x);
        }
        public static bool ChooseResource (out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource("", out resource);
        }
        public static bool ChooseResource(string type, out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource(type, out resource);
        }
        public static bool ChooseFile(string mask, out string path)
        {
            return Implementation.ChooseFile(mask, out path);
        }
        public static int WaitForExit(System.Diagnostics.Process process)
        {
            return Implementation.WaitForExit(process);
        }


        public static string BinFolder
        {
            get
            {
                return Implementation.BinFolder;
            }
        }
        public static string SeqFolder
        {
            get
            {
                return Implementation.SeqFolder;
            }
        }

        public static string JobFolder
        {
            get
            {
                return Implementation.JobFolder;
            }
        }
        public static string DataFolder
        {
            get
            {
                return Implementation.DataFolder;
            }
        }
        public static string ResourcesFile
        {
            get
            {
                return Implementation.ResourcesFile;
            }
        }

        public static string ResourceTypesFile
        {
            get
            {
                return Implementation.ResourceTypesFile;
            }
        }

        public static Resources.DB CurrentResources = new Resources.DB();

        public interface Impl
        {
            void ShowException(System.Exception x);
            bool ChooseResource(string mask, out SNAP.Resources.Resource resource);
            bool ChooseFile(string mask, out string path);
            int WaitForExit(System.Diagnostics.Process process);

            string BinFolder
            {
                get;
            }
            string SeqFolder
            {
                get;
            }
            string JobFolder
            {
                get;
            }
            string DataFolder
            {
                get;
            }
            string ResourcesFile
            {
                get;
            }

            string ResourceTypesFile
            {
                get;
            }
        }

        public static Impl Implementation;
    }
}
