#pragma once

#include "UniStudent.h"
#include "ColStudent.h"

class Institution
{
  private:
    vector<Student*> listOfStudents;
    University* uniStudent;
    College* colStudent;

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