using Stellib.Drivers.Injection;
using System;
using XSharp.Assembler;
using IL2CPU.API.Attribs;
using XSharp.x86.Assemblers;
using XSharp;
using XSharp.Assembler.x86;
namespace Stellib.Plugs
{

    [Plug(Target = typeof(ExecutionRepair))]
    public class ExecRepair
    {
        [PlugMethod(Assembler = typeof(RestoreStackAssembler), PlugRequired = true)]
        public static unsafe void RestoreStack(uint SP, uint BP) => throw new NotImplementedException();
    }

    public class ExecuteRawAssembler : AssemblerMethod
    {
        // public static unsafe void ExecuteRaw(byte* Data)
        public override void AssembleNew(XSharp.Assembler.Assembler aAssembler, object aMethodInfo)
        {
            XS.LiteralCode("mov eax, [ebp + 8]");
            XS.PushAllRegisters();
            XS.LiteralCode("call eax");
            XS.PopAllRegisters();
        }
    }

    public class RestoreStackAssembler : AssemblerMethod
    {
        // public static unsafe void RestoreStack(uint SP, uint BP)
        public override void AssembleNew(XSharp.Assembler.Assembler aAssembler, object aMethodInfo)
        {
            XS.LiteralCode("pop eax"); // Clear EBP
            XS.LiteralCode("pop eax"); // Clear return address (Keep it)
            XS.LiteralCode("pop ebx"); // Get the original SP
        }
    }
}
