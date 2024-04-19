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

Student* University::createStudent(string name, string birthday, string schoolName)
{
    Student* student = new UniStudent(name, birthday, schoolName);
    student->Study();
    student->setGPA();
    return student;
}