#include <iostream>
#include <vector>
#include <string>   
#include <chrono>
#include <thread>
#include <windows.h>


using namespace std;



int main() {
    cout << endl;
    cout << "\nWelcome to scalar's To-do list manager!" << endl;
    cout << "\nUsage:" << endl;
    cout << "e to exit/end program (warning, will wipe all info), FIX THIS," << endl;
    cout << "a to add a new To-do List item" << endl;                       
    cout << "s to see all to-do list items " << endl;
    cout << "r to modify a To-do list item" << endl;
    cout << "d to delete a To-do list item" << endl;
    cout << "w to enter standby mode. After entering all of your to-do list items, enter standby mode and leave the code running in the background. It will notify you when a deadline has approached.  " << endl;
    cout << endl;
    cout << endl;

    string action_input;
    string name_input;
    string description_input;
    string due_input;
    string delete_input;
    string edit_input;

    vector<string> items_names; 
    vector<string> items_due;
    vector<string> items_description;

    // items_names.push_back("item 1");

    while (true) {
        cout << "Input: " ;
        getline (cin, action_input);
        
        if (action_input == "e") {
            break;
        }


        else if (action_input == "a") {
            cout << "\nLets add a new To-do list item" << endl;
            cout << endl;

            cout << "Name of the To-do item: ";
            getline(cin, name_input); 
            items_names.push_back(name_input);
        
            cout << "Description of the To-do item: " << endl;
            getline(cin, description_input); 
            items_description.push_back(description_input);

            cout << "What time is it due today? (hh:mm):  " << endl;
            getline(cin, due_input); 
            items_due.push_back(due_input);
        
            cout << "Item successfully added to storage :)" << endl;
        } 

        else if (action_input == "s") {
            cout << endl;
            cout << "Here is all the stored to-do list items:" << endl;
            cout << endl;

            for (int i=0; i < items_names.size(); i++) {
                cout << "Item #" << i << ":" << endl;
                cout << endl;

                cout << items_names[i] << endl;
                cout << items_due[i] << endl;
                cout << items_description[i] << endl;
                
                cout << endl;


            }
        
        }
        
        
        else if (action_input == "w") {
            cout << endl;
            cout << "entering standby mode:" << endl;
            
            while (true) {
            
                auto now = chrono::system_clock::now();
                time_t t_now = chrono::system_clock::to_time_t(now);
                tm local_tm = *localtime(&t_now);

                int current_hour = local_tm.tm_hour;
                int current_minute = local_tm.tm_min;

                for (int i = 0; i < items_due.size(); i++) {
                    // stoi converts string to int
                    int due_hour = stoi(items_due[i].substr(0,2));
                    int due_minute = stoi(items_due[i].substr(3,2));

                    if (current_hour == due_hour && current_minute == due_minute) {
                        cout << "\a"; // beep
                        cout << "ALERT! To-do item \"" << items_names[i] << "\" is due now!" << endl;
                        Beep(300, 5000);

                    }
                }

                this_thread::sleep_for(chrono::seconds(30)); // check every 30 seconds
            }

        }

        else if (action_input == "d") {
            // deleting yeee
            cout << "Deleting an item. To delete an item, you will need its index number (find this when reading all to do list items)" << endl;
            cout << "Delete index: ";
            getline(cin, delete_input);
            int delete_index = stoi(delete_input);

            if (delete_index >= 0 && delete_index < items_names.size()) {
                items_names.erase(items_names.begin() + delete_index);
                items_description.erase(items_description.begin() + delete_index);
                items_due.erase(items_due.begin() + delete_index);
            }

        }

        else if (action_input == "r") {
            cout << "Modifying an item in the list. You will need its index number (find this when reading all to do list items)" << endl;
            cout << "Edit index: "
            getline(cin, edit_input);

            cout << endl;
            int edit_index = stoi(edit_input);
            cout << "editing item#" << edit_index << endl;

            cout << "Updated name of the To-do item: ";
            getline(cin, name_input); 
            items_names[edit_index] = name_input;
            
        
            cout << "Updated description of the To-do item: " << endl;
            getline(cin, description_input); 
            items_description[edit_index] = description_input;
            

            cout << "What time is it due today? (hh:mm):  " << endl;
            getline(cin, due_input); 
            items_due[edit_index] = due_input;
            
            cout << endl;


        }
              

    } 

    return 0;  
    
}