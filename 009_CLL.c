#include <stdio.h>
#include <stdlib.h>
void create();
void insert_at_specific();
void delete_at_specific();
void display();
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

int count, no;

int main()
{

    int ch;

    while (1)
    {

        printf("Please Choose From The Following:\n");
        printf("1.Create node\n2.Insert from specific\n3.delete from specific postion\n4.Display\n5.Linear search\n6.Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert_at_specific();
            break;
        case 3:
            delete_at_specific();
            break;
        case 4:
            display();
            break;
        case 5:
            linear_search();
        default:
            printf("Wrong choice!");
        }
    }
}
void create()
{
    node *new;
    int val;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("unable to create node");
    }
    else
    {
        printf("Enter %d value for your node\n", no + 1);
        scanf("%d", &val);
        new->prev = NULL;
        new->data = val;
        new->next = NULL;
        if (head == NULL && last == NULL)
        {
            head = last = new;
        }
        else
        {
            last->next = new;
            new->prev = last;
            last = new;
        }
        last->next = head;
        count++;
        no++;
    }
}

void insert_at_specific()
{
    node *new, *temp;
    int l, d, choice, Insert;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Unable to create node\n");
    }
    else
    {

        if (count == 1)
        {
            printf("There is only one node\n1.Insert from beg\n2.Insert from end");
            scanf("%d", &choice);
            if (choice == 1)
            {
                Insert = 1;
            }
            else
            {
                if (choice == 2)
                    Insert = 2;
            }
        }
        if (count > 1)
        {
            printf("Please enter the location\n");
            scanf("%d", &l);
        }

        if (l == 0 || Insert == 1)
        {

            printf("Enter data which you want to insert\n");
            scanf("%d", &d);

            new->data = d;
            new->next = head;
            head->prev = new;
            head = new;
            head->prev = NULL;
            last->next = head;
            count++;
        }
        else
        {
            if (count == l || Insert == 2)
            {
                new->prev = last;

                printf("Enter data which you want to insert\n");
                scanf("%d", &d);
                new->data = d;
                new->next = head;
                last->next = new;
                last = new;
                count++;
            }
            else
            {
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
                count++;
            }
        }
    }
}
void delete_at_specific()
{
    node *temp;
    int l;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (head->next == head)
        {
            head = NULL;
            free(head);
            count--;
        }
        else
        {
            printf("Enter the position of element which you want to delete\n");
            scanf("%d", &l);

            if (l == 1)
            {

                temp = head;
                head = head->next;
                head->prev = NULL;
                free(temp);
                count--;
            }
            else
            {
                if (l == count)
                {
                    temp = last;
                    last = last->prev;
                    last->next = head;
                    free(temp);
                    count--;
                }

                temp = head;
                for (int i = 0; i < l - 1; i++)
                {
                    temp = temp->next;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                free(temp);
                count--;
            }
        }
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
        printf("Elements in node are:\n");
        while (temp->next != head)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
        printf("\n");
    }
}
void linear_search()
{
    node *temp;
    int v, found;
    temp = head;
    printf("Enter data which you want to search");
    scanf("%d", &v);

    for (int i = 0; temp->next != head; i++)
    {
        if (temp->data == v)
        {
            printf("Element found at %d location", i + 1);
            break;
        }
        else
        {
            found = 1;
            temp = temp->next;
        }
    }
       
    if (temp->data == v)
    {
        printf("Element found");
    }
    else
 
        printf("Element not found");
       
}