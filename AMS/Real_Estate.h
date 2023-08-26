#pragma once  // Ensures this header file is included only once during compilation

#include <iostream>  // Includes the input/output stream library
#include <string>    // Includes the string library
#include <thread>    // Includes the thread library for multi-threading
#include <chrono>    // Includes the chrono library for time-related operations

using namespace std;

// Declaration of the Real_Estate class
class Real_Estate {

private:
    // Private member variables of the Real_Estate class
    string location;           // Location of the real estate
    double area;               // Area of the real estate
    int year_of_purchase;      // Year in which the real estate was purchased
    long double cost;          // Cost of the real estate
    long double current_market_value;  // Current market value of the real estate

public:
    // Method to get the location of the real estate
    string get_location();

    // Method to get the area of the real estate
    double get_area();

    // Method to get the current market value of the real estate
    double get_current_price();

    // Method to set the current market value of the real estate
    void set_current_price(long double price);

    // Method to get information about the real estate
    void get_info();

    // Method to calculate and get the profit of the real estate
    double get_profit();

};
