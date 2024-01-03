#include <iostream>
#include "Student.h"

using namespace std;
//getters for student
//return functions from Student.h
Student::Student(char* f, char* l, int id, float gpa) {
  strcpy(f, firstName);
  strcpy(l, lastName);
  studentID = id;
  GPA = gpa;
}


char* Student::getFirstName() {
  return firstName;

}

char* Student::getLastName() {
  return lastName;
  
}

int Student::getStudentID() {
  return studentID;
}

float Student:: getGPA() {
  return GPA;

}
