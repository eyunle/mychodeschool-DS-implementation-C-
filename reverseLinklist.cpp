#include <iostream>
#include <stack>
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

//reverse a linklist(stack)
void sReverse(Node** pointerToHead)
{
	stack<Node*> S;
	Node *temp=*pointerToHead;
	while(temp!=NULL)
	{
		S.push(temp);
		temp=temp->next;
	}
	*pointerToHead=S.top();
	S.pop();
	temp=*pointerToHead;
	while(!S.empty())
	{
		temp->next=S.top();
		S.pop();
		temp=temp->next;
	}
	temp->next=NULL;
}


//print linklist
void Print(Node *head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	printf("\n");
}

//下面这个改错了
// print(recursion reverse)
//Node* rPrint(Node *p)
//{
//	if(p->next==NULL)
//	{
//		head=p;
//		return head;
//	}
//	rPrint(p->next);
//	cout<<p->data<<" ";
//}
/*地址传head
Node* Insert(int x,Node** pointerToHead)
{
	Node *temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=*pointerToHead;
	*pointerToHead=temp;
}

*/
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
	sReverse(&head);
	Print(head);
}