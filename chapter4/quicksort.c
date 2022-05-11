void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#include <stdio.h>
void printlst(int v[], int len) {
    putchar('[');
    for (int i=0; i < len; i++)
        printf("%d, ", v[i]);
    printf("\b\b]\n");
}

int main()
{
    int v[] = {2, 0, 9, 3, 7, 8, 4, 1, 6};
    int left = 0, right = 8;
    printlst(v, right+1);
    qsort(v, left, right);
    printlst(v, right+1);
}
