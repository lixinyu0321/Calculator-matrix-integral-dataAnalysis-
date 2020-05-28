#include "stat.h"

void get_two_dimension(char* line, double** data, char *filename)
{
    FILE* stream = fopen(filename, "r");
    int i = 0;
    while (fgets(line, 1024, stream))//逐行读取
    {
        int j = 0;
        char *tok;
        char* tmp = strdup(line);
        for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ",\n")){
            data[i][j] = atof(tok);//转换成浮点数
        }//字符串拆分操作
        i++;
        free(tmp);
    }
    fclose(stream);
}
void get_variable(char **variable, int col, char *filename)
{
    FILE* stream = fopen(filename, "r");
    int i=0,j=0; char c;
    for(i=0;i<col;i++){
        j=0;
        while((c=fgetc(stream))!=',' && c!=' ' && c!='\n'){
            variable[i][j]=c;
            j++;
        }
        variable[i][j]='\0';
    }
    variable[col-1][j-1]='\0';//手动替换最后一个换行符为'\0'
    fclose(stream);
}
void preview_two_dimension(char **variable, double** data, int row, int col)
{
    int i, j;
    printf("数据预览前6行：\n");
    for(i=0;i<col;i++)
        printf("%s\t",variable[i]);
    printf("\n");
    for(i=1; i<7; i++){
        for(j=0; j<col; j++){
            printf("%.2f\t", data[i][j]);
        }
        printf("\n");
    }//打印的时候不打印第一行，第一行全是字符
}
int get_row(char *filename)
{
    char line[1024];
    int i = 0;
    FILE* stream = fopen(filename, "r");
    while(fgets(line, 1024, stream)){
        i++;
    }
    fclose(stream);
    return i;
}
int get_col(char *filename)
{
    char line[1024];
    int i = 0;
    FILE* stream = fopen(filename, "r");
    fgets(line, 1024, stream);
    char* token = strtok(line, ",");
    while(token){
        token = strtok(NULL, ",");
        i++;
    }
    fclose(stream);
    return i;
}
double *get_average(char **variable, double **data, int row, int col, double average[]){
    double sum;
    int i,j;
    for(i=0;i<col;i++){
        sum=0;
        for(j=1;j<row;j++)
        {sum+=data[j][i];}
        average[i]=sum/(row-1);
    }
    return average;
}
void get_mode(char **variable, double **data, int row, int col){
    int i,j,k,l,tag;
    struct number{
        double value;
        int num;
    } *mode;
	mode = new number[row-1];//定义结构体来存储数的值与出现次数，实际变量数为row-1由于第一行是变量名
    printf("注意：如果出现多个众数，将取最小者显示。\n");
    for(i=0;i<col;i++){
    //double var[row-1],temp;
		double* var = new double[row-1];
		double temp;
        for(j=1;j<row;j++)  {var[j-1]=data[j][i];}//避免破坏原数据，将数据复制出来处理
        for(j=1;j<=row-2;j++){
            for(k=0;k<=row-2-j;k++){
                if(var[k]>var[k+1]){
                    temp=var[k];var[k]=var[k+1];var[k+1]=temp;
                }
            }
        }//冒泡排序
        //求众数：统计出现次数
        mode[0].value=var[0];mode[0].num=1;
        l=0;
        for(j=0;j<row-2;j++){
            if(var[j+1]!=var[j])
            {
                l++;
                mode[l].num=1;
                mode[l].value=var[j+1];
            }
               else mode[l].num++;
        }
        //比较出现次数大小
               tag=0;
               for(j=1;j<=l;j++)    {if(mode[j].num>mode[tag].num) tag=j;}
               printf("变量%s众数为：%.2lf\t,共出现了%d次\n",variable[i],mode[tag].value,mode[tag].num);
    }
}
void get_medium(char **variable, double **data, int row, int col){
    int i,j,k;
    //double var[row-1],temp;
	double* var = new double[row-1];
	double temp;
    for(i=0;i<col;i++){
        for(j=1;j<row;j++)  {var[j-1]=data[j][i];}//避免破坏原数据，将数据复制出来处理
        for(j=1;j<=row-2;j++){
            for(k=0;k<=row-2-j;k++){
                if(var[k]>var[k+1]){
                    temp=var[k];var[k]=var[k+1];var[k+1]=temp;
                }
            }
        }//冒泡排序
        if((row-1)%2==0) printf("变量%s的中位数：%lf\n",variable[i],(var[(row-1)/2-1]+var[(row-1)/2])/2);
        else   printf("变量%s的中位数：%lf\n",variable[i],var[row/2-1]);
    }
}
double *get_variance(char **variable, double **data, int row, int col, double variance[], double average[]){
    int i,j;
    double sum,avrg;
    for(i=0;i<col;i++){
        sum=0;
        avrg=*(average+i);
        for(j=1;j<row;j++){
            sum+=(data[j][i]-avrg)*(data[j][i]-avrg);
        }
        variance[i]=sum/(row-2);
    }
    return variance;
}
void linear_regression(char **variable, double **data, int row, int col){
    int i,j,k,y,n;
    printf("以下为可选变量序号：");
    for(i=0;i<col;i++) printf("No.%d:%s\t",i,variable[i]);
    printf("\n请选择一个因变量：");
    scanf("%d",&y);
    printf("请输入需要参与回归的应变量个数（1到%d个）：",col-1);
    scanf("%d",&n);
	int *regressor = new int [n];
    printf("请输入自变量序号：");
    for(i=0;i<n;i++) scanf("%d",&regressor[i]);

	double* arr = new double[row-1];
    for(j=1;j<row;j++)  arr[j-1]=data[j][y];

    myMatrix Y = myMatrix(row-1,1,arr);
    myMatrix X = myMatrix(row-1,n,data);

    MatrixXd result = multi_regression(Y, X);
}

