#pragma once  // Ensures this header file is included only once during compilation

#include <iostream>  // Includes the input/output stream library
#include <string>    // Includes the string library
#include <iomanip>   // Includes the input/output manipulation library
#include <limits>    // Includes the limits library for handling input errors
#include <thread>    // Includes the thread library for multi-threading
#include <chrono>    // Includes the chrono library for time-related operations
#include <cstdlib>   // Includes the cstdlib library for standard C library functions
#include "Stocks.h"  // Includes the header file for the Stocks class
#include "Real_Estate.h"  // Includes the header file for the Real_Estate class
#include "Simple_Stocks.h"  // Includes the header file for the Simple_Stocks class
#include "Dividend_Stocks.h"  // Includes the header file for the Dividend_Stocks class

using namespace std;

// Declaration of the Investor class
class Investor {
private:
    Stocks** stocks;        // Pointer to an array of pointers to Stocks objects
    Real_Estate* real_estates;  // Pointer to an array of Real_Estate objects
    int index;              // Index to keep track of stocks array
    string username;        // Username of the investor
    double currency;        // Currency amount owned by the investor
    int res_index;          // Index to keep track of real_estates array

public:
    // Constructor declaration
    Investor();

    // Method to add assets to the investor's portfolio
    void add_assets();

    // Method to set the username of the investor
    void set_username(string usrnm);

    // Method to get the username of the investor
    string get_username();

    // Method to check and display the investor's assets
    void check_assets();

    // Method to check and display the investor's profits
    void check_profit();

    // Method to change the prices of assets
    void change_prices();

    // Method to manage the investor's assets
    void manage_assets();
};
