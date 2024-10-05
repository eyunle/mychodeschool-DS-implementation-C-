#include<iostream>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;

bool IsEmpty()
{
	return top==-1;
}

void Push(int x)
{
	if(top<MAX_SIZE)
	{
		top++;
		A[top]=x;
	}
	else
	{
		cout<<"Error:stack overflow!"<<endl;
	}
}

void Pop()
{
	if (!IsEmpty())
	top--;
	else
	cout<<"The Stack is empty!!!can't pop!!!'"<<endl;
}

int Top()
{
	return A[top];
}

void Print() {
	cout<<"stack:";
	for (int i=0;i<=top;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}


int main() {
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
}