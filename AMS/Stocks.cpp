#include "Stocks.h"

// Getter functions for various attributes
int Stocks::get_total_stocks() { return total_stocks; }
double Stocks::get_total_cost() { return total_cost; }
double Stocks::get_current_price() { return current_price; }
string Stocks::get_symbol() { return symbol; }
string Stocks::get_type() { return type; }

// Setter functions to set attributes
void Stocks::set_total_stocks(int stocks, long double price)
{
    total_stocks = stocks;
    set_total_cost(stocks * price);
    current_price = price;
}

void Stocks::set_total_cost(long double cost) { total_cost = cost; }
void Stocks::set_current_price(long double price) { current_price = price; }
void Stocks::set_symbol(string symb) { symbol = symb; }
void Stocks::set_type(string t) { type = t; }

// Function to add stocks to the existing total
void Stocks::add_stocks()
{
    int stocks;
    int price;

    cout << "\nENTER NUMBER OF STOCKS: ";
    while (!(cin >> stocks)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER NUMBER OF STOCKS: ";
    }

    cout << "\nENTER PRICE PER STOCK: ";
    while (!(cin >> price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER PRICE PER STOCK: ";
    }

    total_stocks += stocks;
    total_cost += price * stocks;
}

// Function to subtract stocks from the existing total
void Stocks::subtract_stocks()
{
    int stocks;
    int price;

    cout << "\nENTER NUMBER OF STOCKS: ";
    while (!(cin >> stocks)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER NUMBER OF STOCKS: ";
    }

    cout << "\nENTER PRICE PER STOCK: ";
    while (!(cin >> price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER PRICE PER STOCK: ";
    }

    if (stocks > total_stocks) {
        cout << "\n*** ERROR! NOT ENOUGH STOCKS ***\n";
    }
    else {
        total_cost -= total_cost / total_stocks * stocks;
        total_stocks -= stocks;
    }
}

// Function to calculate profit (placeholder, not implemented)
double Stocks::get_profit()
{
    return 0.0;
}

// Setter and getter for dividend (placeholder, not implemented)
void Stocks::set_dividend(double div) {}
double Stocks::get_dividend() { return 0; }
