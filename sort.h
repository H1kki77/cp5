#ifndef SORT_H
#define SORT_H
#include <string.h>
void sort_ascending (char **mass, int num)
{
    for(int i=0;i<num-1;i++)
        for(int j=i+1;j<num;j++)
            if (strcmp(mass[i],mass[j]) > 0)
            {
                char *tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
}
void sort_descending (char **mass, int num)
{
    for(int i=0;i<num-1;i++)
        for(int j=i+1;j<num;j++)
            if (strcmp(mass[i],mass[j]) < 0)
            {
                char *tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
}

#endif //SORT_H
