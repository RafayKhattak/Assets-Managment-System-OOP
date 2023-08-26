#include "Dividend_Stocks.h"  // Include the corresponding header file

// Constructor for Dividend_Stocks class
Dividend_Stocks::Dividend_Stocks(string sym, string type) {
    set_symbol(sym);  // Set the symbol of the stock
    int stocks;
    double price;
    cout << "\nENTER NUMBER OF STOCKS: ";
    cin >> stocks;
    cout << "\nENTER PRICE PER STOCK: ";
    cin >> price;
    set_total_stocks(stocks, price);  // Set total stocks and total cost
    cout << "\nENTER AMOUNT OF DIVIDENDS: ";
    cin >> dividend;  // Set dividend amount
    set_type(type);   // Set the type of stock
}

// Setter method for setting dividend
void Dividend_Stocks::set_dividend(double div) {
    dividend = div;
}

// Getter method for getting dividend
double Dividend_Stocks::get_dividend() {
    return dividend;
}

// Calculate and return the profit of dividend stocks
double Dividend_Stocks::get_profit() {
    // Profit = Current value of stocks - Total cost of stocks
    return get_current_price() * get_total_stocks() - get_total_cost();
}
