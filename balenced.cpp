#include <iostream>
#include <stack>
using namespace std;

//括号是否匹配
//从左到右扫描
//左括号，如{[(,入栈
//右括号，检查是否和栈顶括号匹配
//匹配，出栈
//不匹配，return false
//扫描结束，如果isempty，return true
bool isBalanced(char* ch,int n)
{
	stack<char> S;
	for (int i=0;i<n;i++)
	{
		switch (ch[i])
		{
			case '{':
			case '(':
			case '[':
				S.push(ch[i]);
				break;
			case '}':
				if (S.top()=='{')
				{
					S.pop();
					break;
				}
				else
				return false;
			case ')':
				if (S.top()=='(')
				{
					S.pop();
					break;
				}
				else
				return false;
			case ']':
				if (S.top()=='[')
				{
					S.pop();
					break;
				}
				else
				return false;
		}
	}
	if(S.empty())
	return true;
	else
	return false;
}
int main()
{
	char ch[51];
	cout<<"a patentheses:"<<endl;
	gets(ch);
	if(isBalanced(ch,strlen(ch)))
	cout<<"balenced"<<endl;
	else
	cout<<"not balanced"<<endl;
}