//C Program to print the position of the smallest number in an array
#include<stdio.h>

int main()
{
    int n; //Size of the array
    printf("Enter the size of the array : ");
    scanf("%d",&n); //Scanning the value of n from the user

    int arr[n]; //Array declaration of size n
    printf("Enter the array elements : ");

    //Reading array elements
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int smallest = arr[0]; //Assigning first element of the array to the variable smallest
    int pos=0; //Assigning the position as 0

    //Traversing the whole array except first element
    for(int i=1;i<n;i++)
    {
        //Assigning the array element to smallest if it is smaller than the smallest element
        //and its position to pos
        if(smallest>arr[i])
        {
            smallest = arr[i];
            pos = i;
        }
    }

    //Printing the smallest element of the array
    printf("The position of the smallest element of the array is : %d \n",pos);

    return 0;
}
