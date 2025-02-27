
using IL2CPU.API.Attribs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace Stellib.Drivers.Injection
{   
    public class CodeExecution
    {
        /// <summary>
        /// Injects a block of unmanaged assembly code into the kernel to be executed.
        /// </summary>
        /// <param name="Data">The unmanaged assembly code to be injected.</param>
        public static unsafe void ExecuteRaw(byte* Data)
        {
            ((delegate*<void>)Data)();
        }

        /// <summary>
        /// Injects a block of unmanaged assembly code into the kernel to be executed at a specific start address.
        /// </summary>
        /// <param name="Data">The unmanaged assembly code to be injected.</param>
        /// <param name="Start">The start address within the code block where execution should begin.</param>
        public static unsafe void ExecuteRaw(byte* Data, uint Start)
        {
            //start executing  Start

            byte* offset = Data + Start;
            ((delegate*<void>)offset)();
        }
    }
}
