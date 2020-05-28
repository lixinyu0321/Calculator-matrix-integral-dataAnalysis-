#ifndef BASIC_CAL_H_
#define BASIC_CAL_H_

#define PI 3.14159265358979323846
#define ERROR_IN_DIVIDER 1
#define ERROR_IN_BASE 2
#define ERROR_IN_ANTILOGARITHM 3
#define ERROR_IN_RADICAND 4
#define ERROR_IN_TANGENT 5
#define ERROR_IN_ARCSC 6

	double addition(void);
	double subtraction(void);
	double multiplication(void);
	struct div_ret_val
	{
		int state;
		double ret_val;
	} ;
	typedef div_ret_val * ptr_to_div;
	ptr_to_div division(void);

    double power(void);
	double exp_power(void);
	struct sqrt_ret_val
	{
		int state;
		double ret_val;
	} ;
	typedef sqrt_ret_val * ptr_to_sqrt;
	ptr_to_sqrt square_root(void);
	struct log_ret_val 
	{
		int state;
		double ret_val;
	} ;
	typedef log_ret_val * ptr_to_log;
	ptr_to_log log_common(void);
	ptr_to_log log_10(void);
	ptr_to_log ln(void);

	double sine(void);
	double cosine(void);
	struct tan_ret_val
	{
		int state;
		double ret_val;
	} ;
	typedef tan_ret_val * ptr_to_tan;
	ptr_to_tan tangent(void);
	struct arcsc_ret_val
	{
		int state;
		double ret_val;
	} ;
	typedef arcsc_ret_val * ptr_to_arcsc;
	ptr_to_arcsc arcsine(void);
	ptr_to_arcsc arccosine(void);
	double arctangent(void);

	int modulus(void);
	struct rec_coo 
	{
		double x_coo;
		double y_coo;
	} ;
	struct pol_coo
	{
		double radius;
		double angle;
	} ;
	typedef rec_coo * ptr_to_rec;
	typedef pol_coo * ptr_to_pol;
	ptr_to_pol rec_to_pol(void);
	ptr_to_rec pol_to_rec(void);

	void clean_buffer(void);

	void basic_cal_display();

#endif