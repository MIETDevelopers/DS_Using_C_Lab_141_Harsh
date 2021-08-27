#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *front = NULL;
node *rear = NULL;
int main()
{
    int ch;
    while (1)
    {
        printf("please choice from the following:\n");
        printf("1.Enqueue\n2.Dequeue\n3.display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}
void enqueue()
{
    node *new;
    int num;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
        printf("Unable to allocate the memory\n");
    else
    {
        printf("Please Enter The Value\n");
        scanf("%d", &num);
        new->data = num;
        new->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = new;
        }
        else
            rear->next = new;
        rear = new;
    }
}
void dequeue()
{
    node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        printf("Dequeued Element:%d\n", front->data);
        front = front->next;
      temp->next = NULL;
        free(temp);
    }
}
void display()
{
    node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        printf("Elements are:\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}