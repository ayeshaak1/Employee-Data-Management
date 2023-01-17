#include <stdio.h>
#include <string.h>

#define SIZE 25
#define NUM_EMP 3

typedef struct employee{
  char fname[20];
  char lname[20];
  int id;
  char dependents [3][20]; // assume that employees have exactly
			   // 3 registered dependents
} Employees;

void saveEmployees (Employees [NUM_EMP], int c, char [SIZE]);
int loadEmployees (Employees [NUM_EMP], char [SIZE]);
void printEmployees(Employees[NUM_EMP], int c);
void swapEmployee(Employees*, Employees*);

int main(int argc, char *argv[]){
  Employees employee1, employee2;

  // Employee objects
  strcpy(employee1.fname, "Ayesha");
  strcpy(employee1.lname, "Khan");
  employee1.id = 0001;
  strcpy(employee1.dependents[0], "dep1");
  strcpy(employee1.dependents[1], "dep2");
  strcpy(employee1.dependents[2], "dep3");

  strcpy(employee2.fname, "ayesha");
  strcpy(employee2.lname, "khan");
  employee2.id = 0002;
  strcpy(employee2.dependents[0], "depe1");
  strcpy(employee2.dependents[1], "depe2");
  strcpy(employee2.dependents[2], "depe3");

  // Employee array with objects
  Employees employeeArray[3];
  employeeArray[0] = employee1;
  employeeArray[1] = employee2;

  saveEmployees(employeeArray, 2, argv[1]);
  loadEmployees(employeeArray, argv[1]);
  printEmployees(employeeArray, 2);

  return 0;
}
