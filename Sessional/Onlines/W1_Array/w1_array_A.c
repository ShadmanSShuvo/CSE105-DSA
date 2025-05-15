#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max=arr[0];
    
    for (int i = 0; i < n; i++)
    {
        int sum=arr[i];
        if(sum>max)
        max=sum;
        for(int j=i+1; j<n; j++){
            sum += arr[j];
            if(sum>max)
                max=sum;
        }
    }
    
    printf("%d\n", max);
    

    return 0;
    
}