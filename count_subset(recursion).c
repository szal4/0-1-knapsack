#include <stdio.h>
int subset_count(int arr[],int n,int s){
    if(n==0&&s!=0){
      return 0;
    }
    if(s==0){
        return 1;
    }
    if(arr[n-1]<=s){
       return subset_count(arr,n-1,s-arr[n-1])+subset_count(arr,n-1,s);
    }
    else{
       return subset_count(arr,n-1,s);
    }
}
int main()
{
   int arr[5]={3,5,8,9,4};
   int sum=17;//{3,5,9}{8,9}{5,8,4} totall 3
   int ans=subset_count(arr,5,sum);
   printf("%d",ans);
    return 0;
}
