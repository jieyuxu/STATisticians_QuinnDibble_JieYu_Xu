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

void printhelper(int perms) {
	printf((perms & 4) ? "r" : "-");
	printf((perms & 2) ? "w" : "-");
	printf((perms & 1) ? "x" : "-");
} //Jerry Chang helped me with this
void printPermissions(struct stat opened) {
	int user = (opened.st_mode % 01000) / 0100;
	int group = (opened.st_mode % 0100) / 010;
	int other = (opened.st_mode % 010);
	printf("Permissions:\t\t");
	printhelper(user);
	printhelper(group);
	printhelper(other);
	printf("\n");
}

int main() {
	struct stat openfile;
	int status;
	status = stat("book.txt", &openfile);
	printf("===STATISTICAL STATTERY===\n\n");
	printf("File that has been statted:\tfile.file\n");
	printSize(openfile);
	printPermissions(openfile);
	time_t rawtime = openfile.st_atime;
	printf("Time of access:\t\t%s\n", ctime(&rawtime));

}
