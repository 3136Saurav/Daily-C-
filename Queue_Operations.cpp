// #include<stdio.h>
#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

// void main()
int main()
{
    int no, ch, e;

    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // printf("Enter data : ");
            // scanf("%d", &no);
            cout<<"Enter data: ";
            cin>>no;
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                // printf("Front element : %d", e);
                cout<<"Front element: "<<e;
            else
                cout<<"/n No front element in Queue as queue is empty";
                // printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            // printf("Wrong choice, Please enter correct choice ");
            cout<<"Wrong choice, Please enter correct choice ";
            break;
        }
    }
    return 0;
}

void create()
{
    front = rear = NULL;
}

void queuesize()
{
    // printf("\n Queue size : %d", count);
    cout<<"\n Queue size : "<<count;
}

void enq(int data)
{
    if (rear == NULL)
    {
        // rear = (struct node *)malloc(1*sizeof(struct node));
        rear = new node();
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        // temp=(struct node *)malloc(1*sizeof(struct node));
        temp = new node();
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        // printf("Queue is empty");
        cout<<"Queue is empty";
        return;
    }
    while (front1 != rear)
    {
        // printf("%d ", front1->info);
        cout<<front1->info;
        front1 = front1->ptr;
    }
    if (front1 == rear)
        cout<<front1->info;
        // printf("%d", front1->info);
}

void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        // printf("\n Error: Trying to display elements from empty queue");
        cout<<"\n Error: Trying to display elements from empty queue";
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            cout<<"\n Dequed value : "<<front->info;
            // printf("\n Dequed value : %d", front->info); ///***************
            free(front);
            front = front1;
        }
        else
        {
            // printf("\n Dequed value : %d", front->info);
            cout<<"\n Dequed value : "<<front->info;
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

void empty()
{
     if ((front == NULL) && (rear == NULL))
        cout<<"\n Queue empty";
        // printf("\n Queue empty");
    else
        cout<<"Queue not empty";
       // printf("Queue not empty");
}
