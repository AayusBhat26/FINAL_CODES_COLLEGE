// Write a Program to calculate the total mark of a student using the concept of virtual class(C++).
#include <iostream>
using namespace std;
class Student {
protected:
    string name;
    string rollNumber;
public:
    Student(string name, string rollNumber) {
        this->name = name;
        this->rollNumber = rollNumber;
    }
    void displayStudentInfo() {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
    }
};
class Marks : virtual public Student {
protected:
    int oopsMarks;
    int dsaMarks;
public:
    Marks(string name, string rollNumber, int oopsMarks, int dsaMarks)
        : Student(name, rollNumber) {
        this->oopsMarks = oopsMarks;
        this->dsaMarks = dsaMarks;
    }
    void displayMarks() {
        cout << "oops Marks: " << oopsMarks << "\ndsa Marks: " << dsaMarks << endl;
    }
};
class OS : virtual public Student {
protected:
    int OSMarks;
public:
    OS(string name, string rollNumber, int OSMarks)
        : Student(name, rollNumber) {
        this->OSMarks = OSMarks;
    }
    void displayOSMarks() {
        cout << "OS Marks: " << OSMarks << endl;
    }
};
class Result : public Marks, public OS {
public:
    Result(string name, string rollNumber, int oopsMarks, int dsaMarks, int OSMarks)
        : Student(name, rollNumber), Marks(name, rollNumber, oopsMarks, dsaMarks),
          OS(name, rollNumber, OSMarks) {}
    void displayTotal() {
        int totalMarks = oopsMarks + dsaMarks + OSMarks;
        displayStudentInfo();
        displayMarks();
        displayOSMarks();
        cout << "Total Marks: " << totalMarks << endl;
    }
};
int main() {
    string name, rollNumber;
    int oopsMarks, dsaMarks, OSMarks;
    cout << "Enter student's name: ";
    getline(cin, name);
    cout << "Enter student's roll number: ";
    getline(cin, rollNumber);
    cout << "Enter oops marks: ";
    cin >> oopsMarks;
    cout << "Enter dsa marks: ";
    cin >> dsaMarks;
    cout << "Enter OS marks: ";
    cin >> OSMarks;
    Result student(name, rollNumber, oopsMarks, dsaMarks, OSMarks);
    cout << "\nStudent Total Marks Information:\n";
    student.displayTotal();
    return 0;
}
