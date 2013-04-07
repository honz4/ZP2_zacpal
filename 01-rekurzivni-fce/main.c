#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

{
    double fib=0, Nmin1, Nmin2, temp;
    if (n<2) return n;
    Nmin1=1;
    Nmin2=0;
    for (int i=2; i<n; i++)
    {
        temp=Nmin1;
        Nmin1=Nmin1+Nmin2;
        Nmin2=temp;
    }
    return (Nmin1+Nmin2);
}
