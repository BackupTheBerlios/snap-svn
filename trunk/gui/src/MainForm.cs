using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class MainForm : Form {
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
            ConfiGenForm form = new ConfiGenForm();
            form.MdiParent = this;
            form.Show();
        }

        private void MainForm_Load(object sender, EventArgs e) {

        }

        private void toolStripButton2_Click_1(object sender, EventArgs e) {
            SeedSearchForm form = new SeedSearchForm();
            form.MdiParent = this;
            form.Show();
        }
    }
}