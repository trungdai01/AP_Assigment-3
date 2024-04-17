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

string ColStudent::getName() const
{
    return student.name;
}

string ColStudent::getDayOfBirth() const
{
    return student.dayOfBirth;
}

string ColStudent::getSchoolName() const
{
    return student.schoolName;
}

string ColStudent::getSchoolType() const
{
    return student.schoolType;
}

int ColStudent::getNumOfSemesters() const
{
    return student.numOfSemesters;
}

int ColStudent::getNumOfCourses() const
{
    return student.numOfCourses;
}

int ColStudent::getNumOfAssignments() const
{
    return student.numOfAssignments;
}

int ColStudent::getNumOfTests() const
{
    return student.numOfTests;
}

int ColStudent::getNumOfExams() const
{
    return student.numOfExams;
}

void ColStudent::setGPA()
{
    float assignmentScore = getAssignmentScore();
    float testScore = getTestScore();
    float examScore = getExamScore();

    student.gpa = (0.2 * assignmentScore) + (0.3 * testScore) + (0.5 * examScore);
}

void ColStudent::DoAssignment()
{
    for (int& score : scores[0])
    {
        score = randomGenerator();
    }
    return;
}

void ColStudent::TakeTest()
{
    for (int& score : scores[1])
    {
        score = randomGenerator();
    }
    return;
}

void ColStudent::TakeExam()
{
    for (int& score : scores[2])
    {
        score = randomGenerator();
    }
    return;
}

void ColStudent::Study()
{
    DoAssignment();
    TakeTest();
    TakeExam();
}

float ColStudent::getAssignmentScore() const
{
    int sum = 0;
    for (int score : scores[0])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfAssignments());
    return avg;
}

float ColStudent::getTestScore() const
{
    int sum = 0;
    for (int score : scores[1])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfTests());
    return avg;
}

float ColStudent::getExamScore() const
{
    int sum = 0;
    for (int score : scores[2])
    {
        sum += score;
    }
    float avg = (float)(sum / getNumOfExams());
    return avg;
}

float ColStudent::getGPA() const
{
    return student.gpa;
}

void ColStudent::displayInfo() const
{
    printf("Name: %s\n", getName().c_str());
    printf("Day of birth: %s\n", getDayOfBirth().c_str());
    printf("School name: %s\n", getSchoolName().c_str());
    printf("School type: %s\n", getSchoolType().c_str());
    printf("GPA: %0.2f\n", getGPA());
}

ColStudentFactory::ColStudentFactory() {}
ColStudentFactory::~ColStudentFactory() {}

Student* ColStudentFactory::createStudent(string name, string birthday, string schoolname)
{
    Student* student = new ColStudent(name, birthday, schoolname);
    student->Study();
    student->setGPA();
    return student;
}