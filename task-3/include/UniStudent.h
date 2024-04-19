#pragma once

#include "Student.h"

class UniStudent : public Student
{
  public:
    UniStudent();
    UniStudent(string, string, string);

    ~UniStudent();

    void setNumOfSemesters();
    void setNumOfCourses();
    void setNumOfAssignments();
    void setNumOfTests();
    void setNumOfExams();

    void DoAssignment();
    void TakeTest();
    void TakeExam();
};

class University : public School
{
  public:
    Student* createStudent(string, string, string);
};