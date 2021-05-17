#include <stdio.h>
#define MAX 5

int dqueue[MAX];
int rear = -1;
int front = -1;

void insertFront(int ele)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Dqueue is in Overflow condition!\n");
    }
    else if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front = front - 1;
        }
    }
    dqueue[front] = ele;
}

void insertRear(int ele)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Dqueue is in Overflow condition!\n");
        return;
    }
    else if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }
    dqueue[rear] = ele;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Dqueue is in Underflow codition!\n");
        return;
    }
    printf("Deleted item is : %d\n", dqueue[front]);
    if (front == rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        if (front == MAX-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Dqueue is in Underflow codition!\n");
        return;
    }
    printf("Deleted item is : %d\n", dqueue[rear]);
    if (front == rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        if (rear == 0)
        {
            rear = MAX-1;
        }
        else
        {
            rear--;
        }
    }
}

void display()
{
    int f = front, r = rear;
    if (f == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("The elements of the dqueue are : ");
    if (f <= r)
    {
        while (f <= r)
        {
            printf("%d ", dqueue[f]);
            f++;
        }
        printf("\n");
    }
    else
    {
        while (f <= MAX - 1)
        {
            printf("%d ", dqueue[f]);
            f++;
        }
        int i = 0;
        while (i <= r)
        {
            printf("%d ", dqueue[i]);
            i++;
        }
        printf("\n");
    }
}

void input_dequeue()
{
    int ch, ele;
    do
    {
        printf("1.insertRear\n2.deleteFront\n3.dleteRear\n4.Display\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &ele);
            insertRear(ele);
            break;

        case 2:
            deleteFront();
            break;

        case 3:
            deleteRear();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Choice!\n");
        }
    } while (ch != 5);
}

void output_dequeue()
{
    int ch, ele;
    printf("1.insertRear\n2.insertFront\n3.dleteRear\n4.Display\n5.Exit\n");
    scanf("%d", &ch);
    do
    {
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted at the rear: ");
            scanf("%d", &ele);
            insertRear(ele);
            break;

        case 2:
            printf("Enter the element to be inserted at the front : ");
            scanf("%d", &ele);
            insertFront(ele);
            break;

        case 3:
            deleteRear();
            break;

        case 4:
            display();
            break;

        default:
            printf("Invalid Choice!\n");
        }
    } while (ch != 5);
}

int main()
{
    int ch;
    printf("1.Input restricted dequeue\n2.Output restricted dequeue\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        input_dequeue();
        break;

    case 2:
        output_dequeue();
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}
