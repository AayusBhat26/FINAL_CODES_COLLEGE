// WAP to implement the following types of constructors in a class (C++)
// a. No-argument constructor.
// b. One-argument constructor.
// c. Two-argument constructor.
// d. Copy constructor.

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Students {
    string name;
    string rollNumber;
    string phoneNumber;
    vector<string> subjects;
    string emailAddress;
    map<string, string> nameAndRelation;

public:
    // a. No-argument constructor
    Students() {
        name = "Unknown";
        rollNumber = "";
        phoneNumber = "N/A";
        emailAddress = "N/A";
        cout << "No-argument constructor called\n";
    }
    // b. One-argument constructor
    Students(string name) {
        this->name = name;
        rollNumber  =  "";
        phoneNumber = "N/A";
        emailAddress = "N/A";
        cout << "One-argument constructor called for " << name << "\n";
    }
    // c. Two-argument constructor
    Students(string name, long long rollNumber) {
        this->name = name;
        this->rollNumber = rollNumber;
        phoneNumber = "N/A";
        emailAddress = "N/A";
        cout << "Two-argument constructor called for " << name << " with roll number " << rollNumber << "\n";
    }
    // d. Copy constructor
    Students(const Students &other) {
        name = other.name;
        rollNumber = other.rollNumber;
        phoneNumber = other.phoneNumber;
        subjects = other.subjects;
        emailAddress = other.emailAddress;
        nameAndRelation = other.nameAndRelation;
        cout << "Copy constructor called for " << name << "\n";
    }

    // Function to set detailed information for the student
    void setDetails(string name, string rollNumber, string phoneNumber, vector<string> subjects,
                    string emailAddress, map<string, string> nameAndRelation) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->phoneNumber = phoneNumber;
        this->subjects = subjects;
        this->emailAddress = emailAddress;
        this->nameAndRelation = nameAndRelation;
    }

    // Display function to show details of the student
    void display() const {
        cout << "Name: " << name
             << "\nRoll Number: " << rollNumber
             << "\nPhone Number: " << phoneNumber
             << "\nEmail Address: " << emailAddress
             << "\nSubjects: ";
        for (const string &subject : subjects) {
            cout << subject << " ";
        }
        cout << "\nFamily Relations:\n";
        for (const auto &relation : nameAndRelation) {
            cout << relation.first << ": " << relation.second << endl;
        }
        cout << endl;
    }
};
int main() {
    // Using no-argument constructor
    cout<<"\n";
    Students student1;
    student1.display();
    // Using one-argument constructor
    cout<<"\n";
    Students student2("Alice");
    student2.display();
    // Using two-argument constructor
    cout<<"\n";
    Students student3("Bob", 101);
    student3.display();
    // Using copy constructor
    cout<<"\n";
    Students student4 = student3;
    student4.display();
    // Creating a student with full details
    cout<<"\n";
    Students student5;
    vector<string> subjects = {"C++", "OOPS", "DSA", "Cloud"};
    map<string, string> relations = {{"Ramesh Kumar", "Father"}, {"Reshma Kumar", "Mother"}};
    student5.setDetails("Rahul Kumar", "102024404524", "9876543211", subjects, "rahul.kumar@gmail.com", relations);
    
    cout << "Displaying details of student5:\n";
    student5.display();

    return 0;
}
