#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtBeginning(Node**head,int insertedData)
{
    Node*current=new Node;
    current->data=insertedData;
    current->next=NULL;

    if(*head==NULL) 
            *head=current;
        
    else 
        {
            current->next=*head;
            *head=current;
        }
}

void display(Node**head)
{
    Node*temp=*head;
    while(temp!=NULL) 
        {
            if(temp->next!=NULL)
            cout<<temp->data<<" ";
            else
            cout<<temp->data;
            
            temp=temp->next; 
        }
    cout<<endl;
}
 
Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;
    
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else 
        {
            if (prev)
                prev->next = cur->next;
            Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    if ((*newHead) == NULL)
        (*newHead) = pivot;
        
    (*newEnd) = tail;
    return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
        return head;
    Node *newHead = NULL, *newEnd = NULL;
    Node *pivot = partition(head, end, &newHead, &newEnd);
 
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
	cin >> n;
	int value;
    
    for(int i = 0; i < n; i++)
    {
    	cin >> value;
    	insertAtBeginning(&head, value);
    }

    cout << "before sorting \n";
    display(&head);
 
    quickSort(&head);
 
    cout << "after sorting \n";
    display(&head);
 
    return 0;
}