void stat_run()
{
	printf("欢迎使用功能区4——统计！\n本功能需要使用csv型文件作为数据源，并要求第一行为变量名称，从第二行起每行一组变量组合，所有变量需为数字或浮点型。\n");
    printf("请输入您需要处理的csv文件路径：");
    char filename[500];
    gets(filename);
    //本电脑路径：char filename[] = "/Users/qianchihuang/Documents/计算机语言与程序设计/Group Project/oldCarData.csv";
    char line[1024];
    double **data;
    int row, col,input,i;
    row = get_row(filename);
    col = get_col(filename);
    //double average[col],variance[col];
	double* average = new double[col];
	double* variance = new double[col];
    double *aver;
    data = (double **)malloc(row * sizeof(int *));
    //char variable[col][30];
	//char **variable;
	char **variable = new char* [col];
	for(int i = 0; i < col; i++) variable[i] = new char[30];
    for (int i = 0; i < row; i++){
        data[i] = (double *)malloc(col * sizeof(double));
    }//动态申请二维数组
    get_two_dimension(line, data, filename);
    get_variable(variable, col, filename);
    printf("row = %d\t", row);
    printf("col = %d\n", col);
    preview_two_dimension(variable, data, row, col);
    //数据读取与预览完成
    
    reuse:
    //设置goto接口以供需要重复使用
    printf("\n1、求平均值   2、求众数   3、求中位数   4、求方差   5、求标准差   6、多元线性回归\n请选择您需要使用的功能：");
    scanf("%d",&input);
    switch(input){
        case 1:{for(i=0;i<col;i++){
            printf("变量名%s平均值：%lf\t\n",variable[i],*(get_average(variable, data, row, col, average)+i));}
            break;
        }
        case 2:{get_mode(variable, data, row, col);break;
            }
        case 3:{get_medium(variable, data, row, col);break;
        }
        case 4:{printf("注：方差使用N-1为分母。\n");
            aver = get_average(variable, data, row, col, average);
            for(i=0;i<col;i++){
                printf("变量名%s方差：%lf\t\n",variable[i],*(get_variance(variable, data, row, col, variance, aver)+i));}
            break;
        }
        case 5:{printf("注：标准差使用N-1为根号内分母。\n");
            aver = get_average(variable, data, row, col, average);
            for(i=0;i<col;i++){
                printf("变量名%s标准差：%lf\t\n",variable[i],sqrt(*(get_variance(variable, data, row, col, variance, aver)+i)));}
            break;
        }
        case 6:{
            linear_regression(variable, data, row, col);
        }
        default: break;
    }
    char c;
    printf("\n需要继续使用或退出（Y/N）？");
    getchar();
    scanf("%c",&c);
    if(c == 'Y' || c == 'y') goto reuse;
    else   printf("谢谢使用！");
}