#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv){
DIR *dir;
dir = opendir(argv[1]);
if (dir == NULL)
	printf("errore lettura direttorio\n");
struct dirent *dp;
while ((dp = readdir(dir))!=NULL){
	if (strcmp(dp -> d_name, ".")!=0){
		if (strcmp(dp -> d_name,"..")!=0){
		printf("%s\n",dp -> d_name);}}}
closedir(dir);
return 0;
}
