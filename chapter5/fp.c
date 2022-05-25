#include <stdio.h>

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// decide if int i is greater than j
int greater(int *pi, int *pj)
{
    if (*pi == *pj)
        return 0;
    return (*pi > *pj) ? 1 : -1;
}

// decide if string s is longer than t
int longer(char *s, char *t)
{
    while (*s++)
        if (!*t++)
            return 1;
    if (*t)
        return -1;
    return 0;
}

// sort an array of pointers
void slowsort(
    void *v[], int len, int start, int (*comp)(void *, void *)
)
{
    if (start >= len-1)
        return;
    int small = start;
    for (int i=start+1; i < len; i++)
        if ((*comp)(v[small], v[i]) == 1)
            small = i;
    swap(v, small, start);
    slowsort(v, len, start + 1, comp);
}

int main()
{
    char *strs[] = {
        "this is a very long one",
        "medium",
        "a bit longer",
        "small",
    };
    slowsort(
        (void **) strs, 4, 0, (int (*)(void *, void *)) longer
    );
    for (int i=0; i < 4; i++)
        printf("%s\n", strs[i]);

    int a, b, c, d;
    a = 7; b = 3; c = 8; d = 1;
    int *nums[] = {&a, &b, &c, &d};
    slowsort(
        (void **) nums, 4, 0, (int (*)(void *, void *)) greater
    );
    for (int i=0; i < 4; i++)
        printf("%d\n", *nums[i]);
}
