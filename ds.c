#include<stdio.h>
#include<stdlib.h>
int main()
{

int a [100];
int i,n,data,m;
printf("enter the length of array ");
scanf("%d",&n);
printf("Enter Array numbers ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the data for insertion ");
scanf("%d",&data);
printf("Enter the position for insertion ");
scanf("%d",&m);
for(i=n;i>=m;i--){
a[i]=a[i-1];
}
a[m-1]=data;
printf("inserted array");
for(i=0;i<n+1;i++)
{
printf("\n%d\n",a[i]);
}

return 0;
}
