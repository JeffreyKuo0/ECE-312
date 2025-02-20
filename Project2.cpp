// matrix-multiplication <Project2.cpp>
// ECE 312 Project 2 submission by
// <Your Name Here>
// <Your EID>
// Slip days used: <0>
// Fall 2023

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
            double temp;
            for(uint32_t i=0; i<a_rows; i++){
                for(uint32_t j=0; j< b_cols; j++){
                    temp = 0;
                    for(uint32_t x=0; x<a_cols; x++){
                        temp += a[i*a_cols+x] * b[x*b_cols+j];
                    }
                    c[i*b_cols+j] = temp;
                }
            }
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
            // 1. allocate the arrays
            // 2. multiply
            // 3. return
            double** c;
            c = (double**) malloc(a_rows * sizeof(double*));  //array of pointers, each row
            if(c==NULL){
                printf("memory allocation failure");
            }
            for(int i=0; i<a_rows; i++){
                *(c+i) = (double*) malloc(b_cols * sizeof(double));
                if(*(c+i)==NULL){
                    printf("memory allocation failure");
                }
            }
            double temp;
            for(uint32_t i=0; i<a_rows; i++){
                for(uint32_t j=0; j< b_cols; j++){
                    temp = 0;
                    for(uint32_t x=0; x<a_cols; x++){
                        temp += a[i][x] * b[x][j];
                    }
                    c[i][j] = temp;
                }
            }
            return c;
        }

// https://en.wikipedia.org/wiki/Matrix_(mathematics)#Submatrix
double** createSubMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols,
		 const uint32_t row_x, 
		 const uint32_t col_y) {
    // return a_rows-1 x a_cols-1 by removing row_x and col_y
    double** a2;
    a2 = (double**) malloc((a_rows-1) * sizeof(double*));  //array of pointers, each row
    if(a2==NULL){
        printf("memory allocation failure");
    }
    for(int i=0; i<(a_rows-1); i++){
        *(a2+i) = (double*) malloc((a_cols-1) * sizeof(double));
        if(*(a2+i)==NULL){
            printf("memory allocation failure");
        }
    }
    for(int i=0; i<row_x; i++){ //top left, uncut part
        for(int j=0; j<col_y; j++){
            a2[i][j] = a[i][j];
        }
    }
    for(int i=0; i<row_x; i++){ //top right, cut by col not row
        for(int j=col_y; j<(a_cols-1); j++){
            a2[i][j] = a[i][j+1];
        }
    }

    for(int i=row_x; i<(a_rows-1); i++){ // bottom left, cut by row not col
        for(int j=0; j<col_y; j++){
            a2[i][j] = a[i+1][j];
        }
    }

    for(int i=row_x; i<(a_rows-1); i++){ // bottom right, cut by both
        for(int j=col_y; j<(a_cols-1); j++){
            a2[i][j] = a[i+1][j+1];
        }
    }
    return a2;
}
