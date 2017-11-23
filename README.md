# DBT-RISE-RiscV
Am instruction set simulator based on DBT-RISE implementing the Risc-V ISA

**DBT-RISE-RiscV README**

This is work in progress, so use at your own risk. Goal is to implement an open-source ISS which can easily embedded e.g. into SystemC Virtual Prototypes. It used code generation to allow easy extension and adaptation of the used instruction.
The Risc-V ISS reaches about 20MIPS at an Intel Core i7-2600K.

The implementation is based on LLVM 4.0. Eclipse CDT 4.7 (Oxygen) is recommended as IDE.

DBT-RISE-RiscV uses libGIS (https://github.com/vsergeev/libGIS) as well as ELFIO (http://elfio.sourceforge.net/), both under MIT license 

**What's missing**

* RV64I is only preliminary verified
* F & D standard extensions to be implemented

**Planned features**

* add platform peripherals beyond programmers view to resemble E300 platform
  * QSPI
  * PWM
  * ...
* and more

**Quick start**

* you need to have a decent compiler, make, python, and cmake installed
* install LLVM 4.0 according to http://apt.llvm.org/ (if it is not already provided by your distribution)
* install conan.io (see also http://docs.conan.io/en/latest/installation.html):
```
    pip install conan
```
* setup conan to use the minres repo:
```
    conan remote add minres https://api.bintray.com/conan/minres/conan-repo
```
* checkout source from git
* start an out-of-source build:
```
    cd DBT-RISE-RiscV
    mkdir build
    cd build
    cmake ..
    cmake --build .
```
* if you encounter issues when linking wrt. c++11 symbols you might have run into GCC ABI incompatibility introduced from GCC 5.0 onwards. You can fix this by adding '-s compiler.libcxx=libstdc++11' to the conan call or changing compiler.libcxx to
```
compiler.libcxx=libstdc++11
```
in $HOME/.conan/profiles/default