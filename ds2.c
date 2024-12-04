#include<stdio.h>
int main()
{
int a[100],i,n,pos;
printf("Enter the size of array");
scanf("%d",&n);
printf("Enter the values to store");
for (i=0;i<n;i++)
  scanf("%d",&a[i]);
printf("enter the position to delete");
scanf("%d",&pos);
if (pos>n+1)
  printf("not find in array");
else 
  for (i=pos-1;i<n-1;i++)
	a[i]=a[i+1];
printf("deleted array is ");

for(i=0;i<n-1;i++)
	printf("%d\n",a[i]);

return 0;
}
