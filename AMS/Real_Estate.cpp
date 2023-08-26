#include"Real_Estate.h"

// Function to check if a string contains spaces
bool valid_space(string spc) {
    for (int i = 0; i < spc.length(); i++) {
        if (spc.at(i) == ' ') {
            return true;
        }
    }
    return false;
}

// Function to add a small delay
void estatedelay() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

// Getter function for location
string Real_Estate::get_location() { return location; }

// Getter function for area
double Real_Estate::get_area() { return area; }

// Getter function for current market value
double Real_Estate::get_current_price() { return current_market_value; }

// Setter function to update current market value
void Real_Estate::set_current_price(long double price) { current_market_value = price; }

// Function to input information for a new real estate asset
void Real_Estate::get_info() {
    system("cls");
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t*****    REAL ESTATE MANAGMENT PORTAL    *****\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";

    // Input the location of the real estate
    cout << "ENTER THE LOCATION OF THE REAL ESTATE [USE _ INSTEAD OF SPACE]: ";
    getline(cin >> ws, location);

    // Validating location for spaces
    while (valid_space(location)) {
        cout << "\nERROR! SPACES WERE DETECTED IN REAL ESTATE LOCATION\n";
        cout << "\nPLEASE ENTER THE LOCATION OF THE REAL ESTATE [USE _ INSTEAD OF SPACE]: ";
        getline(cin >> ws, location);
    }

    // Input the area size of the real estate
    cout << "\nENTER THE AREA SIZE OF THE REAL ESTATE [SQ. METERS]: ";
    while (!(cin >> area)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER THE AREA SIZE OF THE REAL ESTATE [SQ. METERS]: ";
    }

    // Input the year of purchase of the real estate
    cout << "\nENTER THE YEAR OF PURCHASE OF THE REAL ESTATE: ";
    while (!(cin >> year_of_purchase)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER THE YEAR OF PURCHASE OF THE REAL ESTATE: ";
    }

    // Input the cost of the real estate
    cout << "\nENTER THE COST OF THE REAL ESTATE: $";
    while (!(cin >> cost)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
        cout << "\nENTER THE COST OF THE REAL ESTATE: $";
    }
    current_market_value = cost;
    cout << "\n*** REAL ESTATE ADDED SUCCESSFULLY ***\n";
    std::thread t(estatedelay);
    t.join();
}

// Function to calculate the profit of the real estate
double Real_Estate::get_profit() {
    return current_market_value - cost;
}
