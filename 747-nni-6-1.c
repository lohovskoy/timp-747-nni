#include <stdio.h>
#include <stdlib.h>
void combsort(int *array, size_t size) 
{
    if (array && size) 
    {
        size_t jump = size, i;
        int swapped = 1;
        while (jump > 1 || swapped) 
        {
            if (jump > 1)
                jump /= 1.24733;
            swapped = 0;
            for (i = 0; i + jump < size; ++i)
                if (array[i + jump] > array[i]) 
        {
            int tmp;
            tmp = array[i];
            array[i] = array[i + jump];
            array[i + jump] = tmp;
                    //std::swap(array[i], array[i + jump]);
                        swapped = 1;
                }
        }
    }
}
int main()
{
  int g;
  scanf("%d",&g);
  int mass[g];
  for (int i = 0; i<g; i++)
      scanf("%d",&mass[i]);

  combsort(mass, g);
   for (int i = g - 1 ; i>=0; i--)
    printf("%d ", mass[i]);
  printf("\n");
 }
