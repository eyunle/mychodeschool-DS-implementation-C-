#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node* head=NULL;

//insert node at beginning
void InsertAtHead(int x){
	Node* temp=new Node();
	temp->data=x;
	temp->prev=NULL;
	temp->next=head;
	head=temp;
}

//insert node at end
void InsertAtTail(int x){
	Node* temp=new Node();
	Node* cur=head;
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if (cur==NULL)
	{
		head=temp;
		return;
	}
	while (cur->next!=NULL)
	{
		cur=cur->next;
	}
	temp->prev=cur;
	cur->next=temp;
}

void lPrint(Node* p)
{
	if (p==NULL)
	{
		return;
		cout<<endl;
	}
	cout<<p->data<<" ";
	lPrint(p->next);
}

void rPrint(Node* p)
{
	if (p==NULL)
	{
		return;
	}
	rPrint(p->next);
	cout<<p->data;
}

int main()
{
	head=NULL;
	int n,x;
	cout<<"how many?"<<endl;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"at end!"<<endl;
		cin>>x;
		InsertAtTail(x);
		lPrint(head);
	}
}