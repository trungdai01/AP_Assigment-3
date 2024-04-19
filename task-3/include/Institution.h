#pragma once

#include "UniStudent.h"
#include "ColStudent.h"

class Institution
{
  private:
    vector<Student*> listOfStudents;
    UniStudentFactory* unistudentFactory;
    ColStudentFactory* colstudentFactory;

  private:
    void sortGPA();

  public:
    Institution();
    ~Institution();

    void addStudent();
    void displayInfo();
    void removeStudent();
    void displayBestStudent();
};