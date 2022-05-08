int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low < high) {
        mid = (low+high)/2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    if (x == v[low])
        return low;
    return -1;
}

#include <stdio.h>
int main()
{
    int x, len, res;
    int v[] = {
        -32, 6, 23, 24, 889, 3423, 3424, 3425,
        3433, 3533, 3677, 3723, 3812, 3912, 4011,
        4122, 52533, 52534, 62543, 234432, 2345626
    };
    for (len=0; v[len]!='\0'; len++)
        ;
    for (int j=0; j<10; j++)
        for (x=-100; x<2345627; x++)
            if ((res = binsearch(x, v, len)) >=0)
                printf("%d at pos %d\n", x, res);
}
