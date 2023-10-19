# 彩銘羽 モーユー(MoYu)
簡単な方法でCPUの性能テストを行う！

The CPU performance is tested by the Chacha20 encryption test, and the CPU is scored by the final number of encryptions.

The source code of ChaCha20 is obtained from [here](https://github.com/marcizhu/ChaCha20), and thanks to the author's open source code, this project is run on Chacha20.

## How to use
If you need to use a compiled version, download the latest version [here](https://github.com/Cai-Ming-Yu/CMY-MoYu/releases).

Note that this project only provides ready-made compiled files for x86 and x86_64 architectures for Windows and arm64-v8a, armeabi-v7a, x86 and x86_64 architectures for Linux platforms (including Android).

Note that due to different compilation tools and different running systems, the score obtained by using the EXE file of the Windows platform may be different from the score obtained by using the ELF file of the Linux platform, and the architecture of the CPU will also affect the score, so please try to only compare the score of the same system and the CPU architecture (or, for example, the Windows system uses the Windows Subsystem for Linux to run the elf file). And if you need to compile the files yourself, then try to use the Android NDK or other musl tools to provide the highest compatibility for various Linux platforms (including Android).

If you need to start building from source, first you need to download the source code in the "jni" folder (note that if you want to build with the Android NDK, please keep the name of the folder "jni" unchanged).

MoYu has two ways to output it, the first is to output the complete information of the run, and the second is to output the score obtained only after the run, you can change it by modifying the "RUN_UI" constant in the "MoYu.cpp" file, the first one is used by default.

Here are descriptions of several important constants:
- The "proc" constant is the number of concurrent runs
- The "runTime" constant is the time to run
- The "file" constant is the size of the empty file used by the runtime for encryption
In general, the size of the running memory occupied by MoYu is the value of the "proc" constant multiplied by the value of the "file" constant, and the test run time is the value of the "runTime" constant.

For the compilation method, the recommended method for this project is to compile with Visual Studio for Windows (open the configuration file of the Visual Studio project through Visual Studio), and the Linux platform (including Android) to compile with Android NDK (for a simple example, open the folder where the project file is located on the Windows platform, and then right-click and select "Open in Terminal", Finally, compile via the "ndk-build" command and enter (you need to set the Android NDK path in the system's Path)), but this does not mean that MoYu cannot run on other platforms, other CPU architectures, or cannot be compiled using other compilation tools, it is just not tested.

MoYu's Windows GUI version and Android APK version will arrive soon!

## [License](https://github.com/Cai-Ming-Yu/CMY-MoYu/blob/C-M-Y/LICENSE)