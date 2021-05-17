#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int rear = -1, front = -1;

void enqueue(int ele){
    if(front != 0 && rear == MAX-1){
        rear = -1;
    }

    if(front == -1){
        front++;
    }

    queue[++rear] = ele;
}

void dequeue(){
    if(rear == front){
        rear = front = -1;
    }else{
        if(front == MAX-1)
            front = 0;
        else
            front++;
    }
}

int queueFront(){
    return queue[front];
}

int queueRear(){
    return queue[rear];
}

int display(){
    int i = 0;
    if(front > rear){
        for(i = front; i <= MAX-1; i++){
            printf("%d  ", queue[i]);
        }

        for(i = 0; i <= rear; i++){
            printf("%d  ", queue[i]);
        }
    }else{
        for(i = front; i <= rear; i++){
            printf("%d  ", queue[i]);
        }
    }
    printf("\n");
}

int main(){
    int ch, ele;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\n5.Display\n6.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if((front == 0 && rear == MAX-1) || (front == rear+1)){
                printf("Queue is Overflow!\n");
            }else{
                printf("Enter the element to store : ");
                scanf("%d", &ele);
                enqueue(ele);
                printf("Successfully inserted the element in the queue!\n");
            }
            break;

        case 2:
            if(front == -1 && rear == -1){
                printf("Queue is Underflow!\n");
            }else{
                dequeue(ele);
                printf("Successfully deleted the element from the queue!\n");
            }
            break;

        case 3:
            if(front == -1 && rear == -1){
                printf("Queue is Empty!\n");
            }else{
                printf("%d\n", queueFront());
            }
            break;

        case 4:
            if(front == -1 && rear == -1){
                printf("Queue is Empty!\n");
            }else{
                printf("%d\n", queueRear());
            }
            break;

        case 5:
            if(front == -1 && rear == -1){
                printf("Queue is Empty!\n");
            }else{
                display();
            }
            break;

        case 6:
            exit(0);
            break;                    
        
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }

    return 0;
}
