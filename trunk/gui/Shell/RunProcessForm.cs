using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP
{
    public partial class RunProcessForm : Form
    {
        private DateTime _start = DateTime.Now;
        private System.Diagnostics.Process _process;
        private System.IO.BufferedStream _out;
        private System.IO.BufferedStream _err;
        private bool _outReadInProcess = false;
        private bool _errReadInProcess = false;
        private System.IO.StreamReader _outReader;
        private System.IO.StreamReader _errReader;

        public RunProcessForm(System.Diagnostics.Process process)
        {
            InitializeComponent();
            _process = process;
            _out = new System.IO.BufferedStream(_process.StandardOutput.BaseStream);
            _err = new System.IO.BufferedStream(_process.StandardError.BaseStream);
            // TODO: use async IO here
            if (_out.CanTimeout)
                _out.ReadTimeout = 1;

            if (_err.CanTimeout)
                _err.ReadTimeout = 1;

            _outReader = new System.IO.StreamReader(_out);
            _errReader = new System.IO.StreamReader(_err);
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            const int bufSize = 1024;

            int length = 0;
            char [] buffer = new char [bufSize];
            length = _outReader.Read(buffer, 0, bufSize);
            txtOutput.Text = txtOutput.Text + new string(buffer, 0, length);

            if (_process.WaitForExit(1))
            {
                length = _errReader.Read(buffer, 0, bufSize);
                txtError.Text = txtError.Text + new string(buffer, 0, length);

                button1.Text = "OK";
            }

            txtTime.Text = DateTime.Now.Subtract (_start).ToString ();
        }

        void process_ErrorTextAvailable(IAsyncResult ar)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        void process_OutputTextAvailable(IAsyncResult ar)
        {
            throw new Exception("The method or operation is not implemented.");
        }
    }
}