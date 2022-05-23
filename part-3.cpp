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
       cout << "Please enter Grade " << (i+1) <<": ";
       cin >> s.grade[i]; 
       if (isGradeValid(s.grade[i]) == 0) {
           cout << "Invalid Grade " << (i+1) <<". Try Again! \n";
           i--;
       }
    }
}

int main() {
              
    int numOfGrades;
    int numOfStudents;
    
    Student *students;
    
    cout << "How many students are there: ";
    cin >> numOfStudents; 
    
    cout << "How many grades are there: ";
    cin >> numOfGrades; 
    
    students = new Student[numOfStudents]; // creates designated number of student array instances 

    for(int i=0; i<numOfStudents; i++) {
        students[i].grade = new double[numOfGrades]; // creates designated number of grade elements
        inputStudents(students[i], numOfGrades);
    }
    
    cout << "Students Info:" << "\n";
    
    for(int i=0; i<numOfStudents; i++) {
        printStudentInfo(students[i], numOfGrades); // creates designated number of grade elements
    }
    
    return 0;
}
