#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basic_cal.h"
#include "utils.h"

double addition(void)
{
	double addend_1;
	double addend_2;
	double ret_val;
	printf("请输入第一个加数：");
	::scanf("%lf", &addend_1);
	printf("请输入第二个加数：");
	::scanf("%lf", &addend_2);
	ret_val = addend_1 + addend_2;
	return ret_val;
}
double subtraction(void)
{
	double minuend;
	double subtrahend;
	double ret_val;
	printf("请输入被减数：");
	::scanf("%lf", &minuend);
	printf("请输入减数：");
	::scanf("%lf", &subtrahend);
	ret_val = minuend - subtrahend;
	return ret_val;
}
double multiplication(void)
{
	double multiplier_1;
	double multiplier_2;
	double ret_val;
	printf("请输入第一个乘数：");
	::scanf("%lf", &multiplier_1);
	printf("请输入第二个乘数：");
	::scanf("%lf", &multiplier_2);
	ret_val = multiplier_1 * multiplier_2;
	return ret_val;
}
ptr_to_div division(void)
{
	double dividend;
	double divider;
	ptr_to_div ptr;
	ptr = (struct div_ret_val *) malloc(sizeof(struct div_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入被除数：");
	::scanf("%lf", &dividend);
	printf("请输入除数：");
	::scanf("%lf", &divider);
	if (divider == 0)
	{
		ptr->state = ERROR_IN_DIVIDER;
		return ptr;
	}
	ptr->ret_val = dividend / divider;
	return ptr;
}
double power(void)
{
	double base;
	double exponent;
	double ret_val;
	printf("请输入底数部分：");
	::scanf("%lf", &base);
	printf("请输入指数部分：");
	::scanf("%lf", &exponent);
	ret_val = pow(base, exponent);
	return ret_val;
}
double exp_power(void)
{
	double exponent;
	double ret_val;
	printf("请输入指数部分：");
	::scanf("%lf", &exponent);
	ret_val = exp(exponent);
	return ret_val;
}
ptr_to_sqrt square_root(void)
{
	double radicand;
	ptr_to_sqrt ptr;
	ptr = (struct sqrt_ret_val *) malloc(sizeof(sqrt_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入被开方数：");
	::scanf("%lf", &radicand);
	if (radicand < 0)
	{
		ptr->state = ERROR_IN_RADICAND;
		return ptr;
	}
	ptr->ret_val = sqrt(radicand);
	return ptr;
}
ptr_to_log log_common(void)
{
	double antilogarithm;
	double base;
	ptr_to_log ptr;
	ptr = (struct log_ret_val *) malloc(sizeof(log_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入底数部分：");
	::scanf("%lf", &base);
	if ((base <= 0) || (base == 1))
	{
		ptr->state = ERROR_IN_BASE;
		return ptr;
	}
	printf("请输入真数部分：");
	::scanf("%lf", &antilogarithm);
	if (antilogarithm <= 0)
	{
		ptr->state = ERROR_IN_ANTILOGARITHM;
		return ptr;
	}
	ptr->ret_val = log(antilogarithm)/log(base);
	return ptr;
}
ptr_to_log log_10(void)
{
	double antilogarithm;
	ptr_to_log ptr;
	ptr = (struct log_ret_val *) malloc(sizeof(log_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入真数部分：");
	::scanf("%lf", &antilogarithm);
	if (antilogarithm <= 0)
	{
		ptr->state = ERROR_IN_ANTILOGARITHM;
		return ptr;
	}
	ptr->ret_val = log10(antilogarithm);
	return ptr;
}
ptr_to_log ln(void)
{
	double antilogarithm;
	ptr_to_log ptr;
	ptr = (struct log_ret_val *) malloc(sizeof(log_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入真数部分：");
	::scanf("%lf", &antilogarithm);
	if (antilogarithm <= 0)
	{
		ptr->state = ERROR_IN_ANTILOGARITHM;
		return ptr;
	}
	ptr->ret_val = log(antilogarithm);
	return ptr;
}
double sine(void)
{
	double angle;
	double radian;
	double ret_val;
	printf("请输入角度（以度为单位）：");
	::scanf("%lf", &angle);
	radian = angle * PI / 180.0;
	ret_val = sin(radian);
	return ret_val;
}
double cosine(void)
{
	double angle;
	double radian;
	double ret_val;
	printf("请输入角度（以度为单位）：");
	::scanf("%lf", &angle);
	radian = angle * PI / 180.0;
	ret_val = cos(radian);
	return ret_val;
}
ptr_to_tan tangent(void)
{
	double angle;
	double radian;
	ptr_to_tan ptr;
	ptr = (struct tan_ret_val *) malloc(sizeof(tan_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入角度（以度为单位）：");
	::scanf("%lf", &angle);
	if ((angle == (int)angle) && (((int)angle % 180 == 90) || ((int)angle % 180 == -90)))
	{
		ptr->state = ERROR_IN_TANGENT;
		return ptr;
	}
	radian = angle * PI / 180.0;
	ptr->ret_val = tan(radian);
	return ptr;
}
ptr_to_arcsc arcsine(void)
{
	double sine;
	double radian;
	ptr_to_arcsc ptr;
	ptr = (struct arcsc_ret_val *) malloc(sizeof(arcsc_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入正弦值：");
	::scanf("%lf", &sine);
	if ((sine < -1) || (sine > 1))
	{
		ptr->state = ERROR_IN_ARCSC;
		return ptr;
	}
	radian = asin(sine);
	ptr->ret_val = radian * 180 / PI;
	return ptr;
}
ptr_to_arcsc arccosine(void)
{
	double cosine;
	double radian;
	ptr_to_arcsc ptr;
	ptr = (struct arcsc_ret_val *) malloc(sizeof(arcsc_ret_val));
	ptr->state = 0;
	ptr->ret_val = 0.0;
	printf("请输入余弦值：");
	::scanf("%lf", &cosine);
	if ((cosine < -1) || (cosine > 1))
	{
		ptr->state = ERROR_IN_ARCSC;
		return ptr;
	}
	radian = acos(cosine);
	ptr->ret_val = radian * 180 / PI;
	return ptr;
}
double arctangent(void)
{
	double tangent;
	double radian;
	double ret_val;
	printf("请输入正切值：");
	::scanf("%lf", &tangent);
	radian = atan(tangent);
	ret_val = radian * 180 / PI;
	return ret_val;
}
int modulus(void)
{
	int number_1;
	int number_2;
	int ret_val;
	printf("请输入参与模运算的第一个整数：");
	::scanf("%d", &number_1);
	printf("请输入参与模运算的第二个整数：");
	::scanf("%d", &number_2);
	ret_val = number_1 % number_2;
	return ret_val;
}
ptr_to_pol rec_to_pol(void)
{
	double x;
	double y;
	double tan_temp;
	struct pol_coo * ret_val;
	ret_val = (struct pol_coo *) malloc(sizeof(pol_coo));
	printf("请输入点的横坐标：");
	::scanf("%lf", &x);
	printf("请输入点的纵坐标：");
	::scanf("%lf", &y);
	ret_val->radius = hypot(x, y);
	tan_temp = y / x;
	ret_val->angle = atan(tan_temp) * 180 / PI;
	return ret_val;
}
ptr_to_rec pol_to_rec(void)
{
	double radius;
	double angle;
	double angle_temp;
	ptr_to_rec ret_val;
	ret_val = (struct rec_coo *) malloc(sizeof(struct rec_coo));
	printf("请输入点的极径：");
	::scanf("%lf", &radius);
	printf("请输入点的极角：");
	::scanf("%lf", &angle);
	angle_temp = angle * PI / 180;
	ret_val->x_coo = radius * cos(angle_temp);
	ret_val->y_coo = radius * sin(angle_temp);
	return ret_val;
}
void clean_buffer(void)
{
	while(getchar() != '\n')
	{
		continue;
	}
	return;
}

void basic_cal_display()
{
	int menu_1;
	int menu_2;
	int result_int;
	double result_double;
	ptr_to_div result_div;
	ptr_to_sqrt result_sqrt;
	ptr_to_log result_log;
	ptr_to_tan result_tan;
	ptr_to_arcsc result_arcsc;
	ptr_to_pol result_pol;
	ptr_to_rec result_rec;
	char option;
	option = 'Y';
	color(11);
	printf("欢迎使用功能区2——基础运算！\n");
	printf("本功能区支持下列功能：\n");
	printf("一、四则运算&简单表达式计算：\n");
	printf("1、加法   2、减法   3、乘法   4、除法   5、简单表达式计算\n\n");
	printf("二、幂、平方根、对数运算：\n");
	printf("1、普通幂运算   2、以e为底的幂运算   3、平方根   4、普通对数运算   5、以10为底的对数运算   6、以e为底的对数运算\n\n");
	printf("三、三角函数与反三角函数：\n");
	printf("1、正弦函数   2、余弦函数   3、正切函数   4、反正弦函数   5、反余弦函数   6、反正切函数\n\n");
	printf("四、其他功能：\n");
	printf("1、求模运算   2、直角坐标转换为极坐标   3、极坐标转换为直角坐标\n\n");
	color(7);
	while (option == 'Y')
	{
		printf("请输入您想使用的功能所在的类别序号（例如，如果想使用正切函数功能，请输入“3”）：");
		::scanf("%d", &menu_1);
		while ((menu_1 < 1) || (menu_1 > 4))
		{
			printf("您输入的序号有误，请重新输入（例如，如果想使用正切函数功能，请输入“3”）：");
			clean_buffer();
			::scanf("%d", &menu_1);
		}
		if (menu_1 == 1)
		{
			printf("请输入您想使用的具体功能：\n");
			printf("1、加法   2、减法   3、乘法   4、除法   5、简单表达式计算（例如，如果想使用减法功能，请输入“2”）：");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 5))
			{
				printf("您输入的序号有误，请重新输入！\n");
				printf("1、加法   2、减法   3、乘法   4、除法   5、简单表达式计算（例如，如果想使用减法功能，请输入“2”）：");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = addition();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = subtraction();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_double = multiplication();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 4)
			{
				result_div = division();
				if (result_div->state == ERROR_IN_DIVIDER)
				{
					printf("除数不能为0！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_div->ret_val);
				}
			}
		}
		else if (menu_1 == 2)
		{
			printf("请输入您想使用的具体功能：\n");
			printf("1、普通幂运算   2、以e为底的幂运算   3、平方根   4、普通对数运算   5、以10为底的对数运算   6、以e为底的对数运算\n");
			printf("（例如，如果想使用平方根功能，请输入“3”）：");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 6))
			{
				printf("您输入的序号有误，请重新输入！\n");
				printf("1、普通幂运算   2、以e为底的幂运算   3、平方根   4、普通对数运算   5、以10为底的对数运算   6、以e为底的对数运算\n");
				printf("（例如，如果想使用平方根功能，请输入“3”）：");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = power();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = exp_power();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_sqrt = square_root();
				if (result_sqrt->state == ERROR_IN_RADICAND)
				{
					printf("被开方数必须大于等于0！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_sqrt->ret_val);
				}
			}
			else if (menu_2 == 4)
			{
				result_log = log_common();
				if (result_log->state == ERROR_IN_BASE)
				{
					printf("底数必须大于0且不能为1！\n");
				}
				else if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("真数部分必须大于0！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_log->ret_val);
				}
			}
			else if (menu_2 == 5)
			{
				result_log = log_10();
				if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("真数部分必须大于0！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_log->ret_val);
				}
			}
			else if (menu_2 == 6)
			{
				result_log = ln();
				if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("真数部分必须大于0！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_log->ret_val);
				}
			}
		}
		else if (menu_1 == 3)
		{
			printf("请输入您想使用的具体功能：\n");
			printf("1、正弦函数   2、余弦函数   3、正切函数   4、反正弦函数   5、反余弦函数   6、反正切函数\n");
			printf("（例如，如果想使用正切功能，请输入“3”）：");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 6))
			{
				printf("您输入的序号有误，请重新输入！\n");
				printf("1、正弦函数   2、余弦函数   3、正切函数   4、反正弦函数   5、反余弦函数   6、反正切函数\n");
				printf("（例如，如果想使用正切功能，请输入“3”）：");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = sine();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = cosine();
				printf("结果为：%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_tan = tangent();
				if (result_tan->state == ERROR_IN_TANGENT)
				{
					printf("所输入度数不能为90°的奇数倍！\n");
				}
				else
				{
					printf("结果为：%lf\n", result_tan->ret_val);
				}
			}
			else if (menu_2 == 4)
			{
				result_arcsc = arcsine();
				if (result_arcsc->state == ERROR_IN_ARCSC)
				{
					printf("正弦值应在区间[-1, 1]内！\n");
				}
				else
				{
					printf("结果为：%lf度\n", result_arcsc->ret_val);
				}
			}
			else if (menu_2 == 5)
			{
				result_arcsc = arccosine();
				if (result_arcsc->state == ERROR_IN_ARCSC)
				{
					printf("余弦值应在区间[-1, 1]内！\n");
				}
				else
				{
					printf("结果为：%lf度\n", result_arcsc->ret_val);
				}
			}
			else if (menu_2 == 6)
			{
				result_double = arctangent();
				printf("结果为：%lf度\n", result_double);
			}
		}
		else if (menu_1 == 4)
		{
			printf("请输入您想使用的具体功能：\n");
			printf("1、求模运算   2、直角坐标转换为极坐标   3、极坐标转换为直角坐标\n");
			printf("（例如，如果想使用求模运算功能，请输入“1”）：");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 3))
			{
				printf("您输入的序号有误，请重新输入！\n");
				printf("1、求模运算   2、直角坐标转换为极坐标   3、极坐标转换为直角坐标\n");
				printf("（例如，如果想使用求模运算功能，请输入“1”）：");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_int = modulus();
				printf("结果为：%d\n", result_int);
			}
			else if (menu_2 == 2)
			{
				result_pol = rec_to_pol();
				printf("该点的极坐标为：(%lf, %lf)\n", result_pol->radius, result_pol->angle);
			}
			else if (menu_2 == 3)
			{
				result_rec = pol_to_rec();
				printf("该点的直角坐标为：(%lf, %lf)\n", result_rec->x_coo, result_rec->y_coo);
			}
		}
		printf("\n需要继续使用或退出（Y/N）？");
		clean_buffer();
		::scanf("%c", &option);
	}
}