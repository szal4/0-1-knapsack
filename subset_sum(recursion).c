#include <stdio.h>
#include<stdbool.h>
bool subset_sum(int arr[],int n,int s){
    if(n==0&&s!=0){
      return false;
    }
    if(s==0){
        return true;
    }
    if(arr[n-1]>s){
        return subset_sum(arr,n-1,s);
    }
    else{
       return subset_sum(arr,n-1,s-arr[n-1])||subset_sum(arr,n-1,s); 
    }
}
int main()
{
   int arr[5]={3,5,8,9,4};
   int sum=3;
   bool ans=subset_sum(arr,5,sum);
   printf("%d",ans);
    return 0;
}
