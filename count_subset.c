//given a array and a sum s we have to find totall subset whose indivisial sum of element are equal to given sum
#include<stdio.h>
#include<stdbool.h>
int dp[10][25];//according to constrain
int subset_sum(int *arr,int n,int s){
    for(int k=0;k<n+1;k++){
        for(int l=0;l<s+1;l++){
            if(k==0){
                dp[k][l]=0;//if no element in array then we can't make subset of sum equal to l
            }
             if(l==0){//for dp[0][0]=1 because there is one subset i.e. null array
                dp[k][l]=1;//if sum(l)=0 then null array sum is equal to 0 so 1 sub set present
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
        if(arr[i-1]<=j){
            dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
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
    int s=10;//to make the sum=s
    int ans=subset_sum(arr,5,s);
    printf("%d",ans);
    return 0;
}
