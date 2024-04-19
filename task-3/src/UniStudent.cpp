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

void UniStudent::DoAssignment()
{
    for (int& score : scores[0])
    {
        score = randomGenerator();
    }
    return;
}

void UniStudent::TakeTest()
{
    for (int& score : scores[1])
    {
        score = randomGenerator();
    }
    return;
}

void UniStudent::TakeExam()
{
    for (int& score : scores[2])
    {
        score = randomGenerator();
    }
    return;
}

void UniStudent::Study()
{
    DoAssignment();
    TakeTest();
    TakeExam();
}

float UniStudent::getAssignmentScore() const
{
    int sum = 0;
    for (int score : scores[0])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfAssignments());
    return avg;
}

float UniStudent::getTestScore() const
{
    int sum = 0;
    for (int score : scores[1])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfTests());
    return avg;
}

float UniStudent::getExamScore() const
{
    int sum = 0;
    for (int score : scores[2])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfExams());
    return avg;
}

void UniStudent::setGPA()
{
    float assignmentScore = getAssignmentScore();
    float testScore = getTestScore();
    float examScore = getExamScore();

    student.gpa = (0.2 * assignmentScore) + (0.3 * testScore) + (0.5 * examScore);
}

float UniStudent::getGPA() const
{
    return student.gpa;
}

void UniStudent::displayInfo() const
{
    printf("Name: %s\n", getName().c_str());
    printf("Day of birth: %s\n", getDayOfBirth().c_str());
    printf("School name: %s\n", getSchoolName().c_str());
    printf("School type: %s\n", getSchoolType().c_str());
    printf("Assignment: %0.2f\n", getAssignmentScore());
    printf("GPA: %0.2f\n", getGPA());
}

Student* UniStudentFactory::createStudent(string name, string birthday, string schoolName)
{
    Student* student = new UniStudent(name, birthday, schoolName);
    student->Study();
    student->setGPA();
    return student;
}