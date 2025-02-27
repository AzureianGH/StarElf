using Cosmos.Core.Memory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using uchar = System.Byte;
namespace Stellib.ELF
{
    public enum ElfInstructionSet
    {
        NoSpecific = 0x0,
        Sparc = 0x2,
        X86 = 0x3,
        Mips = 0x8,
        PowerPC = 0x14,
        Arm = 0x28,
        SuperH = 0x2A,
        IA64 = 0x32,
        X86_64 = 0x3E,
        AArch64 = 0xB7,
        RiscV = 0xF3
    }
    public static class ElfNameConv
    {
        public static string ElfIS(ElfInstructionSet iset)
        {
            switch (iset)
            {
                case ElfInstructionSet.NoSpecific:
                    return "No Specific";
                case ElfInstructionSet.Sparc:
                    return "SPARC";
                case ElfInstructionSet.X86:
                    return "x86";
                case ElfInstructionSet.Mips:
                    return "MIPS";
                case ElfInstructionSet.PowerPC:
                    return "PowerPC";
                case ElfInstructionSet.Arm:
                    return "ARM";
                case ElfInstructionSet.SuperH:
                    return "SuperH";
                case ElfInstructionSet.IA64:
                    return "IA-64";
                case ElfInstructionSet.X86_64:
                    return "x86-64";
                case ElfInstructionSet.AArch64:
                    return "AArch64";
                case ElfInstructionSet.RiscV:
                    return "RISC-V";
            }
            return "";
        }

        public static string ElfF(ElfFlags flags)
        {
            switch (flags)
            {
                case ElfFlags.None:
                    return "None";
                case ElfFlags.Executable:
                    return "Executable";
                case ElfFlags.Writeable:
                    return "Writeable";
                case ElfFlags.Readable:
                    return "Readable";
            }
            return "";
        }

        public static string ElfST(ElfSegmentType type)
        {
            switch (type)
            {
                case ElfSegmentType.Null:
                    return "Null";
                case ElfSegmentType.Load:
                    return "Load";
                case ElfSegmentType.Dynamic:
                    return "Dynamic";
                case ElfSegmentType.Interp:
                    return "Interp";
                case ElfSegmentType.Note:
                    return "Note";
                case ElfSegmentType.Shlib:
                    return "Shlib";
                case ElfSegmentType.Phdr:
                    return "Phdr";
                case ElfSegmentType.Other:
                    return "Other";
            }
            return "";
        }
    }
    public enum ElfFlags
    {
        None = 0x0,
        Executable = 0x1,
        Writeable = 0x2,
        Readable = 0x4
    }

