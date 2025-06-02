
#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"




void initializeStruct(struct Students studentArray[], int n) {

    //Declare all variables 
    char buffer[260];
    int id;
    char firstName[15];
    char lastName[15];
    int a1, a2, a3, midterm, exam;
    int index = 0; // To keep track of the current index in the studentArray

    FILE *file = fopen("students.txt", "r");

    // Handle error if the file cannot be opened
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    //Initiallize the struct Array with the info in the file
    while (fgets(buffer, sizeof(buffer), file) != NULL && index < n) {
        sscanf(buffer, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
           &id, firstName, lastName, &a1, &a2, &a3, &midterm, &exam);
        studentArray[index].id = id;
        strcpy(studentArray[index].firstName, firstName);
        strcpy(studentArray[index].lastName, lastName);
        studentArray[index].a1 = a1;
        studentArray[index].a2 = a2;
        studentArray[index].a3 = a3;
        studentArray[index].midterm = midterm;
        studentArray[index].exam = exam;
        studentArray[index].total = calculateTotal(a1, a2, a3, midterm, exam);
        studentArray[index].grade = calculateGrade(studentArray[index].total);
        index++;
    }

    fclose(file); // Close the file after reading
    
}

//Set the grade distribution 
void gradeDistribution(struct Students *array, int n){
    int charA = 0, charB = 0, charC = 0, charD = 0, charF = 0;
    int i, j;
    int charIntArray[5];
    char charArray[5]= {'A', 'B', 'C', 'D', 'F'};
    for ( i = 0 ; i < n ;i++ ){
        switch (array[i].grade){
            case 'A':  charA++;
            break;
            case 'B': charB++ ;
            break;
            case 'C': charC++ ;
            break;
            case 'D': charD++ ;
            break;
            case 'F': charF++ ;
            break;
        }
    }
    charIntArray[0]= charA;
    charIntArray[1]= charB;
    charIntArray[2]= charC;
    charIntArray[3]= charD;
    charIntArray[4]= charF;
    for (i = 0 ; i < 5; i++){
        printf("%c:  ", charArray[i]);
        for (j = 0 ; j < charIntArray[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

//Print spreadsheet
void printSheet(struct Students *array, int n){
    int i ;
    printf("COMP 348 GRADE SHEET\n");
    printf("\n");
    printf("ID\tLast\tFirst\tA1\tA2\tA3\tMidterm\tExam\tTotal\tGrade\n");
    printf("--\t----\t-----\t--\t--\t--\t-------\t----\t-----\t-----\n");
    for (i = 0 ; i < n ; i++){
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%c\n",array[i].id , array[i].firstName , array[i].lastName , array[i].a1, array[i].a2 , array[i].a3 , array[i].midterm , array[i].exam, array[i].total, array[i].grade );
    }
    printf("\n\n\n");
}