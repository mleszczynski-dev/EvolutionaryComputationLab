# Evolutionary Computation Lab


This project aims to provide a flexible and extensible platform to solve search and optimization problems.
The platform allows you to easily test different evolutionary strategies, compare their performance, and study their behavior under various conditions.


## System Architecture

The software consists of three applications.

EvolutionaryComputationLab is the core of the entire system. It manages the operation of the computational nodes, including defining and distributing tasks, as well as monitoring node activity.

EvolutionaryComputationUI is a client application for EvolutionaryComputationLab that enables convenient interaction with the system.

Instances of EvolutionaryComputationNode form a computational cluster that enables distributed evolutionary computations based on the island model. The cluster nodes operate in parallel but communicate with each other to exchange individuals (experience) during the evolutionary process.

The diagram below illustrates the system architecture.

<p align="center"> <img src="docs/architecture.png" alt="Architecture diagram"> </p>

The island model can be configured by assigning selected nodes to a newly created computation.
Each node can run multiple computations simultaneously (see Node C above); the only limiting factor is the available hardware resources.

In the final version, nodes will be able to run on major operating systems — Windows, macOS (only for ARM), Linux — with support for both CPU and GPU execution.

The project is currently under active development. The project is not ready for use until the official release is published.


## Getting Started

After cloning the repository, make sure to initialize and update all submodules:

```bash
git submodule update --init --recursive --depth 1
```

Qt6 is required to build EvolutionaryComputationUI. To ensure CMake can find the library, set the environment variable `CMAKE_PREFIX_PATH` to the path of your Qt installation, for example: `C:/Qt/6.x.x/some_build_tools_dir`.
