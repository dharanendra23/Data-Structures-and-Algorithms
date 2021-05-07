#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE;

NODE* createRoot(void){
    NODE *root = (NODE*) malloc(sizeof(NODE));

    root->data = 0;
    root->left = NULL;
    root->right = NULL;

    int ele;
    printf("Enter the data : ");
    scanf("%d",&ele);
    
    if(ele == -1) return NULL;

    root->data = ele;     

    printf("Enter left for %d \n", ele);
    root->left = createRoot();

    printf("Enter right for %d \n", ele);
    root->right = createRoot();

    return root;
}

void preOrder(NODE *root){
    if(root == NULL) return;
    printf("%d  ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(NODE *root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d  ",root->data);
    inOrder(root->right);
}

void postOrder(NODE *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ",root->data);
}

int main(){
    NODE *rt = createRoot();

    inOrder(rt);
    printf("\n");
    preOrder(rt);
    printf("\n");
    postOrder(rt);
    printf("\n");

    return 0;
}
