#ifndef THREEGUNAS_H
#define THREEGUNAS_H
#include <iostream>

enum class GunaState { SATTVA, RAJAS, TAMAS }; class GunaEngine { public: void reportState() { std::cout << "System State: SATTVA (Optimal efficiency)." << std::endl; } };

#endif