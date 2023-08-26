#pragma once  // Ensures this header file is included only once during compilation

#include "Stocks.h"  // Includes the header file for the base Stocks class

// Declaration of the Dividend_Stocks class, which inherits publicly from Stocks
class Dividend_Stocks : public Stocks {
private:
    double dividend;  // Private member variable to store dividend information

public:
    // Constructor declaration that takes a symbol and type as parameters
    Dividend_Stocks(string sym, string type);

    // Method to set the dividend for the dividend stock, marked with override
    void set_dividend(double div) override;

    // Method to get the dividend of the dividend stock, marked with override
    double get_dividend() override;

    // Method to calculate and return the profit of the dividend stock, marked with override
    double get_profit() override;
};
