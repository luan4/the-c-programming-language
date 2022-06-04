#include <stdio.h>
#include <stdlib.h>

#define nelem(a) (sizeof(a) / sizeof(a[0]))

int pow2(int exp) {
	unsigned int res = 1;
	res <<= exp;
	return res;
}

struct node {
	char val;
	struct node *left;
	struct node *right;
};

struct node *find(struct node *n, char val) {
	if (val == n->val)
		return n;
	if (val < n->val)
		return n->left ? find(n->left, val) : NULL;
	return n->right ? find(n->right, val) : NULL;
}

void insert(struct node *n, char val) {
	if (val == n->val)
		return;
	if (val < n->val) {
		if (n->left)
			return insert(n->left, val);
		struct node *new_node = calloc(1, sizeof(struct node));
		new_node->val = val;
		n->left = new_node;
		return;
	}
	if (n->right)
		return insert(n->right, val);
	struct node *new_node = calloc(1, sizeof(struct node));
	new_node->val = val;
	n->right = new_node;
	return;
}

void repr_tree(char *lines[], struct node *n, int d, int depth) {
	if (d >= depth)
		return;

	int c = pow2(depth) - 1;
	while (lines[d][c] == ' ' && c > 0)
		c--;
	if (c == 0)
		c -= pow2(depth - d - 1);
	c += pow2(depth - d);

	lines[d][c] = n ? n->val : '.';
	repr_tree(lines, n ? n->left : NULL, d + 1, depth);
	repr_tree(lines, n ? n->right : NULL, d + 1, depth);
}

void print_tree(struct node *n, int depth) {
	int line_memb = pow2(depth) + 2;
	char *lines[depth];
	for (int l=0; l<depth; l++) {
		lines[l] = calloc(line_memb, sizeof(char));
		for (int c=0; c < line_memb-1; c++)
			lines[l][c] = ' ';
		lines[l][line_memb-1] = '\0';
	}
	repr_tree(lines, n, 0, depth);
	for (int l=0; l < depth; l++) {
		printf("%s", lines[l]);
		for (int j=depth-l; j >= 0; j--)
			putchar('\n');
	}
}

int main()
{
	int depth = 5;
	struct node n = {'j', NULL, NULL};
	print_tree(&n, depth);
	int inserciones[] = {'f', 'h', 'a', 'b', 'r', 's', 'q', 'w', 'm', 'x', 'j', 'k', 'c', 't', 'p', 's'};
	for (int i=0; i < nelem(inserciones); i++)
		insert(&n, inserciones[i]);
	print_tree(&n, depth);
}
