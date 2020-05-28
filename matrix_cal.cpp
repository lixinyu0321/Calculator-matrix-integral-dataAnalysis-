#include "matrix_cal.h"
#include "utils.h"
//������
double** myMatrix::toArrray()
{
	double** arr = new double* [rows];
	for(int i = 0; i < rows; i++)
		arr[i] = new double[cols];

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			arr[i][j] = matrix_x(i, j);

	return arr;
}
double** myMatrix::addAsArray(myMatrix A)
{
	double** arr = new double* [rows];
	for(int i = 0; i < rows; i++)
		arr[i] = new double[cols];
	if((A.getCols() == cols) && (A.getRows() == rows))
	{
		MatrixXd temp = matrix_x + A.matrix_x;

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				arr[i][j] = temp(i, j);

		return arr;
	}
	else
	{
		printf("���в�ƥ�䣡\n");
		return arr;
	}
}
MatrixXd myMatrix::Add(myMatrix A)
{
	return matrix_x + A.getMatrix();
}
double** myMatrix::minusAsArray(myMatrix A)
{
	double** arr = new double* [rows];
	for(int i = 0; i < rows; i++)
		arr[i] = new double[cols];
	if((A.getCols() == cols) && (A.getRows() == rows))
	{
		MatrixXd temp = matrix_x - A.matrix_x;

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				arr[i][j] = temp(i, j);

		return arr;
	}
	else
	{
		printf("���в�ƥ�䣡\n");
		return arr;
	}
}
MatrixXd myMatrix::Minus(myMatrix A)
{
	return matrix_x - A.getMatrix();
}
double** myMatrix::multiplyAsArray(myMatrix A)
{
	double** arr = new double* [rows];
	int Arow = A.getRows();
	for(int i = 0; i < rows; i++)
		arr[i] = new double[Arow];
	if(Arow == cols)
	{
		MatrixXd temp = matrix_x * A.matrix_x;

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < A.getCols(); j++)
				arr[i][j] = temp(i, j);

		return arr;
	}
	else
	{
		printf("���в�ƥ�䣡\n");
		return arr;
	}
}
MatrixXd myMatrix::Multiply(myMatrix A)
{
	return matrix_x * A.getMatrix();
}

myMatrix myMatrix::trans()
{
	return myMatrix(cols, rows, matrix_x.transpose());
}
double myMatrix::deter()
{
	return matrix_x.determinant();
}
myMatrix myMatrix::inv()
{
	if(cols != rows)
	{
		printf("ֻ�з�����������\n");
		return myMatrix();
	}
	else if(matrix_x.determinant() == 0)
	{
		printf("����ʽ = 0������󲻴��ڣ�\n");
		return myMatrix(rows, cols);
	}
	else
		return myMatrix(rows, cols, matrix_x.inverse());
}

double* myMatrix::character()
{
	double *arr = new double[rows];
	if(rows == cols)
	{
		EigenSolver<MatrixXd> es(matrix_x);
		MatrixXd D = es.pseudoEigenvalueMatrix();
		for(int i = 0; i < rows; i++) arr[i] = D(i, i);
		return arr;
	}
	else
	{
		printf("ֻ�з����������ֵ��\n");
		return arr;
	}
}

