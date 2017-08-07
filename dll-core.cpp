#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node
{
	int data;
	node* prev;
	node* next;
};

node* insert_head(node* head,int x)
{
	node* temp = new node();
	temp->data =x;
	if(head==NULL)
	{
		head = temp;
		temp->prev = NULL;
		temp->next = NULL;
		return head;
	}
	temp->prev = NULL;
	head->prev = temp;
	temp->next=head;
	head = temp;
	return head;
}

void print_rec(node* head)
{
	while(head !=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

node* insert_end(node* head,int x)
{
	node* temp = new node();
	temp->data =x;
	if(head==NULL)
	{
		head = temp;
		temp->prev = NULL;
		temp->next = NULL;
		return head;
	}
	node* ptr = head;
	while(ptr->next !=NULL)
		ptr = ptr->next;
	ptr->next = temp;
	temp->prev = ptr;
	temp->next = NULL;
	return head;
}

node* insert_at_pos(node* head,int x,int pos)
{
	node* temp = new node();
	temp->data =x;
	if(pos==1)
	{
		
		temp->prev = NULL;
		temp->next = head;
		head = temp;
		return head;
	}
	node* ptr = head;
	for(int i=1;i<(pos-1);i++)				//iterating to previous position
		ptr = ptr->next;
	temp->prev = ptr;
	temp->next = ptr->next;
	ptr->next->prev = temp;
	ptr->next = temp;
	return head;
}

node* delete_front(node* head)
{
	node* temp = head;
	head = head->next;
	head->prev =  NULL;
	delete temp;
	return head;
}

node* delete_end(node* head)
{
	node* ptr=head;
	while(ptr->next !=NULL)
		ptr=ptr->next;
	ptr->prev->next=NULL;
	delete ptr;
	return head;
}

node* delete_at_pos(node* head,int pos)
{
	if(pos==1)
		delete_front(head);
	else
	{
		node* ptr=head;
		for(int i=1;i<(pos);i++)
			ptr=ptr->next;                              //iterating to that position
		node* p=ptr->prev;
		node* q = ptr->next;
		p->next=q;
		q->prev = p;
		delete ptr;
		return head;
	}
	
}

node* reverse(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		swap(temp->prev,temp->next);
		head = temp;
		temp=temp->prev;
	}
	return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node* head = NULL;
    head=insert_head(head,5);
    head=insert_head(head,4);
    head=insert_head(head,3);
    head=insert_head(head,2);
    head=insert_head(head,1);
    print_rec(head);
    head=insert_end(head,6);
    head=insert_end(head,6);
    head=insert_end(head,6);
    head=insert_end(head,6);
    print_rec(head);
    head = insert_at_pos(head,9,2);
    print_rec(head);
    head = insert_at_pos(head,9,1);
    print_rec(head);
    head = delete_end(head);
    print_rec(head);
    head = delete_front(head);
    print_rec(head);
    head = delete_at_pos(head,1);
    print_rec(head);
    head = reverse(head);
    print_rec(head);
    return 0;
}
