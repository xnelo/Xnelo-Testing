/**

@page readmefile Read Me

Xnelo Testing

Created By: Spencer Hoffa

Contact: Xnelo.productions@gmail.com

----------------------------------------------
Windows:
----------------------------------------------

To compile on windows use Testing.sln. The Testing.vcxproj contains the project that actually compiles the libraries. The Example.vcxproj contains the test project that shows how to use the library.  Both projects have four build settings(See below for a description of the file structure and files):

DLL-Debug: This compiles the .dll debug file and the accompanying .lib import library. If you build the Example program then the debug version of Example.exe will be created.

DLL-Release: This configuration is the same as the DLL-Debug configuration except everything is built for release. Optimized for speed and no debug info.

LIB-Debug: This compiles the .lib debug library and if you build the Example program then the debug version of Example.exe will be created.

LIB-Release: This configuration is the same as the LIB-Debug configuration except everything is built for release. Optimized for speed and no debug info.

----------------------------------------------
Build Files Descriptions - Windows
----------------------------------------------

bin/(Configuration)/Example.exe: The example program.

bin/(Configuration)/XneloTesting.dll: The Dynamically linked library(when it is built) that contains the library.

lib/(Configuration)/XneloTesting.lib: The import library(if .dll is built), or the static .lib(if .lib it is built).

----------------------------------------------
Linux
----------------------------------------------

This library can be compiled using the included makefile. This makefile requires g++. It has only been tested on Ubuntu but should work with any GNU make program. Makefile targets are:

bin: Builds all the components of this library. The static and shared libraries, as well as a statically linked example program and a dynamically linked example program (See Built Files Descriptions below).

staticlib: Builds the static library(libXneloTesting.a).

example: Builds the example program(example). This version of the example program is linked statically.

sharedlib: Builds the shared library(libXneloTesting.so). 

exampleshared: Builds the example program(example_SHARED). This version of the example program dynamically linked.

runsharedexample: Runs the dynamically linked example program

makedirs: Makes all the directories needed to build this program.

clean: Clean all of the intermediary files (.o, .os, .P, .Ps)

cleanall: Cleans all of the intermediary files as well as the libraries and example programs

distclean: Returns the project folder to the original state.

----------------------------------------------
Build Files Descriptions - Linux
----------------------------------------------

bin/example: A simple example program showing how to use Xnelo Testing. This version is statically linked.

bin/example_SHARED: A simple example program showing how to use Xnelo Testing. This version is dynamically linked.

lib/libXneloTesting.a: The static Xnelo Testing library ready to be linked into your projects.

lib/libXneloTesting.so: The shared Xnelo Testing library ready to be linked into your projects.

obj: This folder contains all of the intermediary files used to build the libraries. The .o files are the intermediary files for the static library and the .os files are for the shared library.

obj/.deps: This folder contains all of the dependencies files for each file.  The .P files are for the static library and the .Ps are for the shared library.

include: This contains all of the header files for the library. You should only include Testing.hpp. This will include all of the header files you need to use this library.

source: This contains all of the source files for the Xnelo Testing library.

Example: This contains main.cpp which is the source file for the example program.

----------------------------------------------
License
----------------------------------------------

This library is released under the zlib/libpng License. You may use this library for any purpose even comercial purposes subject to the restrictions below:

The zlib/libpng License

Copyright (c) 2014 Spencer Hoffa

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software. Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.

*/