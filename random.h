#ifndef RANDOM_H
#define RANDOM_H
#include <stdlib.h>
char randomizer(int range_min, int range_max)
{
    char generated_char = range_min + rand() % (range_max - range_min + 1);
    if (generated_char > 90 && generated_char < 97)
    {
        generated_char += 6;
    }
    return generated_char;
}

#endif
