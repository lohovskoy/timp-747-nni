#include <stdio.h>
int main(void)
{
    int n = 0,x1 = 0,x2 = 0,rez =1,c = 0;
    scanf("%d", &n);
    scanf("%d", &x2);
    for (int i=1;i<n;i++)
        {
scanf("%d",&c);
        if ((i%2)==1 && rez != 0)  
             {
             x1 = c; if (x2<=x1) rez = 1; else rez = 0;
             }
        if ((i%2)==0 && rez != 0){x2=c; if(x1<=x2) rez = 1; else rez=0 ; 
             }

}
printf("%d\n",rez);
}
   
