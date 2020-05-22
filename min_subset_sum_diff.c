//you have to divide array in two part such that difference between the sum of element of both araay is minimum
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool dp[6][25];
bool subset(int *arr,int n,int s){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int k=1;k<n+1;k++){
        for(int l=0;l<s+1;l++){
            if(arr[k-1]>l){
                dp[k][l]=dp[k-1][l];
            }
            else{
                dp[k][l]=dp[k-1][l-arr[k-1]]||dp[k-1][l];
            }
        }
    }
    return dp[n][s];
}
int main(){
    int arr[4]={1,6,11,5},sum=0,check;
    bool b;
    for(int i=0;i<4;i++){
        sum+=arr[i];
    }
    int min=sum;
    for(int j=0;j<=sum/2;j++){//instread of checking for different sum we can return last row when sum is passed into subset function 
        b=subset(arr,4,j);//because last row indicate for all elemet and for different value of j(sum)
        if(b){
           check=abs(sum-2*j);
        if(check<min){
            min=check;
        }
        }
    }
   printf("%d",min);
}
