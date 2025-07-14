#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <conio.h>  // For _getch()

using namespace std;

// Function to get masked password input
string getMaskedPassword() {
    string password;
    char ch;

    while ((ch = _getch()) != '\r') {  // '\r' is Enter key
        if (ch == '\b') {  // Handle backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

// Load credentials from file
unordered_map<string, string> loadCredentials(const string& filename) {
    unordered_map<string, string> users;
    ifstream file(filename);
    string user, pass;

    while (file >> user >> pass) {
        users[user] = pass;
    }

    file.close();
    return users;
}

// Register new user
void registerUser(const string& filename) {
    unordered_map<string, string> users = loadCredentials(filename);
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter a new username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Try another.\n";
        return;
    }

    cout << "Enter a password: ";
    password = getMaskedPassword();  // Masked password input

    ofstream file(filename, ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful.\n";
}

// Login existing user
void loginUser(const string& filename) {
    unordered_map<string, string> users = loadCredentials(filename);
    string username, password;

    cout << "\n--- User Login ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    password = getMaskedPassword();  // Masked password input

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Login successful. Welcome, " << username << "!\n";
    } else {
        cout << "Invalid credentials.\n";
    }
}

int main() {
    const string filename = "users.txt";
    int choice;

    do {
        cout << "\n===== Login & Registration Menu =====\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(filename);
                break;
            case 2:
                loginUser(filename);
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

