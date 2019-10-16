#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
//����ջ
typedef struct
{
    Status *base;
    Status *top;
    int stacksize;
}SqStack;
//��ʼ��
 Status InitStack(SqStack &S)
{
    S.base=(Status*)malloc(STACK_INIT_SIZE*sizeof(Status));
    if(!S.base){exit(-1);return 0;}
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return 1;
}
//��ջ
Status Push(SqStack &S,Status e)
{
    if(S.top-S.base>=S.stacksize){
            S.base=(Status*)realloc(S.base,(STACKINCREMENT+STACK_INIT_SIZE)*sizeof(Status));
            S.top=S.base+S.stacksize;
    S.stacksize=STACKINCREMENT+STACK_INIT_SIZE;}
    *S.top=e;
    S.top++;
    return 1;
}
//��ջ
Status Pop(SqStack &S,Status &e)
{
    if(S.base==S.top)return 0;
    S.top--;
    e=*S.top;
    return 1;
}
//�õ�ջ��Ԫ��
Status GetTop(SqStack S)
{
    if(S.base==S.top)return 0;
    else return *(S.top--);
}
SqStack change(SqStack &S,int n,int r)
{
    while(n)
    {
        Push(S,n%r);
        n/=r;
    }
    return S;
}
int main()
{
    int n,r;
    SqStack S;
    InitStack(S);
    printf("������Ҫת�������֣�\n");
    scanf("%d",&n);
    printf("������Ҫת���Ľ��ƣ�\n");
    scanf("%d",&r);
    if(n==0){printf("0\n");return 0;}
    change(S,n,r);
    int e;
    printf("ת��Ϊ%d���ƽ����\n",r);
    while(S.base!=S.top)
    {
        Pop(S,e);
        printf("%d",e);
    }
    printf("\n");
    scanf("%d",&n);
    return 0;
}
