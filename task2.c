#include <stdio.h>
#include <math.h>

/// decodifica input-ul
void decode(unsigned int input, char operators[10], int *n, int *dim)
{
    unsigned int mask = pow(2, 31); ///masca
    int i;
    for (i = 0; i <= 2; i++)
    {
        *n += (input & mask) == mask ? pow(2, 2 - i) : 0;
        mask >>= 1;
    }
    int bit1, bit2; ///variabile in care citesc bitii pentru operatori
    for (i = 0; i <= *n - 1; i++)
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
    }
    for (i = 3; i >= 0; i--)
    {
        *dim += (input & mask) == mask ? pow(2, i) : 0;
        mask >>= 1;
    }
    return;
}

void readOperands(int n, int dim, int nrCitiri, int operands[10])
{
    int i, j, k;
    unsigned short tempUS; /// unsigned short temporar
    int temp;              /// int temporar
    unsigned short mask;   /// masca
    int nrNumere = 0;
    for (i = 1; i <= nrCitiri && nrNumere != n + 1; i++)
    {
        mask = pow(2, 15);
        scanf("%hu", &tempUS);
        for (j = 0; j <= 16 / dim - 1 && nrNumere != n + 1; j++)
        {
            temp = 0;
            for (k = dim - 1; k >= 0; k--)
            {
                temp += (tempUS & mask) == mask ? pow(2, k) : 0;
                mask >>= 1;
            }
            operands[nrNumere] = temp;
            nrNumere++;
        }
    }
    return;
}

/// executa operatiile
void executeOperations(int n, char operators[10], int operands[10])
{
    int i;
    for(i = 0; i < n; i++)
    {
        switch (operators[i])
        {
            case '+':
                operands[i+1] = operands[i] + operands[i+1];
                break;
            case '-':
                operands[i+1] = operands[i] - operands[i+1];
                break;
            case '/':
                operands[i+1] = operands[i] / operands[i+1];
                break;
            case '*':
                operands[i+1] = operands[i] * operands[i+1];
                break;
        }
    }
    printf("%d\n", operands[n]);
    return;
}

int main()
{
    unsigned int binaryInst; ///instructiunea in format binar
    char operators[10];
    int n = 1;   ///nr de instructiuni
    int dim = 1; ///dimensiunea unui operand
    scanf("%u", &binaryInst);
    decode(binaryInst, operators, &n, &dim);
    ///cate unsigned short trebuie citite
    int nrCitiri = ceil(((n + 1) * dim) / 16.0); 
    int operands[10];
    readOperands(n, dim, nrCitiri, operands);
    executeOperations(n,operators,operands);
}