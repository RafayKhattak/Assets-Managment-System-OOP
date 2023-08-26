#include"Investor.h"  // Include the corresponding header file

// Function to validate whether a symbol contains spaces
bool valid_symbol(string sym) {
	for (int i = 0; i < sym.length(); i++) {
		if (sym.at(i) == ' ') {
			return true;
		}
	}
	return false;
}
// Function to introduce a small delay using sleep_for
void stockdelay() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
// Constructor for Investor class
Investor::Investor() {
	stocks = new Stocks * [10];
	real_estates = new Real_Estate[10];
	res_index = 0;
	index = 0;
	currency = 0;
}
// Function to add assets (stocks, real estate, currency)
void Investor::add_assets()
{
	int choice;
	bool loop = true;
	while (loop) {
		system("cls");
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t*****    ASSETS MANAGMENT PORTAL    *****\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";
		cout << "[1] ADD STOCKS" << endl;
		cout << endl;
		cout << "[2] ADD REAL ESTATE" << endl;
		cout << endl;
		cout << "[3] ADD CURRENCY" << endl;
		cout << endl;
		cout << "[4] GO BACK" << endl;
		cout << "\nENTER YOUR CHOICE HERE: ";
		while (!(cin >> choice)) {
			cin.clear();  // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
			cout << "\nENTER YOUR CHOICE HERE: ";
		}
		if (choice == 1)
		{
			system("cls");
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\t\t\t*****    STOCKS MANAGMENT PORTAL    *****\n";
			cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";

			cout << "[1] SIMPLE STOCKS" << endl;
			cout << endl;
			cout << "[2] DIVIDEND STOCKS" << endl;
			cout << "\nENTER YOUR CHOICE HERE: ";
			while (!(cin >> choice)) {
				cin.clear();  // Clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
				cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
				cout << "\nENTER YOUR CHOICE HERE: ";
			}
			if (choice == 1)
			{
				system("cls");
				cout << "------------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t\t\t\t\t*****    STOCKS MANAGMENT PORTAL    *****\n";
				cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";
				cout << "STOCK TYPE: SIMPLE STOCKS\n";
				cout << "\nENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
				string symbol;
				getline(cin >> ws, symbol);

				// Validating admin name for spaces
				while (valid_symbol(symbol)) {
					cout << "\nERROR! SPACES WERE DETECTED IN STOCK NAME\n";
					cout << "\nPLEASE ENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
					getline(cin >> ws, symbol);
				}
				bool found = false;
				for (int i = 0; i < index; i++)
				{
					if (symbol == stocks[i]->get_symbol())
					{
						found = true;
						stocks[i]->add_stocks();
						cout << "\n*** STOCK ADDED SUCCESSFULLY! ***\n";
						std::thread t(stockdelay);
						t.join();
						break;
					}
				}

				if (!found)
				{
					stocks[index++] = new Simple_Stocks(symbol, "SIMPLE");
					cout << "\n*** STOCK ADDED SUCCESSFULLY! ***\n";
					std::thread t(stockdelay);
					t.join();
				}
			}
			else if (choice == 2)
			{
				system("cls");
				cout << "------------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t\t\t\t\t*****    STOCKS MANAGMENT PORTAL    *****\n";
				cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";
				cout << "STOCK TYPE: DIVIDEND STOCKS\n";
				string symbol;
				cout << "\nENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
				getline(cin >> ws, symbol);

				// Validating admin name for spaces
				while (valid_symbol(symbol)) {
					cout << "\nERROR! SPACES WERE DETECTED IN STOCK NAME\n";
					cout << "\nPLEASE ENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
					getline(cin >> ws, symbol);
				}
				bool found = false;
				for (int i = 0; i < index; i++)
				{
					if (symbol == stocks[i]->get_symbol())
					{
						stocks[i]->add_stocks();
						found = true;
						cout << "\n*** STOCK ADDED SUCCESSFULLY! ***\n";
						std::thread t(stockdelay);
						t.join();
						break;
					}
				}

				if (!found)
				{
					stocks[index++] = new Dividend_Stocks(symbol, "DIVIDEND");
					cout << "\n*** STOCK ADDED SUCCESSFULLY! ***\n";
					std::thread t(stockdelay);
					t.join();
				}
			}
		}
		else if (choice == 2)
		{
			real_estates[res_index++].get_info();
		}
		else if (choice == 3) {
			double am;
			system("cls");
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\t\t\t*****    STOCKS MANAGMENT PORTAL    *****\n";
			cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";
			cout << "\nENTER CURRENCY AMOUNT: $";
			cin >> am;
			currency += am;
			cout << "\n*** CURRENCY ADDED SUCCESSFULLY ***";
			std::thread t(stockdelay);
			t.join();
		}
		else if (choice == 4)
		{
			loop = false;
			}
		else {
			cout << "\n*** ERROR! INVALID OPTION ENTERED ***\n";
			std::thread t(stockdelay);
			t.join();
		}
	}
}
// Function to set investor's username

void Investor::set_username(string usrnm) {
	username = usrnm;
}
// Function to get investor's username

