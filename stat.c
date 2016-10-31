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
	printf("File size:\t\t%d\n", openfile.st_size);
	printf("File permissions:\t%o\n", openfile.st_mode);
	char date [100];
	printf("%d\n", openfile.st_atim);
	strcpy(date, ctime(openfile.st_atim));
	printf("Time of access:\t\t%s\n", date);
}
