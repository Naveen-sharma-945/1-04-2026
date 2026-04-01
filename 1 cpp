#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int roll_number;
    string name;
    float marks[5];

public:
    // Default Constructor
    Student() {
        roll_number = 0;
        name = "Unknown";
        for (int i = 0; i < 5; i++)
            marks[i] = 0;
    }

    // Parameterized Constructor (Full Details)
    Student(int r, string n, float m[]) {
        roll_number = r;
        name = n;
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
    }

    // Overloaded Constructor (Only Roll Number)
    Student(int r) {
        roll_number = r;
        name = "Not Assigned";
        for (int i = 0; i < 5; i++)
            marks[i] = 0;
    }

    // Destructor
    ~Student() {
        cout << "\nDestructor called for Roll No: " << roll_number << endl;
    }

    // Add Student (User Input)
    void addStudent() {
        cout << "\nEnter Roll Number: ";
        cin >> roll_number;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter 5 Marks: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }

    // Overloaded addStudent()
    void addStudent(int r, string n, float m[]) {
        roll_number = r;
        name = n;
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
    }

    // Modify Student
    void modifyStudent() {
        cout << "\nModify Name: ";
        cin >> name;
        cout << "Modify Marks: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }

    // Calculate Average
    float calculateAverage() {
        float sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        return sum / 5;
    }

    // Display Student
    virtual void displayStudent() {
        cout << "\n--- Student Details ---";
        cout << "\nRoll Number: " << roll_number;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << "\nAverage: " << calculateAverage() << endl;
    }
};

// Derived Class: Undergraduate
class UndergraduateStudent : public Student {
private:
    string course;

public:
    void setCourse(string c) {
        course = c;
    }

    void displayStudent() override {
        Student::displayStudent();
        cout << "Course: " << course << endl;
    }
};

// Derived Class: Graduate
class GraduateStudent : public Student {
private:
    string research_topic;

public:
    void setResearch(string topic) {
        research_topic = topic;
    }

    void displayStudent() override {
        Student::displayStudent();
        cout << "Research Topic: " << research_topic << endl;
    }
};

// Main Function
int main() {
    float m1[5] = {85, 90, 88, 92, 87};

    // Using Parameterized Constructor
    Student s1(101, "Amit", m1);
    s1.displayStudent();

    // Using Overloaded Constructor
    Student s2(102);
    float m2[5] = {75, 80, 70, 85, 78};
    s2.addStudent(102, "Riya", m2);
    s2.displayStudent();

    // Undergraduate Student
    UndergraduateStudent u1;
    u1.addStudent();
    u1.setCourse("BCA");
    u1.displayStudent();

    // Graduate Student
    GraduateStudent g1;
    g1.addStudent();
    g1.setResearch("Artificial Intelligence");
    g1.displayStudent();

    return 0;
}
