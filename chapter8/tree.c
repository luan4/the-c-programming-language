#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

int all = 0;
int size = 0;

// apply fnc to all files in dir
void dirwalk(char *dir, void (*fnc)(char *))
{
	DIR *dp;
	if ((dp = opendir(dir)) == NULL) {
		perror("tree");
		return;
	}
	struct dirent *dntp;
	char path[PATH_MAX];
	while ((dntp = readdir(dp)) != NULL) {
		if ((strcmp(dntp->d_name, ".") == 0)
		 || (strcmp(dntp->d_name, "..") == 0))
			continue;
		if (snprintf(path, PATH_MAX, "%s/%s", dir, dntp->d_name)
		 >= PATH_MAX) {
			fprintf(stderr, "tree: path too long: %s\n", path);
			continue;
		}
		fnc(path);
	}
	closedir(dp);
}

void print_file(char *s, int indent, long unsigned siz, int isdir)
{
	if (indent == 0) {
		printf("%s\n", s);
		return;
	}

	while (--indent > 0)
		printf(" |  ");
	printf(" \\__%s", s);
	if (isdir)
		putchar('/');
	if (siz && !isdir)
		printf("  %lu", siz);

	putchar('\n');
}

void tree(char *path)
{
	static int indent = 0;

	struct stat stbuf;
	if (stat(path, &stbuf) != 0) {
		perror("tree");
		return;
	}

	char *bsname = basename(path);
	if (!all && *bsname == '.')
		return;

	long unsigned siz = size ? stbuf.st_size : 0;

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
		print_file(bsname, indent, siz, 1);
		indent++;
		dirwalk(path, tree);
		indent--;
		return;
	}
	print_file(bsname, indent, siz, 0);
}

int main(int argc, char *argv[])
{
	int opt;
	while((opt = getopt(argc, argv, "as")) != -1)
		switch (opt) {
		case 'a':
			all = 1;
			break;
		case 's':
			size = 1;
			break;
		default:
			fprintf(stderr, "Usage: %s [-a] [-s] [path]...", argv[0]);
		}

	argc -= optind - 1;
	argv += optind - 1;

	if (argc == 1)
		tree(realpath(".", NULL));
	else {
		char rpath[PATH_MAX];
		while (--argc > 0) {
			realpath(*++argv, rpath);
			tree(rpath);
		}
	}
	return 0;
}