string Investor::get_username() {
	return username;
}
// Function to check all assets

void Investor::check_assets() {
	system("cls");
		
		cout << "======================================================CURRENCY==========================================================\n";
		cout << endl;
		cout << "CURRENCY    :     $ " << currency << endl;
		cout << endl;
		cout << "======================================================STOCKS============================================================\n";
		cout << endl;
		cout << "STOCK SYMBOL          CURRENT PRICE       TOTAL STOCKS      TYPE      DIVIDENDS TO RECEIVE" << endl;
		for (int i = 0; i < index; i++)
		{
			cout << setw(12) << stocks[i]->get_symbol() << setw(22) << stocks[i]->get_current_price() << setw(20) << stocks[i]->get_total_stocks() << setw(10) << stocks[i]->get_type();
			if (stocks[i]->get_type() == "DIVIDEND")
				cout << setw(10) << stocks[i]->get_dividend() * stocks[i]->get_total_stocks();

			cout << endl;
		}
		cout << endl;
		cout << "====================================================REAL ESTATE=========================================================\n";
		cout << endl;
		cout << "LOCATION          CURRENT PRICE       AREA" << endl;
		for (int i = 0; i < res_index; i++)
		{
			cout << std::left << setw(18) << real_estates[i].get_location() << setw(20) << real_estates[i].get_current_price() << setw(20) << real_estates[i].get_area() << endl;
		}
		cout << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		system("pause");

}
// Function to check profits from assets

void Investor::check_profit() {
	system("cls");
	cout << "======================================================STOCKS PROFIT=====================================================\n";
	cout << endl;
	cout << left << setw(20) << "STOCK SYMBOL" << setw(20) << "TOTAL PROFIT" << setw(20) << "TOTAL STOCKS" << "TYPE" << endl;
	long double max = -1;
	string max_profit_string = "";
	long double profit = 0;

	for (int i = 0; i < index; i++) {
		cout << setw(20) << stocks[i]->get_symbol() << setw(20) << stocks[i]->get_profit() << setw(20) << stocks[i]->get_total_stocks() << stocks[i]->get_type() << endl;
		if (stocks[i]->get_profit() > max) {
			max = stocks[i]->get_profit();
			max_profit_string = "MAX PROFIT IS FROM \"" + stocks[i]->get_symbol() + "\" STOCK OF TYPE \"" + stocks[i]->get_type() + "\"";
		}

		profit += stocks[i]->get_profit();
	}
	cout << "====================================================REAL ESTATE PROFIT==================================================\n";
	cout << endl;
	cout << left << setw(20) << "LOCATION" << setw(20) << "PROFIT" << "AREA" << endl;

	for (int i = 0; i < res_index; i++) {
		cout << setw(20) << real_estates[i].get_location() << setw(20) << real_estates[i].get_profit() << real_estates[i].get_area() << endl;
		double pr = real_estates[i].get_profit();

		if (pr > max) {
			max = pr;
			max_profit_string = "MAX PROFIT IS FROM A REAL ESTATE AT LOCATION \"" + real_estates[i].get_location() + "\"";
		}
		profit += pr;
	}
	cout << endl;
	cout << "************************************************************************************************************************\n";
	cout << endl;
	cout << max_profit_string << endl;
	cout << endl;
	cout << "TOTAL PROFIT: " << profit << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	system("pause");
}
// Function to change asset prices

