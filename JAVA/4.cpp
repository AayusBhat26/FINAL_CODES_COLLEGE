#include <iostream>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void displayPersonInfo() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};
class Student : public Person {
protected:
    string rollNumber;
public:
    Student(string name, int age, string rollNumber) : Person(name, age) {
        this->rollNumber = rollNumber;
    }
    void displayStudentInfo() {
        displayPersonInfo();  // Calling base class function
        cout << "Roll Number: " << rollNumber << endl;
    }
};
class GraduateStudent : public Student {
private:
    string degree;
public:
    GraduateStudent(string name, int age, string rollNumber, string degree) : Student(name, age, rollNumber) {
        this->degree = degree;
    }
    void displayGraduateStudentInfo() {
         displayStudentInfo();  
        cout << "Degree: " << degree << endl;
    }
};
int main() {
    GraduateStudent gradStudent("Rahul Kumar", 22, "102024404524", "Computer Science");
    cout<<endl;
    cout << "Graduate Student Information:\n";
    gradStudent.displayGraduateStudentInfo();
    cout<<endl;
    return 0;
}
