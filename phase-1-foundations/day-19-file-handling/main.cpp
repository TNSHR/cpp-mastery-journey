#include <iostream>
#include <vector>

#include "Student.h"
#include "FileManager.h"

using namespace std;

int main()
{
    cout << "===================================" << endl;
    cout << " Student File Management System" << endl;
    cout << "===================================" << endl;

    // Create Student Objects
    Student student1(101, "Shrinath", 95.5);
    Student student2(102, "Rahul", 89.0);
    Student student3(103, "Priya", 91.5);

    // Store Students in a Vector
    vector<Student> students;

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    FileManager fileManager;

    // Save Students
    if(fileManager.saveStudents(students, "students.txt"))
    {
        cout << "\nStudents saved successfully.\n";
    }
    else
    {
        cout << "\nFailed to save students.\n";
    }

    // Append New Student
    Student student4(104, "Amit", 88.5);

    if(fileManager.appendStudent(student4, "students.txt"))
    {
        cout << "New student appended successfully.\n";
    }
    else
    {
        cout << "Failed to append student.\n";
    }

    // Read Students
    vector<Student> loadedStudents =
        fileManager.loadStudents("students.txt");

    cout << "\n========== Student Records ==========\n";

    for(const Student &student : loadedStudents)
    {
        cout << "ID    : "
             << student.getId()
             << endl;

        cout << "Name  : "
             << student.getName()
             << endl;

        cout << "Marks : "
             << student.getMarks()
             << endl;

        cout << "------------------------------"
             << endl;
    }

    cout << "\nProgram Finished Successfully."
         << endl;

    return 0;
}