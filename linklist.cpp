#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};


//insert a node at the beginning，参数传出
Node* Insert(int x,Node* head)
{
	Node *temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}

/*地址传出
Node* Insert(int x,Node** pointerToHead)
{
	Node *temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=*pointerToHead;
	*pointerToHead=temp;
}
*/

//insert a node at position n
void Insert(int x,Node** pointerToHead,int pos)
{
	Node *temp1=new Node();
	temp1->data=x;
	temp1->next=NULL;
	if (pos==1)
	{
		temp1->next=*pointerToHead;
		*pointerToHead=temp1;
		return;
	}
	Node *temp2=*pointerToHead;
	for (int i=1;i<pos-1;i++)
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
	
}

//delete a node at position n
void Delete(Node** pointerToHead,int pos)
{
	Node* temp1=*pointerToHead;
	if(pos==1)
	{
		*pointerToHead=temp1->next;
		delete temp1;
		return;
	}
	for (int i=1;i<pos-1;i++)
	{
		temp1=temp1->next;
	}
	Node* temp2=temp1->next;
	temp1->next=temp1->next->next;
	delete temp2;
}

//reverse a linklist(iterate)
void Reverse(Node** pointerToHead)
{
	struct Node *cur,*prev,*next;
	cur=*pointerToHead;
	prev=NULL;
	while(cur !=NULL)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	*pointerToHead=prev;
}

//reverse a linklist(recursion)
Node* rReverse(Node* p)
{
	Node *temp;
	if(p->next==NULL)
	{
		temp=p;
		return temp;
	}
	temp=rReverse(p->next);
	p->next->next=p;
	p->next=NULL;//保证首元结点地址为NULL
	return temp;
}


//print linklist
void Print(Node *head)
{
	struct Node* temp = head;
	while(temp!= NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//print(recursion)
void rPrint(Node *p)
{
	if(p==NULL)
	{
		return;
	}
	cout<<p->data<<" ";
	rPrint(p->next);
}

//reverse print(recursion)
void reversePrint(Node *p)
{
	if(p==NULL)
	{
		return;
	}
	cout<<p->data<<" ";
	rPrint(p->next);
}


int main() {
	struct Node* head=NULL;//empty list;
	printf("How many?\n");
	int n,x;
	int p;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		printf("Enter the number \n");
		scanf("%d",&x);
		head=Insert(x,head);//注意这里函数里的head改变指向首元结点，main的head不会改变，需要把参数传出或者再用一个指针指向head或者引用
		Print(head);
	}
//	cout<<"Insert 3 at pos 2"<<endl;
//	Insert(3,&head,2);
//	Print(head);
//	cout<<"Delete node at?"<<endl;
//	cin>>p;
//	Delete(&head,p);
//	Print(head);
	cout<<"reverse it!"<<endl;
	head=rReverse(head);
//	Print(head);
	rPrint(head);
}
