# Graph-Based-DFA

## Overview

Welcome to this Graph-Based-DFA, a C++ template designed for deterministic finite automata (DFA). This template leverages a graph-based approach to model and implement DFAs in C++. 

## Getting Started

To seamlessly integrate this template into your project, follow these steps:

1. Include the AFD header file named "AFD.h" in your project.
2. Utilize various methods provided by the template, such as:
   - `addNode`: Adds a new state to the DFA.
   - `addAwn`: Establishes a new path in the DFA.
   - `evaluate`: Inputs data and instructs the DFA to evaluate it.
   
   and several more

## Example Usage of the DFA to determine wether a binary has an even or odd number of ones

```cpp
#include <iostream>
#include "AFD.h"

int main() {
//instanciamos
  AFD<char, char >* AFDTaller = new AFD<char, char >('e');
  AFDTaller->addNode('o');
  AFDTaller->setFinalState('o');
  AFDTaller->addAwn('o', 'e','1');
  AFDTaller->addAwn('e', 'e','0');
  AFDTaller->addAwn('e','o', '1');
  AFDTaller->addAwn('o', 'o','0');
  std::string num = "00111";
  for(int i = 0; i < num.length(); i++)
    {
      AFDTaller->evaluate(num[i]);
    }
  std::cout << "\nHas an even number of ones? " << (AFDTaller->accepted() ? "\nyes" : "\nno") << std::endl;
}
