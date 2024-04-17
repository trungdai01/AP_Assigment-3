#include "../include/Student.h"

Student::Student() {}
Student::Student(string name, string dayOfBirth)
{
    student.name = name;
    student.dayOfBirth = dayOfBirth;
    scores = vector<vector<int>>(3);
}
Student::~Student() {}

int Student::randomGenerator()
{
    srand(time(NULL));
    int random = rand();
    return (random % 10) + 1;
}