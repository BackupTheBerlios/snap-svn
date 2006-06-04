using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SNAP.ConfEditor
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string []argv)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
            //SNAP.Engine.Parser parser = new SNAP.Engine.Parser (argv);
            SNAP.Engine.Setup.ProgramName = System.Windows.Forms.Application.ProductName;
            if (argv.Length > 0)
            {
                SNAP.Engine.Conf conf = SNAP.Engine.Conf.LoadFile (argv [0]);
                Application.Run(new ConfiGenForm(conf));
            }
            else
            {
                Application.Run(new ConfiGenForm());
            }
        }
    }
}
