using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class CalcForm : Form {
        public CalcForm() {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            int x,  k,  N,  M;
            HyperGeometric.TFPN2Params (
                decimal.ToDouble (numTP.Value),
                decimal.ToDouble (numFP.Value),
                decimal.ToDouble (numTN.Value),
                decimal.ToDouble (numFN.Value),
                out x,
                out k,
                out N,
                out M);

            textBox1.Text = (HyperGeometric.logTailhyge (x, M, k, N) / System.Math.Log (10)).ToString ();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e) {
            if (radioButton3.Checked) {
                textBox1.Text = System.Math.Pow(10, double.Parse(textBox1.Text)).ToString();                
            }
            else {
                textBox1.Text = System.Math.Log10(double.Parse(textBox1.Text)).ToString();
            }
            
            
        }
    }
}