/*1)to find whether any subset of arr can make the given sum by summing its elements*/
/*2)-for equal sum partition(i.e. dvide arr completly into two subset such that sum of both is equal) of array check if sum of arr is divisible by 2 if not then ans will be false if yes then divide sum by 2 and 
question become same as subset_sum*/
/*2)for counting tthe total subset that indivisal makes sum of there element equal to given sum we just put +(plus) sign instread of or and define dp as int and also bool to int of function*/
#include<stdio.h>
#include<stdbool.h>
bool dp[10][25];//according to constrain
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
bool subset_sum(int *arr,int n,int s){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){//indicate when i=0andj=0 then dp[0][0]=true because n(i)=0 means null set and required sum(j)=0 can be achieved
                dp[i][j]=true;//by null subset
            }
        else if(arr[i-1]<=j){
            dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
        }
    }
    return dp[n][s];
}
int main(){
    int arr[5]={2,3,7,8,10};//given array
    int s=6;//to make the sum=s
    int ans=subset_sum(arr,5,s);
    printf("%d",ans);
    return 0;
}
