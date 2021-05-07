//Author : Dharanendra.L.V.
//Program to implement the singly linked list and it's operations

#include<stdio.h>
#include<stdlib.h>

//structure to contain node
typedef struct node{
    int data;
    struct node *next;
}NODE;

//structure to contain the head and count of the nodes in the list
typedef struct{
    int count;
    NODE *head;
    NODE *rear;
}LIST;

//function for creating the list
LIST* createList(void){
    LIST *list = (LIST*) malloc(sizeof(LIST));
    if(list){
        list->count = 0;
        list->head = NULL;
        list->rear = NULL;
    }
    return list;
}

//function to create a node
NODE *getNode(int ele){
    NODE *node = (NODE*) malloc(sizeof(NODE));
    if(node){
        node->data = ele;
        node->next = NULL;
    }
    return node;
}

//function to insert the node at the beginning of the list
void insertBeg(LIST *lp, int ele){
    NODE *newNode = getNode(ele);
    if(lp->head == NULL){  //if list is empty
        lp->head = lp->rear = newNode;
    }else{
        NODE *temp = lp->head; //temp node to store the first node and swapping the nodes
        lp->head = newNode;
        newNode->next = temp;
    }
    lp->count++;
}

//function to insert the node at the end of the list
void insertEnd(LIST *lp, int ele){
    NODE *newNode = getNode(ele);
    if(lp->head == NULL){//list is empty
        lp->head = lp->rear = newNode;
    }else{
        NODE *temp = lp->head; //temp node pointer to contain the head
        while(temp->next){ //traversing the list until the end node
            temp = temp->next;
        }
        temp->next = newNode;
        //else we can use rear node as below
        //lp->rear->next = newNode;
        lp->rear = newNode;
    }
    lp->count++;
}

//function to add the node before a given node
void insertBefore(LIST *lp, int ele, int key){
    NODE *newNode = getNode(ele);
    if(lp->head == NULL){//list empty
        lp->head = lp->rear = newNode;
    }else{
        NODE *temp = lp->head;
        if(temp->data == key){
            newNode->next = temp;
            lp->head = newNode;
            lp->count--;
            return;
        }
        while(temp){//traversing the list and inserting the node before the given node
            if(temp->next->data == key){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        if(!temp){
            printf("Given node is not found!!\n\n");
        }
    }
    lp->count++;
}

//function to create add the node after a given node
void insertAfter(LIST *lp, int ele, int key){
    NODE *newNode = getNode(ele);
    if(lp->head == NULL){//list empty
        lp->head = lp->rear = newNode;
    }else{
        NODE *temp = lp->head;
        while(temp){//traversing the list and inserting the node after the given node
            if(temp->data == key){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        if(!temp){
            printf("Given nod not found!\n\n");
        }
    }
    lp->count++;
}

//function to delete the beginning node
void deleteBeg(LIST *lp){
    NODE *node = lp->head;
    if(!node){//list empty
        printf("List is empty!\n\n");
        return;
    }
    //deleting the first node i.e.head
    lp->head = node->next;
    free(node);
    lp->count--;
}

//function to delete the node at the end of the list
void deleteEnd(LIST *lp){
    NODE *node = lp->head,*prev;
    if(!node){//list empty
        printf("List is empty!\n\n");
        return;
    }
    while(node->next){//traversing until the last second node of the list
        prev = node;
        node = node->next;
    }
    //deleting the last node
    NODE *temp = node;
    prev->next = NULL;
    free(temp);
    lp->count--;
}

//function to delete the given node
void deleteNode(LIST *lp, int key){
    NODE *node = lp->head, *prev = lp->head;
    if(!node){//list empty
        printf("List is empty!\n\n");
        return;
    }else{
        if(lp->head->data == key){
            lp->head = node->next;
            free(node);
            lp->count--;
            return;
        }
        while(node){//traversing the list and after getting the node deleting it
            if(node->data == key){
                prev->next = node->next;
                free(node);
                break;
            }
            prev = node;
            node = node->next;
        }
        if(!node){
            printf("Given node not found!\n\n");
        }
    }
    lp->count--;
}

//function to delete the node after the a given node
void deleteAfter(LIST *lp, int ele, int key){
    NODE *node = lp->head;
    if(!node){//list empty
        printf("List is empty!\n\n");
        return;
    }
    while(node){//traversing the list and deleting the node after the the given node
        if(node->data == key){
            NODE *temp = node->next;
            if(temp){
                node->next = temp->next;
                free(temp);
            }else{
                printf("The next node does not exist!\n\n");
            }
            break;
        }
        node = node->next;
    }
    lp->count--;
}

//function to delete whole list
void delteList(LIST *lp){
    NODE *node = lp->head, *temp;
    while(node){//deleting the nodes one by one by traversing the list
        temp = node;
        node = node->next;
        free(temp);
    }
    lp->head = lp->rear = NULL;
    printf("Successfully the list is deleted!\n\n");
    lp->count = 0;
}

//function to sort the list
void sortList(LIST *lp){
    NODE *node = lp->head, *nextNode;
    int temp;
    while(node->next){//traverse the list and sorting
        nextNode = node->next;
        while(nextNode){
            if(node->data > nextNode->data){
                temp = node->data;
                node->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        node = node->next;
    }
}

//function to display the list
void display(LIST lp){
    NODE *node = lp.head;
    if(!node){//list is empty
        printf("LIST is empty\n\n");
        return;
    }
    while(node){//traversing the whole list until node is NULL
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n\n");
}

int main(){
    LIST *lp = createList();
    insertBeg(lp, 10);
    insertBeg(lp, 20);
    insertEnd(lp, 30);
    insertBefore(lp, 40, 20);
    insertAfter(lp, 50, 40);
    deleteBeg(lp);
    deleteEnd(lp);
    deleteNode(lp, 50);
    sortList(lp);

    display(*lp);
    return 0;
}
