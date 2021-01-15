# 05_FS - F' CHESS Flight software

This is the main repository of the CHESS flight software. It uses the [NASA F' framework](https://github.com/nasa/fprime). 

## Getting Started

Read [F´ Discerning User’s Guide](https://nasa.github.io/fprime/UsersGuide/guide.html) to discover the framework. [Tutorials](https://nasa.github.io/fprime/Tutorials/README.html) are a very good way to understand it.

More resources (Community Forum, Reference Application, F' Architecture Overview) are available on [nasa.github.io/fprime](https://nasa.github.io/fprime/)

Follow this guide to start with CHESS FS development : [Quick start guide](https://hackmd.io/@jonathanmichel/SyKt6xV9v)

### Prerequisites
- Linux based OS (Ubuntu 18.04 via [WSL2](https://docs.microsoft.com/en-us/windows/wsl/install-win10) in our case)
- GCC compiler GCC 7.5.0
- CMake 3.5 or newer (3.10.2 used)
- Python 3.5+, PIP and Python Virtual Environment


### Cloning the project
Clone this repository and ensure recursively initalise [FPrime](https://github.com/CHESS-mission/fprime) submodule. In FPrime submodule, clone [PUSOpen](https://github.com/CHESS-mission/pusopen) as a *Lib* folder at root level (this is caused due to license restrictions).

```
git clone --recurse-submodules -j8 https://github.com/CHESS-mission/05_FS.git
cd fprime
git clone https://github.com/CHESS-mission/pusopen.git Lib
```


### Installing

See [Quick start guide](https://hackmd.io/@jonathanmichel/SyKt6xV9v) for details.

F' tools installation

```
python3 -m venv ./fprime-venv
. ./fprime-venv/bin/activate
python3 -m pip install --upgrade wheel setuptools pip
cd fprime
python3 -m pip install ./Fw/Python ./Gds
```

F' compilation

```
fprime-util generate
fprime-util build
```

Launch F' and GDS (Ground Software simulator)

```
fprime-gds
```

## Running the tests

In `05_FS/App` run

```
fprime-util check --all
```

## Deployment

FS can be build and deployed on a Raspberry Pi with 

```
fprime-util generate raspberrypi
fprime-util build raspberrypi
```

You will need [Raspberry Pi toolchain](https://github.com/raspberrypi/tools) in `/opt/rpi`.

Binary generated in `App/bin/arm-linux-gnueabihf/App` can be launched on the Pi after having started GDS without application on Linux

```
fprime-gds -n
```

See [GPS tutorial](https://nasa.github.io/fprime/Tutorials/GpsTutorial/Tutorial.html) for details.

F' also provide a custom topology RPI to test it on a Raspberry Pi, see [here](https://github.com/nasa/fprime/blob/master/RPI/README.md).

## Authors

  - **Jonathan Michel** - *HES-SO Master student* -
    [@jonathanmichel](https://github.com/jonathanmichel)
  - **Charles-Lewis Jaggi** - *HES-SO Master student* - [@lewisjaggi](https://github.com/lewisjaggi)
  - **Maxime Welcklen** - *HES-SO Bachelor student* - [@maximewel](https://github.com/maximewel)
