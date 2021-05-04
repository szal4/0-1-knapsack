//maximum values(each value have some weight) a bag can store with a givin capacity(weight) of bag
#include<stdio.h>
#include<conio.h>
int dp[10][10];//according to constrain
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int knapsack(int *val,int *wt,int w,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
              dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);  
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int val[3]={60,100,120};
    int wt[3]={1,2,3};
    int w=5;
    int ans=knapsack(val,wt,w,3);
    printf("%d",ans);
    return 0;
}
