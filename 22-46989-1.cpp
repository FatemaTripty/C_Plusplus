#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next= NULL;
    }
    ~Node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};
void insertAtFirst(Node* &head, int data)
{
    Node* temp= new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtLast(Node* &tail, int data)
{
    Node* temp= new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtAnyPosition(Node* &head, int position, int data)
{
    Node* temp=head;
    Node* n= new Node(data);
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
}
void deleteNode(int position, Node* &head)
{
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int n=1;
        while(n<position)
        {
            prev=curr;
            curr=curr->next;
            n++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int smallestElement(Node* head)
{
    int min= head->data;
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data<min)
        {
            min=temp->data;

        }
        temp=temp->next;
    }

    cout<<"The minimum element is : "<<min<<endl;;
}
int largestElement(Node* head)
{
    Node* temp = head;
    int max=0;
    while(temp!=NULL)
    {
        if(temp->data>max)
        {
            max=temp->data;

        }
        temp=temp->next;
    }

    cout<<"The maximum element is : "<<max<<endl;;
}
void display(Node* head)
{
    int temp1;
    int temp2;
    Node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
Node* reverse(Node* head)
{
    Node* temp=head;
    Node* temp1=temp->next;
    temp->next=NULL;
    temp->prev=temp1;
    while(temp1!=NULL)
    {
        temp1->prev=temp1->next;
        temp1->next=temp;
        temp=temp1;
        temp1=temp1->prev;
    }
    head=temp;
    return head;

}

int main ()
{
    Node* n= new Node(15);
    Node* head= n;
    Node* tail= n;
    insertAtFirst(head,18);
    insertAtFirst(head,17);

    insertAtFirst(head,19);
    insertAtLast(tail,20);

    cout<<"After insertion data list is : ";
    insertAtAnyPosition(head,2,89);
    display(head);
    cout<<endl;
     cout<<"After insertion at any position list is : ";
    deleteNode(3,head);
    display(head);
    cout<<endl;
    cout<<"After deleting data list is : ";
    deleteNode(1,head);
    display(head);
    cout<<endl;
    smallestElement(head);
    cout<<endl;
    largestElement(head);
    cout<<endl;
    cout<<"Reverse of the list is : ";
    head=reverse(head);
    display(head);
    return 0;

}
