#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include<vector>
#include<string>
#include "Student.h"

class FileManager{
    public:
      bool saveStudents(const std::vector<Student>& students,
    const std::string& filename);
      bool appendStudent(const Student& student, const std::string& filename);
      bool deleteStudent(const Student& student, const std::string& filename);

      std::vector<Student>loadStudents(const std::string& filename);

};

#endif