    public enum ElfSegmentType
    {
        Null = 0x0,
        Load = 0x1,
        Dynamic = 0x2,
        Interp = 0x3,
        Note = 0x4,
        Shlib = 0x5,
        Phdr = 0x6,
        Other = 0x7
    }
    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential, Pack = 1)]
    public unsafe struct Elf32_Phdr
    {
        public uint Type; // 1 = loadable segment, 2 = dynamic, etc. // 0-3
        public uint Offset; // Offset in file to segment data          // 4-7
        public uint VAddr; // Virtual address of segment               // 8-11
        public uint PAddr; // Physical address of segment              // 12-15
        public uint FileSize; // Size of segment in file                // 16-19
        public uint MemSize; // Size of segment in memory               // 20-23
        public uint Flags; // Segment flags                            // 24-27
        public uint Align; // Alignment of segment                      // 28-31
    } // 32 bytes

    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential, Pack = 1)]
    public unsafe struct Elf32_Ehdr
    {
        public fixed uchar Magic[4]; // 0x7F, 'E', 'L', 'F'          // 0-3
        public uchar Class; // 1 = 32-bit, 2 = 64-bit                // 4
        public uchar Data; // 1 = little-endian, 2 = big-endian      // 5
        public uchar HeaderVersion; // 1 = current version           // 6
        public uchar OSABI; // 0 = System V, 1 = HP-UX, etc.         // 7
        public fixed uchar Unused[8];                                // 8-15
        public ushort Type; // 1 = relocatable, 2 = executable, etc. // 16-17
        public ushort Machine; // 3 = Intel 80386, etc.              // 18-19
        public uint ElfVersion; // 1 = current version               // 20-23
        public uint Entry; // Entry point address                    // 24-27
        public uint PhOff; // Program header table file offset       // 28-31
        public uint ShOff; // Section header table file offset       // 32-35
        public uint Flags; // Architecture-specific flags            // 36-39
        public ushort EhSize; // Size of this header                 // 40-41
        public ushort PhEntSize; // Size of program header entry     // 42-43
        public ushort PhNum; // Number of program header entries     // 44-45
        public ushort ShEntSize; // Size of section header entry     // 46-47
        public ushort ShNum; // Number of section header entries     // 48-49
        public ushort ShStrNdx; // Section name string table index   // 50-51
    } // 52 bytes

    public unsafe class Elf32
    {
        public Elf32_Ehdr Header;
        public uchar[] Magic;
        public List<Elf32_Phdr> ProgramHeaders = new List<Elf32_Phdr>();
        byte* StartIndex = null;

        public Elf32(byte[] bytes)
        {
            fixed (byte* p = bytes)
            {
                StartIndex = p;
                Header = *(Elf32_Ehdr*)p;
                Magic = new byte[4];
                for (int i = 0; i < 4; i++)
                {
                    Magic[i] = Header.Magic[i];
                }
                for (int i = 0; i < Header.PhNum; i++)
                {
                    var phdr = *(Elf32_Phdr*)(p + Header.PhOff + (i * Header.PhEntSize));
                    ProgramHeaders.Add(phdr);
                }
            }
        }

        public unsafe byte* ExtractEntryCode()
        {
            byte* entry = StartIndex + Header.Entry;
            return entry;
        }

        public void LoadElf()
        {
            foreach (var phdr in ProgramHeaders)
            {
                if (phdr.Type == (uint)ElfSegmentType.Load)
                {
                    byte* mem = Heap.Alloc(phdr.MemSize);
                    Buffer.MemoryCopy(StartIndex + phdr.Offset, mem, phdr.MemSize, phdr.FileSize);
                    if (phdr.MemSize > phdr.FileSize)
                    {
                        // Zero out the rest of the memory if MemSize is greater than FileSize
                        for (uint i = phdr.FileSize; i < phdr.MemSize; i++)
                        {
                            mem[i] = 0;
                        }
                    }
                }
            }

            // Execute the entry point
            ExecuteEntryPoint();
        }
        public void Print(char* str)
        {
            char* video = (char*)0xB8000;
            int i = 0;
            while (str[i] != '\0')
            {
                video[i * 2] = str[i];
                video[i * 2 + 1] = (char)0x07; // White on black
                i++;
            }
            video[i * 2] = '\0';
            video[i * 2 + 1] = (char)0x07; // White on black
        }

        static char* test_str = null;
        private void ExecuteEntryPoint()
        {
            byte* entryPoint = StartIndex + Header.Entry;
            // Assuming the entry point is a function pointer, cast and call it
            var entryFunc = (delegate* unmanaged< void * ,void >)entryPoint;
            test_str = (char*)Heap.Alloc(13);
            test_str[0] = 'H';
            test_str[1] = 'e';
            test_str[2] = 'l';
            test_str[3] = 'l';
            test_str[4] = 'o';
            test_str[5] = ' ';
            test_str[6] = 'W';
            test_str[7] = 'o';
            test_str[8] = 'r';
            test_str[9] = 'l';
            test_str[10] = 'd';
            test_str[11] = '!';
            test_str[12] = '\0';
            //convert Print to a function pointer using Marshal.GetFunctionPointerForDelegate
            IntPtr mr = Marshal.GetFunctionPointerForDelegate(Print);
            //convert to a void* pointer
            void* ptr = (void*)mr;
            //call the entry function
            entryFunc(ptr);
        }

        public void PrintElfInfo()
        {
            Console.WriteLine("Program Headers:");

            // Calculate the maximum widths for each column
            int typeWidth = "Type".Length;
            int offsetWidth = "Offset".Length;
            int vaddrWidth = "VAddr".Length;
            int paddrWidth = "PAddr".Length;
            int fileSizeWidth = "FileSize".Length;
            int memSizeWidth = "MemSize".Length;
            int flagsWidth = "Flags".Length;
            int alignWidth = "Align".Length;

            foreach (var phdr in ProgramHeaders)
            {
                // Calculate the width of the fields dynamically if needed, e.g., max width of values
                typeWidth = Math.Max(typeWidth, ElfNameConv.ElfST((ElfSegmentType)phdr.Type).Length);
                offsetWidth = Math.Max(offsetWidth, phdr.Offset.ToString().Length);
                vaddrWidth = Math.Max(vaddrWidth, phdr.VAddr.ToString().Length);
                paddrWidth = Math.Max(paddrWidth, phdr.PAddr.ToString().Length);
                fileSizeWidth = Math.Max(fileSizeWidth, phdr.FileSize.ToString().Length);
                memSizeWidth = Math.Max(memSizeWidth, phdr.MemSize.ToString().Length);
                flagsWidth = Math.Max(flagsWidth, ElfNameConv.ElfF((ElfFlags)phdr.Flags).Length);
                alignWidth = Math.Max(alignWidth, phdr.Align.ToString().Length);
            }

            // Print the header with dynamic widths
            Console.WriteLine(
                $"{"Type".PadRight(typeWidth)} " +
                $"{"Offset".PadRight(offsetWidth)} " +
                $"{"VAddr".PadRight(vaddrWidth)} " +
                $"{"PAddr".PadRight(paddrWidth)} " +
                $"{"FileSize".PadRight(fileSizeWidth)} " +
                $"{"MemSize".PadRight(memSizeWidth)} " +
                $"{"Flags".PadRight(flagsWidth)} " +
                $"{"Align".PadRight(alignWidth)}"
            );

            // Print the program headers with dynamic widths
            foreach (var phdr in ProgramHeaders)
            {
                Console.WriteLine(
                    $"{ElfNameConv.ElfST((ElfSegmentType)phdr.Type).PadRight(typeWidth)} " +
                    $"{phdr.Offset.ToString().PadRight(offsetWidth)} " +
                    $"{phdr.VAddr.ToString().PadRight(vaddrWidth)} " +
                    $"{phdr.PAddr.ToString().PadRight(paddrWidth)} " +
                    $"{phdr.FileSize.ToString().PadRight(fileSizeWidth)} " +
                    $"{phdr.MemSize.ToString().PadRight(memSizeWidth)} " +
                    $"{ElfNameConv.ElfF((ElfFlags)phdr.Flags).PadRight(flagsWidth)} " +
                    $"{phdr.Align.ToString().PadRight(alignWidth)}"
                );
            }

            Console.WriteLine("Total Program Headers: " + ProgramHeaders.Count);
            if (Header.Machine != (int)ElfInstructionSet.X86)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Warning: This ELF is not for x86 architecture.\n         It will most likely fail. (Invalid Opcode)");
                Console.ResetColor();
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("This ELF is for x86 architecture.\nIt should be compatible.");
                Console.ResetColor();
            }
        }
    }

}