#include <stdio.h>
#include <dirent.h>

int main()
{
	DIR *dp = opendir("../chapter8");
	struct dirent *dntp;
	while ((dntp = readdir(dp)) != NULL)
		printf("%8ld %s\n", dntp->d_ino, dntp->d_name);
}
