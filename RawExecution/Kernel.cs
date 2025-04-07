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
using XSharp.Assembler;
using Cosmos.Core_Asm;
using Cosmos.System.FileSystem;
using Cosmos.System.FileSystem.VFS;
using System.IO;
using System.Diagnostics.Metrics;
using RawExecution.Drivers.ELF;
namespace RawExecution
{
    public unsafe class Kernel : Sys.Kernel
    {
        CosmosVFS mVFS = new CosmosVFS();

        [ManifestResourceStream(ResourceName = "RawExecution.Drivers.ELF.TestElf")]
        public static byte[] TestElf;
        protected override void BeforeRun()
        {
            VFSManager.RegisterVFS(mVFS);

            File.WriteAllBytes(@"0:\Elfs\TestElf", TestElf);
            File.WriteAllText(@"0:\test.txt", "Haii!! :3");
            
            Elf32 elf = new Elf32(@"0:\Elfs\TestElf");
            elf.LoadAndExecuteElf();
            elf.FreeElf();
        }

        protected override void Run()
        {
        }
    }
}
