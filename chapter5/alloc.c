#define BUFSIZE 10000

static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (n<=0 || allocp+n > allocbuf+BUFSIZE)
        return 0;
    allocp += n;
    return allocp - n;
}

void afree(char *p) {
    if (allocbuf<=p && p<allocbuf+BUFSIZE)
        allocp = p;
}
