#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ordering.h"
#include "data.h"
#include "calc.h"

struct Students *studentArray;

int main (){
    
        //Declare all variables.
        int n = 10; 
        int menu;
        int mapping1 = 80, mapping2 = 70, mapping3 = 60, mapping4 = 50;
        char c ;

        // Allocate memory for studentArray to hold 'n' Students structs
        studentArray= (struct Students *)malloc(n * sizeof(struct Students));

        // Handle memory allocation failure
        if (studentArray == NULL){
            printf("Memory allocation failled \n");
            return 1;
        }

        initializeStruct(studentArray, n);
        sortArrayByID( studentArray, n);

        // Clear the screen and display the main menu
        system("clear");
        printf("Spreadsheet Menu \n\n");
        printf("1. Display Spreadsheet\n");
        printf("2. Display Histogram\n");
        printf("3. Set sort column \n");
        printf("4. Update last name \n");
        printf("5. Update Exam Grade\n");
        printf("6. Update Grade Mapping\n ");
        printf("7. Delete Student\n");
        printf("8. Exit\n\n");
        printf("Selection: ");
        scanf("%d", &menu);
        printf("\n");

        while(menu<1 || menu > 8){
            printf("Incorrect input.Please enter a number between 1 and 8");
            scanf("%d", &menu);
            printf("\n");
        }
        while (menu >= 1 && menu <=8){

            // Option 1: Display the spreadsheet of students
            if (menu == 1){
                printSheet(studentArray , n);
            }
            // Option 2: Display grade distribution (Histogram)
            else if( menu == 2){
                printf("COMP 348 Grade Distribution \n\n");
                gradeDistribution( studentArray, n );

            }
            // Option 3: Set the sorting column (for sorting students)
            else if(menu == 3){
                menu3(studentArray , n);
            }
            // Option 4: Update a student's last name
            else if (menu == 4){ 
                printSheet( studentArray, n);
                changeLast(studentArray, n);
                
            }
            // Option 5: Update a student's exam grade
            else if (menu == 5){ 
                printSheet(studentArray , n);
                changeExam(studentArray , n);
            }
            // Option 6: Update the grade mapping (A, B, C, D thresholds)
            else if (menu == 6){ 
                menu6( studentArray, n, &mapping1, &mapping2, &mapping3, &mapping4 );
            }
            // Option 7: Delete a student from the list
            else if (menu == 7){ 
                menu7(studentArray , &n);
            }
            // Option 8: Exit the program
            else {
                printf("Program exiting immediatly. Thank you for using SpreadSheet\n");
                exit(0);
            }

            // Prompt user to press 'c' or 'C' to continue
            printf("\n\nPress \'c\' or \'C\' to continue \n");
            getchar();//Junk scanner 
            c = getchar();
            while(!(c == 'c' || c == 'C')){
                printf("Please enter a valid input \'c\' or \'C\' in order to continue\n");
                getchar();//Junk scanner 
                c = getchar();
            }
            if (c == 'c' || c == 'C'){
                system("clear");
            }
            //Redisplay the menu after clearing the screen 
            printf("Spreadsheet Menu \n\n");
            printf("1. Display Spreadsheet\n");
            printf("2. Display Histogram\n");
            printf("3. Set sort column \n");
            printf("4. Update last name \n");
            printf("5. Update Exam Grade\n");
            printf("6. Update Grade Mapping\n ");
            printf("7. Delete Student\n");
            printf("8. Exit\n\n");
            printf("Selection: ");
            scanf("%d", &menu);
            printf("\n");
            }
            
                
        free(studentArray);
    
    return 0;
}




