#include <stdio.h>
#include <string.h>

#define SIZE 25
#define NUM_EMP 3

/* definition of an employee record*/
typedef struct employee{
  char fname[20];
  char lname[20];
  int id;
  char dependents [3][20]; // assume that employees have exactly
			   // 3 registered dependents
} Employees;

void printEmployees(Employees[NUM_EMP], int c);
void swapEmployees(Employees*, Employees*);

void printEmployees(Employees employees[NUM_EMP], int c){
  // Print fields of each struct object
  for (int i = 0; i < c; i++){
    printf("\n%s %s %d", employees[i].fname, employees[i].lname, employees[i].id);
    // Print each dependent
    for (int j = 0; j < 3; j++){
      printf(" %s", employees[i].dependents[j]);
    }
  }
}

void swapEmployees(Employees *employee1, Employees *employee2){
  // Keep a temporary file
  Employees employeeHolder = *employee1;

  // Swap the info
  *employee1 = *employee2;
  *employee2 = employeeHolder;
}
