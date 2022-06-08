#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrdup(char *s)
{
	char *t;
	t = malloc((strlen(s)+1)*sizeof(char));
	if (t)
		strcpy(t, s);
	return t;
}

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31*hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np=hashtab[hash(s)]; np!=NULL; np=np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np=lookup(name)) == NULL) {
		np = malloc(sizeof(*np));
		if (np==NULL || (np->name=mystrdup(name))==NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);
	if ((np->defn = mystrdup(defn)) == NULL)
		return NULL;
	return np;
}

int main()
{
	struct {
		char *n;
		char *d;
	} inst[] = {
		{"uno", "1"},
		{"dos", "2"},
		{"tres", "3"},
		{"cuatro", "4"},
		{"cinco", "5"},
		{"pedo", "5"},
		{"perro", "5"},
		{"morsa", "5"},
		{"calco", "5"},
	};
	for (int i=0; i<(sizeof(inst)/sizeof(inst[0])); i++)
		install(inst[i].n, inst[i].d);
	for (int i=0; i<(sizeof(inst)/sizeof(inst[0])); i++)
		printf("[%d] %s: %s\n", hash(inst[i].n), inst[i].n, lookup(inst[i].n)->defn);
}
