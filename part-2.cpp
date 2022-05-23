#include <iostream>
using namespace std;

// student struct
struct Student {
    string name;
    int ID;
    double *grade;
};

// prints student info
void printStudentInfo(Student &s, int numOfGrades) {
    cout << "Student Info:" << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "ID: " << s.ID << "\n";
    
    for(int i=0; i<numOfGrades; i++) {
        cout << "Grade " << (i + 1) <<": "<< s.grade[i] << "\n";
    }
}

// Checks if grade is valid
bool isGradeValid(double grade) {
    return (grade >= 0 && grade <= 100);
}

// inputs student struct
void inputStudents(Student &s, int numOfGrades) {
    cout << "Please enter a name: ";
    cin >> s.name; 
    cout << "Please enter an ID: ";
    cin >> s.ID; 
    
    for(int i=0; i<numOfGrades; i++) {
       cout << "Please enter Grade " << i <<": ";
       cin >> s.grade[i]; 
       if (isGradeValid(s.grade[i]) == 0) {
           cout << "Invalid Grade " << i <<". Try Again! \n";
           i--;
       }
    }
    printStudentInfo(s, numOfGrades);
}

int main() {
    Student stud;           
    int numOfGrades;
    
    cout << "How many grades are there: ";
    cin >> numOfGrades; 
    
    stud.grade = new double[numOfGrades]; // creates designated number of grade elements

    inputStudents(stud, numOfGrades);
    return 0;
}
