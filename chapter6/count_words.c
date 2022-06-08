#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1000
#define nelem(a) (sizeof(a) / sizeof(a[0]))

struct cnode {
	char *s;
	int count;
	struct cnode *left;
	struct cnode *right;
};

struct cnode *makecnode(char *s, int count,
			struct cnode *left, struct cnode *right)
{
	struct cnode *n = malloc(sizeof(struct cnode));
	n->s = s;
	n->count = count;
	n->left = left;
	n->right = right;
	return n;
}

void printcounts(struct cnode *n)
{
	if (n->left)
		printcounts(n->left);
	printf("%s %d\n", n->s, n->count);
	if (n->right)
		printcounts(n->right);
}

int inccnode(struct cnode *n, char *s)
{
	int sc = strcmp(s, n->s);
	if (sc == 0)
		return ++(n->count);
	if (sc < 0) {
		if (n->left)
			return inccnode(n->left, s);
		n->left = makecnode(s, 1, NULL, NULL);
		return 1;
	}
	if (n->right)
		return inccnode(n->right, s);
	n->right = makecnode(s, 1, NULL, NULL);
	return 1;
}

/*
 * find alphabetic words in input (separated by
 * either space or nonalpha chars) return them
 * in lower case
 */
char *getword(int lim)
{
	int c, i = 0;
	char *s = malloc(lim*sizeof(char));
	while (!isalpha(c = getchar()) && c != EOF)
		;
	if (c == EOF) {
		free(s);
		return NULL;
	}
	s[i++] = tolower(c);
	while (isalpha(c = getchar()))
		s[i++] = tolower(c);
	s = realloc(s, (i+1)*sizeof(char));
	s[i] = '\0';
	return s;
}

int main()
{
	char *w = getword(MAXWORD);
	if (!w)
		return 0;
	struct cnode *t = makecnode(w, 1, NULL, NULL);
	while (w = getword(MAXWORD))
		if (inccnode(t, w) != 1)
			free(w);
	printcounts(t);
}
