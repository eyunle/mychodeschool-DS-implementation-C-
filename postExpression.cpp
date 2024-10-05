#include <iostream>
#include <stack>
using namespace std;
//2 3 * 5 4 * + 9 -

void operate(stack<int> *pointerToS,char ch)
{
	int a,b;
	a=pointerToS->top();
	pointerToS->pop();
	b=pointerToS->top();
	pointerToS->pop();
	switch (ch){
		case '+':
			pointerToS->push(a+b);
			break;
		case '-':
			pointerToS->push(b-a);
			break;
		case '*':
			pointerToS->push(a*b);
			break;
		case '/':
			pointerToS->push(b/a);
			break;
	}
}

int postEvaluation()
{
	stack<int> S;
	int x;
	int a,b;
	char ch;
	while(true)
	{
		ch=getchar();//cin会自动把缓冲区的' '和\n清除，所以用getchar()，\n作为判断退出的条件。。
		if(ch<='9'&&ch>='0')
		{
			cin.putback(ch);
			cin>>x;
			S.push(x);
		}
		else if(ch==' ')
		{
			continue;
		}
		else if(ch=='\n')
		{
			break;
		}
		else
		{
			operate(&S,ch);
		}
	}
	return S.top();
}


int main()
{
	int result;
	cout<<"input the postfix expression:"<<endl;
	result=postEvaluation();
	cout<<"result:"<<result<<endl;
}