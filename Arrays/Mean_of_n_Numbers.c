//C Program to finding the mean of n numbers
#include<stdio.h>

int main()
{
    int n; //Array size or number of elements
    printf("Enter the number of elements : ");
    scanf("%d",&n); // reading n from the user

    int arr[n]; //Declaration of the array
    printf("Enter the array elements : ");

    //Scanning array elements
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int sum=0; //Assigning the value 0 at the time of declaration of sum variable

    //Summation of all array elements
    for(int i=0;i<n;i++)
    {
        sum += arr[i];    //It is same as, sum = sum + arr[i];
    }

    float mean;
    mean = sum/n; //Mean of all array elements

    //Printing the mean value
    printf("Mean of all array elements is : %f",mean);

    return 0;
}
