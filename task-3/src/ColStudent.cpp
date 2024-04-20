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

Student* College::createStudent(string name, string birthday, string schoolName)
{
    Student* student = new ColStudent(name, birthday, schoolName);
    student->Study();
    student->setGPA();
    return student;
}