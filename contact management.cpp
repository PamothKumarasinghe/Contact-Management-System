#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// store the contact as 
// nikolai laazz|0742614052|nikolai@example.com
// in the file contacts.txt

struct Contact {
    string name;
    string phone;
    string email;
};
vector<string> split(const string& line, char delimiter = '|') {
    vector<string> tokens;
    string token;
    istringstream stream(line);
    while (getline(stream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}
void addContact() {
    Contact c;
    cout << "Enter name: ";
    getline(cin, c.name);

    cout << "Enter phone number: ";
    getline(cin, c.phone);

    cout << "Enter email: ";
    getline(cin, c.email);

    ofstream file("contacts.txt", ios::app); // output file stream
    if (file.is_open()) 
        file << c.name <<"|" << c.phone << "|" << c.email << endl;
    file.close();

    cout << "Contact added successfully!" << endl;
}
void searchContact() {
    string keyWord;
    getline(cin, keyWord);
    ifstream file("contacts.txt"); // input file stream
    string line;
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> data = split(line);
            if ((data.size() == 3) && (data[0].find(keyWord) != string:: npos || data[1].find(keyWord) != string::npos)) {
                cout << "Found Contact" << endl;
                cout << "Name: " << data[0] << ", Phone: " << data[1] << ", Email: " << data[2];
                found = true;
            }
        }
        if (!found) cout << "No Matching Contact Found" << endl;
    }
    file.close();
}

void viewContact() {
    ifstream file("contacts.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> data = split(line);

            if (data.size() == 3) {
                cout << endl << data[0] << " " << data[1] << " " << data[2] << endl;
            }
        }
    }
    file.close();
}
int main() {
    while (true) {
        cout << "\n-----Contact Management-----\n";
        cout << "1. Add Contact\n2. View Contact\n3. Exit\n\n choice: ";
        string choice;
        getline(cin, choice);

        if (choice == "1")
            addContact();
        else if (choice == "2")
            viewContact();
        else if (choice == "3")
            break;
        else 
            cout << "Invalid Option. Please Try Again!\n";
    }
    cout << "-----Good Bye!-----";
}