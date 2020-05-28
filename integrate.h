#include<map>
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;

#define Var map<string, double>

const double eps = 1e-12;  //��������
Var vars;   //����Ԥ����
string str;  //���ʽ
string variable;  //������
double a, b;  //����������
 
struct Expression;
struct Constant;
struct UnkownNumber;
struct Operation;
struct Integral;
Expression *expressionTree(string s, int start, int len);
void Initialization();
 
struct Expression
{
public:
    virtual double Evaluate(Var v)
    {
        return 0;
    }
};
Expression *EXP;  //���ʽ��
/*
������
*/
struct Constant : public Expression  
{
public:
    double value;
    Constant(double value)
    {
        this->value = value;
    }
    double Evaluate(Var vars)
    {
        return value;
    }
};
/*
��������
�ɴ���������ӱ��ʽ����
*/
struct Operation: public Expression
{
public:
    char op;
    Expression *Left, *Right;
    Operation(Expression *Left, Expression *Right, char op)
    {
        this->Left = Left;
        this->Right = Right;
        this->op = op;
    }
    double Evaluate(Var v)
    {
        double x = Left->Evaluate(v);
        double y = Right->Evaluate(v);
        switch(op)
        {
        case'+':
            return x + y;
        case'-':
            return x - y;
        case'*':
            return x * y;
        case'/':
            return x / y;
		case'^':
			return pow(x,y);
        }
        return 0;
    }
};
/*
δ֪����
�����ʽ�е�δ֪������ת��
*/
struct UnkownNumber: public Expression
{
public:
    string name;
    UnkownNumber(string name)
    {
        this->name = name;
    }
    double Evaluate(Var v)
    {
        return vars[name];
    }
};
/*
���ַ���תΪ���ʽ��
*/
Expression *expressionTree(string s, int start, int len)
{
    bool hasAlpha = false, hasOperator = false;
    int bracket = 0, PS = -1, MD = -1;
    while(start <= len && s[start] == '(' && s[len] == ')')
        start++, len--;
    if(start > len)
        return new Constant(0);
    for(int i = start; i <= len; i++)
    {
        if(s[i] != '.' && !isdigit(s[i]))
        {
            if(isalpha(s[i]))
                hasAlpha = true;
            else
            {
                hasOperator = true;
                switch(s[i])
                {
                case '+':
				case '^':
					if(!bracket) MD = i;
                    break;
                case '-':
                    if(!bracket) PS = i;
                    break;
                case '*':
                case '/':
                    if(!bracket) MD = i;
                    break;
                case '(':
                    bracket++;
                    break;
                case ')':
                    bracket--;
                    break;
                }
            }
        }
    }
 
    if(hasAlpha == false && hasOperator == false)
        return new Constant(stod(s.substr(start, len - start + 1)));
    else if(hasOperator == false)
        return new UnkownNumber(s.substr(start, len - start + 1));
    else
    {
        int mid = PS == -1 ? MD : PS;
        return new Operation(expressionTree(s, start, mid - 1), expressionTree(s, mid + 1, len), s[mid]);
    }
    return 0;
}
/*
������
*/
struct Integral
{
public:
    double a, b;
    Integral(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    double Function(double x)
    {
        vars[variable]=x;
        return EXP->Evaluate(vars);
    }
    double simpson(double a, double b)
    {
        double c = a + (b - a) / 2;
        return (Function(a) + 4 * Function(c) + Function(b)) * (b - a) / 6.0;
    }
    double calculate(double a, double b, double Eps)
    {
        double c = a + (b - a) / 2;
        double mid = simpson(a, b);
        double Left = simpson(a, c);
        double Right = simpson(c, b);
        if(fabs(Left + Right - mid) <= 15.0 * eps)
            return Left + Right + (Left + Right - mid) / 15.0;
        return calculate(a, c, Eps / 2.0) + calculate(c, b, Eps / 2.0);
    }
    double Evaluate(double Eps)
    {
        double up, down;
        down = this->a;
        up = this->b;
        return calculate(down, up, Eps);
    }
}; 
void Initialization()  //��Ԥ�賣��ֵ
{
    vars["e"] = 2.7182818284;
    vars["pi"] = acos(-1);
}
 
 