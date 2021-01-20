#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define set_bit(num, idx) num = num | (1 << idx);
#define clear_bit(num, idx) num = num & ~(1 << idx);
#define is_set(num, idx) (num & (1 << idx))
 
/*
 * Swap numbers in place
 */
void swap(int *a, int *b)
{
    size_t len = (sizeof(int) * 8) - 1;

    for (int i = 0; i < len; i++)
    {
        if (is_set(*a, i) == is_set(*b, i))
        {
            continue;
        }
        else if (is_set(*a, i) == 0)
        {
            set_bit(*a, i)
            clear_bit(*b, i)
        }
        else
        //else if (is_set(*b, i) == 0)
        {
            set_bit(*b, i)
            clear_bit(*a, i)
        }
    }
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("Usage: %s a b\n", argv[0]);
        return 1;
    }

    errno = 0;

    int a = strtol(argv[1], NULL, 10); 
    int b = strtol(argv[2], NULL, 10);

    if (errno != 0)
    {
        printf("Invalid number(s) specified\n");
        return 1;
    }

    printf("Entered: a: %d (0x%X), b: %d (0x%X)\n", a, a, b, b);
    swap(&a, &b);
    printf("Result: a: %d (0x%X), b: %d (0x%X)\n", a, a, b, b);

    return 0;
}