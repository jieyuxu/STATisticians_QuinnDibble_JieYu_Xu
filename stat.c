#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
	struct stat openfile;
	int status;
	status = stat("file.file", &openfile);
	printf("===STATISTICAL STATTERY===\n\n");
	printf("File that has been statted:\tfile.file\n");
	printf("File size:\t\t%d\n", openfile.st_size);
	printf("File permissions:\t%o\n", openfile.st_mode);
	printf("Time of access:\t\t%d\n", openfile.st_atim);
}

