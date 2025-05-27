#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Students {
    int id;
    char firstName[10];
    char lastName[10];
    int a1;
    int a2;
    int a3;
    int midterm;
    int exam;
    double total;
    char grade;
};

extern struct Students *studentArray; // Declaration

#endif