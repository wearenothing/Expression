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

void Push(ElemType item, Stack PtrS)
{
	if (PtrS->top == MAXSIZE - 1)
		return;
	PtrS->data[++(PtrS->top)] = item;
}
ElemType Pop(Stack PtrS)
{
	if (PtrS->top == -1)
		return '0';
	return PtrS->data[(PtrS->top)--];
}
int f(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '(')
		return 0;
	else//处理输入为‘0’的情况
		return -1;
}
int main()
{
	Stack PtrS;
	PtrS = (Stack)malloc(sizeof(struct SNode));
	PtrS->top = -1;

	string str;
	cin >> str;
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0'&&str[i] <= '9')
			cout << str[i];
		else if (str[i] == '(')
			Push(str[i], PtrS);
		else if (str[i] == ')')
		{
			char c = Pop(PtrS);
			while (c != '(')
			{
				cout << c;
				c = Pop(PtrS);
			}
		}
		else
		{
			if (PtrS->top == -1)
				Push(str[i], PtrS);
			else
			{
				char TopElem;
				TopElem = PtrS->data[PtrS->top];
				if (f(str[i])>f(TopElem))
					Push(str[i], PtrS);
				else
				{
					cout << Pop(PtrS);
					TopElem = PtrS->data[PtrS->top];
					while (f(str[i]) <= f(TopElem))
					{
						cout << Pop(PtrS);
						TopElem = PtrS->data[PtrS->top];
					}
					Push(str[i], PtrS);
				}
			}	
		}
		i++;
	}
	while (PtrS->top != -1)
	{
		cout << Pop(PtrS);
	}
}
