#include <stdio.h>  
#include <stdlib.h> 

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

 node *head=NULL;

void Insert_1st();   
void insert_at_specific();  
void delete_at_specific(); 
void search();        
void display();      
void main()
{
    int choice;
   
    while (1)
    {
        printf("\nMain menu");
        printf("\n1.Insert in begining");
        printf("\n2.Insert At Specified Position");
        printf("\n3.Delete From A Spefic Position");
        printf("\n4.View ");
        printf("\n5.To search element");
        printf("\n6.Exit");
        printf("\nEnter your choice\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            Insert_1st();
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
            search();
            break;
            case 6: 
            exit(0);
        default:
            printf("Please enter valid choice..");
        }
    }
}
void Insert_1st()
{
    node *new,*temp;
    int num;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Unable To create node\n");
    }
    else
    {
        printf("Enter data which you want to insert\n");
        scanf("%d", &num);
        new->data = num;
        new->next = head;
        head = new;
    }
       
   
}

void insert_at_specific()
{
    int i, loc, item;
     node *ptr, *temp;
    ptr = (node *)malloc(sizeof( node));
    if (ptr == NULL)
    {
        printf("unable to insert\n");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the index after which you want to insert ");
        scanf("\n%d", &loc);
        temp = head;
        for (i = 0; i < loc-1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted");
    }
}
void delete_at_specific()
{
     node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the index of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc-1; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d ", loc + 1);
}
void display()
{
     node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void search()
{
    node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        for (int i = 0; ptr != NULL; i++)
        {
            if (ptr->data == item)
            {
                printf("item found at location %d\n", i + 1);
                flag = 0;
                if (flag == 0)
                {
                    break;
                }
            }
            else
            {
                flag = 1;
            }

            ptr = ptr->next;
            if (ptr == NULL)
            {
                if (flag == 1)
                {
                    printf("Item not found\n");
                }
            }
        }
    }
}
