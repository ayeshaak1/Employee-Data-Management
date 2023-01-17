#include <stdio.h>
#include <string.h>

#define SIZE 25
#define NUM_EMP 3

/* definition of an employee record*/
typedef struct employee
{
   char fname[20];
   char lname[20];
   int id;
   char dependents[3][20]; // assume that no employees can have more
			   // than 3 registered dependents
} Employees;

// Prototypes
void saveEmployees(Employees[NUM_EMP], int c, char[SIZE]);
int loadEmployees(Employees[NUM_EMP], char[SIZE]);


/*
 * 1
 *
 * Save information of c number of employees in a text file
 * Returns nothing.
 */
void saveEmployees (Employees employees[NUM_EMP], int c, char fileName[SIZE]) {
   FILE *file;
   // Open file to save file
   file = fopen(fileName, "w");

   // Check for c number of employees
   for (int i = 0; i < c; ++i){
       // Add employees to the file from the array
       fprintf(file, "%s %s %d %s %s %s\n",
				employees[i].fname,
				employees[i].lname,
				employees[i].id,
				employees[i].dependents[0],
				employees[i].dependents[1],
				employees[i].dependents[2]);
       fprintf(file, "\n");
   }
   // Close file
   fclose(file);
}

/*
 * 2
 *
 * Load all employee records that are stored in a text file to an array of Employees.
 * Returns the total number of records loaded.
 */
int loadEmployees (Employees employees[NUM_EMP], char fileName[SIZE]) {
   FILE *file;
   int count = 0;

   // Open file to read contents
   file = fopen(fileName, "r");

   // Check if file exists
   if (file == NULL){
       printf("File %s not found" , fileName);
       return 0;
   }
   else{
      // Load contents into array until end of file
      while (!feof(file)){
	fscanf(file, "%s %s %d %s %s %s",
				employees[count].fname,
				employees[count].lname,
				&employees[count].id,
				employees[count].dependents[0],
				employees[count].dependents[1],
				employees[count].dependents[2]);
         count++;
      }
   }

   // Returns the total number of records
   return count;
}
