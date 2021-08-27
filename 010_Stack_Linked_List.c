#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *head = NULL;

int main()
{
    while (1)
    {
        int ch;
        printf("Please select from the following:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}
void push()
{
    node *ptr;
    int num;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Unable To create node\n");
    }
    else
    {
        printf("Enter data which you want to insert\n");
        scanf("%d", &num);
        ptr->data = num;
        ptr->link = head;
        head = ptr;
    }
}

void pop()
{
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Stack Is In Underflow Condition\n");
    }
    else
    {
        printf("Removed Element is:%d\n", head->data);
        head = head->link;
        free(temp);
    }
}
void display()
{
    node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack Is Empty\n");
    }
    else
    {

        printf("Values are:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}