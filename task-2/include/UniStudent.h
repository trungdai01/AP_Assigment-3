#pragma once

#include "Student.h"

class UniStudent : public Student
{
  public:
    UniStudent();
    UniStudent(string, string, string);

    ~UniStudent();

    string getName() const;
    string getDayOfBirth() const;
    string getSchoolName() const;
    string getSchoolType() const;
    int getNumOfSemesters() const;
    int getNumOfCourses() const;
    int getNumOfAssignments() const;
    int getNumOfTests() const;
    int getNumOfExams() const;

    void setGPA();

    void DoAssignment();
    void TakeTest();
    void TakeExam();

    void Study();

    float getAssignmentScore();
    float getTestScore();
    float getExamScore();
    float getGPA();

    void displayInfo();
};

class UniStudentFactory : public StudentFactory
{
  public:
    UniStudentFactory();
    ~UniStudentFactory();
    Student* createStudent(string, string, string);
};