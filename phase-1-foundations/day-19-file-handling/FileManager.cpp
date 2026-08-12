#include "FileManager.h"
#include <fstream>
#include<iostream>

/*  Save all the Students*/

bool FileManager::saveStudents(const std::vector<Student>& students, const std::string& filename){
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cout << "Error : Unable to open the file." << std::endl;
        return false;
    }
    for(const Student& student : students)
    {
        file << student.getId() << " "
        <<student.getName() << " "
        << student.getMarks()
        << std::endl;
    }
    file.close();
    return true;
}

/* Append one Student*/

bool FileManager::appendStudent(const Student& student, const std::string& filename){
    std::ofstream file(filename, std::ios::app);

    if(!file.is_open()){
        std::cout << "Error: Unable to open the file." << std::endl;
        return false;
    }
    file << student.getId() << " "
    << student.getName() << " "
    << student.getMarks()
    << std::endl;
    file.close();
    return true;
}

/* Load the Students*/

std::vector<Student> FileManager::loadStudents(const std::string& filename){
    std::vector<Student> students;
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cout << "Error: Unable to open file." << std::endl;
        return students;
    }
    int id;
    std::string name;
    double marks;
    while (file>> id >> name >> marks){
        Student student(id,name, marks);
        students.push_back(student);
    }
    file.close();
    return students;
}