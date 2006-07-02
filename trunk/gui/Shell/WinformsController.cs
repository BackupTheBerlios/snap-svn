using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using SNAP.Resources;

namespace SNAP
{
    class WinformsController : SNAP.Controller.Impl 
    {
        public readonly System.IO.DirectoryInfo _binFolder;

        public WinformsController()
        {
            _binFolder = new System.IO.DirectoryInfo (
                System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath)
                );
        }
        public WinformsController(string binFolder)
        {
            _binFolder = new System.IO.DirectoryInfo (binFolder);
        }

        public void ShowException(System.Exception x)
        {
            ErrorForm errForm = new ErrorForm(x);
            errForm.ShowDialog();
        }
        public void ShowException(string message, System.Exception x)
        {
            ErrorForm errForm = new ErrorForm(message, x);
            errForm.ShowDialog();
        }
        public bool ChooseResource(
            IEnumerable <SNAP.Resources.InternalRefFieldType.Mask> masks, 
            out SNAP.Resources.Resource resource)
        {
            FamiliesForm familiesForm;
            if (masks == null)
                familiesForm = new FamiliesForm();
            else
                familiesForm = new FamiliesForm(masks);

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
            openFileDialog1.InitialDirectory = SNAP.Controller.SeqFolder;
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
        public int WaitForExit(System.Diagnostics.Process process)
        {
            RunProcessForm form = new RunProcessForm(process);
            form.ShowDialog();
            return process.ExitCode;
        }
        public Resources.IResourceUI CreateResourceUI(Resources.IResourceValue value)
        {
            IResourceUI ui = null;
            switch (value.MyType.Typename)
            {
                case "text":
                    ui = new SNAP.ResourceFields.TextFieldControl();
                    ui.LoadFromFieldValue(value);
                    break;

                case "external_ref":
                    ui = new SNAP.ResourceFields.ExternalRefFieldControl();
                    ui.LoadFromFieldValue(value);
                    break;

                case "internal_ref":
                    ui = new SNAP.ResourceFields.InternalRefFieldControl();
                    ui.LoadFromFieldValue(value);
                    break;

                case "numeric":
                    ui = new SNAP.ResourceFields.NumericFieldControl();
                    ui.LoadFromFieldValue(value);
                    break;

                case "enum":
                    ui = new SNAP.ResourceFields.EnumFieldControl();
                    ui.LoadFromFieldValue(value);
                    break;
            }

            return ui;
        }

        public string BinFolder
        {
            get
            {
                return _binFolder.FullName;
            }
        }

        public string SeqFolder
        {
            get
            {
                return @"C:\Aviad\Dev\SNAP\Inputs";
            }
        }
        public string JobFolder
        {
            get
            {
                return System.IO.Path.Combine(RootFolder, "Data");
            }
        }
        /// <summary>
        /// Gets the root folder.
        /// </summary>
        /// <value>The root folder.</value>
        public string RootFolder
        {
            get 
            {
                System.IO.DirectoryInfo parent = _binFolder.Parent;
                return parent.FullName;
            }
        }
        public string DataFolder
        {
            get
            {
                return System.IO.Path.Combine(RootFolder, "Settings");
                
            }
        }
        public string PluginFolder
        {
            get
            {
                return System.IO.Path.Combine(RootFolder, "Plugins");
            }
        }
        public string ResourcesFile
        {
            get
            {
                /// same location as executable of SNAP
                return System.IO.Path.Combine(DataFolder, "resources.xml");
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
