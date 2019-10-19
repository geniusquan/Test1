#include <ctype.h>(C)<cctype>(C++)
#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
char token[61]; /*��ű��ʽ�ַ���������*/ 
int n=0; 
void error(void) /*���������*/ 
{ 
	printf("ERROR!\n"); 
	exit(1); 
} 
void match(char expected) /*����ַ�ƥ��ĺ���*/ 
{ 
	if(token[n]==expected) 
		token[++n]=getchar(); 
	else error(); 
} 
double term(void); /*����˳��ĺ���*/ 

double factor(void); /*�������ź����ֵĺ���*/ 

double exp(void) /*����Ӽ��ĺ���*/ 
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
				if(div==0) /*�������Ϊ������*/ 
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
		while(isdigit(token[n])||token[n]=='.') /*���ַ���ת��Ϊ������*/ 
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
	printf("����������������\n");
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

