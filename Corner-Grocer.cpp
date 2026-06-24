#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;  // Map to store item names and their frequencies
    string inputFileName;
    string outputFileName;

    // Helper method to convert string to lowercase for case-insensitive matching
    string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

public:
    // Constructor
    GroceryTracker() {
        inputFileName = "CS210_Project_Three_Input_File.txt";
        outputFileName = "frequency.dat";
    }

    // Method to read the input file and build the frequency map
    bool readInputFile() {
        ifstream inFile(inputFileName);
        
        // FIXED: Check if file is NOT open (opposite of what you had)
        if (!inFile.is_open()) {
            cout << "Error: Could not open file '" << inputFileName << "'." << endl;
            cout << "Please ensure the file exists in the current directory." << endl;
            return false;
        }

        string item;
        // Read each word from the file and increment its frequency count
        while (inFile >> item) {
            // Convert to lowercase for case-insensitive counting
            string lowerItem = toLower(item);
            itemFrequency[lowerItem]++;
        }

        inFile.close();

        // Check if any items were read
        if (itemFrequency.empty()) {
            cout << "Warning: The input file was empty or contained no readable data." << endl;
            return false;
        }

        // FIXED: Return true to indicate success
        return true;
    }

    // Method to create the backup data file
    bool createBackupFile() {
        ofstream outFile(outputFileName);
        
        if (!outFile.is_open()) {
            cout << "Error: Could not create backup file '" << outputFileName << "'." << endl;
            return false;
        }

        // Write all items and their frequencies to the backup file
        for (const auto& pair : itemFrequency) {
            // Capitalize first letter for cleaner output
            string itemName = pair.first;
            itemName[0] = toupper(itemName[0]);
            outFile << itemName << " " << pair.second << endl;
        }

        outFile.close();
        cout << "Backup file '" << outputFileName << "' created successfully." << endl;
        return true;
    }

    // Menu Option One: Get frequency of a specific item
    void getItemFrequency() {
        string userInput;
        
        cout << "\n========================================" << endl;
        cout << "  FIND ITEM FREQUENCY" << endl;
        cout << "========================================" << endl;
        cout << "Enter the item name to search for: ";
        cin >> userInput;

        string lowerInput = toLower(userInput);
        
        auto it = itemFrequency.find(lowerInput);
        
        if (it != itemFrequency.end()) {
            string displayName = lowerInput;
            displayName[0] = toupper(displayName[0]);
            cout << "\n>> " << displayName << " appears " << it->second << " time(s)." << endl;
        } else {
            cout << "\n>> Item '" << userInput << "' was not found in the purchase records." << endl;
        }
    }

    // Menu Option Two: Display all items with their frequencies
    void displayAllFrequencies() {
        cout << "\n========================================" << endl;
        cout << "  ALL ITEM FREQUENCIES" << endl;
        cout << "========================================" << endl;
        
        if (itemFrequency.empty()) {
            cout << "No data available. Please load the input file first." << endl;
            return;
        }

        cout << left << setw(20) << "ITEM" << "FREQUENCY" << endl;
        cout << "----------------------------------------" << endl;
        
        for (const auto& pair : itemFrequency) {
            string itemName = pair.first;
            itemName[0] = toupper(itemName[0]);
            cout << left << setw(20) << itemName << pair.second << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "Total unique items: " << itemFrequency.size() << endl;
    }

    // Menu Option Three: Display histogram
    void displayHistogram() {
        cout << "\n========================================" << endl;
        cout << "  FREQUENCY HISTOGRAM" << endl;
        cout << "========================================" << endl;
        
        if (itemFrequency.empty()) {
            cout << "No data available. Please load the input file first." << endl;
            return;
        }

        for (const auto& pair : itemFrequency) {
            string itemName = pair.first;
            itemName[0] = toupper(itemName[0]);
            
            cout << left << setw(20) << itemName << " ";
            
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            
            cout << " (" << pair.second << ")" << endl;
        }
        cout << "========================================" << endl;
    }

    // Menu Option Four: Exit the program
    void exitProgram() {
        cout << "\n========================================" << endl;
        cout << "  EXITING PROGRAM" << endl;
        cout << "========================================" << endl;
        cout << "Thank you for using the Corner Grocer Item Tracker!" << endl;
        cout << "Goodbye!" << endl;
    }

    // Display the main menu
    void displayMenu() {
        cout << "\n========================================" << endl;
        cout << "  CORNER GROCER - ITEM TRACKER" << endl;
        cout << "========================================" << endl;
        cout << "  [1] Look up item frequency" << endl;
        cout << "  [2] Display all item frequencies" << endl;
        cout << "  [3] Display frequency histogram" << endl;
        cout << "  [4] Exit program" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice (1-4): ";
    }

    // Main program loop
    void run() {
        cout << "\n========================================" << endl;
        cout << "  WELCOME TO CORNER GROCER ITEM TRACKER" << endl;
        cout << "========================================" << endl;
        cout << "Loading purchase data..." << endl;

        if (!readInputFile()) {
            cout << "Program cannot continue without valid input data." << endl;
            return;
        }

        createBackupFile();

        int choice;
        bool running = true;

        while (running) {
            displayMenu();
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n!! Invalid input. Please enter a number between 1 and 4." << endl;
                continue;
            }

            switch (choice) {
                case 1:
                    getItemFrequency();
                    break;
                case 2:
                    displayAllFrequencies();
                    break;
                case 3:
                    displayHistogram();
                    break;
                case 4:
                    exitProgram();
                    running = false;
                    break;
            }
        }
    }
};

int main() {
    GroceryTracker tracker;
    tracker.run();
    return 0;
}
