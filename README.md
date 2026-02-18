```mermaid
graph TD
    A[Start] --> B[Proces]
    B --> C{Decyzja}
    C -->|Tak| D[Opcja 1]
    C -->|Nie| E[Opcja 2]

# Evolutionary Computation Lab


This project aims to provide a flexible and extensible environment for testing and analyzing evolutionary algorithms.
The main goal is to create a platform that enables researchers to experiment with different evolutionary strategies, compare their performance, and study their behavior under various conditions.


The project is currently under active development. The project is not ready for use until the official release is published.


## Getting Started

After cloning the repository, make sure to initialize and update all submodules:

```bash
git submodule update --init --recursive --depth 1
