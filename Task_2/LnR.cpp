#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Save the credentials to a file
    ofstream outFile("database.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful!\n";
}

// Function to login a user
bool loginUser() {
    string username, password, storedUser, storedPass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream inFile("database.txt");
    bool loginSuccess = false;
    while (inFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            loginSuccess = true;
            break;
        }
    }
    inFile.close();

    if (loginSuccess) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Login failed! Invalid username or password.\n";
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\n3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                // Successful login, you can add more functionality here
                cout << "Welcome to the system!\n";
            }
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
    }

    return 0;
}
