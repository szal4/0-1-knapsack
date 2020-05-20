#include <stdio.h>
#include<conio.h>
int dp[52][10];
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int knapsack(int *val,int *weight,int w,int n){
    if(w==0||n==0){
        return 0;
    }
    else if(dp[w-1][n-1]!=-1){
        return dp[w-1][n-1];
    }
    else if(weight[n-1]>w){
         dp[w-1][n-1]=knapsack(val,weight,w,n-1);
         return dp[w-1][n-1];
    }
    else{
    dp[w-1][n-1]=max(val[n-1]+knapsack(val,weight,w-weight[n-1],n-1),knapsack(val,weight,w,n-1));
       return dp[w-1][n-1];
    }
}

int main()
{
    for(int i=0;i<52;i++){
    for(int j=0;j<10;j++){
        dp[i][j]=-1;
    }
}
    int val[3]={60,100,120};
    int weight[3]={10,20,30};
    int w=50;
    int ans=knapsack(val,weight,w,3);
    printf("%d",ans);
    return 0;
}
