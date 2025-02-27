using Cosmos.Core;
using Cosmos.Core.Memory;
using Cosmos.HAL;
using Stellib.Drivers.Injection;
using System;
using System.Collections.Generic;
using System.Text;
using Sys = Cosmos.System;
using Stellib.ELF;
using IL2CPU.API.Attribs;
using CodeExecution = Stellib.Drivers.Injection.CodeExecution;
using XSharp.Assembler;
namespace RawExecution
{
    public unsafe class Kernel : Sys.Kernel
    {
        [ManifestResourceStream(ResourceName = "RawExecution.Drivers.ELF.TestElf")]
        public static byte[] TestElf;
        protected override void BeforeRun()
        {
            byte[] nElf = new byte[TestElf.Length];
            for (int i = 0; i < TestElf.Length; i++)
            {
                nElf[i] = TestElf[i];
            }
            Elf32 elf = new Elf32(nElf);
            elf.PrintElfInfo();
            elf.LoadElf();

        }

        protected override void Run()
        {
            
        }
    }
}
