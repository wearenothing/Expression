#include<cstdlib>
#include<iostream>
#include<string>
#define MAXSIZE 1000
using namespace std;
typedef char ElemType;
typedef struct SNode *Stack;
struct SNode
{
	ElemType data[MAXSIZE];
	int top;
};

void Push(ElemType item,Stack PtrS)
{
	if(PtrS->top=MAXSIZE-1)
	return ;
	PtrS->data[++(PtrS->top)]=item;
}
ElemType Pop(Stack PtrS)
{
	if(PtrS->top==-1)
	return '\0';
	return PtrS->data[(PtrS->top)--];
}
int main()
{
	Stack PtrS;
	PtrS=(Stack)malloc(sizeof(struct SNode));
	PtrS->top=-1;
	
	string str;
	cin>>str;
	int i=0;
	while(str[i])
	{
		if(str[i]>='0'&&str[i]<='9')
		cout<<str[i];
		else if(str[i]=='(')
		Push(str[i],PtrS);
		else if(str[i]==')')
		
		i++;
	}
}
