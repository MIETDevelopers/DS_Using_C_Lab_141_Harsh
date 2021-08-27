#include <stdio.h>
#include <stdlib.h>
void insert();
void pop();
void view();
int Stack[100], sizeofarry,INDEX = -1, ch, val, i;
int main()
{
    printf(">>enter size of array\n");
    scanf("%d", &sizeofarry);
    do
    {
        printf("\nmain menu");
        printf("\n1.Insert");
        printf("\n2.pop");
        printf("\n3.view");
        printf("\n4.exit");

        printf("\n>>enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            pop();
            break;
        case 3:
            view();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid statement\n");
        }
    } while (1);
}
void insert()
{
    if (INDEX == sizeofarry - 1)
    {
        printf(">>stack overflow\n ");
    }
    else
    {
        printf(">>enter number which you want to insert\n");
        scanf("%d", &val);
        INDEX = INDEX + 1;
        Stack[INDEX] = val;
    }
}
void pop()
{
    if (INDEX == -1)
    {
        printf(">>stack is underflow\n");
    }
    else
    {
            INDEX = INDEX - 1;       
    }
}
void view()
{
    if (INDEX == -1)
    {
        printf(">>stack empty\n");
    }
    else
    {
        for (i = INDEX; i >= 0; i--)
        {
            printf("%d\t", Stack[i]);
        }
    }
}