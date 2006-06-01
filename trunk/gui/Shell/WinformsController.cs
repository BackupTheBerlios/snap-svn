using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace SNAP
{
    class WinformsController : SNAP.Controller.Impl 
    {
        public void ShowException(System.Exception x)
        {
            ErrorForm errForm = new ErrorForm(x);
            errForm.ShowDialog();
        }
        public bool ChooseResource(string type, out SNAP.Resources.Resource resource)
        {
            FamiliesForm familiesForm = new FamiliesForm();
            if (familiesForm.ShowDialog() == DialogResult.OK)
            {
                resource = familiesForm.SelectedResource;
                return true;
            }
            resource = null;
            return false;
                
        }
        public bool ChooseFile(string mask, out string path)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.AddExtension = true;
            openFileDialog1.CheckFileExists = true;
            openFileDialog1.CheckPathExists = true;
            //openFileDialog1.DefaultExt = "*.seq, *.fasta";
            //openFileDialog1.Filter = "Fasta sequence files (*.seq;*.fasta)|*.SEQ;*.FASTA;|All files (*.*)|*.*";
            openFileDialog1.Filter = mask;
            openFileDialog1.InitialDirectory = SNAP.Program.CurrentOptions.SeqFolder;
            openFileDialog1.Multiselect = false;
            openFileDialog1.SupportMultiDottedExtensions = true;
            openFileDialog1.Title = "Choose a file";
            openFileDialog1.FileName = "";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                path = openFileDialog1.FileName;
                return true;
            }
            path = null;
            return false;
            //txtFilename.Text = openFileDialog1.FileName;
            //txtDisplayName.Text = System.IO.Path.GetFileNameWithoutExtension(Filename);
            
        }
    }
}
