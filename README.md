# SapphiresKernelHelper
An all in one solution to building a kernel from source

# Future content
Allow downloading and extraction of specific kernels via commandline argument.

# Usage
Place the compiled output file in the root directory of the kernel you wish you build.

Open terminal, and do `chmod +x`

Run the program with `./{name}`

Choose your mode. 

Basic: Use 4 threads to compile the kernel

Low perf: Single thread, lowest performance, lowest hit to system resources.

High perf: All thread usage. Hardest hit to system resources.

Expert: Configure the compilation exactly how you want it. Specify job threads, ignore error, etc. 

Distribution: Build kernel into an installable .deb file, as well as specify the custom name, and other variables. 

# Notes
Expert mode is currently disabled until it's functionality is added.

Distribution naming is currently disabled until it's functionality is added.
