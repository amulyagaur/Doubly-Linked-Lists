#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node
{
	int data;
	node* prev;
	node* next;
};
struct node* head;

//function to dynamically allocate a new node
node* new_node(int x)
{
	node* temp = new node();
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

//function to insert at the head of the doubly-linkedlist
void insert_at_head(int x)
{
	node* temp = new_node(x);
	if(head==NULL)
	{
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next=head;
	head = temp;
}

//function to print the doubly linked list

void print_f()
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

//function to print the reverse of doubly-linkedlist 

void print_r()
{
	node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	cout<<"reverse is"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}

//function to reverse a doubly linked list
void reverse()
{
	node* temp = head;
	while(temp!=NULL)
	{
		swap(temp->prev,temp->next);
		head = temp;
		temp=temp->prev;
	}
}

//function to insert at the tail of doubly linked list
void insert_at_tail(int x)
{
	node* temp = new_node(x);
	node* temp1 = head;
	if(head==NULL)
	{
		head = temp;
		return;
	}
	//else iterate to the last node 

	while(temp1->next != NULL)
		temp1=temp1->next;
	temp1->next = temp;
	temp->prev = temp1;
}



int main()
{
    head = NULL;
    insert_at_head(2); print_f(); print_r();
    insert_at_head(4); print_f(); print_r();	
    insert_at_head(6); print_f(); print_r();
    insert_at_head(8); print_f(); print_r();
    reverse();
    print_r();
    insert_at_tail(1);
    print_f();
    return 0;
}
