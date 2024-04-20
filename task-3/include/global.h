#pragma once

#include <string>
#include <vector>
#include <limits>
#include <iostream>
#include <random>
#include <time.h>
#include <queue>

#define NUM_ROWS 3
using namespace std;

enum
{
    ADD = 1,
    DISPLAY = 2,
    REMOVE = 3,
    DISPLAY_BEST = 4,
    EXIT = -1,
    UNIVERSITY = 1,
    COLLEGE = 2,
};

typedef struct student_info_t
{
    string name;
    string schoolName;
    string dayOfBirth;
    string schoolType;
    int numOfSemesters;
    int numOfCourses;
    int numOfAssignments;
    int numOfTests;
    int numOfExams;
    float gpa;
} s_info;

class Student;
class UniStudent;
class ColStudent;
class Institution;