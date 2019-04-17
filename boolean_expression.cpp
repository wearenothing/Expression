// 005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<string>
#include <iostream>
#include <stack>
using namespace std;

void clearSpace(string &str)
{
	int i = 0;
	while(str[i])
	{
		if (isspace(str[i]))
		{
			str.erase(i,1);
			i--;
		}
		i++;
	}
}
void clearPar(string &str)
{
	int n = str.size();
	if (str[0] == '('&&str[n - 1] == ')')
	{
		stack<char> s;
		for (int i = 1; i < n - 1; i++)
		{
			if (str[i] == '(')
				s.push(str[i]);
			if (str[i] == ')')
			{
				if (s.empty())
					return;
				else if (s.top() != '(')
					return;
				else
					s.pop();
			}
		}
		if (s.empty())
		{
			str.erase(0, 1);
			str.erase(str.size() - 1, 1);
		}
		else
			return;
	}
}
bool expression(string str)
{
	
	//去除最外面无意义的括号
	clearPar(str);

	int n = str.size();
	//判断
	if (str == "F"||str=="!V")
		return false;
	else if (str == "V"||str=="!F")
		return true;
	else 
	{
		//找到第一个表达式
		string str1 = "";
		int i = 0;
		bool flag = true;
		if (str[0] == '!')
		{
			flag = false;
			if (str[1] == '(')
			{
				str1 += str[1];
				int left = 1;
				for (i = 2; i < n; i++)
				{
					if (str[i] == '(')
						left++;
					else if (str[i] == ')')
						left--;
					else if ((str[i] == '|' || str[i] == '&') && left == 0)
						break;
					str1 += str[i];
				}
			}
			else
			{
				while (str[i] != '|'&&str[i] != '&')
				{
					str1 += str[i];
					i++;
				}
			}
		}
		else if (str[0] == '(')
		{
			str1 += str[0];
			int left = 1;
			for (i = 1; i < n; i++)
			{
				if (str[i] == '(')
					left++;
				else if (str[i] == ')')
					left--;
				else if ((str[i] == '|' || str[i] == '&') && left == 0)
					break;
				str1 += str[i];
			}
		}
		else
		{
			while (str[i] != '|'&&str[i] != '&')
			{
				str1 += str[i];
				i++;
			}
		}
		
		char c = str[i++];
		string str2="";
		for (; i < n; i++)
		{
			str2 += str[i];
		}
		if (c == '&')
		{
			if(flag)
			return expression(str2)&&expression(str1) ;
			else
			return expression(str2)&&(!expression(str1)) ;
		}
		else
		{
			if(flag)
			return  expression(str2)|| expression(str1);
			else
			return  expression(str2)|| (!expression(str1));
		}
	}
}
int main()
{
	int counts = 1;
	string str;
	while (getline(cin, str))
	{
		clearSpace(str);
		cout << "Expression " << counts << ": ";
		if (expression(str))
			cout << "V" << endl;
		else
			cout << "F" << endl;
		counts++;
	}
	return 0;
}

