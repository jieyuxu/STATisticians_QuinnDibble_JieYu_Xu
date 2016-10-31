#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
	struct stat openfile;
	int status;
	status = stat("file.file", &openfile);
	printf("===STATISTICAL STATTERY===\n\n");
	printf("File that has been statted:\tfile.file\n");
	printf("File size:\t\t%ld\n", openfile.st_size);
	printf("File permissions:\t%o\n", openfile.st_mode);
	time_t rawtime = openfile.st_atime;
	printf("Time of access:\t\t%s\n", ctime(&rawtime));
}
