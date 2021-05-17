#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int ele){
    if(front == -1){
        front++;
    }

    queue[++rear] = ele;
}

void dequeue(){
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

int Front(){
    return queue[front]; 
}

int Rear(){
    return queue[rear];
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }else{
        for(i = front; i <= rear; i++){
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int ele, ch;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.front\n4.rear\n5.Display\n6.Exit\nEnter Your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1 : scanf("%d", &ele);
                     enqueue(ele);
                     break;

            case 2 : dequeue();
                     break;

            case 3 : if(front == -1){
                         printf("Queue is Overflow!\n");
                     }else if(front == MAX-1){
                         printf("Queue is underflow!\n");
                     }else{
                         printf("%d\n", Front());
                     }
                     break;

            case 4 : if(front == -1){
                         printf("Queue is Overflow!\n");
                     }else if(front == MAX-1){
                         printf("Queue is underflow!\n");
                     }else{
                         printf("%d\n", Rear());
                     }
                     break;

            case 5 : display();
                     break;
            
            case 6 : exit(0);

            default : printf("Invalid input!\n");
        }
    }

    return 0;
}
