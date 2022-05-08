#include <stdio.h>
void printlist(int v[], int n) {
    printf("[");
    for (int i=0; i<n; i++)
        printf("%d, ", v[i]);
    printf("\b\b]\n");
}

void sort(int v[], int n) {
    int gap, i, j, temp;

    for (gap=n/2; gap>0; gap/=2)
        for (i=gap; i<n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j--) {
                if (v[j]>v[j+gap]) {
                    temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                }
                printlist(v, n);
            }
}

int main()
{
    int v[] = {12, 4, 5, 15, 1, 8, 7, 9, 11};
    int n = 9;

    printlist(v, n);
    sort(v, n);
}
