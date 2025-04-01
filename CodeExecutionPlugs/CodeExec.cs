using Stellib.Drivers.Injection;
using System;
using XSharp.Assembler;
using IL2CPU.API.Attribs;
using XSharp.x86.Assemblers;
using XSharp;
using XSharp.Assembler.x86;
namespace Stellib.Plugs
{
    
    [Plug(Target = typeof(RawExecute))]
    public class ExecBinaryAssembler : AssemblerMethod
    {
        // public static unsafe void ExecuteBinary(void*** FuncTable, void* Entry)
        public override void AssembleNew(XSharp.Assembler.Assembler aAssembler, object aMethodInfo)
        {
            XS.LiteralCode("mov ebx, [ebp + 8]"); // Get the entry point
            XS.LiteralCode("mov eax, [ebp + 12]"); // Get the function table
            XS.PushAllRegisters(); // Save all registers
            XS.LiteralCode("push eax"); // Push the entry point
            XS.LiteralCode("call ebx"); // Call the entry point
            XS.PopAllRegisters(); // Restore all registers
            XS.LiteralCode("ret"); // Return
        }
    }

    [Plug(Target = typeof(ExecutionRepair))]
    public class RestoreStackAssembler : AssemblerMethod
    {
        // public static unsafe void RestoreStack(uint SP, uint BP) [Cosmos is a fucker and pushes args in reverse order than standard]
        public override void AssembleNew(XSharp.Assembler.Assembler aAssembler, object aMethodInfo)
        {
            XS.LiteralCode("pop eax"); // Clear EBP
            XS.LiteralCode("pop eax"); // Clear return address (Keep it)
            XS.LiteralCode("pop ebx"); // Get the original EBP
            XS.LiteralCode("pop ecx"); // Get the original ESP
            XS.LiteralCode("mov ebp, ebx"); // Restore EBP to Pre-ControlTransfer state
            XS.LiteralCode("mov esp, ecx"); // Restore ESP to Pre-ControlTransfer state
            XS.LiteralCode("push eax"); // Push the return address back
            XS.LiteralCode("ret"); // Return
        }
    }
}
