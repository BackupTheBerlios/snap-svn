using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP.Resources
{
    public class SNAPException : System.ApplicationException 
    {
        public SNAPException()
        {
        }

        public SNAPException(string message)
            : base(message)
        {
        }
    }

    public class FieldException : SNAPException
    {
        public FieldException()
        {
        }

        public FieldException(string message)
            : base(message)
        {
        }
    }
}
