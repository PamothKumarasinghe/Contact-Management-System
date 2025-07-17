#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// store the contact as 
// nikolai laazz|0742614052|nikolai@example.com
// in the file contacts.txt

struct Contact {
    string name;
    string phone;
    string email;
};
vector<string> split(string& line) {
    
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

}