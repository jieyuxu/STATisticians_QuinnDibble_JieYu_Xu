#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>

void printSize(struct stat opened) {
	long filesize = opened.st_size;
	int gb = filesize / 1073741824;
	filesize = filesize % 1073741824;
	int mb = filesize / 1048576;
	filesize = filesize % 1048676;
	int kb = filesize / 1024;
	filesize = filesize % 1024;
	int b = filesize;
	if (gb > 0) printf("File size:\t\t%d.%dgb\n", mb, kb);
	else if (mb > 0) printf("File size:\t\t%d.%dmb\n", mb, kb);
	else if (kb > 0) printf("File size:\t\t%d.%dkb\n", kb, b);
	else printf("File size:\t\t%db\n", b);
}		

void printPermissions(struct stat opened) {
	int user = (opened.st_mode % 01000) / 0100;
	int group = (opened.st_mode % 0100) / 010;
	int other = (opened.st_mode % 010);
/*	printf("(int) 0775:\t%d\n", (int) 0775 % 1000);
	int permissions = (int) (opened.st_mode % 1000);
	int user = permissions / 100;
	permissions = permissions % 100;
	int group = permissions / 10;
	permissions = permissions % 10;
	int other = permissions;
*/
	printf("user:\t%d\ngroup:\t%d\nother:\t%d\n", user, group, other);
}
	
int main() {
	struct stat openfile;
	int status;
	status = stat("stat", &openfile);
	printf("===STATISTICAL STATTERY===\n\n");
	printf("File that has been statted:\tfile.file\n");
	printf("PERMS:\t%o\n", openfile.st_mode);
	printSize(openfile);
	printPermissions(openfile);
	time_t rawtime = openfile.st_atime;
	printf("Time of access:\t\t%s\n", ctime(&rawtime));

}
