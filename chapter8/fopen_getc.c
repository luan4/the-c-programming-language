#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define MAXOPEN 20
#define PERMS 0666
#define BUFSZ 1024

typedef struct {
        char *buf;
        char *cp; // pointer to next char
        int fd;
        int cr;
        unsigned char _READ : 1;
        unsigned char _WRITE : 1;
        unsigned char _UNBUF : 1;
        unsigned char _EOF : 1;
        unsigned char _ERR : 1;
} FIL;

FIL _iob[MAXOPEN] = {
        { NULL, NULL, 0, 0, 1, 0, 0, 0, 0},
        { NULL, NULL, 1, 0, 0, 1, 0, 0, 0},
        { NULL, NULL, 2, 0, 0, 1, 1, 0, 0},
};

FIL *filopen(char *fname, char *mode)
{
        if (*mode != 'r' && *mode != 'w' && *mode != 'a')
                return NULL;

        FIL *fp;
        for (fp = &_iob[0]; fp < _iob + MAXOPEN; fp++)
                if (!(fp->_READ || fp->_WRITE))
                        break; // found free slot.
        if (fp >= _iob + MAXOPEN)
                return NULL;

        int fd;
        if (*mode == 'w')
                fd = creat(fname, PERMS);
        else if (*mode == 'a')
                if ((fd = open(fname, O_WRONLY)) == -1)
                        fd = creat(fname, PERMS);
                else
                        lseek(fd, 0L, 2);
        else
                fd = open(fname, O_RDONLY);

        if (fd == -1)
                return NULL;
        // _iob is global so FILs are initialized as 0.
        fp->fd = fd;
        (*mode == 'r') ? (fp->_READ = 1) : (fp->_WRITE = 1);
        return fp;
}

int filbin(FIL *fp)
{
        if (!fp->_READ || fp->_EOF || fp->_ERR)
                return EOF;
        if (fp->_UNBUF) {
                int c;
                if (read(fp->fd, &c, 1) == 1)
                        return (unsigned char) c;
                return EOF;
        }
        if (!fp->buf)
                fp->buf = malloc(BUFSZ);

        fp->cr = read(fp->fd, fp->buf, BUFSZ);
        fp->cp = fp->buf;
        if (--fp->cr < 0) {
                if (fp->cr == -1)
                        fp->_EOF = 1;
                else
                        fp->_ERR = 1;
                return EOF;
        }
        return (unsigned char) *fp->cp++;
}

//#define gtc(p) ((--p->cr >= 0) ? (*p->cp++) : (filbin(p)))
int gtc(FIL *fp)
{
        if (--fp->cr >= 0)
                return *fp->cp++;
        return filbin(fp);
}
