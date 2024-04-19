#include "../include/ColStudent.h"

ColStudent::ColStudent() {}
ColStudent::ColStudent(string name, string dayOfBirth, string schoolName) : Student(name, dayOfBirth)
{
    student.schoolName = schoolName;
    student.schoolType = "College";
    student.numOfSemesters = 4;
    student.numOfCourses = student.numOfSemesters * 3;
    student.numOfAssignments = student.numOfCourses * 1;
    student.numOfTests = student.numOfCourses * 1;
    student.numOfExams = student.numOfCourses * 1;
    scores[0] = vector<int>(student.numOfAssignments);
    scores[1] = vector<int>(student.numOfTests);
    scores[2] = vector<int>(student.numOfExams);
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