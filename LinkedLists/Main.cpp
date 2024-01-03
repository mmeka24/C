

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

/*
function prototypes if neccessary
void (add ); 
void (deletes ); 
void (print ); 
void (average ); */

void add(Node* cur, Node* prev, Node* &head);
void print(Node* next);
float getAvg(Node* current, int total);
void remove(Node* &head, Node* current, Node* prev,  int studentID, int &total);



void add(Node* newNode, Node* cur, Node* prev, Node* &head) {
  if (cur == NULL) {
    //checking if the current node is null 
    if (prev == NULL) {
      //checking if the previous node is null so llist is empty
      //if empty head is the newNode
      head = newNode;
    } else{
      //if 
      prev->setNext(newNode);
    }
    return;
  }
  if(newNode->getStudent()->getStudentID() < cur->getStudent()->getStudentID()) {
    newNode->setNext(cur);
    if (prev != NULL) {
      prev->setNext(newNode);
    } else {
      head = newNode;
    }
  } else {
    add(newNode, cur->getNext(), cur, head);
  }
}


float getAvg(Node* current, int total){
  if (current == NULL) {
    return 0;
  }
  return current->getStudent()->getGPA()/total + getAvg(current->getNext(), total);

}


void print(Node* next){
  if (next == NULL) {
    return;
  }
  Student* cur = next->getStudent();
  cout << cur->getStudentID() << "\n";
  cout << cur->getGPA() << "\n";
  print(next->getNext());
}


void remove(Node* &head, Node* current, Node* prev, int studentID, int &total) {
  if (current == NULL) {
    return;
  }
  if (current->getStudent()->getStudentID() == studentID) {
    if (prev != NULL) {
      prev->getNext()->setNext(current->getNext());
    } else {
      head = NULL;;
    }
    total--;

    delete current;
  } else {
    remove(head, current->getNext(), prev, studentID, total);
  }
}



int main() {
  int total = 0;
  char inp[20];
  char first[20];
  char last[20];
  char input[10]; 
  int id; 
  Node* head = NULL; 
  bool running = true; 
  while(running){
    cout << "what would you like to do: add, print, delete, or avg? " << endl; 
    cin >> inp; 
    if(strcmp(inp, "add") == 0){
      
        //id
      cout << "ID: " ;
      int studentID;
      cin >> studentID;
      //first name
      cout << "First Name:" ;
         cin.getline(first, 81);
         

      //last name
      cout << "Last Name: " ;
         cin.getline(last, 81);

      //gpa
      cout << "GPA: " << endl ;
      float GPA; 
      cin >> GPA;
      Student* student = new Student(first, last, studentID, GPA);
      add(new Node(student), head, NULL, head);
      total += 1;

    }
    //print
    else if(strcmp(inp,"print") == 0) {
                print(head);
    }
    //avg 
    else if(strcmp(inp,"avg") == 0) {
		cout << "The average gpa is: " << getAvg(head, total) << endl;
		}

//deleting
else if(strcmp(inp,"delete") == 0) { 
			cout << "Enter the id of the student you would like to delete" << endl;
			int studentID; 
      cin >> studentID;
			Node* current = head;
			remove(head, current, NULL , studentID, total);
      

		} 

  //quit
    else if (strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }

  


}


