using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class SeedSearchForm : Form {
        public SeedSearchForm() {
            InitializeComponent();
        }

        internal Resources.Resource Sequences;
        internal Resources.Resource Weights;

        private void Form1_Load(object sender, EventArgs e) {

        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e) {

        }

        private void btnSeqBrowse_Click(object sender, EventArgs e) {
            FamiliesForm familiesForm = new FamiliesForm();
            if (familiesForm.ShowDialog() == DialogResult.OK) {
                Sequences = familiesForm.SelectedResource;
                txtSeqFile.Text = familiesForm.SelectedResource.QualifiedName;
            }
        }

        private void btnWgtBrowse_Click(object sender, EventArgs e) {
            FamiliesForm familiesForm = new FamiliesForm();
            if (familiesForm.ShowDialog() == DialogResult.OK) {
                Weights = familiesForm.SelectedResource;
                txtWgtFile.Text = familiesForm.SelectedResource.QualifiedName;
            }
        }

        private void optionsToolStripMenuItem_Click(object sender, EventArgs e) {

        }
        private void btnOK_Click(object sender, EventArgs e) {
            //SNAP.Jobs.CreateJob("general.jobs", (Resources.SeqFileResource)Sequences, (Resources.WgtFileResource) Weights, txtName.Text, txtConf.Text); 

        }

        private void btnConfBrowse_Click(object sender, EventArgs e) {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
                txtConf.Text = openFileDialog1.FileName;
        }
    }
}