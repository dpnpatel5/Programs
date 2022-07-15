#include <iostream>

using namespace std;
struct node{
    int data;
    struct node* link;
};

void print(struct node* head)
{   
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->link;
    }
    return;
}

struct node* insertatBegin(struct node *head,int data)
{
    struct node *temp=new node;
    temp->data=data;
    temp->link=head;
    /*if(head==NULL)
    head=temp;
    else
    temp->link=head;*/
    head=temp;
    
    return head;
}
struct node* insertatEnd(struct node *head,int data)
{
    struct node *temp1=head;
    struct node *temp=new node;
    temp->data=data;
    temp->link=NULL;
    while(temp1->link!=NULL)
    {
     temp1=temp1->link;
    }
    temp1->link=temp;
    return head;
}
struct node* insertatPos(struct node *head,int data,int pos)
{
    int count=1;
    struct node *temp=head;
    struct node *temp1=new node;
    temp1->data=data;
    temp1->link=NULL;
    if(pos==1)
    {
        temp1->link=head;
        head=temp1;
        return head;
    }
    else
    {
        for(int i=0;i<pos-2;i++)
            temp=temp->link;
        temp1->link=temp->link;
        temp->link=temp1;
        return head;
    }
}
struct node* deleteAtPos(struct node* head,int pos)
{
    struct node* temp=head;
    for(int i=0;i<pos-2;i++)
    {
        temp=temp->link;
    }
    struct node *temp1=temp->link;
    temp->link=temp->link->link;
    delete temp1;
    return head;
}
struct node* reverse (struct node* head)
{
    struct node* prev;
    struct node* next;
    prev=NULL;
    struct node* current=head;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
void printRecursion(struct node* head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    printRecursion(head->link);
}
void reverseprintRecursion(struct node* head)
{
    if(head==NULL)
    return;
    reverseprintRecursion(head->link);
    cout<<head->data<<" ";
    
}
struct node* reverseRecursion(struct node* head)
{
    struct node* temp=head;
    if(temp->link==NULL)
    {
        head=temp;
        return head;
    }
    reverseRecursion(temp->link);
    struct node* temp1=temp->link;
}
/*
int main()
{
    struct node* head= NULL;
    head=insertatBegin(head,10);head=insertatBegin(head,30);
    head=insertatBegin(head,40);head=insertatBegin(head,20);
    head=insertatEnd(head,60);head=insertatEnd(head,5);
    head=insertatPos(head,14,3);
    print(head);
    cout<<"\n";
    head=deleteAtPos(head,3);
    print(head);
    cout<<"\n";
    head=reverse(head);
    printRecursion(head);
    cout<<"\n";
    reverseprintRecursion(head);
    return 0;
}
*/
