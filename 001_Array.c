#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

int arr[maxsize],n;
void create();
void insert();
void delete();
void search();
void display();

int main(){
      int choice;

      do
      {
          printf("\nMain Menu:\n");
          printf("1.Create\n");
          printf("2.Insert\n");
          printf("3.Delete\n");
          printf("4.Search\n");
          printf("5.Display\n");
          printf("6.Exit\n");

          printf("\nEnter your choice:");
          scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        
        default:
            printf("\nEnter the option between 1 to 6\n");
            break;
        }

      } while (choice<7);
      
    return 0;
}
void create()
{
    int i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the element of your array:\n");
    for ( i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    display();
    
}
void insert()
{
    int i, num, pos;
    printf("Enter the number to be inserted:");
    scanf("%d",&num);
    printf("Enter the position where you want to insert the element in array:");
    scanf("%d",&pos);
    for ( i = n-1; i>= pos; i--)
    {
        arr[i+1]=arr[i];
    }
      arr[pos]=num;
      n=n+1;
      display();
}
void delete()
{
    int i, pos;
    printf("Enter the position from where you want to delete the element:");
    scanf("%d",&pos);
    printf("The element deleted is: %d",arr[pos]);
    for ( i = pos; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
      n=n-1;
    printf("\n");
    display();
    
}
void search()
{
    int search,count,i=0;
    printf("Enter the element you are looking for:");
    scanf("%d",&search);
    for ( i = 0; i < n; i++)
    {
        if (search==arr[i])
        {
            printf("Element %d is present at %d position",search,i);
            count=1;
            break;
        }
        if (count==0)
        {
            printf("Element %d is not in the array",&search);
        }
        printf("\n\n");
        
    }
    
}
void display()
{
    int i;
    printf("Elements in the array are\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n\n");
    
}