#include <stdio.h>
void printlist(int v[], int n) {
    printf("[");
    for (int i=0; i<n; i++)
        printf("%d, ", v[i]);
    printf("\b\b]\n");
}

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap=n/2; gap>0; gap/=2) {
        printf("gap: %d\n", gap);
        for (i=gap; i<n; i++) {
            printf("\ti: %d\n", i);
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                printf("\t\tj: %d swapping %d with %d\n", j, v[j], v[j+gap]);
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                printf("\t\t");
                printlist(v, n);
            }
        }
    }
}


int main()
{
    int v[] = {15, 2, 9, 7, 13, 5, 14, 124, 4, 253, 32, 213};
    int n = 12;

    printlist(v, n);
    shellsort(v, n);

}

