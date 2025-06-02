#include "struct.h"
#include <stdio.h>
#include <string.h>
#include "ordering.h"



//Sort struct Array by ID
void sortArrayByID( struct Students *array, int n){
    int i , j ;
    struct Students temp;
    for (i = 0 ; i < n-1 ; i++ ){
        for (j = 0 ; j < n-i-1 ; j++){
            if (array[j].id > array[j+1].id){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp ;
            }
        }
    }
}
//Sort struct Array by Last name 
void sortArrayByLast( struct Students *array, int n){
    int i , j ,result;
    struct Students temp;
    
    for (i = 0 ; i < n-1 ; i++ ){
        for (j = 0 ; j < n-i-1 ; j++){
            result = strcmp(array[j].firstName, array[j+1].firstName);
            if ( result > 0 ){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp ;
            }
        }
    }
}
//Sort struct Array by Exam 
void sortArrayByExam( struct Students *array, int n){
    int i , j ;
    struct Students temp;
    for (i = 0 ; i < n-1 ; i++ ){
        for (j = 0 ; j < n-i-1 ; j++){
            if (array[j].exam > array[j+1].exam){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp ;
            }
        }
    }
}
//Sort struct Array by Total
void sortArrayByTotal( struct Students *array, int n){
    int i , j ;
    struct Students temp;
    for (i = 0 ; i < n-1 ; i++ ){
        for (j = 0 ; j < n-i-1 ; j++){
            if (array[j].total < array[j+1].total){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp ;
            }
        }
    }
}


