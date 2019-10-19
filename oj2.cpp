#include <ctype.h>(C)<cctype>(C++)
#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
char token[61]; /*存放表达式字符串的数组*/ 
int n=0; 
void error(void) /*报告错误函数*/ 
{ 
	printf("ERROR!\n"); 
	exit(1); 
} 
void match(char expected) /*检查字符匹配的函数*/ 
{ 
	if(token[n]==expected) 
		token[++n]=getchar(); 
	else error(); 
} 
double term(void); /*计算乘除的函数*/ 

double factor(void); /*处理括号和数字的函数*/ 

double exp(void) /*计算加减的函数*/ 
{ 
	double temp=term(); 
	while((token[n]=='+')||(token[n]=='-')) 
	switch(token[n]) 
	{ 
		case'+':
			match('+'); 
			temp+=term(); 
		break; 
		case'-':
			match('-'); 
			temp-=term(); 
		break; 
	} 
	return temp; 
} 
double term(void) 
{ 
	double div; 
	double temp=factor(); 
	while((token[n]=='*')||(token[n]=='/')) 
		switch(token[n]) 
		{ 
			case'*':
				match('*'); 
				temp*=factor(); 
				break; 
			case'/':
				match('/'); 
				div=factor(); 
				if(div==0) /*处理除数为零的情况*/ 
				{ 
					printf("The divisor is zero!\n"); 
					exit(1); 
				} 
				temp/=div; 
				break; 
		} 
	return temp; 
} 
double factor(void) 
{ 
	double temp; 
	char number[61]; 
	int i=0; 
	if(token[n]=='(') 
	{ 
		match('('); 
		temp=exp(); 
		match(')'); 
	} 
	else if(isdigit(token[n])||token[n]=='.') 
	{ 
		while(isdigit(token[n])||token[n]=='.') /*将字符串转换为浮点数*/ 
		{ 
			number[i++]=token[n++]; 
			token[n]=getchar(); 
		} 
			number[i]='\0'; 
			temp=atof(number); 
	} 
	else 
		error();
	return temp; 
} 
int main() 
{ 
	double result; 
	printf("请输入四则混合运算\n");
		token[n]=getchar(); 
		result=exp(); 
		if(token[n]=='\n') 
		{ 
			token[n]='\0'; 
			printf("%s=%g\n",token,result); 
		} 
		else error();  
	return 0; 
}

