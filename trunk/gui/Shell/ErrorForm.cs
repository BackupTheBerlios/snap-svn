using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class ErrorForm : Form {
        public ErrorForm(System.Exception x) {
            InitializeComponent();

            txtMain.Text =
                "An error of type \"" + x.GetType().FullName + "\"\r\n" + 
                "Has Occured. The message is \"" + x.Message + "\"\r\n" + 
                "Please contact the maintainer of this program.\r\n";
            txtDetails.Text = x.ToString();
        }

        public ErrorForm(string message, System.Exception x)
        {
            InitializeComponent();

            txtMain.Text = message + "\r\n\r\n" + 
                "An error of type \"" + x.GetType().FullName + "\"\r\n" +
                "Has Occured. The message is \"" + x.Message + "\"\r\n" +
                "Please contact the maintainer of this program.\r\n";
            txtDetails.Text = x.ToString();
        }

        private void btnOK_Click(object sender, EventArgs e) {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void btnQuit_Click(object sender, EventArgs e) {
            this.DialogResult = DialogResult.Abort;
            Application.Exit();
            this.Close();
        }
    }
}