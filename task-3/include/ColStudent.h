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

    void DoAssignment();
    void TakeTest();
    void TakeExam();

    void Study();

    float getAssignmentScore() const;
    float getTestScore() const;
    float getExamScore() const;
    void setGPA();
    float getGPA() const;

    void displayInfo() const;
};

class ColStudentFactory : public StudentFactory
{
  public:
    Student* createStudent(string, string, string);
};
