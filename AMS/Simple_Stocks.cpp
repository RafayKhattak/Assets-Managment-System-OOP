#include"Simple_Stocks.h"

// Constructor for Simple_Stocks class
Simple_Stocks::Simple_Stocks(string sym, string type)
{
    // Set the stock symbol using the setter method
    set_symbol(sym);

    int stocks;
    double price;

    // Input the number of stocks and price per stock
    cout << "\nENTER NUMBER OF STOCKS: ";
    cin >> stocks;
    cout << "\nENTER PRICE PER STOCK: ";
    cin >> price;

    // Set the total stocks and total cost using setter methods
    set_total_stocks(stocks, price);

    // Set the stock type using the setter method
    set_type(type);
}

// Function to calculate the profit of Simple_Stocks
double Simple_Stocks::get_profit() {
    // Calculate the profit as the difference between the current value and total cost
    return get_current_price() * get_total_stocks() - get_total_cost();
}
