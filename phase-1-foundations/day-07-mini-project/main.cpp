#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    int rollNo;
    int marks;
};

vector<Student> students;

// Update Student

void updateStudent(){
    int roll;
    cout << "Enter Roll Number of Student to Update: ";
    cin >> roll;
    for(auto& s : students)
    {
        if(s.rollNo == roll)
        {
            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Marks: ";
            cin >> s.marks;

            cout << "Student Updated Successfully\n";
            return;
        }
    }
    cout << "Student Not Found\n";
}
// Sort Students by Marks
void sortStudentsByMarks()
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks; // Sort in descending order
    });
    cout << "Students Sorted by Marks Successfully\n";
}
// Show Topper
void showTopper()
{
    if(students.empty())
    {
        cout << "No Students Found\n";
        return;
    }

    auto topper = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks < b.marks;
    });

    cout << "Topper: " << topper->name << " with Marks: " << topper->marks << endl;
}
// Calculate Average Marks
double calculateAverageMarks()
{
    if(students.empty())
    {
        return 0;
    }

    int totalMarks = 0;
    for(const auto& s : students)
    {
        totalMarks += s.marks;
    }

    return static_cast<double>(totalMarks) / students.size();
}
//Update Student

void addStudent()
{
    Student s;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "Student Added Successfully\n";
}

void viewStudents()
{
    if(students.empty())
    {
        cout << "No Students Found\n";
        return;
    }

    for(const auto& s : students)
    {
        cout << "\nName: " << s.name;
        cout << "\nRoll No: " << s.rollNo;
        cout << "\nMarks: " << s.marks;
        cout << "\n-----------------\n";
    }
}


void searchStudent()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    for(const auto& s : students)
    {
        if(s.rollNo == roll)
        {
            cout << "\nStudent Found\n";
            cout << s.name << endl;
            cout << s.marks << endl;
            return;
        }
    }

    cout << "Student Not Found\n";
}

void deleteStudent()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    for(auto it = students.begin();
        it != students.end();
        ++it)
    {
        if(it->rollNo == roll)
        {
            students.erase(it);

            cout << "Deleted Successfully\n";
            return;
        }
    }

    cout << "Student Not Found\n";
}

void menu()
{
    cout << "\n===== Student Management System =====\n";

    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Update Student\n";
    cout << "4. Search Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";

    cout << "Enter Choice: ";
}

int main()
{
    int choice;

    while(true)
    {
        menu();

        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "Goodbye\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}