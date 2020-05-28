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
	printf("�������һ��������");
	::scanf("%lf", &addend_1);
	printf("������ڶ���������");
	::scanf("%lf", &addend_2);
	ret_val = addend_1 + addend_2;
	return ret_val;
}
double subtraction(void)
{
	double minuend;
	double subtrahend;
	double ret_val;
	printf("�����뱻������");
	::scanf("%lf", &minuend);
	printf("�����������");
	::scanf("%lf", &subtrahend);
	ret_val = minuend - subtrahend;
	return ret_val;
}
double multiplication(void)
{
	double multiplier_1;
	double multiplier_2;
	double ret_val;
	printf("�������һ��������");
	::scanf("%lf", &multiplier_1);
	printf("������ڶ���������");
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
	printf("�����뱻������");
	::scanf("%lf", &dividend);
	printf("�����������");
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
	printf("������������֣�");
	::scanf("%lf", &base);
	printf("������ָ�����֣�");
	::scanf("%lf", &exponent);
	ret_val = pow(base, exponent);
	return ret_val;
}
double exp_power(void)
{
	double exponent;
	double ret_val;
	printf("������ָ�����֣�");
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
	printf("�����뱻��������");
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
	printf("������������֣�");
	::scanf("%lf", &base);
	if ((base <= 0) || (base == 1))
	{
		ptr->state = ERROR_IN_BASE;
		return ptr;
	}
	printf("�������������֣�");
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
	printf("�������������֣�");
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
	printf("�������������֣�");
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
	printf("������Ƕȣ��Զ�Ϊ��λ����");
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
	printf("������Ƕȣ��Զ�Ϊ��λ����");
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
	printf("������Ƕȣ��Զ�Ϊ��λ����");
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
	printf("����������ֵ��");
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
	printf("����������ֵ��");
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
	printf("����������ֵ��");
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
	printf("���������ģ����ĵ�һ��������");
	::scanf("%d", &number_1);
	printf("���������ģ����ĵڶ���������");
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
	printf("�������ĺ����꣺");
	::scanf("%lf", &x);
	printf("�������������꣺");
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
	printf("�������ļ�����");
	::scanf("%lf", &radius);
	printf("�������ļ��ǣ�");
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
	printf("��ӭʹ�ù�����2�����������㣡\n");
	printf("��������֧�����й��ܣ�\n");
	printf("һ����������&�򵥱��ʽ���㣺\n");
	printf("1���ӷ�   2������   3���˷�   4������   5���򵥱��ʽ����\n\n");
	printf("�����ݡ�ƽ�������������㣺\n");
	printf("1����ͨ������   2����eΪ�׵�������   3��ƽ����   4����ͨ��������   5����10Ϊ�׵Ķ�������   6����eΪ�׵Ķ�������\n\n");
	printf("�������Ǻ����뷴���Ǻ�����\n");
	printf("1�����Һ���   2�����Һ���   3�����к���   4�������Һ���   5�������Һ���   6�������к���\n\n");
	printf("�ġ��������ܣ�\n");
	printf("1����ģ����   2��ֱ������ת��Ϊ������   3��������ת��Ϊֱ������\n\n");
	color(7);
	while (option == 'Y')
	{
		printf("����������ʹ�õĹ������ڵ������ţ����磬�����ʹ�����к������ܣ������롰3������");
		::scanf("%d", &menu_1);
		while ((menu_1 < 1) || (menu_1 > 4))
		{
			printf("�����������������������루���磬�����ʹ�����к������ܣ������롰3������");
			clean_buffer();
			::scanf("%d", &menu_1);
		}
		if (menu_1 == 1)
		{
			printf("����������ʹ�õľ��幦�ܣ�\n");
			printf("1���ӷ�   2������   3���˷�   4������   5���򵥱��ʽ���㣨���磬�����ʹ�ü������ܣ������롰2������");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 5))
			{
				printf("�����������������������룡\n");
				printf("1���ӷ�   2������   3���˷�   4������   5���򵥱��ʽ���㣨���磬�����ʹ�ü������ܣ������롰2������");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = addition();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = subtraction();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_double = multiplication();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 4)
			{
				result_div = division();
				if (result_div->state == ERROR_IN_DIVIDER)
				{
					printf("��������Ϊ0��\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_div->ret_val);
				}
			}
		}
		else if (menu_1 == 2)
		{
			printf("����������ʹ�õľ��幦�ܣ�\n");
			printf("1����ͨ������   2����eΪ�׵�������   3��ƽ����   4����ͨ��������   5����10Ϊ�׵Ķ�������   6����eΪ�׵Ķ�������\n");
			printf("�����磬�����ʹ��ƽ�������ܣ������롰3������");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 6))
			{
				printf("�����������������������룡\n");
				printf("1����ͨ������   2����eΪ�׵�������   3��ƽ����   4����ͨ��������   5����10Ϊ�׵Ķ�������   6����eΪ�׵Ķ�������\n");
				printf("�����磬�����ʹ��ƽ�������ܣ������롰3������");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = power();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = exp_power();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_sqrt = square_root();
				if (result_sqrt->state == ERROR_IN_RADICAND)
				{
					printf("��������������ڵ���0��\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_sqrt->ret_val);
				}
			}
			else if (menu_2 == 4)
			{
				result_log = log_common();
				if (result_log->state == ERROR_IN_BASE)
				{
					printf("�����������0�Ҳ���Ϊ1��\n");
				}
				else if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("�������ֱ������0��\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_log->ret_val);
				}
			}
			else if (menu_2 == 5)
			{
				result_log = log_10();
				if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("�������ֱ������0��\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_log->ret_val);
				}
			}
			else if (menu_2 == 6)
			{
				result_log = ln();
				if (result_log->state == ERROR_IN_ANTILOGARITHM)
				{
					printf("�������ֱ������0��\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_log->ret_val);
				}
			}
		}
		else if (menu_1 == 3)
		{
			printf("����������ʹ�õľ��幦�ܣ�\n");
			printf("1�����Һ���   2�����Һ���   3�����к���   4�������Һ���   5�������Һ���   6�������к���\n");
			printf("�����磬�����ʹ�����й��ܣ������롰3������");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 6))
			{
				printf("�����������������������룡\n");
				printf("1�����Һ���   2�����Һ���   3�����к���   4�������Һ���   5�������Һ���   6�������к���\n");
				printf("�����磬�����ʹ�����й��ܣ������롰3������");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_double = sine();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 2)
			{
				result_double = cosine();
				printf("���Ϊ��%lf\n", result_double);
			}
			else if (menu_2 == 3)
			{
				result_tan = tangent();
				if (result_tan->state == ERROR_IN_TANGENT)
				{
					printf("�������������Ϊ90�����������\n");
				}
				else
				{
					printf("���Ϊ��%lf\n", result_tan->ret_val);
				}
			}
			else if (menu_2 == 4)
			{
				result_arcsc = arcsine();
				if (result_arcsc->state == ERROR_IN_ARCSC)
				{
					printf("����ֵӦ������[-1, 1]�ڣ�\n");
				}
				else
				{
					printf("���Ϊ��%lf��\n", result_arcsc->ret_val);
				}
			}
			else if (menu_2 == 5)
			{
				result_arcsc = arccosine();
				if (result_arcsc->state == ERROR_IN_ARCSC)
				{
					printf("����ֵӦ������[-1, 1]�ڣ�\n");
				}
				else
				{
					printf("���Ϊ��%lf��\n", result_arcsc->ret_val);
				}
			}
			else if (menu_2 == 6)
			{
				result_double = arctangent();
				printf("���Ϊ��%lf��\n", result_double);
			}
		}
		else if (menu_1 == 4)
		{
			printf("����������ʹ�õľ��幦�ܣ�\n");
			printf("1����ģ����   2��ֱ������ת��Ϊ������   3��������ת��Ϊֱ������\n");
			printf("�����磬�����ʹ����ģ���㹦�ܣ������롰1������");
			::scanf("%d", &menu_2);
			while ((menu_2 < 1) || (menu_2 > 3))
			{
				printf("�����������������������룡\n");
				printf("1����ģ����   2��ֱ������ת��Ϊ������   3��������ת��Ϊֱ������\n");
				printf("�����磬�����ʹ����ģ���㹦�ܣ������롰1������");
				clean_buffer();
				::scanf("%d", &menu_2);
			}
			if (menu_2 == 1)
			{
				result_int = modulus();
				printf("���Ϊ��%d\n", result_int);
			}
			else if (menu_2 == 2)
			{
				result_pol = rec_to_pol();
				printf("�õ�ļ�����Ϊ��(%lf, %lf)\n", result_pol->radius, result_pol->angle);
			}
			else if (menu_2 == 3)
			{
				result_rec = pol_to_rec();
				printf("�õ��ֱ������Ϊ��(%lf, %lf)\n", result_rec->x_coo, result_rec->y_coo);
			}
		}
		printf("\n��Ҫ����ʹ�û��˳���Y/N����");
		clean_buffer();
		::scanf("%c", &option);
	}
}