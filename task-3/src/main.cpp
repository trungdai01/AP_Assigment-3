#include "../include/Institution.h"

int main()
{
    Institution ins;
    while (1)
    {
        int choice;
        cout << "=======================\n";
        cout << "1. Add a student\n";
        cout << "2. Display student list\n";
        cout << "3. Remove a student\n";
        cout << "4. Display best students\n";
        cout << "-1. Exit menu\n";
        cout << "Enter your choice here: ";

        if (!(cin >> choice))
        {
            cout << "=======================\n";
            cout << "... Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "=======================\n";
        switch (choice)
        {
            case ADD:
                ins.addStudent();
                break;
            case DISPLAY:
                ins.displayInfo();
                break;
            case REMOVE:
                ins.removeStudent();
                break;
            case DISPLAY_BEST:
                ins.displayBestStudent();
                break;
            case EXIT:
                return 0;
            default:
                cout << "\n ..... Invalid choice, retry please!\n\n";
                break;
        }
    }
    return 0;
}