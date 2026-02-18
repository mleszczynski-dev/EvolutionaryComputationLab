# Evolutionary Computation Lab


This project aims to provide a flexible and extensible environment for testing and analyzing evolutionary algorithms.
The main goal is to create a platform that enables researchers to experiment with different evolutionary strategies, compare their performance, and study their behavior under various conditions.


## System Architecture

The software consists of three applications.

EvolutionaryComputationLab is the core of the entire system. It manages the operation of the computational nodes, including defining and distributing tasks, as well as monitoring node activity.

EvolutionaryComputationUI is a client application for EvolutionaryComputationLab that enables convenient interaction with the system.

Instances of EvolutionaryComputationNode form a computational cluster that enables distributed evolutionary computations based on the island model. The cluster nodes operate in parallel but communicate with each other to exchange individuals (experience) during the evolutionary process.

The diagram below presents the described system architecture.

![Architecture of distributed computing nodes](doc/architecture.png)


The project is currently under active development. The project is not ready for use until the official release is published.



## Getting Started

After cloning the repository, make sure to initialize and update all submodules:

```bash
git submodule update --init --recursive --depth 1
