#include <stdio.h>
#include<stdlib.h>
int main()
{
int a[100],b[100];
int n1,n2,i,j,total,size=0,temp;
printf("size of two array");
scanf("%d %d",&n1,&n2);
printf("first array : ");
for (i=0; i<n1;i++)
scanf("%d",&a[i]);
printf("second array : ");
for(i=0;i<n2;i++)
scanf("%d",&b[i]);
total = n1+n2;
for(i=n1;i<total;i++)
{
a[i]=b[size];
size ++;
}
for(i=0;i<total;i++){
 for(j=0;j<total-1;j++)
 {
  if (a[j]>a[j+1])
  {
   	temp = a[j];
	a[j] = a[j + 1];
   	a[j + 1] = temp;

	}
	}
	}
printf("after sorting in ");
for (i=0;i<total;i++)
{
printf("%d\n",a[i]);
}
return 0;
}

