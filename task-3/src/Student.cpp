#include "../include/Student.h"

Student::Student() {}
Student::Student(string name, string dayOfBirth)
{
    student.name = name;
    student.dayOfBirth = dayOfBirth;
    scores = vector<vector<int>>(3);
}
Student::~Student() {}

string Student::getName() const
{
    return student.name;
}

string Student::getDayOfBirth() const
{
    return student.dayOfBirth;
}

string Student::getSchoolName() const
{
    return student.schoolName;
}

string Student::getSchoolType() const
{
    return student.schoolType;
}

int Student::getNumOfSemesters() const
{
    return student.numOfSemesters;
}

int Student::getNumOfCourses() const
{
    return student.numOfCourses;
}

int Student::getNumOfAssignments() const
{
    return student.numOfAssignments;
}

int Student::getNumOfTests() const
{
    return student.numOfTests;
}

int Student::getNumOfExams() const
{
    return student.numOfExams;
}

void Student::DoAssignment()
{
    setNumOfAssignments();
    scores[0] = vector<int>(getNumOfAssignments());
    for (auto& score : scores[0])
    {
        score = randomGenerator();
    }
    return;
}

void Student::TakeTest()
{
    setNumOfTests();
    scores[1] = vector<int>(getNumOfTests());
    for (auto& score : scores[1])
    {
        score = randomGenerator();
    }
    return;
}

void Student::TakeExam()
{
    setNumOfExams();
    scores[2] = vector<int>(getNumOfExams());
    for (auto& score : scores[2])
    {
        score = randomGenerator();
    }
    return;
}

void Student::Study()
{
    setNumOfSemesters();
    setNumOfCourses();
    DoAssignment();
    TakeTest();
    TakeExam();
}

float Student::getAssignmentScore() const
{
    int sum = 0;
    for (auto score : scores[0])
    {
        sum += score;
    }
    float avg = ((float)sum / getNumOfAssignments());
    return avg;
}

float Student::getTestScore() const
{
    int sum = 0;
    for (auto score : scores[1])
    {
        sum += score;
    }
    float avg = ((float)sum / getNumOfTests());
    return avg;
}

float Student::getExamScore() const
{
    int sum = 0;
    for (auto score : scores[2])
    {
        sum += score;
    }
    float avg = ((float)sum / getNumOfExams());
    return avg;
}

void Student::setGPA()
{
    float assignmentScore = getAssignmentScore();
    float testScore = getTestScore();
    float examScore = getExamScore();

    student.gpa = (0.2 * assignmentScore) + (0.3 * testScore) + (0.5 * examScore);
}

float Student::getGPA() const
{
    return student.gpa;
}

void Student::displayInfo()
{
    printf("Name: %s\n", getName().c_str());
    printf("Day of birth: %s\n", getDayOfBirth().c_str());
    printf("School name: %s\n", getSchoolName().c_str());
    printf("School type: %s\n", getSchoolType().c_str());
    printf("GPA: %0.2f\n", getGPA());
}

int randomGenerator()
{
    random_device rd;
    mt19937 eng(rd());

    uniform_int_distribution<int> distr(0, 10);
    return distr(eng);
}
