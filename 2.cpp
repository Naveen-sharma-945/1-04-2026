#include <iostream>
#include <fstream>
#include <vector
using namespace std;

class Employee {
private:
    int employee_id;
    string name;
    float salary;

public:
    // Constructor
    Employee() {
        employee_id = 0;
        name = "";
        salary = 0;
    }

    // Function to read employee data
    void readData(ifstream &inFile) {
        inFile >> employee_id >> name >> salary;
    }

    // Function to calculate salary (example logic)
    void calculateSalary() {
        float bonus = 0.10 * salary;     // 10% bonus
        float deduction = 0.05 * salary; // 5% deduction
        salary = salary + bonus - deduction;
    }

    // Function to write employee data
    void writeData(ofstream &outFile) {
        outFile << employee_id << " "
                << name << " "
                << salary << endl;
    }

    // Display data (for checking)
    void display() {
        cout << employee_id << " "
             << name << " "
             << salary << endl;
    }
};

int main() {
    ifstream inFile("employees.txt");     // Input file
    ofstream outFile("updated.txt");      // Output file

    // Error handling
    if (!inFile) {
        cout << "Error: Cannot open input file!" << endl;
        return 1;
    }

    if (!outFile) {
        cout << "Error: Cannot open output file!" << endl;
        return 1;
    }

    vector<Employee> empList;

    // Read data from file
    while (!inFile.eof()) {
        Employee emp;
        emp.readData(inFile);

        if (inFile.fail()) break; // Prevent garbage read

        empList.push_back(emp);
    }

    inFile.close();

    // Process data (calculate salary)
    for (int i = 0; i < empList.size(); i++) {
        empList[i].calculateSalary();
    }

    // Write updated data to file
    for (int i = 0; i < empList.size(); i++) {
        empList[i].writeData(outFile);
    }

    outFile.close();

    // Display updated records
    cout << "\nUpdated Employee Records:\n";
    for (int i = 0; i < empList.size(); i++) {
        empList[i].display();
    }

    return 0;
}
