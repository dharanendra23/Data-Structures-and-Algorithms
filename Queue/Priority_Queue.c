#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int ind;
    struct node *next;
} NODE;

typedef struct
{
    int count;
    NODE *head;
} LIST;

LIST *createList(void)
{
    LIST *lp = (LIST *)malloc(sizeof(LIST));
    if (lp)
    {
        lp->count = 0;
        lp->head = NULL;
    }

    return lp;
}

NODE *getNode(int ele, int ind)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node)
    {
        node->data = ele;
        node->ind = ind;
        node->next = NULL;
    }

    return node;
}

void insertNode(LIST *lp, int ele, int ind)
{
    NODE *node = getNode(ele, ind), *temp = lp->head;
    if (temp == NULL)
    {
        lp->head = node;
    }
    else
    {
        if (node->ind < temp->ind)
        {
            node->next = temp;
            lp->head = node;
        }
        else
        {
            while (temp->next != NULL && 
                        node->ind > temp->next->ind)
            {
                temp = temp->next;
            }
            
            node->next = temp->next;
            temp->next = node;
        }
    }

    lp->count++;
}

void delete(LIST *lp){
    NODE *node = lp->head, *temp;
    if(!node){
        printf("List is empty!\n");
        return;
    }

    temp = lp->head; 
    lp->head = lp->head->next;
    free(temp);

    lp->count--;
}

void display(LIST lp){
    NODE *node = lp.head;
    if(!node){
        printf("List is empty!\n");
        return;
    }

    while(node){
        printf("%d->", node->data, node->ind);
        node = node->next;
    }
    printf("NULL\nNumber of Nodes : %d\n", lp.count);
}

int main()
{
    LIST *lp = createList();

    insertNode(lp, 10, 3);
    insertNode(lp, 20, 1);
    insertNode(lp, 30, 2);
    insertNode(lp, 100, 1);
   // delete(lp);
    display(*lp);

    return 0;
}
