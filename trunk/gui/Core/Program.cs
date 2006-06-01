using System;
using System.Collections.Generic;

namespace SNAP {
    static public class Program {
        public static Options CurrentOptions = new Options();
        public static Resources.DB CurrentResources = new Resources.DB();
    }

    public class Options {
        public string SeqFolder {
            get {
                return @"C:\Aviad\Dev\SNAP\Inputs";
            }
        }
        public string JobFolder {
            get {
                return System.IO.Path.Combine(DataFolder, "MyJobs");
            }
        }
        public string DataFolder {
            get {
                /// same location as executable of SNAP
                //return System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
                return @"D:\Aviad\Dev\SNAP\trunk\gui\src\bin\Debug";
            }
        }
        public string ResourcesFile {
            get {
                /// same location as executable of SNAP
                return System.IO.Path.Combine (DataFolder, "resources.xml");
            }
        }

        public string ResourceTypesFile
        {
            get
            {
                /// same location as executable of SNAP
                return System.IO.Path.Combine(DataFolder, "resources.types.xml");
            }
        }
    }


}