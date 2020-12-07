#include <iostream>
using namespace std;

void print_DLL(struct node *head,struct node *temp,int n);
struct node *insert_at_begin(struct node *newnode,struct node *head,struct node *tail,int n);
struct node *insert_at_end(struct node *newnode,struct node *head,struct node *tail,int n);
void insert_before_position(struct node *newnode,struct node *head,struct node *tail,struct node *temp,int n);
void insert_after_position(struct node *newnode,struct node *head,struct node *tail,struct node *temp,int n);

struct node
{
    int data;
    struct node *prev,*next;
};

void print_DLL(struct node *head,struct node *temp,int n)
{
    temp=head;
    for(int j=0;j<n;j++)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}

struct node *insert_at_begin(struct node *newnode,struct node *head,struct node *tail,int n)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;

    head=newnode;
    return head;
}

struct node *insert_at_end(struct node *newnode,struct node *head,struct node *tail,int n)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=NULL;
    tail=newnode;

    return tail;
}

void insert_before_position(struct node *newnode,struct node *head,struct node *tail,struct node *temp,int n)
{
    int position;
   cout<<"\nENTER POSITION : ";
   cin>>position;
   temp=head;
   struct node *before=NULL;
   for(int k=1;k<position;k++)
   {
       before=temp;
       temp=temp->next;
   }
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    newnode->prev=before;
    before->next=newnode;

    newnode->next=temp;
    temp->prev=newnode;
    n++;
   print_DLL(head,temp,n);
}

void insert_after_position(struct node *newnode,struct node *head,struct node *tail,struct node *temp,int n)
{
    int position;
   cout<<"\nENTER POSITION : ";
   cin>>position;
   temp=head;
   struct node *after=head->next;
    for(int i=1;i<position;i++)
    {
        temp=temp->next;
        after=after->next;

    }
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    newnode->prev=temp;
    temp->next=newnode;

    newnode->next=after;
    after->prev=newnode;

    n++;
   print_DLL(head,temp,n);

}

int main()
{
    struct node *newnode,*head,*temp,*tail;
    int n;
    cout<<"\n ENTER THE NUMBER OF NODES IN A LINKED LIST YOU WANT : ";
    cin>>n;

    head=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        cout<<"ENTER DATA : ";
        cin>>newnode->data;
        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }

    }
    print_DLL(head,tail,n);

    cout<<"\nINSERT AT BEGIN ";
    n++;
    head=insert_at_begin(newnode,head,tail,n);
    print_DLL(head,tail,n);
    cout<<"\nINSERT AT END ";
    n++;
    tail=insert_at_end(newnode,head,tail,n);
    print_DLL(head,tail,n);

    cout<<"\nINSERT BEFORE POSITION ";
    insert_before_position(newnode,head,tail,temp,n);
    n++;
    cout<<"\nINSERT BEFORE POSITION ";
    insert_after_position(newnode,head,tail,temp,n);



    return 0;
}
