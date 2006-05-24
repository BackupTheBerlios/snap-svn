using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    class Util {
        public static void ShowException(System.Exception x) {
            ErrorForm errForm = new ErrorForm(x);
            errForm.ShowDialog();
        }
    }
}
