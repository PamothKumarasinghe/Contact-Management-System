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
    cout << "Enter name:\n ";
    getline(cin, c.name);

    cout << "Enter phone number: \n";
    getline(cin, c.phone);

    cout << "Enter email: \n";
    getline(cin, c.email);

    ofstream file("contact.txt", ios::app);
    if (file.is_open()) 
        file << c.name <<"|" << c.phone << "|" << c.email;
    file.close();

    cout << "Contact added successfully!" << endl;
}
void viewContact() {
    ifstream file("contacts.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> data = split(line);

            if (data.size() == 3) {
                cout << data[0] << " " << data[1] << " " << data[2] << endl;
            }
        }
    }
    file.close();
}
int main() {
    while (true) {
        cout << "\n-----Contact Management-----\n";
        cout << "1. Add Contact\n2. View Contact\n3. Exit";
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