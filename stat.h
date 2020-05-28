#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix_cal.h"
#include "regress.h"

#ifndef _STAT_H_
#define _STAT_H_

//功能区
void get_two_dimension(char* line, double** data, char *filename);
void get_variable(char **variable, int col, char *filename);
void preview_two_dimension(char **variable, double** data, int row, int col);
int get_row(char *filename);
int get_col(char *filename);
double *get_average(char **variable, double **data, int row, int col, double average[]);
void get_mode(char **variable, double **data, int row, int col);
void get_medium(char **variable, double **data, int row, int col);
double *get_variance(char **variable, double **data, int row, int col, double variance[], double average[]);
void linear_regression(char **variable, double **data, int row, int col);

//展示
void stat_run();

#endif