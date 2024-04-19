#include "../include/Institution.h"

Institution::Institution()
{
    uniStudent = new University();
    colStudent = new College();
}
Institution::~Institution() {}

void Institution::addStudent()
{
    cin.ignore();
    cout << "Enter a name: ";
    string name;
    getline(cin, name);
    if (name == "-1") return;

    cout << "Enter day of birth: ";
    string dayOfBirth;
    getline(cin, dayOfBirth);
    if (dayOfBirth == "-1") return;

    cout << "Enter a school name: ";
    string schoolName;
    getline(cin, schoolName);
    if (schoolName == "-1") return;

    cout << "1. University\n2. College\n";
    int schoolType;
    do {
        cout << "Enter a number between " << 1 << " and " << 2 << ": ";
        cin >> schoolType;
    } while (schoolType != 1 && schoolType != 2);
    cin.ignore();

    Student* student;
    if (schoolType == 1)
    {
        student = uniStudent->createStudent(name, dayOfBirth, schoolName);
    }
    else if (schoolType == 2)
    {
        student = colStudent->createStudent(name, dayOfBirth, schoolName);
    }
    else if (schoolType == -1)
        return;
    listOfStudents.push_back(student);
}

void Institution::displayInfo()
{
    if (listOfStudents.empty() == true)
    {
        cout << " .. The list is empty!!!\n";
        cout << "=======================\n";
        return;
    }
    cout << "Current size: " << listOfStudents.size() << endl;
    cout << "=======================\n";
    int index = 0;
    for (Student* student : listOfStudents)
    {
        printf("%d.\n", ++index);
        student->displayInfo();
    }
}

void Institution::removeStudent()
{
    cin.ignore();
    bool flag = false;
    if (listOfStudents.size() == 0)
    {
        cout << " .. The list is empty!!!\n";
        return;
    }
    string name;
    cout << "Enter a name you want to remove from the list: ";
    getline(cin, name);
    if (name == "-1") return;
    int indexRemove = 0;
    for (auto it = listOfStudents.begin(); it != listOfStudents.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            string type;
            cout << "Enter school type: ";
            getline(cin, type);
            if (type == "-1") return;
            cout << "=======================\n";
            if ((*it)->getSchoolType() == type)
            {
                flag = true;
                printf("Found at index %d\n", indexRemove);
                listOfStudents.erase(it);
                printf("Remove successfully!!!\n");
                break;
            }
        }
        indexRemove++;
    }
    if (!flag) cout << "Not found in the list\n";
    return;
}

void Institution::displayBestStudent()
{
    if (listOfStudents.size() == 0)
    {
        cout << "... The list is empty!!!\n";
        return;
    }
    sortGPA();
    cout << "1. University: \n";
    for (auto uni_student : listOfStudents)
    {
        if (uni_student->getSchoolType() == "University")
        {
            printf("Name: %s\n", uni_student->getName().c_str());
            printf("Day of Birth: %s\n", uni_student->getDayOfBirth().c_str());
            printf("School name: %s\n", uni_student->getSchoolName().c_str());
            printf("GPA: %0.2f\n", uni_student->getGPA());
            break;
        }
    }
    cout << "2. College: \n";
    for (auto col_student : listOfStudents)
    {
        if (col_student->getSchoolType() == "College")
        {
            printf("Name: %s\n", col_student->getName().c_str());
            printf("Day of Birth: %s\n", col_student->getDayOfBirth().c_str());
            printf("School name: %s\n", col_student->getSchoolName().c_str());
            printf("GPA: %0.2f\n", col_student->getGPA());
            break;
        }
    }
}

void Institution::sortGPA()
{
    int n = listOfStudents.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (listOfStudents[j]->getGPA() < listOfStudents[j + 1]->getGPA())
            {
                swap(listOfStudents[j], listOfStudents[j + 1]);
            }
        }
    }
}
