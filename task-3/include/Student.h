#pragma once

#include "global.h"
class Student
{
  protected:
    s_info student;
    vector<vector<int>> scores;

  public:
    Student();
    Student(string, string);
    virtual ~Student();

    string getName() const;
    string getDayOfBirth() const;
    string getSchoolName() const;
    string getSchoolType() const;
    int getNumOfSemesters() const;
    int getNumOfCourses() const;
    int getNumOfAssignments() const;
    int getNumOfTests() const;
    int getNumOfExams() const;

    virtual void setNumOfSemesters() = 0;
    virtual void setNumOfCourses() = 0;
    virtual void setNumOfAssignments() = 0;
    virtual void setNumOfTests() = 0;
    virtual void setNumOfExams() = 0;

    void DoAssignment();
    void TakeTest();
    void TakeExam();

    void Study();

    float getAssignmentScore() const;
    float getTestScore() const;
    float getExamScore() const;
    void setGPA();
    float getGPA() const;

    void displayInfo();
};

int randomGenerator();

class School
{
  public:
    virtual Student* createStudent(string, string, string) = 0;
};
