#include "calculus.h"
#include "integrate.h"
#include "utils.h"

void derivative_polynomial(void)//多项式求导
   {
      float a[10000];
      int n,s,i,j;
      printf("请输入最大次数的值:");
      scanf("%d",&n);
      for(i=0;i<=n;i++)
         {
         printf("请输入次数为%d的系数:",i);
         scanf("%f",a+i);
         }
      printf("请输入求导的次数:");
      scanf("%d",&s); 
      for(j=1;j<=s;j++)
         {
         for(i=1;i<=(n-j+1);i++)
            {
            a[i-1]=i*a[i];
            }   
         }
       printf("%f+",a[0]);
       for(i=1;i<(n-s);i++)
            {
            printf("%f*x^%d+",a[i],i);
            }
         printf("%f*x^%d",a[n-s],(n-s));
}
void derivative_logarithm(void)//对数函数求导
{
     float a;
     printf("请输入对数函数的底数：") ;
     cin>>a;
     printf("导数：1/(x*ln%f)",a);
} 
void derivative_exponential(void)//指数函数求导
{
     float a;
     printf("请输入指数函数的底数：") ;
     scanf("%f",&a);
     printf("导数：(ln%f)*%f^x",a,a);
} 
void derivative_trigonometric(void)//三角函数求导
{
     char a[6];
     printf("请输入三角函数（sin,cos,tan,cot,sec,csc,arcsin,arccos,arctan或者arccot）：") ;
     scanf("%s",a);
     getchar();
     if(a[0]=='s'&&a[1]=='i'&&a[2]=='n') 
        printf("导数：cosx");
     else if(a[0]=='c'&&a[1]=='o'&&a[2]=='s') 
        printf("导数：-sinx");
     else if(a[0]=='t'&&a[1]=='a'&&a[2]=='n') 
        printf("导数：(secx)^2");
     else if(a[0]=='c'&&a[1]=='o'&&a[2]=='t') 
        printf("导数：-(cscx)^2");
     else if(a[0]=='s'&&a[1]=='e'&&a[2]=='c') 
        printf("导数：(secx)*(tanx)");
     else if(a[0]=='c'&&a[1]=='s'&&a[2]=='c') 
        printf("导数：-(cscx)*(cotx)");
     else if(a[0]=='a'&&a[1]=='r'&&a[2]=='c'&&a[3]=='s'&&a[4]=='i'&&a[5]=='n') 
        printf("导数：(1-x^2)^(-1/2)");
     else if(a[0]=='a'&&a[1]=='r'&&a[2]=='c'&&a[3]=='c'&&a[4]=='o'&&a[5]=='s') 
        printf("导数：-(1-x^2)^(-1/2)");
     else if(a[0]=='a'&&a[1]=='r'&&a[2]=='c'&&a[3]=='t'&&a[4]=='a'&&a[5]=='n') 
        printf("导数：1/(1+x^2)");
     else if(a[0]=='a'&&a[1]=='r'&&a[2]=='c'&&a[3]=='c'&&a[4]=='o'&&a[5]=='t') 
        printf("导数：-1/(1+x^2)");
}
void integral(void)//积分
{
	/*
     double a,b,i,j;
     double sum=0;
     double d=0;
     int n,k;
     char c;
     double s[10000];
     printf("请输入函数类型：\n（多项式函数请输入A,对数函数请输入B,指数函数请输入C,三角函数请输入D）");
     scanf("%c",&c);
     printf("请输入区间上限：");
     scanf("%f",&a);
     printf("请输入区间下限：");
     scanf("%f",&b); 
     if (c=='A')
        {
         printf("请输入最大次数的值:");
         scanf("%d",&n);
         for(k=0;k<=n;k++)
            {
            printf("请输入次数为%d的系数:",k);
            scanf("%f",s+k);
            }
         for(i=b;i<=a;i=i+0.001)
            {
            for(k=0,j=0;k<=n;k++,j++)
               {
               d=d+s[k]*pow(i,j);
               }
            sum=sum+d*0.001;
            d=0;
            }
         }
     if (c=='B')
       {
        printf("请输入对数函数的底数：") ;
        scanf("%f",&j);
        sum=(a*log(a)-a)/log(j)-(b*log(b)-b)/log(j);
        }
     if (c=='C')
       {
        printf("请输入指数函数的底数：") ;
        scanf("%f",&j);
        for(i=b;i<=a;i=i+0.0001)
            {
            d=pow(j,i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     if (c=='D')
       { 
       printf("请输入三角函数（sin,cos,tan,cot,sec,csc,arcsin,arccos,arctan或者arccot）：") ;
       scanf("%s",s);
       getchar();
     if(s[0]=='s'&&s[1]=='i'&&s[2]=='n') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=sin(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='c'&&s[1]=='o'&&s[2]=='s') 
       {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=cos(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='t'&&s[1]=='a'&&s[2]=='n') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=tan(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='c'&&s[1]=='o'&&s[2]=='t') 
       {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=1/tan(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='s'&&s[1]=='e'&&s[2]=='c') 
       {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=1/cos(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='c'&&s[1]=='s'&&s[2]=='c') 
       {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=1/sin(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='a'&&s[1]=='r'&&s[2]=='c'&&s[3]=='s'&&s[4]=='i'&&s[5]=='n') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=asin(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='a'&&s[1]=='r'&&s[2]=='c'&&s[3]=='c'&&s[4]=='o'&&s[5]=='s') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=acos(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     else if(s[0]=='a'&&s[1]=='r'&&s[2]=='c'&&s[3]=='t'&&s[4]=='a'&&s[5]=='n') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=atan(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
      else if(s[0]=='a'&&s[1]=='r'&&s[2]=='c'&&s[3]=='c'&&s[4]=='o'&&s[5]=='t') 
        {
        for(i=b;i<=a;i=i+0.0001)
            {
            d=(3.1415926/2)-atan(i);
            sum=sum+d*0.0001;
            d=0;
            }
        }
     }           
     printf("积分=%f",sum);
	 */
	Initialization();
    cout << "请输入表达式（目前只支持单变量以及+，-，×，÷，^（幂与指数）运算）：" << endl;
    cin >> str;
    EXP = expressionTree(str, 0, str.length() - 1);
    cout << "请输入积分的下界和积分上界：" << endl;
    cin >> a >> b;
    cout << "请输入变量名字：" << endl;
    cin >> variable;
    Integral I (a, b);
    printf("%.5f\n", I.Evaluate(eps));
}  
void extremum(void)//极值
{
     double a,b,i,j;
     double sum=0;
     double d0=0;
     double d1=0;
     double d2=0;
     double flag=0.00001;
     int n,k;
     char c;
     double s[10000];
     char p[10];
     printf("请输入函数类型：\n（多项式函数请输入A,对数函数请输入B,指数函数请输入C,三角函数请输入D）");
     cin>>c;
     printf("请输入区间上限：");
     cin>>a;
     printf("请输入区间下限：");
     cin>>b; 
     if (c=='A')
        {
         printf("请输入最大次数的值:");
         scanf("%d",&n);
         for(k=0;k<=n;k++)
            {
            printf("请输入次数为%d的系数:",k);
            scanf("%lf",s+k);
            }
         for(k=1;k<=n;k++)
            {
            s[k-1]=k*s[k];
            }
         for(i=b;i<=a;i=i+0.0001)
            {
            for(k=0,j=0;k<=n;k++,j++)
               {
               d0=d0+s[k]*pow(i,j);
               d1=d1+s[k]*pow((i-0.0001),j);
               d2=d2+s[k]*pow((i+0.0001),j);
               }
            if(d0==0&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            d0=0;
            d1=0;
            d2=0;
            }
         if(flag==0.00001)
            printf("函数在此区间内无极值！"); 
         }
     if (c=='B')
       {
        printf("请输入对数函数的底数：") ;
        scanf("%lf",&j);
        for(i=b;i<=a;i=i+0.0001)
            {
            d0=1/(i*log(j));
            d1=1/((i-0.0001)*log(j));
            d2=1/((i+0.0001)*log(j));
            if(d0==0&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
         if(flag==0.00001)
            printf("函数在此区间内无极值！"); 
        }
     if (c=='C')
       {
        printf("请输入指数函数的底数：") ;
        scanf("%lf",&j);
        for(i=b;i<=a;i=i+0.0001)
            {
            d0=(log(j))*pow(j,i);
            d1=(log(j))*pow(j,(i-0.0001));
            d2=(log(j))*pow(j,(i+0.0001));
            if(d0==0&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
        if(flag==0.00001)
            printf("函数在此区间内无极值！");
        }
     if (c=='D')
       { 
       printf("请输入三角函数（sin,cos,tan,cot,sec,csc,arcsin,arccos,arctan或者arccot）：") ;
       scanf("%s",p);
       getchar();
     if(p[0]=='s'&&p[1]=='i'&&p[2]=='n') 
        {
        for(i=b;i<=a;i=i+0.001)
            {
            d0=cos(i);
            d1=cos(i-0.001);
            d2=cos(i+0.001);
            if(d0<=0.0001&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
        if(flag==0.00001)
            printf("函数在此区间内无极值！");
        }
     else if(p[0]=='c'&&p[1]=='o'&&p[2]=='s') 
       {
        for(i=b;i<=a;i=i+0.001)
            {
            d0=-sin(i);
            d1=-sin(i-0.001);
            d2=-sin(i+0.001);
            if(d0<=0.0001&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
        if(flag==0.00001)
            printf("函数在此区间内无极值！");
        }
     else if(p[0]=='t'&&p[1]=='a'&&p[2]=='n') 
        {
        printf("函数在此区间内无极值！");
        }
     else if(p[0]=='c'&&p[1]=='o'&&p[2]=='t') 
        {
        printf("函数在此区间内无极值！");
        }
     else if(p[0]=='s'&&p[1]=='e'&&p[2]=='c') 
        {
        for(i=b;i<=a;i=i+0.001)
            {
            d0=tan(i)/cos(i);
            d1=tan(i-0.001)/cos(i-0.001);
            d2=tan(i+0.001)/cos(i+0.001);
            if(d0<=0.0001&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
        if(flag==0.00001)
            printf("函数在此区间内无极值！");
        }
     else if(p[0]=='c'&&p[1]=='s'&&p[2]=='c') 
        {
        for(i=b;i<=a;i=i+0.001)
            {
            d0=-1/tan(i)*sin(i);
            d1=-1/tan(i-0.001)*sin(i-0.001);
            d2=-1/tan(i+0.001)*sin(i+0.001);
            if(d0<=0.0001&&(d1*d2)<0)
               {
               printf("%lf",i);
               flag=i;
               }
            }
        if(flag==0.00001)
            printf("函数在此区间内无极值！");
        }
     else if(p[0]=='a'&&p[1]=='r'&&p[2]=='c'&&p[3]=='s'&&p[4]=='i'&&p[5]=='n') 
        {
        printf("函数在此区间内无极值！");
        }
     else if(p[0]=='a'&&p[1]=='r'&&p[2]=='c'&&p[3]=='c'&&p[4]=='o'&&p[5]=='s') 
        {
        printf("函数在此区间内无极值！");
        }
     else if(p[0]=='a'&&p[1]=='r'&&p[2]=='c'&&p[3]=='t'&&p[4]=='a'&&p[5]=='n') 
        {
        printf("函数在此区间内无极值！");
        }
      else if(p[0]=='a'&&p[1]=='r'&&p[2]=='c'&&p[3]=='c'&&p[4]=='o'&&p[5]=='t') 
        {
        printf("函数在此区间内无极值！");
        }
     }               
}      

void calculus_display()
{
	color(11);
	printf("欢迎使用功能区3——微积分！\n");
    int input;
	int choice;
	reuse:
    //设置goto接口以供需要重复使用
    color(11);
	printf("\n1、求导数   2、求定积分   3、求区间极值\n请选择您需要使用的功能：");
	color(7);
	scanf("%d",&input);
    switch(input){
        case 1:
			{
				printf("\n1、多项式   2、对数   3、指数 4、三角函数\n请选择您需要使用的功能：");
				cin>>choice;
				switch(choice)
				{
				case 1:
					{
						derivative_polynomial(); break;
					}
				case 2:
					{
						derivative_logarithm(); break;
					}
				case 3:
					{
						derivative_exponential(); break;
					}
				case 4:
					{
						derivative_trigonometric(); break;
					}
				default: break;
				}
				break;
			}
        case 2:
			{
				integral(); break;
            }
        case 3:
			{
				extremum(); break;
			}
        default: break;
    }
    char c;
    printf("\n需要继续使用或退出（Y/N）？");
    cin>>c;
    if(c == 'Y' || c == 'y') goto reuse;
    else   printf("谢谢使用！");
}