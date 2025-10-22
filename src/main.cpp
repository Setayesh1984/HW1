#include "student.hpp"
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    Student *head = nullptr;
    int choice;

    do
    {
        cout << "\n************ Student file management menu ************" << endl;
        cout << "1. Add new file                                        *" << endl;
        cout << "2. Delete file                                         *" << endl;
        cout << "3. File search                                         *" << endl;
        cout << "4. Update GPA and credits                              *" << endl;
        cout << "5. Show all files                                      *" << endl;
        cout << "6. Exit                                                *" << endl;
        cout << "********************************************************" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            string name;
            long long id;
            int units, code;
            float gpa;

            cout << "\n=== Add new file ===" << endl;
            cout << "Student Name: ";
            getline(cin, name);

            cout << "Student ID (up to 11 digits): ";
            cin >> id;
            while (cin.fail() || id <= 0 || existsByID(head, id))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (existsByID(head, id))
                    cout << "This student ID already exists. Please enter a new one: ";
                else
                    cout << "Invalid ID. Please enter a positive number: ";

                cin >> id;
            }

            cout << "Number of units (0 - 25): ";
            cin >> units;
            while (cin.fail() || units < 0 || units > 25)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number of units (0 - 25 allowed). Enter again: ";
                cin >> units;
            }

            cout << "GPA (0 - 20): ";
            cin >> gpa;
            while (cin.fail() || gpa < 0 || gpa > 20)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid GPA. Must be between 0 and 20. Enter again: ";
                cin >> gpa;
            }

            cout << "Security code (4 digits): ";
            cin >> code;
            while (cin.fail() || code < 1000 || code > 9999 || existsByCode(head, code))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (existsByCode(head, code))
                    cout << "This security code already exists. Please enter a different one: ";
                else
                    cout << "Invalid security code (must be 4 digits). Enter again: ";

                cin >> code;
            }

            Student *newStu = createStudent(name, id, units, gpa, code);
            addStudent(head, newStu);
            cout << "File added successfully!" << endl;
        }

        else if (choice == 2)
        {
            cout << "\n=== Delete file ===" << endl;
            long long id;
            cout << "Student number in question: ";
            cin >> id;

            while (cin.fail() || id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a positive number: ";
                cin >> id;
            }

            if (deleteStudent(head, id))
                cout << "The file was successfully deleted." << endl;
            else
                cout << "No file with this number was found." << endl;
        }

        else if (choice == 3)
        {
            cout << "\n=== File search ===" << endl;
            long long id;
            cout << "Student number in question: ";
            cin >> id;

            while (cin.fail() || id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a positive number: ";
                cin >> id;
            }

            Student *found = searchStudent(head, id);
            if (found != nullptr)
            {
                cout << "\nFile found:" << endl;
                cout << "Name: " << found->name << endl;
                cout << "Student ID: " << found->studentID << endl;
                cout << "Units: " << found->units << endl;
                cout << "GPA: " << found->gpa << endl;
                cout << "Security Code: " << found->securityCode << endl;
            }
            else
            {
                cout << "No file with this number was found." << endl;
            }
        }

        else if (choice == 4)
        {
            cout << "\n=== Update GPA and credits ===" << endl;
            long long id;
            int units;
            float gpa;

            cout << "Student number in question: ";
            cin >> id;
            while (cin.fail() || id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID. Please enter a positive number: ";
                cin >> id;
            }

            cout << "New number of units (0 - 25): ";
            cin >> units;
            while (cin.fail() || units < 0 || units > 25)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number of units. Enter again (0 - 25): ";
                cin >> units;
            }

            cout << "New GPA (0 - 20): ";
            cin >> gpa;
            while (cin.fail() || gpa < 0 || gpa > 20)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << " Invalid GPA. Enter again (0 - 20): ";
                cin >> gpa;
            }

            if (updateStudent(head, id, units, gpa))
                cout << "File updated successfully." << endl;
            else
                cout << "No file with this number was found." << endl;
        }

        else if (choice == 5)
        {
            cout << "\n=== Show all files ===" << endl;
            displayAll(head);
        }

        else if (choice == 6)
        {
            cout << "\n Thanks for using this system! Data will be freed from memory..." << endl;
        }

    } while (choice != 6);

    while (head != nullptr)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
