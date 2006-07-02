using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    public class Controller {
        public static void ShowException(System.Exception x) {
            Implementation.ShowException(x);
        }
        public static void ShowException(string message, System.Exception x)
        {
            Implementation.ShowException(message, x);
        }
        public static bool ChooseResource (out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource(null, out resource);
        }
        public static bool ChooseResource(
            IEnumerable <SNAP.Resources.InternalRefFieldType.Mask> masks, 
            out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource(masks, out resource);
        }
        public static bool ChooseFile(string mask, out string path)
        {
            return Implementation.ChooseFile(mask, out path);
        }
        public static int WaitForExit(System.Diagnostics.Process process)
        {
            return Implementation.WaitForExit(process);
        }
        public static Resources.IResourceUI CreateResourceUI(Resources.IResourceValue value)
        {
            return Implementation.CreateResourceUI(value);
        }
        


        public static string BinFolder
        {
            get
            {
                if (Implementation == null)
                    return System.Environment.CurrentDirectory;
                return Implementation.BinFolder;
            }
        }
        public static string SeqFolder
        {
            get
            {
                if (Implementation == null)
                    return System.Environment.CurrentDirectory;

                return Implementation.SeqFolder;
            }
        }

        public static string JobFolder
        {
            get
            {
                if (Implementation == null)
                    return System.Environment.CurrentDirectory;

                return Implementation.JobFolder;
            }
        }
        public static string DataFolder
        {
            get
            {
                if (Implementation == null)
                    return System.Environment.CurrentDirectory;

                return Implementation.DataFolder;
            }
        }
        public static string PluginFolder
        {
            get
            {
                return Implementation.PluginFolder;
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
        public static System.Random Random = new Random();
        
        public interface Impl
        {
            void ShowException(System.Exception x);
            void ShowException(string message, System.Exception x);
            bool ChooseResource(
                IEnumerable <SNAP.Resources.InternalRefFieldType.Mask> masks, 
                out SNAP.Resources.Resource resource
                );

            bool ChooseFile(string mask, out string path);
            int WaitForExit(System.Diagnostics.Process process);
            Resources.IResourceUI CreateResourceUI(Resources.IResourceValue value);

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
            string PluginFolder
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
