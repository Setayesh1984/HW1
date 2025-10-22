#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
using namespace std;

struct Student
{
    string name;
    long long studentID;
    int units; // tedad vahed
    float gpa; // moAdel
    int securityCode;
    Student *next; //*parvande bAdi
};

Student *createStudent(const string &name, long long id, int units, float gpa, int code);

bool addStudent(Student *&head, Student *newStudent);

bool deleteStudent(Student *&head, long long id);

Student *searchStudent(Student *head, long long id);

bool updateStudent(Student *head, long long id, int newUnits, float newGPA);

void displayAll(Student *head);

bool existsByID(Student *head, long long id);

bool existsByCode(Student *head, int code);


#endif
