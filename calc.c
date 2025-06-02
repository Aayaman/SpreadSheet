#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h"
#include "ordering.h"
#include "data.h"


//Claculate the total 
double  calculateTotal(int a , int b , int c , int d, int e){
    double sumAbc;
    double sumDe;
    double average;
    sumAbc = ((double)a *5.0)/24.0 + ((double)b *5.0)/24.0 + ((double)c *5.0)/24.0 ;
    sumDe = (double)d + ((double)e *5.0)/4.0;
    average = sumAbc + sumDe;
    return average;
}

//Calculate the grade 
char calculateGrade( double l){
    char grade;
    if (l >= 80.0) grade = 'A';
    else if (l >= 70.0) grade = 'B';
    else if (l >= 60.0) grade = 'C';
    else if (l >= 50.0) grade = 'D';
    else grade = 'F';
    return grade;
}

//Calculate updated grade after changing the grade mapping 
char calculateUpdatedGrade(double l, int map1, int map2, int map3, int map4){
    char grade;
    if (l >= map1) grade = 'A';
    else if (l >= map2) grade = 'B';
    else if (l >= map3) grade = 'C';
    else if (l >= map4) grade = 'D';
    else grade = 'F';
    return grade;
}

//Update the changed grade in the struct 
void updateStructGrade(struct Students *array, int n , int map1, int map2, int map3, int map4 ){
    int i;
    for (i = 0 ; i < n ; i++){
        array[i].grade = calculateUpdatedGrade(array[i].total , map1, map2, map3, map4 );
    }

}

//Change student's Last name 
void changeLast(struct Students *array, int n){
    int idChoice , idfound = 0;
    char nameChoice[50];
    int i;

    printf("Enter Student ID: ");
    scanf("%d", &idChoice);
    
    while (idfound == 0){
        for ( i = 0 ; i < n ; i++){
            if (array[i].id == idChoice ){
                printf("\n\nEnter updated Last Name: ");
                scanf("%s", nameChoice);
                strcpy(array[i].firstName, nameChoice);
                idfound++;
            }
        }
        if(idfound == 0 ){
            printf("ID not found. Please enter a valide ID: ");
            scanf("%d", &idChoice);
        }
    }
    
    printf("\nLast name updated"); 
}

//Change student's Exam 
void changeExam(struct Students *array, int n){
    int idChoice, i, examChoice, idfound = 0;
    double total;
    char grade ;
    

    printf("Enter Student ID: ");
    scanf("%d", &idChoice);
    while(idfound == 0 ){
        for ( i = 0 ; i < n ; i++){
            if (array[i].id == idChoice ){
                printf("\n\nEnter updated Exam Grade: ");
                scanf("%d", &examChoice);
                array[i].exam = examChoice;
                total = calculateTotal(array[i].a1, array[i].a2, array[i].a3, array[i].midterm, array[i].exam);
                grade = calculateGrade(total);
                array[i].total = total;
                array[i].grade = grade;
                idfound++;
            }
        }
        if(idfound == 0 ){
            printf("ID not found. Please enter a valide ID: ");
            scanf("%d", &idChoice);
        }
    }
    
    printf("\nExam grade updated"); 
    
}

//Delete a student from the struct 
void deleteStudent(struct Students **array, int *n, int idChoice){
    int i, j;
    int found = 0;

    for (i = 0; i < *n; i++) {
        if ((*array)[i].id == idChoice) {
            found = 1; // Student found
            break;
        }
    }

    if (!found) {
        printf("No Student ID matches the given ID. No Student was deleted.\n");
        return;
    }

    for (j = i; j < *n - 1; j++) {
        (*array)[j] = (*array)[j + 1];
    }

    // Resizing the memory allocation
    *n = *n - 1; 
    struct Students *temp = realloc(*array, (*n) * sizeof(struct Students));
    if (temp == NULL && *n > 0) {
        printf("Memory reallocation failed.\n");
        return;
    }
    *array = temp; 

    printf("Student deleted successfully.\n");
}

//Manage option 3 of the main menu
void menu3( struct Students *array , int n){
    int menu2;
    printf("Column Options\n");
    printf("--------------\n");
    printf("1. Student ID\n");
    printf("2. Last name \n");
    printf("3. Exam \n");
    printf("4. Total \n");
    printf("\nSort Column: ");
    scanf("%d", &menu2);
    switch(menu2){
        case 1: sortArrayByID( array, n);
        break;
        case 2: sortArrayByLast( array, n);
        break;
        case 3: sortArrayByExam( array, n);
        break;
        case 4: sortArrayByTotal( array, n);
        break;
    }
    printf("\n\nSort column updated\n\n");
}

//Manage option 6 of the main menu 
void menu6( struct Students *array , int n, int *mapping1 , int *mapping2, int *mapping3, int *mapping4 ){
    printf("Current Mapping: \n");
    printf("A: >= %d \n", *mapping1);
    printf("B: >= %d \n", *mapping2);
    printf("C: >= %d \n", *mapping3);
    printf("D: >= %d \n", *mapping4);
    printf("F:  < %d \n\n\n", *mapping4);
    printf("Enter New A baseline: ");
    scanf("%d", mapping1);
    printf("\n");
    while(*mapping1 > 100 || *mapping1 < 0){
        printf("Invalid input! Enter New A baseline: ");
        scanf("%d", mapping1);
        printf("\n");
    }
    printf("Enter New B baseline: ");
    scanf("%d", mapping2);
    printf("\n");
    while((*mapping2 >  100 || *mapping2 < 0)|| (*mapping2 >= *mapping1)){
        printf("Invalid Input! Enter New B baseline: ");
        scanf("%d", mapping2);
        printf("\n");
    }
    printf("Enter New C baseline: ");
    scanf("%d", mapping3);
    printf("\n");
    while((*mapping3 >  100 || *mapping3 < 0)|| (*mapping3 >= *mapping2)){
        printf("Invalid Input! Enter New C baseline: ");
        scanf("%d", mapping3);
        printf("\n");
    }
    printf("Enter New D baseline: ");
    scanf("%d", mapping4);
    printf("\n");
    while((*mapping4 >  100 || *mapping4 < 0)|| (*mapping4 >= *mapping3)){
        printf("Invalid Input! Enter New D baseline: ");
        scanf("%d", mapping4);
        printf("\n");
    }
    updateStructGrade(array, n , *mapping1, *mapping2, *mapping3, *mapping4 );
}

//Manage option 7 of the main menu 
void menu7( struct Students *array , int *n){
    int idDelete;
    printSheet(studentArray , *n);
    printf("Enter Student ID: ");
    scanf("%d", &idDelete);
    deleteStudent(&array, n ,idDelete );
}