void Investor::change_prices()
{
	system("cls");
	int choice;
	bool loop = true;
	while (loop) {
		system("cls");
		cout << "==================================================== CHANGE PRICE ======================================================\n";
		cout << endl;
		cout << "[1] STOCKS" << endl;
		cout << endl;
		cout << "[2] REAL ESTATE" << endl;
		cout << endl;
		cout << "[3] GO BACK" << endl;
		cout << "\nENTER YOUR CHOICE HERE: ";
		while (!(cin >> choice)) {
			cin.clear();  // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
			cout << "\nENTER YOUR CHOICE HERE: ";
		}
		if (choice == 1)
		{
			system("cls");
			cout << "==================================================== CHANGE STOCK PRICE ================================================\n";
			cout << endl;
			cout << "\nENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
			string symbol;
			getline(cin >> ws, symbol);
			while (valid_symbol(symbol)) {
				cout << "\nERROR! SPACES WERE DETECTED IN STOCK NAME\n";
				cout << "\nPLEASE ENTER STOCK SYMBOL [EXAMPLE = TSLA, AAPL, GOOGL]: ";
				getline(cin >> ws, symbol);
			}
			bool found = false;
			for (int i = 0; i < index; i++)
			{
				if (symbol == stocks[i]->get_symbol())
				{
					if (stocks[i]->get_type() == "SIMPLE")
					{
						cout << "\n *** STOCK TYPE: SIMPLE ***\n";
						long double old = stocks[i]->get_current_price();
						long double price;
						cout << "\nENTER CURRENT (NEW) PRICE: ";
						while (!(cin >> price)) {
							cin.clear();  // Clear the error state
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
							cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
							cout << "\nENTER CURRENT (NEW) PRICE: ";
						}
						stocks[i]->set_current_price(price);
						cout << "\n*** NEW PRICE SET FOR " << stocks[i]->get_symbol() << " FROM $" << old << " TO $" << stocks[i]->get_current_price() << endl;
						found = true;
						std::thread t(stockdelay);
						t.join();
					}
					else {
						cout << "\n *** STOCK TYPE: DIVIDEND ***\n";
						cout << "\n[1] CHANGE PRICE\n";
						cout << endl;
						cout << "[2] CHANGE NUMBER OF DIVIDENDS\n";
						cout << "\nENTER YOUR OPTION HERE: ";
						while (!(cin >> choice)) {
							cin.clear();  // Clear the error state
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
							cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
							cout << "\nENTER YOUR OPTION HERE: ";
						}
						if (choice == 1)
						{
							long double old = stocks[i]->get_current_price();
							long double price;
							cout << "\nENTER CURRENT (NEW) PRICE: ";
							cin >> price;
							stocks[i]->set_current_price(price);
							cout << "\n*** NEW PRICE SET FOR " << stocks[i]->get_symbol() << " FROM $" << old << " TO $" << stocks[i]->get_current_price() << endl;

							found = true;
							std::thread t(stockdelay);
							t.join();
						}
						else if (choice == 2) {
							int dividends = stocks[i]->get_dividend();
							double price;
							cout << "\nENTER NUMBER OF DIVIDENDS: ";
							cin >> price;
							stocks[i]->set_dividend(price);
							cout << "\n*** NEW DIVIDENDS SET FOR " << stocks[i]->get_symbol() << " FROM " << dividends << " TO " << stocks[i]->get_dividend() << endl;

							found = true;
							std::thread t(stockdelay);
							t.join();
						}
						else {
							cout << "\n*** INVALID OPTION ENTERED ***\n";
							std::thread t(stockdelay);
							t.join();
						}

					}
				}
			}

			if (!found)
			{
				cout << "\n*** ERROR! STOCK NOT FOUND IN DATABASE ***" << endl;
				std::thread t(stockdelay);
				t.join();
			}
		}
		else if (choice == 2) {
			system("cls");
			cout << "=================================================== CHANGE REAL ESTATE PRICE ===========================================\n";
			cout << endl;
			cout << "SR.NO     LOCATION          CURRENT PRICE       AREA (SQ.METERS)" << endl;
			for (int i = 0; i < res_index; i++)
			{
				cout << std::left << setw(10) << i+1 << setw(18) << real_estates[i].get_location() << setw(20) << real_estates[i].get_current_price() << setw(20) << real_estates[i].get_area() << endl;
			}
			cout << endl;
			cout << "************************************************************************************************************************\n";
			cout << endl;
			cout << "ENTER SR.NO OF REAL ESTATE: ";
			int sr;

			while (!(cin >> sr)) {
				cin.clear();  // Clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
				cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
				cout << "\nENTER SR.NO OF REAL ESTATE: ";
			}
			sr--;
			if (sr > res_index || sr < 0) {
				cout << "\n*** ERROR! INVALID SR.NO ENTERED ***" << endl;
				std::thread t(stockdelay);
				t.join();
			}
			else {
				cout << "\nENTER CURRENT (NEW) PRICE OF REAL ESTATE ASSET: ";
				double price;
				while (!(cin >> price)) {
					cin.clear();  // Clear the error state
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
					cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
					cout << "\nENTER CURRENT (NEW) PRICE OF REAL ESTATE ASSET: ";
				}
				long double oldprice = real_estates[sr].get_current_price();
				real_estates[sr].set_current_price(price);
				cout << "\n*** NEW PRICE SET FOR REAL ESTATE AT LOCATION " << real_estates[sr].get_location() << " FROM $" << oldprice << " TO $" << real_estates[sr].get_current_price() << endl;
				std::thread t(stockdelay);
				t.join();
			}

		}
		else if (choice == 3){
			loop = false;
		}
	}
}
// Function to manage investor's assets

void Investor::manage_assets() {
	int choice;
	bool loop = true;
	while (loop) {
		system("cls");
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t*****    ASSETS MANAGMENT PORTAL    *****\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n";

		cout << "[1] ADD ASSETS" << endl;
		cout << "\n";
		cout << "[2] CHECK ALL ASSETS" << endl;
		cout << "\n";
		cout << "[3] CHECK ASSETS PROFIT" << endl;
		cout << "\n";
		cout << "[4] CHANGE ASSETS PRICE" << endl;
		cout << endl;
		cout << "[5] LOGOUT AS INVESTOR" << endl;
		cout << endl;
		cout << "ENTER YOUR CHOICE HERE: ";
		while (!(cin >> choice)) {
			cin.clear();  // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
			cout << "\nENTER YOUR CHOICE HERE: ";
		}

		if (choice == 1) {
			add_assets();
		}
		else if (choice == 2) {
			check_assets();
		}
		else if (choice == 3) {
			check_profit();
		}
		else if (choice == 4) {
			change_prices();
		}
		else if (choice == 5)
		{
			loop = false;
		}
	}
}