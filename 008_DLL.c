#include <stdio.h>
#include <stdlib.h>
void create();
void insert_at_beg();
void insert_at_end();
void insert_at_specific();
void display();
void delete_at_beg();
void delete_at_last();
void delete_at_specific();
void linear_search();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *head = NULL;
node *last = NULL;

int main()
{
    int ch;
    create();
    while (1)
    {

        printf("Please Choose From The Following:\n");
        printf("1.insert from begining\n2.Insert from Last\n3.Insert from specific postion\n4.Display\n5.Delete at beg\n6.Delete from end\n7.Delete from specific\n8.Linear search\n9.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_specific();
            break;
        case 4:
            display();
            break;
        case 5:
            delete_at_beg();
            break;
        case 6:
            delete_at_last();
            break;
        case 7:
            delete_at_specific();
            break;
        case 8:
            linear_search();
            break;
        case 9:
            exit(0);
        default:
            printf("Wrong choice!");
        }
    }
}
void create()
{
    node *new, *temp;
    int num, n;
    printf("How many node you want to create for your list\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        new = (node *)malloc(sizeof(node));
        if (new == NULL)
        {
            printf("List is empty");
        }
        else
        {
            printf("Enter %d data for your list\n", i + 1);
            scanf("%d", &num);
            new->data = num;
            new->prev = NULL;
            new->next = NULL;
            if (head == NULL && last == NULL)
            {
                head = new;
                temp = new;
            }
            else
            {
                new->prev = temp;
                temp->next = new;
                temp = new;
            }
        }
    }
        last = new;
}
void insert_at_beg()
{
    node *new;
    new = (node *)malloc(sizeof(node));
    int d;
    if (new == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter data which you want to insert\n");
        scanf("%d", &d);
        new->data = d;
        new->next = head;
        head->prev = new;
        new->prev = NULL;
        head = new;
    }
}
void insert_at_end()
{
    node *new;
    int d;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter data which you want to insert\n");
        scanf("%d", &d);
        new->data = d;
        new->next = NULL;
        new->prev = last;
        last->next = new;
        last = new;
    }
}
void insert_at_specific()
{
    node *new, *temp;
    int l, d;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter the location of element which you want to insert\n");
        scanf("%d", &l);
        printf("Enter data which you want to insert\n");
        scanf("%d", &d);
        new->data = d;
        temp = head;
        for (int i = 0; i < l - 1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        new->prev = temp;
        temp->next = new;
    }
}
void display()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
void delete_at_beg()
{
    node *temp;
    if (head == NULL)
        printf("list is empty\n");
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
void delete_at_last()
{
    node *temp;
    if (head == NULL)
        printf("list is empty\n");
    else
    {
        temp = last;
        last = last->prev;
        last->next = NULL;
        free(temp);
    }
}
void delete_at_specific()
{
    node *temp;
    int l;
    temp = head;
    if (head == NULL)
        printf("list is empty\n");
    else
    {
        printf("enter the position of element which you want to delete\n");
        scanf("%d", &l);
        for (int i = 0; i < l - 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}
void linear_search()
{
    node *temp;
    int v, found;
    temp = head;
    printf("Enter the data which you want to search");
    scanf("%d", &v);
    for (int i = 0; temp != NULL; i++)
    {
        if (temp->data == v)
        {
            printf("Element at %d location found\n", i + 1);
            found = 1;
          
           
                break;
            
        }
        else
        {
            found = 0;
        }
        temp = temp->next;
        if (temp == NULL)
        {
            if (found == 0)
            {
                printf("element not found\n");
            }
        }
    }
}