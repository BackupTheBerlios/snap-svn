using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SNAP {
    static class Program {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            Program.CurrentResources.LoadResources();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }

        public static Options CurrentOptions = new Options();
        public static Resources CurrentResources = new Resources();
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