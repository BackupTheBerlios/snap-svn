namespace SNAP
{
    partial class RunProcessForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txtCommandline = new System.Windows.Forms.TextBox();
            this.txtTime = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtOutput = new System.Windows.Forms.TextBox();
            this.txtError = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.button1.Location = new System.Drawing.Point(0, 386);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(673, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Cancel";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.txtCommandline);
            this.groupBox1.Controls.Add(this.txtTime);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(673, 76);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Running";
            // 
            // txtCommandline
            // 
            this.txtCommandline.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtCommandline.Location = new System.Drawing.Point(3, 36);
            this.txtCommandline.MinimumSize = new System.Drawing.Size(4, 20);
            this.txtCommandline.Name = "txtCommandline";
            this.txtCommandline.ReadOnly = true;
            this.txtCommandline.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.txtCommandline.Size = new System.Drawing.Size(667, 20);
            this.txtCommandline.TabIndex = 1;
            this.txtCommandline.WordWrap = false;
            // 
            // txtTime
            // 
            this.txtTime.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtTime.Location = new System.Drawing.Point(3, 16);
            this.txtTime.MaximumSize = new System.Drawing.Size(4, 20);
            this.txtTime.MinimumSize = new System.Drawing.Size(4, 20);
            this.txtTime.Name = "txtTime";
            this.txtTime.ReadOnly = true;
            this.txtTime.Size = new System.Drawing.Size(4, 20);
            this.txtTime.TabIndex = 0;
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtOutput);
            this.groupBox2.Controls.Add(this.txtError);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 76);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(673, 310);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Output";
            // 
            // txtOutput
            // 
            this.txtOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtOutput.Location = new System.Drawing.Point(3, 16);
            this.txtOutput.Multiline = true;
            this.txtOutput.Name = "txtOutput";
            this.txtOutput.ReadOnly = true;
            this.txtOutput.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput.Size = new System.Drawing.Size(667, 181);
            this.txtOutput.TabIndex = 1;
            this.txtOutput.WordWrap = false;
            // 
            // txtError
            // 
            this.txtError.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.txtError.Location = new System.Drawing.Point(3, 197);
            this.txtError.Multiline = true;
            this.txtError.Name = "txtError";
            this.txtError.ReadOnly = true;
            this.txtError.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtError.Size = new System.Drawing.Size(667, 110);
            this.txtError.TabIndex = 0;
            this.txtError.WordWrap = false;
            // 
            // RunProcessForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(673, 409);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.button1);
            this.Name = "RunProcessForm";
            this.Text = "RunProcessForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txtError;
        private System.Windows.Forms.TextBox txtCommandline;
        private System.Windows.Forms.TextBox txtTime;
        private System.Windows.Forms.TextBox txtOutput;
    }
}