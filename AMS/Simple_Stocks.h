#pragma once  // Ensures this header file is included only once during compilation

#include <iostream>  // Includes the input/output stream library
#include "Stocks.h"  // Includes the header file for the Stocks class

using namespace std;

// Declaration of the Simple_Stocks class, inheriting from the Stocks class
class Simple_Stocks : public Stocks {
public:
    // Constructor for Simple_Stocks class
    Simple_Stocks(string sym, string type);

    // Overrides the get_profit method from the Stocks class
    double get_profit() override;
};
