#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<fstream>
#include <thread>
#include <chrono>
#include <cctype>
#include <limits>
#include "Investor.h" // Include your Investor class header file here

using namespace std;

// Function to check if a string contains spaces
bool valid_name(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name.at(i) == ' ') {
            return true;
        }
    }
    return false;
}

// Function to add a small delay
void smoldelay() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    int choice;
    int index = 0;
    Investor* investors = new Investor[100];

    while (1) {
        system("cls"); // Clear the console
        // Display the main menu
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\t*****\t WELCOME TO THE OFFICIAL FAST NUCES ASSETS MANAGEMENT SYSTEM CREATED BY RAFAY KHATTAK\t *****\n";
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n";
        cout << "\n";
        cout << "[1] ADD AN INVESTOR" << endl;
        cout << "\n";
        cout << "[2] MANAGE YOUR ASSETS" << endl;
        cout << "\n";
        cout << "ENTER YOUR CHOICE HERE: ";

        // Validate the choice input
        while (!(cin >> choice)) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            cout << "\nERROR! INVALID INPUT ENTERED, PLEASE ENTER AN INTEGER VALUE\n";
            cout << "\nENTER YOUR CHOICE HERE: ";
        }

        if (choice == 1) {
            string usrname;
            system("cls"); // Clear the console
            // Display the add investor menu
            cout << "------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\t*****\t WELCOME TO THE OFFICIAL FAST NUCES ASSETS MANAGEMENT SYSTEM CREATED BY RAFAY KHATTAK\t *****\n";
            cout << "------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n";
            cout << "\n";
            cout << "ENTER YOUR USERNAME [NO SPACE ALLOWED]: ";
            getline(cin >> ws, usrname);

            // Validate username for spaces
            while (valid_name(usrname)) {
                cout << "\nERROR! SPACES WERE DETECTED IN INVESTOR USERNAME\n";
                cout << "\nPLEASE ENTER USERNAME AGAIN [NO SPACES ALLOWED]: ";
                getline(cin >> ws, usrname);
            }
            bool found = false;
            for (int i = 0; i < index; i++)
                if (investors[i].get_username() == usrname)
                {
                    found = true;
                }

            if (found) {
                cout << "\n*** ERROR! USER ALREADY EXISTS! ***" << endl;
                std::thread t(smoldelay);
                t.join();
            }
            else {
                investors[index++].set_username(usrname);
                cout << "\n*** INVESTOR ADDED SUCCESSFULLY! ***\n";
                std::thread t(smoldelay);
                t.join();
            }
        }
        else if (choice == 2) {
            string usrname;
            system("cls"); // Clear the console
            // Display the manage assets menu
            cout << "------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\t*****\t WELCOME TO THE OFFICIAL FAST NUCES ASSETS MANAGEMENT SYSTEM CREATED BY RAFAY KHATTAK\t *****\n";
            cout << "------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n";
            cout << "\n";
            cout << "ENTER YOUR USERNAME [NO SPACE ALLOWED]: ";
            getline(cin >> ws, usrname);

            // Validate username for spaces
            while (valid_name(usrname)) {
                cout << "\nERROR! SPACES WERE DETECTED IN INVESTOR USERNAME\n";
                cout << "\nPLEASE ENTER USERNAME AGAIN [NO SPACES ALLOWED]: ";
                getline(cin >> ws, usrname);
            }
            bool found = false;
            for (int i = 0; i < index; i++)
                if (investors[i].get_username() == usrname)
                {
                    cout << "\n***LOG IN SUCCESSFUL! YOU WILL NOW BE REDIRECTED TO YOUR ASSETS MANAGEMENT PORTAL ***\n";
                    std::thread t(smoldelay);
                    t.join();
                    investors[i].manage_assets();
                    found = true;
                }

            if (!found) {
                cout << "\n*** ERROR! USER DOES NOT EXIST! ***" << endl;
                std::thread t(smoldelay);
                t.join();
            }
        }
    }
    return 0;
}
