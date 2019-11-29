#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main (void) 
{
int x = 0,y,z=1;
scanf ("%d",&x);
for (int i = 1 ;i<=x;i++)
{
scanf("%d",&y);
y = abs(y);
z = z *(y - i); 
}
printf("%d\n",z);
return 0;
}
