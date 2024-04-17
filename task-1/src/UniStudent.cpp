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

string UniStudent::getName() const
{
    return student.name;
}

string UniStudent::getDayOfBirth() const
{
    return student.dayOfBirth;
}

string UniStudent::getSchoolName() const
{
    return student.schoolName;
}

string UniStudent::getSchoolType() const
{
    return student.schoolType;
}

int UniStudent::getNumOfSemesters() const
{
    return student.numOfSemesters;
}

int UniStudent::getNumOfCourses() const
{
    return student.numOfCourses;
}

int UniStudent::getNumOfAssignments() const
{
    return student.numOfAssignments;
}

int UniStudent::getNumOfTests() const
{
    return student.numOfTests;
}

int UniStudent::getNumOfExams() const
{
    return student.numOfExams;
}

void UniStudent::setGPA()
{
    float assignmentScore = getAssignmentScore();
    float testScore = getTestScore();
    float examScore = getExamScore();

    student.gpa = (0.2 * assignmentScore) + (0.3 * testScore) + (0.5 * examScore);
}

void UniStudent::DoAssignment()
{
    for (int i = 0; i < student.numOfAssignments; i++)
    {
        scores[0][i] = randomGenerator();
    }
    return;
}

void UniStudent::TakeTest()
{
    for (int i = 0; i < student.numOfTests; i++)
    {
        scores[1][i] = randomGenerator();
    }
    return;
}

void UniStudent::TakeExam()
{
    for (int i = 0; i < student.numOfExams; i++)
    {
        scores[2][i] = randomGenerator();
    }
    return;
}

void UniStudent::Study()
{
    DoAssignment();
    TakeTest();
    TakeExam();
}

float UniStudent::getAssignmentScore()
{
    int sum = 0;
    for (int i = 0; i < student.numOfAssignments; i++)
    {
        sum += scores[0][i];
    }
    float avg = (float)(sum / getNumOfAssignments());
    return avg;
}

float UniStudent::getTestScore()
{
    int sum = 0;
    for (int i = 0; i < student.numOfTests; i++)
    {
        sum += scores[1][i];
    }
    float avg = (float)(sum / getNumOfTests());
    return avg;
}

float UniStudent::getExamScore()
{
    int sum = 0;
    for (int i = 0; i < student.numOfExams; i++)
    {
        sum += scores[2][i];
    }
    float avg = (float)(sum / getNumOfExams());
    return avg;
}

float UniStudent::getGPA()
{
    return student.gpa;
}
