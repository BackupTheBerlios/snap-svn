using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SNAP {
    static class Program {
        public static Options CurrentOptions = new Options();
        public static Resources.DB CurrentResources = new Resources.DB();
    }

    class Options {
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
                return System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
            }
        }
        public string ResourcesFile {
            get {
                /// same location as executable of SNAP
                return System.IO.Path.Combine (DataFolder, "resources.xml");
            }
        }
    }


}