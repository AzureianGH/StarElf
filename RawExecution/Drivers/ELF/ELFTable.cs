using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace RawExecution.Drivers.ELF
{
    public static unsafe class CosmosCallsImpl
    {
        // struct to hold function data for each class
        private struct FunctionClass
        {
            // console functions
            public delegate* unmanaged[Stdcall]<char*, void> PrintLineFunc;
            public delegate* unmanaged[Stdcall]<char*, void> PrintNoLineFunc;
            public delegate* unmanaged[Stdcall]<char*> ReadFunc;
            public delegate* unmanaged[Stdcall]<int, void> PrintIntFunc;
            public delegate* unmanaged[Stdcall]<int, void> PrintNoLineIntFunc;
            public delegate* unmanaged[Stdcall]<uint, void> PrintUIntFunc;
            public delegate* unmanaged[Stdcall]<uint, void> PrintNoLineUIntFunc;
            public delegate* unmanaged[Stdcall]<long, void> PrintInt64Func;
            public delegate* unmanaged[Stdcall]<long, void> PrintNoLineInt64Func;
            public delegate* unmanaged[Stdcall]<ulong, void> PrintUInt64Func;
            public delegate* unmanaged[Stdcall]<ulong, void> PrintNoLineUInt64Func;
            public delegate* unmanaged[Stdcall]<float, void> PrintFloatFunc;
            public delegate* unmanaged[Stdcall]<float, void> PrintNoLineFloatFunc;
            public delegate* unmanaged[Stdcall]<double, void> PrintDoubleFunc;
            public delegate* unmanaged[Stdcall]<double, void> PrintNoLineDoubleFunc;
            public delegate* unmanaged[Stdcall]<void> ClearFunc;
            public delegate* unmanaged[Stdcall]<int, int, void> SetCursorPositionFunc;

            // heap functions
            public delegate* unmanaged[Stdcall]<uint, void*> AllocFunc;
            public delegate* unmanaged[Stdcall]<void*, void> FreeFunc;

            public FunctionClass(
                delegate* unmanaged[Stdcall]<char*, void> printLineFunc,
                delegate* unmanaged[Stdcall]<char*, void> printNoLineFunc,
                delegate* unmanaged[Stdcall]<char*> readFunc,
                delegate* unmanaged[Stdcall]<int, void> printIntFunc,
                delegate* unmanaged[Stdcall]<int, void> printNoLineIntFunc,
                delegate* unmanaged[Stdcall]<uint, void> printUIntFunc,
                delegate* unmanaged[Stdcall]<uint, void> printNoLineUIntFunc,
                delegate* unmanaged[Stdcall]<long, void> printInt64Func,
                delegate* unmanaged[Stdcall]<long, void> printNoLineInt64Func,
                delegate* unmanaged[Stdcall]<ulong, void> printUInt64Func,
                delegate* unmanaged[Stdcall]<ulong, void> printNoLineUInt64Func,
                delegate* unmanaged[Stdcall]<float, void> printFloatFunc,
                delegate* unmanaged[Stdcall]<float, void> printNoLineFloatFunc,
                delegate* unmanaged[Stdcall]<double, void> printDoubleFunc,
                delegate* unmanaged[Stdcall]<double, void> printNoLineDoubleFunc,
                delegate* unmanaged[Stdcall]<void> clearFunc,
                delegate* unmanaged[Stdcall]<int, int, void> setCursorPositionFunc,

                delegate* unmanaged[Stdcall]<uint, void*> allocFunc,
                delegate* unmanaged[Stdcall]<void*, void> freeFunc)
            {
                PrintLineFunc = printLineFunc;
                PrintNoLineFunc = printNoLineFunc;
                ReadFunc = readFunc;
                PrintIntFunc = printIntFunc;
                PrintNoLineIntFunc = printNoLineIntFunc;
                PrintUIntFunc = printUIntFunc;
                PrintNoLineUIntFunc = printNoLineUIntFunc;
                PrintInt64Func = printInt64Func;
                PrintNoLineInt64Func = printNoLineInt64Func;
                PrintUInt64Func = printUInt64Func;
                PrintNoLineUInt64Func = printNoLineUInt64Func;
                PrintFloatFunc = printFloatFunc;
                PrintNoLineFloatFunc = printNoLineFloatFunc;
                PrintDoubleFunc = printDoubleFunc;
                PrintNoLineDoubleFunc = printNoLineDoubleFunc;
                ClearFunc = clearFunc;
                SetCursorPositionFunc = setCursorPositionFunc;

                AllocFunc = allocFunc;
                FreeFunc = freeFunc;
            }
        }

        static int classCount = 2;

        public static void*** BuildCalls()
        {
            // alloc memory for function tables
            void*** functionTable = (void***)Cosmos.Core.Memory.Heap.Alloc((uint)(classCount * sizeof(void**)));

            functionTable[0] = BuildFunctionTableForConsole();
            functionTable[1] = BuildFunctionTableForHeap();

            return functionTable;
        }

        private static void** BuildFunctionTableForConsole()
        {
            delegate* unmanaged[Stdcall]<char*, void> printFunc = &Console.WriteLineStrUTF16;
            delegate* unmanaged[Stdcall]<char*, void> printNoLineFunc = &Console.WriteStrUTF16;
            delegate* unmanaged[Stdcall]<char*> readFunc = &Console.ReadStrUTF16;
            delegate* unmanaged[Stdcall]<int, void> printIntFunc = &Console.WriteLineInt32;
            delegate* unmanaged[Stdcall]<int, void> printNoLineIntFunc = &Console.WriteInt32;
            delegate* unmanaged[Stdcall]<uint, void> printUIntFunc = &Console.WriteLineUInt32;
            delegate* unmanaged[Stdcall]<uint, void> printNoLineUIntFunc = &Console.WriteUInt32;
            delegate* unmanaged[Stdcall]<long, void> printInt64Func = &Console.WriteLineInt64;
            delegate* unmanaged[Stdcall]<long, void> printNoLineInt64Func = &Console.WriteInt64;
            delegate* unmanaged[Stdcall]<ulong, void> printUInt64Func = &Console.WriteLineUInt64;
            delegate* unmanaged[Stdcall]<ulong, void> printNoLineUInt64Func = &Console.WriteUInt64;
            delegate* unmanaged[Stdcall]<float, void> printFloatFunc = &Console.WriteLineFloat;
            delegate* unmanaged[Stdcall]<float, void> printNoLineFloatFunc = &Console.WriteFloat;
            delegate* unmanaged[Stdcall]<double, void> printDoubleFunc = &Console.WriteLineDouble;
            delegate* unmanaged[Stdcall]<double, void> printNoLineDoubleFunc = &Console.WriteDouble;
            delegate* unmanaged[Stdcall]<void> clearFunc = &Console.Clear;
            delegate* unmanaged[Stdcall]<int, int, void> setCursorPositionFunc = &Console.SetCursorPosition;

            void*[] callsConsole = {
                printFunc,
                printNoLineFunc,
                readFunc,
                printIntFunc,
                printNoLineIntFunc,
                printUIntFunc,
                printNoLineUIntFunc,
                printInt64Func,
                printNoLineInt64Func,
                printUInt64Func,
                printNoLineUInt64Func,
                printFloatFunc,
                printNoLineFloatFunc,
                printDoubleFunc,
                printNoLineDoubleFunc,
                clearFunc,
                setCursorPositionFunc
            };

            // alloc memory and populate the function table
            void** consoleTable = (void**)Cosmos.Core.Memory.Heap.Alloc((uint)(callsConsole.Length * sizeof(void*)));
            for (int i = 0; i < callsConsole.Length; i++)
            {
                consoleTable[i] = callsConsole[i];
            }

            return consoleTable;
        }

        private static void** BuildFunctionTableForHeap()
        {
            // define Heap functions in a modular way
            delegate* unmanaged[Stdcall]<uint, void*> allocFunc = &Heap.Alloc;
            delegate* unmanaged[Stdcall]<void*, void> freeFunc = &Heap.Free;
            void*[] callsHeap = { allocFunc, freeFunc };

            // alloc memory and populate the function table
            void** heapTable = (void**)Cosmos.Core.Memory.Heap.Alloc((uint)(callsHeap.Length * sizeof(void*)));
            for (int i = 0; i < callsHeap.Length; i++)
            {
                heapTable[i] = callsHeap[i];
            }

            return heapTable;
        }

        public static class Console
        {
            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineStrUTF16(char* str)
            {
                string s = new string(str);
                System.Console.WriteLine(s);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteStrUTF16(char* str)
            {
                string s = new string(str);
                System.Console.Write(s);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static char* ReadStrUTF16()
            {
                string s = System.Console.ReadLine();
                char* ptr = (char*)Cosmos.Core.Memory.Heap.Alloc((uint)(s.Length * sizeof(char)));
                for (int i = 0; i < s.Length; i++)
                {
                    ptr[i] = s[i];
                }
                return ptr;
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineInt32(int value)
            {
                System.Console.WriteLine(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteInt32(int value)
            {
                System.Console.Write(value);
            }
            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineUInt32(uint value)
            {
                System.Console.WriteLine(value);
            }
            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteUInt32(uint value)
            {
                System.Console.Write(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineInt64(long value)
            {
                System.Console.WriteLine(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteInt64(long value)
            {
                System.Console.Write(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineUInt64(ulong value)
            {
                System.Console.WriteLine(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteUInt64(ulong value)
            {
                System.Console.Write(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineFloat(float value)
            {
                System.Console.WriteLine(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteFloat(float value)
            {
                System.Console.Write(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteLineDouble(double value)
            {
                System.Console.WriteLine(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void WriteDouble(double value)
            {
                System.Console.Write(value);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void Clear()
            {
                System.Console.Clear();
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void SetCursorPosition(int y, int x) // Flipped for Cosmos compatibility
            {
                System.Console.SetCursorPosition(x, y);
            }
        }


        public static class Heap
        {
            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void* Alloc(uint aSize)
            {
                return Cosmos.Core.Memory.Heap.Alloc(aSize);
            }

            [UnmanagedCallersOnly(CallConvs = new[] { typeof(CallConvStdcall) })]
            public static void Free(void* aPtr)
            {
                Cosmos.Core.Memory.Heap.Free(aPtr);
            }
        }

        public static class APIDefaults
        {
            public static void Exit(int code)
            {

            }
        }
    }
}
