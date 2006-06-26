using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class MainForm : Form {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
            SNAP.Controller.Implementation = new WinformsController();

            Controller.CurrentResources.LoadResources();
            Application.Run(new MainForm());
        }        
        
        public MainForm() {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            
        }

        private void toolStripButton2_Click(object sender, EventArgs e) {
            SeedSearchForm seedsearchForm = new SeedSearchForm();
            seedsearchForm.MdiParent = this;
            seedsearchForm.Show(); 
        }

        private void toolStripButton1_Click(object sender, EventArgs e) {
            FamiliesForm form = new FamiliesForm();
            form.MdiParent = this;
            form.Show();
        }

        private void toolStripButton4_Click(object sender, EventArgs e) {
            // TODO: launch external program?
            //ConfiGenForm form = new ConfiGenForm();
            //form.MdiParent = this;
            //form.Show();
        }

        private void MainForm_Load(object sender, EventArgs e) {

        }

        private void toolStripButton2_Click_1(object sender, EventArgs e) {
            SeedSearchForm form = new SeedSearchForm();
            form.MdiParent = this;
            form.Show();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e) {
            AboutBox1 about = new AboutBox1 ();
            about.Show ();
        }

        private void toolStripButton5_Click(object sender, EventArgs e) {
            CalcForm form = new CalcForm();
            form.MdiParent = this;
            form.Show();
        }
    }
}