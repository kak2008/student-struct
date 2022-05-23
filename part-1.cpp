#include <iostream>
using namespace std;

// student struct
struct Student {
    string name;
    int ID;
    double grade[3];
};

// prints student info
void printStudentInfo(Student &s) {
    cout << "Student Info:" << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "ID: " << s.ID << "\n";
    
    for(int i=0; i<3; i++) {
        cout << "Grade " << (i + 1) <<": "<< s.grade[i] << "\n";
    }
}

// Checks if grade is valid
bool isGradeValid(double grade) {
    return (grade >= 0 && grade <= 100);
}

// inputs student struct
void inputStudents(Student &s) {
    cout << "Please enter a name: ";
    cin >> s.name; 
    cout << "Please enter an ID: ";
    cin >> s.ID; 
    
    for(int i=0; i<3; i++) {
       cout << "Please enter Grade " << i <<": ";
       cin >> s.grade[i]; 
       if (isGradeValid(s.grade[i]) == 0) {
           cout << "Invalid Grade " << i <<". Try Again! \n";
           i--;
       }
    }
    printStudentInfo(s);
}

int main() {
    Student stud;
    inputStudents(stud);

    return 0;
}
