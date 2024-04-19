#include "../include/UniStudent.h"

UniStudent::UniStudent() : Student() {}
UniStudent::UniStudent(string name, string dayOfBirth, string schoolName) : Student(name, dayOfBirth)
{
    student.schoolName = schoolName;
    student.schoolType = "University";
}

UniStudent::~UniStudent() {}

void UniStudent::setNumOfSemesters()
{
    student.numOfSemesters = 8;
}

void UniStudent::setNumOfCourses()
{
    student.numOfCourses = getNumOfSemesters() * 4;
}

void UniStudent::setNumOfAssignments()
{
    student.numOfAssignments = getNumOfCourses() * 3;
}

void UniStudent::setNumOfTests()
{
    student.numOfTests = getNumOfCourses() * 2;
}

void UniStudent::setNumOfExams()
{
    student.numOfExams = getNumOfCourses() * 1;
}

void UniStudent::DoAssignment()
{
    setNumOfAssignments();
    scores[0] = vector<int>(getNumOfAssignments());
    for (int& score : scores[0])
    {
        score = randomGenerator();
    }
    return;
}

void UniStudent::TakeTest()
{
    setNumOfTests();
    scores[1] = vector<int>(getNumOfTests());
    for (int& score : scores[1])
    {
        score = randomGenerator();
    }
    return;
}

void UniStudent::TakeExam()
{
    setNumOfExams();
    scores[2] = vector<int>(getNumOfExams());
    for (int& score : scores[2])
    {
        score = randomGenerator();
    }
    return;
}

Student* University::createStudent(string name, string birthday, string schoolName)
{
    Student* student = new UniStudent(name, birthday, schoolName);
    student->Study();
    student->setGPA();
    return student;
}