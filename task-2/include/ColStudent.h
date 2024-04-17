#pragma once

#include "Student.h"

class ColStudent : public Student
{
  public:
    ColStudent();
    ColStudent(string, string, string);

    ~ColStudent();

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

class ColStudentFactory : public StudentFactory
{
  public:
    ColStudentFactory();
    ~ColStudentFactory();
    Student* createStudent(string, string, string);
};
