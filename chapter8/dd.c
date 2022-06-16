#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        if (argc > 2) {
                fprintf(stderr, "usage: %s [blocksize]\n", argv[0]);
                return 1;
        }
                
        unsigned int bufsiz;
        if (argc == 2)
                bufsiz = atoi(argv[1]);
        else
                bufsiz = BUFSIZ;

        char buf[bufsiz];
        int n;

        while ((n = read(0, buf, bufsiz)) > 0)
                write(1, buf, n);
        return n;
}
