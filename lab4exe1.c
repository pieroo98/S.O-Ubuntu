#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define MAX 500

void ricorsiva( char *path,int x );

int main(int argc, char **argv){
	ricorsiva(argv[1],0);
	return 0;
}

void ricorsiva( char *path, int x){
	DIR* dir;
	dir = opendir(path);
	struct dirent *dp;
	char buf[MAX]={0};
	while ((dp=readdir(dir))!=NULL){
		if (dp==NULL)
			return;
		if(((strcmp(dp->d_name,"."))!=0) && ((strcmp(dp->d_name,".."))!=0)){
			if (x==0)
				printf("./%s:\n",dp->d_name);
			else{
				for (int y=0;y<x;y++)
					printf("\t");
				printf("%s\n",dp->d_name);
			}
			if (dp->d_type==DT_DIR){
				strcpy(buf,path);
				strcat(buf,dp->d_name);
				strcat(buf,"/");
				ricorsiva(buf, x+1);
				strcpy(buf,path);
			}
		}
	}
}
