#include "matrix_cal.h"
#include "regress.h"

MatrixXd multi_regression(myMatrix Y, myMatrix X)
{
	int size = X.getCols();
	double *coef = new double[size+1];
	if(Y.getCols() != 1)
	{
		printf("因变量只能有唯一值！\n");
		return MatrixXd::Zero(1,1);
	}
	else
	{
		int row = X.getRows();
		int col = X.getCols();
		MatrixXd m = X.getMatrix();
		double** arr = new double* [row];
		for(int i = 0; i < row; i++)
			arr[i] = new double[col + 1];

		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				arr[i][j] = m(i, j);
		for(int i = 0; i < row; i++) arr[i][col] = 1;

		double *temp = new double [row * (col+1)];
		int k = 0;
		for(int i = 0; i < col + 1; i++)
		{
			for(int j = 0; j < row; j++)
			{
				temp[k] = arr[j][i];
				//cout<<temp[k]<<" ";
				k++;
			}
			//cout<<endl;
		}
		MatrixXd reg_m = Map<MatrixXd>(temp,row,col+1);
		MatrixXd pred = (reg_m.transpose()*reg_m).inverse()*(reg_m.transpose() * Y.getMatrix());
		for(int i = 0; i < col; i++)
			printf("The No %d coef is: %lf\n", i+1, pred(i, 0));
		printf("The interval is: %lf\n", pred(col, 0));
		
		return pred;
	}

}