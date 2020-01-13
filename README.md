[![GitHub version](https://img.shields.io/badge/version-1.0.0-green.svg)](https://github.com/hnrck/rrosace_seaplanes/releases/tag/1.0.0)
[![GitHub issues](https://img.shields.io/github/issues/hnrck/rrosace_seaplanes.svg)](https://github.com/hnrck/rrosace_seaplanes/issues)
[![GitHub forks](https://img.shields.io/github/forks/hnrck/rrosace_seaplanes.svg)](https://github.com/hnrck/rrosace_seaplanes/network)
[![GitHub stars](https://img.shields.io/github/stars/hnrck/rrosace_seaplanes.svg)](https://github.com/hnrck/rrosace_seaplanes/stargazers)
[![GitHub license](https://img.shields.io/github/license/hnrck/rrosace_seaplanes)](https://github.com/hnrck/rrosace_seaplanes/blob/master/LICENSE)

# seaplanes 

Scheduling of a Cyber-physcal system simulation -- Simulation Execution Architecture - Partition-based Logical processor Allocator Node with Extensible inline Scheduler

## Description

![rrosace_seaplanes_pic](/res/rrosace_seaplanes.png)

Seaplanes is a distributed simulation framework using the CERTI implementation of the High-Level Architecture (HLA) to schedule and interconnect models in a simulation, available at  [hnrck/seaplanes](https://github.com/hnrck/seaplanes).

Rrosace is a simple longitudinal flight loop :airplane: based on the ROSACE case study
[hnrck/rrosace](https://github.com/hnrck/rrosace).

Rrosace seaplanes is simulator that distribute rrosace models using the seaplanes simulation framework.

This project was used as part of a CIFRE PhD thesis :mortar_board: involving ISAE-SUPAERO and Airbus to illustrate the simulation scheduling of cyber-physical systems.

Requires CERTI >= 4.0, >= rrosace 1.3.0, seaplanes >= 1.1.0

Links :link: to the case study, and some publications, are available below.

## Table of Contents
* [1. Usage](#1-usage)
  * [1.1. Cloning this repo](#11-cloning-this-repo)
  * [1.2. Generating the documentation](#12-generating-the-documentation)
  * [1.3. Building and using the project](#13-building-and-using-the-project)
* [2. Related work](#2-related-work)
* [3. Project structure](#3-project-structure)
* [4. Contributing](#4-contributing)
* [5. Credits](#5-credits)
* [6. License](#6-license)

## 1. Usage

### 1.1. Cloning this repo

This repo is available at :link: [hnrck/rrosace_seaplanes](https://github.com/hnrck/rrosace_seaplanes).

Cloning can be done in HTTPS mode:
```bash
$ git clone https://github.com/hnrck/rrosace_seaplanes
$ git checkout tags/1.0.0
```

or with ssh mode:
```bash
$ git clone git@github.com:hnrck/rrosace_seaplanes.git
$ git checkout tags/1.0.0
```

### 1.2. Generating the documentation
```bash
$ make doc
```
The documentation can be opened in a browser, or generated in PDF from LaTeX sources.

For browser based navigation, open ````build/doc/html/index.html````
For generating PDF, do:

```bash
$ make -C build/doc/latex
```

Generated PDF will be ```build/doc/latex/refman.pdf```

### 1.3. Building and using the project

In order to build the project, use the following command:

```bash
$ make 
```

Project can be install with:

```bash
$ make install
```

By default, the installation is local.
Installed headers and libraries can be used sourcing the local ```rrosace_seaplanespathsrc```: ```install/etc/rrosace_seaplanes/rrosace_seaplanespathsrc```
This can be done using:
```bash
$ source install/etc/rrosace_seaplanes/rrosace_seaplanespathsrc
```

Absolute path can be deduced and sourced directly before use, for instance in dev environment in any .{bash,zsh,...}rc.
```bash
$ source <path/to/rrosace_seaplanes>/install/etc/rrosace_seaplanes/rrosace_seaplanespathsrc
```

Furthermore, while installing, the absolute path of the ```rrosace_seaplanespathsrc``` is given:
```bash
...
-- Installing: <path/to/rrosace_seaplanes>/install/etc/rrosace_seaplanes/rrosace_seaplanespathsrc
```

After installation and sourcing, ```rrosace_seaplanes``` library can be used as any library.
Compilation using ````rrosace_seaplanes```` library might need linking, using ```-lrrosace_seaplanes```.

### 1.5. Other targets

Cleaning the repo:

```bash
make clean
```

Static check on source code (requires clang-tidy):

```bash
make lint
```

Formatting of source code (requires clang-format):

```bash
make format
```

### 1.6. Alternative builds and configurations

It is possible to directly use ```cmake``` to build the project, feel free to based your command on the targets in the ```Makefile```

Furthermore, compilation options are possible from the environment, set the following variable in you shell or before your command:
```bash
$ export <VAR>=<my option>
$ make
```
or
```bash
$ <VAR>=<my option> make
```

| option | VAR | default value | alternatives |
|--------|-----|---------------|--------------|
| C++ compiler | CXX | clang++ | g++, ... |
| Generator | GENERATOR | Ninja | Unix Makefile, ...
| Build type | BUILD_TYPE | RelWithDebInfo | Release, Debug, MinSizeRel |
| Build directory | BUILD_DIR | build |  anywhere |
| Install directory | INSTALL_DIR | install |  anywhere |

## 2. Related work

## 3. Project structure
```bash
.
├── ChangeLog.md
├── cmake-extra-modules
│   └── *.cmake
├── CMakeLists.txt
├── doc
│   └── Doxyfile.in
├── include
│   └── *.h
├── LICENSE
├── Makefile
├── README.md
├── res
│   └── *
├── src
│   └── *.cpp
└── VERSION
```

Important folders:
- ```include``` - the rrosace_seaplanes headers.
- ```src``` - the sources of the rrosace_seaplanes library.

Important files:
- ```README.md``` - this file.
- ```LICENSE``` - the license file.
- ```VERSION``` - the current version of the library.
- ```ChangeLog.md``` - list of changes between revisions.
- ```CMakeLists.txt``` - the project configuration file
- ```Makefile``` - helper for compilation and installation.


## 4. Contributing
Contributions are welcome :unlock:. Feel free to fork too :fork_and_knife:.

## 5. Credits
- Henrick Deschamps  ([:octocat: hnrck](https://github.com/hnrck) ) ([:globe_with_meridians: hnrck.io](https://hnrck.io))

## 6. License
This work is under the [MIT License](https://github.com/hnrck/rrosace_seaplanes/blob/master/LICENSE). :copyright: Henrick Deschamps, 2019.
