#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

// minimal change from K&R version to
// support operating with results


int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2, res;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("zero divisro\n");
                break;
            case '\n':
                res = pop();
                printf("\t%g\n", res);
                push(res); // the change
                break;
            default:
                printf("unsupported op: %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL]; // the stack

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("stack is full\n");
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack is empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;
    // skip whitespace
    while ((s[0]=c=getch())==' '||c=='\t')
        ;
    // non numbers
    s[1] = '\0';
    if (!isdigit(c) && c!='.')
        return c;
    // numbers
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i]=c=getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i]=c=getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch is full\n");
    buf[bufp++] = c;
}

int getch() {
    if (bufp==0)
        return getchar();
    return buf[--bufp];
}
