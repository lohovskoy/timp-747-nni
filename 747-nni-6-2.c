#include <stdio.h>
#include <stdlib.h>
void ShellSort(int *mass,int n)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}
int main()
{
  int g;
  scanf("%d",&g);
  int mass[g];
  for (int i = 0; i<g; i++)
      scanf("%d",&mass[i]);

  ShellSort(mass, g);
   for (int i = 0 ; i < g; i++)
    printf("%d ", mass[i]);
  printf("\n");
}
