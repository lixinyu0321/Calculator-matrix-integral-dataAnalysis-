#include<iostream>
#include<stdio.h>
#include<Eigen/Dense>
#include<Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;

#ifndef _MATRIX_CAL_H_
#define _MATRIX_CAL_H_

struct myMatrix
{
public:
	int rows, cols;
	MatrixXd matrix_x;

public:
	//初始化均为单位阵
	myMatrix(){matrix_x.setIdentity(1,1); rows = 1; cols = 1;}
	myMatrix(int rowSize, int colSize){matrix_x.setIdentity(rowSize, colSize); rows = rowSize; cols = colSize;}
	//自定义初始化
	myMatrix(int rowSize, int colSize, double arr[])
	{
		rows = rowSize;
		cols = colSize;
		matrix_x = Map<MatrixXd>(arr, rows, cols);
	}
	myMatrix(int rowSize, int colSize, MatrixXd matrix)
	{
		rows = rowSize;
		cols = colSize;
		matrix_x = matrix;
	}
	myMatrix(int rowSize, int colSize, double **arr)
	{
		rows = rowSize;
		cols = colSize;
		double *temp = new double [rows * cols];
		int k = 0;
		for(int i = 0; i < cols; i++)
		{
			for(int j = 0; j < rows; j++)
			{
				temp[k] = arr[j][i];
				k++;
			}
		}
		matrix_x = Map<MatrixXd>(temp,rows,cols);
	} //输入行， 列， 二维数组初始化
	//基础信息
	int getCols(){return cols;}
	int getRows(){return rows;}
	MatrixXd getMatrix(){return matrix_x;}
	//基本运算
	double **toArrray();
	double **minusAsArray(myMatrix A);
	MatrixXd Minus(myMatrix A);
	double **addAsArray(myMatrix A);
	MatrixXd Add(myMatrix A);
	double **multiplyAsArray(myMatrix A);
	MatrixXd Multiply(myMatrix A);
	
	myMatrix trans(); //转置
	double deter(); //行列式
	myMatrix inv(); //求逆
	//其他计算
	double* character(); //求特征值 

	void show();
	void mat_run(); //展示结果
};

#endif