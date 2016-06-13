#include<stdio.h>


void Turn_search(int a[],int i,int j,int key)
{

int mid1,mid2;
mid1=i+(j-i)*1/3;
mid2=i+(j-i)*2/3;
if(i<=j)
{

if(key==a[mid1])
{
printf("Key Is present at position %d",mid1+1);
}
else if(key==a[mid2])
{
printf("Key is present at position %d",mid2+1);
}
else if(key<a[mid1])
Turn_search(a,i,mid1-1,key);
else if(key>a[mid2])
Turn_search(a,mid2+1,j,key);
else if(key>a[mid1] && key<a[mid2])
Turn_search(a,mid1+1,mid2-1,key);
}

else 
{
printf("Key not found..!!!\n");
}
}


int main()
{
int i,arr[30],key,n;
printf("Enter the number of elements:\n");
scanf("%d",&n);
printf("enter %d Array elements in ascending order:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

printf("Enter the key element:\n");
scanf("%d",&key);

Turn_search(arr,0,n-1,key);
return 0;
}
