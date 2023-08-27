#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#define N 400

int main(int argc, char** argv){
	
	struct stat buf;
	DIR *dp;
	char fullName[N]={};
	struct dirent *dirp;
	int i;
	if (stat(argv[1],&buf)< 0){
		printf("errore lettura struct stat buf\n");
		exit(1);
	}
	if (S_ISDIR(buf.st_mode)==0){
		printf("buf.st_mode non e' un direttorio\n");
		exit(2);
	}
	if ( (dp = opendir(argv[1])) == NULL){
		printf("non riesco ad aprire il direttorio\n");
		exit(3);
	}
	i = 0;
	while( ( dirp = readdir(dp)) != NULL) {
		sprintf(fullName,"%s%s/",argv[1],dirp->d_name);
		if ( lstat(fullName,&buf)<0){
			printf("errore nella lstat(fullName)\n");
			exit(4);
		}
		if ( S_ISDIR(buf.st_mode)==0){
			printf("File %d = %s \n",i,fullName);
		}
		else{
			//credo che qui dovrei fare la chiamata ricorsiva
			//inoltre devo verificare che non sia . e ..
 			printf("direttorio %d = %s\n",i,fullName);
		}
		i++;
	}
	if (closedir(dp)<0){
		printf("errore chiusura dir\n");
		exit(5);
	}
	return 0;
}
