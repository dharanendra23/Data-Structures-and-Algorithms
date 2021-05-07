// C Program to reading n numbers using array and displaying the same
#include<stdio.h>

int main()
{
    int n; //Declaring size of an array
    printf("Enter the size of the array : ");
    scanf("%d",&n); //Reading the value n from the user

    int arr[n]; //Integer array declaration with size n

    printf("Enter the array elements : ");

    //Reading integer numbers and storing it into an array
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array elements are : ");

    //Printing array elements
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
