#ifndef DATA_H
#define DATA_H
 extern struct Students *studentArray;
double  calculateTotal(int a , int b , int c , int d, int e);
char calculateGrade( double l);
void initializeStruct(struct Students studentArray[], int n );
void gradeDistribution(struct Students array[], int n);
void printSheet(struct Students array[], int n);
#endif