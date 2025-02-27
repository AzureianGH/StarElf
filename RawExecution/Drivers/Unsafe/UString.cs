using Cosmos.Core.Memory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stellib.Str
{
    public unsafe class UString
    {
        private char* internalBuffer;
        private int length;
        public static char* ConvertManaged(string str)
        {
            char* buffer = (char*)Heap.Alloc((uint)(str.Length * 2));
            for (int i = 0; i < str.Length; i++)
            {
                buffer[i] = str[i];
            }
            return buffer;
        }
    }
}
