using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    public class Controller {
        public static void ShowException(System.Exception x) {
            Implementation.ShowException(x);
        }
        public static bool ChooseResource (out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource("", out resource);
        }
        public static bool ChooseResource(string type, out SNAP.Resources.Resource resource)
        {
            return Implementation.ChooseResource(type, out resource);
        }
        public static bool ChooseFile(string mask, out string path)
        {
            return Implementation.ChooseFile(mask, out path);
        }

        public interface Impl
        {
            void ShowException(System.Exception x);
            bool ChooseResource(string mask, out SNAP.Resources.Resource resource);
            bool ChooseFile(string mask, out string path);
        }

        public static Impl Implementation;
    }
}
