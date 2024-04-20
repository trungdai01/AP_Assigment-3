#pragma once

#include "UniStudent.h"
#include "ColStudent.h"

class Institution
{
  private:
    vector<Student*> listOfStudents;
    University* university;
    College* college;

  private:
    void sortGPA();

  public:
    Institution();
    ~Institution();

    void addStudent();
    void addStudent(string, string, string, int);
    void addUniStudent(string, string, string);
    void addColStudent(string, string, string);
    void displayInfo();
    void removeStudent();
    void displayBestStudent();
};