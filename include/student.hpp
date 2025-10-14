#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int studentID;
    int units; // tedad vahed
    float gpa; // moAdel
    int securityCode;
    Student *next; //*parvande bAdi
};

Student *createStudent(const string &name, int id, int units, float gpa, int code);

void addStudent(Student *&head, Student *newStudent);

bool deleteStudent(Student *&head, int id);

Student *searchStudent(Student *head, int id);

bool updateStudent(Student *head, int id, int newUnits, float newGPA);

void displayAll(Student *head);

#endif
