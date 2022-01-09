#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    slrand48(42);

    for (int i = 1; i < 15 - 1; i++)
    {
        int j = i + lrand48() / (RAND_MAX / (15 - i) + 1);
        printf("%d\n", j);
    }
    return 0;
}
