#include <iostream>
#include <vector>
#include <string>   
using namespace std;



int main() {
    vector<string> items_names; 
    vector<int> items_due;
    vector<string> items_description;

    cout << "Welcome to scalar's To-do list manager!" << endl;
    cout << "Usage:" << endl;
    cout << "e to exit/end program (warning, will wipe all info), FIX THIS, a to add a new To-do List item, r to delete a To-do list item." << endl;

    string input;

    // items_names.push_back("item 1");

    while (true) {
        cout << "Input: " ;
        getline (cin, input);
        
        if (input == "e") {
            break;
        }
        else if (input == "a") {
            cout << "Adding a new number" << endl;
        }
    }



    return 0;  
    
}