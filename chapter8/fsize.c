#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAXPATH 1024

// apply fnc to all files in dir
void dirwalk(char *dir, void (*fnc)(char *))
{
	DIR *dp;
	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: could not open %s\n", dir);
		return;
	}
	struct dirent *dntp;
	char path[MAXPATH];
	while ((dntp = readdir(dp)) != NULL) {
		if ((strcmp(dntp->d_name, ".") == 0)
		 || (strcmp(dntp->d_name, "..") == 0))
			continue;
		if (snprintf(path, MAXPATH, "%s/%s", dir, dntp->d_name)
		 >= MAXPATH) {
			fprintf(stderr, "fsize: path too long: %s\n", path);
			continue;
		}
		fnc(path);
	}
}


void fsize(char *path)
{
	struct stat stbuf;

	if (stat(path, &stbuf) != 0) {
		fprintf(stderr, "fsize: could not get stat for %s\n", path);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
		dirwalk(path, fsize);
		return;
	}
	printf("%8lu %s\n", stbuf.st_size, path);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}
