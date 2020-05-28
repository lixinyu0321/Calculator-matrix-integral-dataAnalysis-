#include "stat.h"

void get_two_dimension(char* line, double** data, char *filename)
{
    FILE* stream = fopen(filename, "r");
    int i = 0;
    while (fgets(line, 1024, stream))//���ж�ȡ
    {
        int j = 0;
        char *tok;
        char* tmp = strdup(line);
        for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ",\n")){
            data[i][j] = atof(tok);//ת���ɸ�����
        }//�ַ�����ֲ���
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
    variable[col-1][j-1]='\0';//�ֶ��滻���һ�����з�Ϊ'\0'
    fclose(stream);
}
void preview_two_dimension(char **variable, double** data, int row, int col)
{
    int i, j;
    printf("����Ԥ��ǰ6�У�\n");
    for(i=0;i<col;i++)
        printf("%s\t",variable[i]);
    printf("\n");
    for(i=1; i<7; i++){
        for(j=0; j<col; j++){
            printf("%.2f\t", data[i][j]);
        }
        printf("\n");
    }//��ӡ��ʱ�򲻴�ӡ��һ�У���һ��ȫ���ַ�
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
	mode = new number[row-1];//����ṹ�����洢����ֵ����ִ�����ʵ�ʱ�����Ϊrow-1���ڵ�һ���Ǳ�����
    printf("ע�⣺������ֶ����������ȡ��С����ʾ��\n");
    for(i=0;i<col;i++){
    //double var[row-1],temp;
		double* var = new double[row-1];
		double temp;
        for(j=1;j<row;j++)  {var[j-1]=data[j][i];}//�����ƻ�ԭ���ݣ������ݸ��Ƴ�������
        for(j=1;j<=row-2;j++){
            for(k=0;k<=row-2-j;k++){
                if(var[k]>var[k+1]){
                    temp=var[k];var[k]=var[k+1];var[k+1]=temp;
                }
            }
        }//ð������
        //��������ͳ�Ƴ��ִ���
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
        //�Ƚϳ��ִ�����С
               tag=0;
               for(j=1;j<=l;j++)    {if(mode[j].num>mode[tag].num) tag=j;}
               printf("����%s����Ϊ��%.2lf\t,��������%d��\n",variable[i],mode[tag].value,mode[tag].num);
    }
}
void get_medium(char **variable, double **data, int row, int col){
    int i,j,k;
    //double var[row-1],temp;
	double* var = new double[row-1];
	double temp;
    for(i=0;i<col;i++){
        for(j=1;j<row;j++)  {var[j-1]=data[j][i];}//�����ƻ�ԭ���ݣ������ݸ��Ƴ�������
        for(j=1;j<=row-2;j++){
            for(k=0;k<=row-2-j;k++){
                if(var[k]>var[k+1]){
                    temp=var[k];var[k]=var[k+1];var[k+1]=temp;
                }
            }
        }//ð������
        if((row-1)%2==0) printf("����%s����λ����%lf\n",variable[i],(var[(row-1)/2-1]+var[(row-1)/2])/2);
        else   printf("����%s����λ����%lf\n",variable[i],var[row/2-1]);
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
    printf("����Ϊ��ѡ������ţ�");
    for(i=0;i<col;i++) printf("No.%d:%s\t",i,variable[i]);
    printf("\n��ѡ��һ���������");
    scanf("%d",&y);
    printf("��������Ҫ����ع��Ӧ����������1��%d������",col-1);
    scanf("%d",&n);
	int *regressor = new int [n];
    printf("�������Ա�����ţ�");
    for(i=0;i<n;i++) scanf("%d",&regressor[i]);

	double* arr = new double[row-1];
    for(j=1;j<row;j++)  arr[j-1]=data[j][y];

    myMatrix Y = myMatrix(row-1,1,arr);
    myMatrix X = myMatrix(row-1,n,data);

    MatrixXd result = multi_regression(Y, X);
}

void stat_run()
{
	printf("��ӭʹ�ù�����4����ͳ�ƣ�\n��������Ҫʹ��csv���ļ���Ϊ����Դ����Ҫ���һ��Ϊ�������ƣ��ӵڶ�����ÿ��һ�������ϣ����б�����Ϊ���ֻ򸡵��͡�\n");
    printf("����������Ҫ�����csv�ļ�·����");
    char filename[500];
    gets(filename);
    //������·����char filename[] = "/Users/qianchihuang/Documents/�����������������/Group Project/oldCarData.csv";
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
    }//��̬�����ά����
    get_two_dimension(line, data, filename);
    get_variable(variable, col, filename);
    printf("row = %d\t", row);
    printf("col = %d\n", col);
    preview_two_dimension(variable, data, row, col);
    //���ݶ�ȡ��Ԥ�����
    
    reuse:
    //����goto�ӿ��Թ���Ҫ�ظ�ʹ��
    printf("\n1����ƽ��ֵ   2��������   3������λ��   4���󷽲�   5�����׼��   6����Ԫ���Իع�\n��ѡ������Ҫʹ�õĹ��ܣ�");
    scanf("%d",&input);
    switch(input){
        case 1:{for(i=0;i<col;i++){
            printf("������%sƽ��ֵ��%lf\t\n",variable[i],*(get_average(variable, data, row, col, average)+i));}
            break;
        }
        case 2:{get_mode(variable, data, row, col);break;
            }
        case 3:{get_medium(variable, data, row, col);break;
        }
        case 4:{printf("ע������ʹ��N-1Ϊ��ĸ��\n");
            aver = get_average(variable, data, row, col, average);
            for(i=0;i<col;i++){
                printf("������%s���%lf\t\n",variable[i],*(get_variance(variable, data, row, col, variance, aver)+i));}
            break;
        }
        case 5:{printf("ע����׼��ʹ��N-1Ϊ�����ڷ�ĸ��\n");
            aver = get_average(variable, data, row, col, average);
            for(i=0;i<col;i++){
                printf("������%s��׼�%lf\t\n",variable[i],sqrt(*(get_variance(variable, data, row, col, variance, aver)+i)));}
            break;
        }
        case 6:{
            linear_regression(variable, data, row, col);
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