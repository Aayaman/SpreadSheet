#ifndef CALCULATE_H
#define CALCULATE_H

 
double  calculateTotal(int a , int b , int c , int d, int e);
char calculateGrade( double l);
char calculateUpdatedGrade(double l , int map1, int map2, int map3, int map4);
void updateStructGrade(struct Students array[], int n , int map1, int map2, int map3, int map4 );
void changeLast(struct Students array[], int n);
void changeExam(struct Students array[], int n);
void deleteStudent(struct Students **array, int *n, int idChoice);
#endif