// Lab_24 - COMSC-210
// Malakai Ponce

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, 
SZ_COLORS = 25, 
MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);

// seeing if the do while is going to work 

int select_goat(set<Goat> trip) {
    int choice;
    cout << "Pick a goat to delete: ";
    cin >> choice;

    return choice;
}

void add_goat(set<Goat> &trip, string names[], string colors[]) {

    string name = names[rand() % SZ_NAMES];

    int age = rand() & MAX_AGE;
    string color = colors[rand() % SZ_COLORS];

    Goat new_goat(name, age, color);
    trip.insert(new_goat); //doest use pushback since its a set now

    cout << "Added Goat: " << new_goat.get_name() << endl;
}
void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in the trip to delete" << endl;
        return;
    }
    display_trip(trip);

    int choice = select_goat(trip);

    auto it = trip.begin();
    advance(it, choice - 1);
    trip.erase(it);

    cout << "Goat " << choice << " deleted." << endl;

}

void display_trip(set<Goat> trip) {
    if(trip.empty()) {
        cout << "No goats in the trip!" << endl;
        return;
    }

    int index = 1;
    for (auto goat : trip) {  
        cout << "[" << index << "] " << goat.get_name() 
             << " (" << goat.get_age() << ", " 
             << goat.get_color() << ")" << endl;
        index++;
    }
};


int main_menu() {
    int choice;

    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Invalid. Enter 1-4: ";
        cin >> choice;
    }
    
    return choice;
}

int main() {
    srand(time(0));
    bool again;
    int choice;
   
    // ****TESTING IGNORE****
    // Goat g1;                        
    // Goat g2("Billy");               
    // Goat g3("Nanny", 5);           
    // Goat g4("Gruff", 7, "Brown");  

    // cout << "Goat 1: " << g1.get_name() << " (should be empty)" << endl;
    // cout << "Goat 2: " << g2.get_name() << endl;
    // cout << "Goat 3: " << g3.get_name() << ", age " << g3.get_age() << endl;
    // cout << "Goat 4: " << g4.get_name() << ", age " << g4.get_age() 
    //      << ", color " << g4.get_color() << endl;
    
    // return 0;



    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();


    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();


    set<Goat> trip;

// more efficient thatn a bunch of if else I learned also for loop was limited while isnt hence the switch
// tutor helped with this
    do { 
        choice = main_menu();

        switch(choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
