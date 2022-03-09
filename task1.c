#include <stdio.h>
#include <math.h>

/// decodifica input-ul
void decode(unsigned int input, char operators[10])
{
    unsigned int mask = pow(2, 31);
    int i;
    int n = 1; ///nr de instructiuni
    for (i = 0; i <= 2; i++)
    {
        n += (input & mask) == mask ? pow(2, 2 - i) : 0;
        mask >>= 1;
    }
    printf("%d ", n);
    int bit1, bit2; ///variabile in care citesc bitii pentru operatori
    for (i = 0; i <= n - 1; i++)
    {
        bit1 = (input & mask) == mask ? 1 : 0;
        mask >>= 1;
        bit2 = (input & mask) == mask ? 1 : 0;
        mask >>= 1;
        switch (bit1)
        {
        case 0:
            operators[i] = bit2 == 0 ? '+' : '-';
            break;
        case 1:
            operators[i] = bit2 == 0 ? '*' : '/';
            break;
        }
        printf("%c ", operators[i]);
    }
    int dim = 1; ///dimensiunea unui operand
    for (i = 3; i >= 0; i--)
    {
        dim += (input & mask) == mask ? pow(2, i) : 0;
        mask >>= 1;
    }
    printf("%d\n", dim);
}

int main()
{
    unsigned int binaryInst; ///instructiunea in format binar
    char operators[10];
    scanf("%u", &binaryInst);
    decode(binaryInst, operators);
}