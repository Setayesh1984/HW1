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
        cout << "\n========== Student file management menu ==========" << endl;
        cout << "1. Add new file" << endl;
        cout << "2. Delete file" << endl;
        cout << "3. File search" << endl;
        cout << "4. Update GPA and credits" << endl;
        cout << "5. Show all files" << endl;
        cout << "6. Exit" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            string name;
            long long id;
            int units, code;
            float gpa;

            cout << "\n--- Add new file ---" << endl;
            cout << "Student Name: ";
            getline(cin, name);
            cout << "Student ID (up to 11 digits): ";
            cin >> id;
            cout << "Number of units: ";
            cin >> units;
            cout << "GPA: ";
            cin >> gpa;
            cout << "Security code (any 4 digits): ";
            cin >> code;

            Student *newStu = createStudent(name, id, units, gpa, code);
            addStudent(head, newStu);
            cout << " File added successfully!" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 2)
        {
            cout << "\n--- Delete file ---" << endl;
            long long id;
            cout << "Student number in question: ";
            cin >> id;

            if (deleteStudent(head, id))
                cout << " The file was successfully deleted." << endl;
            else
                cout << " No file with this number was found." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 3)
        {
            cout << "\n--- File search ---" << endl;
            long long id;
            cout << "Student number in question: ";
            cin >> id;

            Student *found = searchStudent(head, id);
            if (found != nullptr)
            {
                cout << "\n File found:" << endl;
                cout << "Name: " << found->name << endl;
                cout << "Student ID: " << found->studentID << endl;
                cout << "Units: " << found->units << endl;
                cout << "GPA: " << found->gpa << endl;
                cout << "Security Code: " << found->securityCode << endl;
            }
            else
            {
                cout << " No file with this number was found." << endl;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 4)
        {
            cout << "\n--- Update GPA and credits ---" << endl;
            long long id;
            int units;
            float gpa;
            cout << "Student number in question: ";
            cin >> id;
            cout << "New number of units: ";
            cin >> units;
            cout << "New GPA: ";
            cin >> gpa;

            if (updateStudent(head, id, units, gpa))
                cout << " File updated successfully." << endl;
            else
                cout << " No file with this number was found." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 5)
        {
            cout << "\n--- Show all files ---" << endl;
            displayAll(head);
        }
        else if (choice == 6)
        {
            cout << "\n Goodbye! Data will be freed from memory..." << endl;
        }
        else
        {
            cout << " Invalid option, please try again." << endl;
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
