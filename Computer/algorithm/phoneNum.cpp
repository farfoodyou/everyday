#include <stdio.h>
int tag[10] = {0}, sum = 0, used = 0;
int uable[10][10];

void fun(int n)
{
    for (int i = 1; i <= 9; ++i)
    {
        if (!tag[i] && (!uable[n][i] || tag[(n+i)/2]))
        {
            if (++used >= 4)
                sum += 1;
            tag[i] = 1;
            fun(i);
            tag[i] = 0;
            used--;
        }
    }
}

int main()
{
    uable[1][3] = uable[1][7] = uable[2][8] = uable[3][1] = 1;
    uable[3][9] = uable[4][6] = uable[1][9] = uable[9][1] = 1;
    uable[6][4] = uable[7][1] = uable[7][9] = uable[8][2] = 1;
    uable[9][7] = uable[9][3] = uable[3][7] = uable[7][3] = 1;
    fun(0);
    printf("%d\n", sum);
    return 0;
}
