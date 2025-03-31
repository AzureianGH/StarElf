
using IL2CPU.API.Attribs;
using Stellib.Plugs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace Stellib.Drivers.Injection
{   
    public class RawExecute
    {
        [PlugMethod(Assembler = typeof(ExecBinaryAssembler))]
        public static unsafe void ExecuteBinary(void*** FuncTable, void* Entry)
        {
            throw null;
        }
    }
    public class ExecutionRepair
    {
        [PlugMethod(Assembler = typeof(RestoreStackAssembler))]
        public static unsafe void RestoreStack(uint SP, uint BP)
        {
            throw null;
        }
    }
}
