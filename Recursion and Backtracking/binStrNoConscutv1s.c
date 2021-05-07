#include<stdio.h>

int binStr(int n){

    if(n == 1 || n == 2)
        return n+1;
    
    return binStr(n-1) + binStr(n-2);
}

// int binStr(int n){
//     int i, num1 = 2, num2 = 3, sum = 0;
//     if(n == 1 || n == 2){
//         return n+1;
//     }
//     for(i = 1; i < n-1; i++){
//         sum = num1 + num2;
//         num1 = num2;
//         num2 = sum; 
//     }

//     return sum;
// }

int main(){
    int n = 3;

    printf("%d", binStr(n));

    return 0;
}