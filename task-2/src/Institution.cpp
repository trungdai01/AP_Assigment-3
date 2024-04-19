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
    for (int i = 0; i < listOfStudents.size(); ++i)
    {
        int it = i;
        printf("%d.\n", ++it);
        listOfStudents[i]->displayInfo();
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
    for (int i = 0; i < listOfStudents.size(); i++)
    {
        if (listOfStudents[i]->getName() == name)
        {
            string type;
            cout << "Enter school type: ";
            getline(cin, type);
            if (type == "-1") return;
            cout << "=======================\n";
            if (listOfStudents[i]->getSchoolType() == type)
            {
                flag = true;
                indexRemove = i;
                printf("Found at index %d\n", indexRemove);
                listOfStudents.erase(listOfStudents.begin() + indexRemove);
                printf("Remove successfully!!!\n");
                break;
            }
        }
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
    for (int i = 0; i < listOfStudents.size(); i++)
    {
        if (listOfStudents[i]->getSchoolType() == "University")
        {
            printf("Name: %s\n", listOfStudents[i]->getName().c_str());
            printf("Day of Birth: %s\n", listOfStudents[i]->getDayOfBirth().c_str());
            printf("School name: %s\n", listOfStudents[i]->getSchoolName().c_str());
            printf("GPA: %0.2f\n", listOfStudents[i]->getGPA());
            break;
        }
    }
    cout << "2. College: \n";
    for (int i = 0; i < listOfStudents.size(); i++)
    {
        if (listOfStudents[i]->getSchoolType() == "College")
        {
            printf("Name: %s\n", listOfStudents[i]->getName().c_str());
            printf("Day of Birth: %s\n", listOfStudents[i]->getDayOfBirth().c_str());
            printf("School name: %s\n", listOfStudents[i]->getSchoolName().c_str());
            printf("GPA: %0.2f\n", listOfStudents[i]->getGPA());
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