//չʾ��
void myMatrix::show()
{
	cout<<matrix_x<<endl;
}
void myMatrix::mat_run()
{
	reuse:
	color(11);
	printf("��ӭʹ�ù�����1�����������㣡\n������֧�־���������㣬ת�ã������Լ�������ֵ\n");
    printf("��Ϸ��������");
    printf("\n1���ӷ�(A+B)   2������(A-B)   3���˷�(A*B)   4��ת��(A')   5����(A^-1)   6������ֵ\n��ѡ������Ҫʹ�õĹ��ܣ�");
    color(7);
	int input;
	scanf("%d",&input);
    switch(input){
        case 1:
			{
				int col1, row1;
				int col2, row2;
				printf("���������1������������\n");
				scanf("%d%d", &row1, &col1);
				double **mat1 = new double* [row1];
				for(int i = 0; i < row1; i++) mat1[i] = new double[col1];
				printf("���������1���������������룩��\n");
				for(int i = 0; i < row1; i++)
					for(int j = 0; j < col1; j++)
						cin>>mat1[i][j];
				printf("���������2������������\n");
				scanf("%d%d", &row2, &col2);
				double **mat2 = new double* [row2];
				for(int i = 0; i < row2; i++) mat2[i] = new double[col2];
				printf("���������2���������������룩��\n");
				for(int i = 0; i < row2; i++)
					for(int j = 0; j < col2; j++)
						cin>>mat2[i][j];
				myMatrix a(row1, col1, mat1);
				myMatrix b(row2, col2, mat2);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				b.show();
				printf("\n");
				cout<<a.Add(b)<<endl;
				break;
			}
        case 2:
			{
				int col1, row1;
				int col2, row2;
				printf("���������1������������\n");
				scanf("%d%d", &row1, &col1);
				double **mat1 = new double* [row1];
				for(int i = 0; i < row1; i++) mat1[i] = new double[col1];
				printf("���������1���������������룩��\n");
				for(int i = 0; i < row1; i++)
					for(int j = 0; j < col1; j++)
						cin>>mat1[i][j];
				printf("���������2������������\n");
				scanf("%d%d", &row2, &col2);
				double **mat2 = new double* [row2];
				for(int i = 0; i < row2; i++) mat2[i] = new double[col2];
				printf("���������2���������������룩��\n");
				for(int i = 0; i < row2; i++)
					for(int j = 0; j < col2; j++)
						cin>>mat2[i][j];
				myMatrix a(row1, col1, mat1);
				myMatrix b(row2, col2, mat2);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				b.show();
				printf("\n");
				cout<<a.Minus(b)<<endl;
				break;
            }
        case 3:
			{
				int col1, row1;
				int col2, row2;
				printf("���������1������������\n");
				scanf("%d%d", &row1, &col1);
				double **mat1 = new double* [row1];
				for(int i = 0; i < row1; i++) mat1[i] = new double[col1];
				printf("���������1���������������룩��\n");
				for(int i = 0; i < row1; i++)
					for(int j = 0; j < col1; j++)
						cin>>mat1[i][j];
				printf("���������2������������\n");
				scanf("%d%d", &row2, &col2);
				double **mat2 = new double* [row2];
				for(int i = 0; i < row2; i++) mat2[i] = new double[col2];
				printf("���������2���������������룩��\n");
				for(int i = 0; i < row2; i++)
					for(int j = 0; j < col2; j++)
						cin>>mat2[i][j];
				myMatrix a(row1, col1, mat1);
				myMatrix b(row2, col2, mat2);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				b.show();
				printf("\n");
				cout<<a.Multiply(b)<<endl;
				break;
			}
        case 4:
			{
				int col1, row1;
				printf("���������������������\n");
				scanf("%d%d", &row1, &col1);
				double **mat1 = new double* [row1];
				for(int i = 0; i < row1; i++) mat1[i] = new double[col1];
				printf("�����������������������룩��\n");
				for(int i = 0; i < row1; i++)
					for(int j = 0; j < col1; j++)
						cin>>mat1[i][j];
				myMatrix a(row1, col1, mat1);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				a.trans().show();
				break;
			}
        case 5:
			{
				int col1, row1;
				printf("���������������������\n");
				scanf("%d%d", &row1, &col1);
				double **mat1 = new double* [row1];
				for(int i = 0; i < row1; i++) mat1[i] = new double[col1];
				printf("�����������������������룩��\n");
				for(int i = 0; i < row1; i++)
					for(int j = 0; j < col1; j++)
						cin>>mat1[i][j];
				myMatrix a(row1, col1, mat1);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				a.inv().show();
				break;
			}
        case 6:
			{
				int n;
				printf("����������ģ��\n");
				scanf("%d", &n);
				double **mat1 = new double* [n];
				for(int i = 0; i < n; i++) mat1[i] = new double[n];
				printf("�����������������������룩��\n");
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						cin>>mat1[i][j];
				myMatrix a(n, n, mat1);
				printf("ԭ����Ϊ��\n");
				a.show();
				printf("\n");
				double *arr = a.character();
				for(int i = 0; i < n; i++)
					printf("����ֵ%d = %lf\n", i+1, arr[i]);
				break;
			}
        default: break;
    }
    char c;
    printf("\n��Ҫ����ʹ�û��˳���Y/N����");
    getchar();
    scanf("%c",&c);
    if(c == 'Y' || c == 'y') goto reuse;
    else   printf("ллʹ�ã�");
}