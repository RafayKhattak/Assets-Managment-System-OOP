#pragma once  // Ensures this header file is included only once during compilation

#include <iostream>  // Includes the input/output stream library
#include <string>    // Includes the string library
#include <limits>    // Includes the limits library for numeric_limits

using namespace std;

// Declaration of the Stocks class
class Stocks {
private:
    string symbol;
    int total_stocks;
    long double total_cost;
    long double current_price;
    long double profit;
    string type;

public:
    // Getter methods
    int get_total_stocks();
    double get_total_cost();
    double get_current_price();
    string get_symbol();
    string get_type();

    // Setter methods
    void set_total_stocks(int stocks, long double price);
    void set_total_cost(long double cost);
    void set_current_price(long double price);
    void set_symbol(string symb);
    void set_type(string t);

    // Methods for managing stocks
    void add_stocks();
    void subtract_stocks();

    // Virtual methods for polymorphism
    virtual double get_profit();
    virtual void set_dividend(double div);
    virtual double get_dividend();
};
