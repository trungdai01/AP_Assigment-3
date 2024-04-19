#include "../include/UniStudent.h"

UniStudent::UniStudent() : Student() {}
UniStudent::UniStudent(string name, string dayOfBirth, string schoolName) : Student(name, dayOfBirth)
{
    student.schoolName = schoolName;
    student.schoolType = "University";
    student.numOfSemesters = 8;
    student.numOfCourses = student.numOfSemesters * 4;
    student.numOfAssignments = student.numOfCourses * 3;
    student.numOfTests = student.numOfCourses * 2;
    student.numOfExams = student.numOfCourses * 1;
    scores[0] = vector<int>(student.numOfAssignments);
    scores[1] = vector<int>(student.numOfTests);
    scores[2] = vector<int>(student.numOfExams);
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
