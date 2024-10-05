#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node* top=NULL;

bool IsEmpty()
{
	return top==NULL;
}

void Push(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->next=top;
	top=temp;
}

void Pop()
{
	if(IsEmpty())
	{
		cout<<"can't pop!"<<endl;
		return;
	}
	Node* temp=top;
	top=temp->next;
	delete temp;
}


int Top()
{
	if(!IsEmpty())
	{
		return top->data;
	}
	else
	{
		cout<<"Stack is empty!!"<<endl;
		return 0;
	}
}

void Print(Node* p)
{
	if(p==NULL)
	{
		cout<<endl;
		return;
	}
	Print(p->next);
	cout<<p->data<<" ";
}

int main()
{
	Push(2);Print(top);
	Push(5);Print(top);
	Push(10);Print(top);
	Pop();Print(top);
	Push(12);Print(top);
}