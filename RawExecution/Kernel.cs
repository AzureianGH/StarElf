using Sys = Cosmos.System;
using Stellib.ELF;
using IL2CPU.API.Attribs;
using Cosmos.System.FileSystem;
using Cosmos.System.FileSystem.VFS;
using System.IO;

namespace RawExecution
{
    public unsafe class Kernel : Sys.Kernel
    {
        //CosmosVFS mVFS = new CosmosVFS();
        public static Cosmos.Debug.Kernel.Debugger cmDebugger;
        
        [ManifestResourceStream(ResourceName = "RawExecution.Drivers.ELF.TestElf")]
        public static byte[] TestElf;
        protected override void BeforeRun()
        {
            cmDebugger = mDebugger;
            //VFSManager.RegisterVFS(mVFS);
            
            //File.WriteAllBytes(@"0:\Elfs\TestElf", TestElf);
            //File.WriteAllText(@"0:\test.txt", "Well well well");
            
            Elf32 elf = new Elf32(TestElf);
            elf.LoadAndExecuteElf();
            elf.FreeElf();
        }

        protected override void Run()
        {
        }
    }
}
