#include "../include/ColStudent.h"

ColStudent::ColStudent() {}
ColStudent::ColStudent(string name, string dayOfBirth, string schoolName) : Student(name, dayOfBirth)
{
    student.schoolName = schoolName;
    student.schoolType = "College";
}

ColStudent::~ColStudent() {}

void ColStudent::setNumOfSemesters()
{
    student.numOfSemesters = 4;
}

void ColStudent::setNumOfCourses()
{
    student.numOfCourses = getNumOfSemesters() * 3;
}

void ColStudent::setNumOfAssignments()
{
    student.numOfAssignments = getNumOfCourses() * 1;
}

void ColStudent::setNumOfTests()
{
    student.numOfTests = getNumOfCourses() * 1;
}

void ColStudent::setNumOfExams()
{
    student.numOfExams = getNumOfCourses() * 1;
}

void ColStudent::DoAssignment()
{
    setNumOfAssignments();
    scores[0] = vector<int>(getNumOfAssignments());
    for (int& score : scores[0])
    {
        score = randomGenerator();
    }
    return;
}

void ColStudent::TakeTest()
{
    setNumOfTests();
    scores[1] = vector<int>(getNumOfTests());
    for (int& score : scores[1])
    {
        score = randomGenerator();
    }
    return;
}

void ColStudent::TakeExam()
{
    setNumOfExams();
    scores[2] = vector<int>(getNumOfExams());
    for (int& score : scores[2])
    {
        score = randomGenerator();
    }
    return;
}

Student* College::createStudent(string name, string birthday, string schoolName)
{
    Student* student = new ColStudent(name, birthday, schoolName);
    student->Study();
    student->setGPA();
    return student;
}