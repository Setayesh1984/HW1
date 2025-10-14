#include "student.hpp"
#include <iostream>
using namespace std;

Student* createStudent(const string& name, int id, int units, float gpa, int code) {
    Student* newStudent = new Student; 
    newStudent->name = name;
    newStudent->studentID = id;
    newStudent->units = units;
    newStudent->gpa = gpa;
    newStudent->securityCode = code;
    newStudent->next = nullptr; //new account = nullptr
    return newStudent;
}

void addStudent(Student*& head, Student* newStudent) {
    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; 
        }
        temp->next = newStudent;
    }
}

Student* searchStudent(Student* head, int id) {
    Student* current = head;
    while (current != nullptr) {
        if (current->studentID == id) {
            return current; 
        }
        current = current->next;
    }
    return nullptr;
}

bool updateStudent(Student* head, int id, int newUnits, float newGPA) {
    Student* target = searchStudent(head, id);
    if (target == nullptr) return false; 
    target->units = newUnits;
    target->gpa = newGPA;
    return true;
}

void displayAll(Student* head) {
    if (head == nullptr) {
        cout << "The file list is empty." << endl;
        return;
    }

    Student* current = head;
    cout << "\n===== List of student files=====" << endl;
    while (current != nullptr) {
        cout << "ٔName :" << current->name << endl;
        cout << "Student ID: " << current->studentID << endl;
        cout << "Units: " << current->units << endl;
        cout << "GPA " << current->gpa << endl;
        cout << "SecurityCode:" << current->securityCode << endl;
        cout << "-----------------------------" << endl;
        current = current->next;
    }
}

bool deleteStudent(Student*& head, int id) {
    if (head == nullptr) return false; 

    // اگر گره اول باید حذف شود
    if (head->studentID == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // در غیر این صورت باید گره مورد نظر را پیدا کنیم
    Student* current = head;
    while (current->next != nullptr && current->next->studentID != id) {
        current = current->next;
    }

    if (current->next == nullptr) return false; // پیدا نشد

    Student* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}
