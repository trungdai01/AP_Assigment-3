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

    float getAssignmentScore() const;
    float getTestScore() const;
    float getExamScore() const;
    float getGPA() const;

    void displayInfo() const;
};

class UniStudentFactory : public StudentFactory
{
  public:
    UniStudentFactory();
    ~UniStudentFactory();
    Student* createStudent(string, string, string);
};