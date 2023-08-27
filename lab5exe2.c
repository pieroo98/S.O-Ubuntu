#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

int i, n , x;
char str[50];
n = atoi(argv[1]);
x = atoi(argv[2]);
printf("run with n=%d\n",n);
fflush(stdout);
for (i=0;i<n;i++){
	if (fork()>0){
		printf("%d",n-1);
		sleep(x);}
	else{
		sprintf(str,"%s %d %s",argv[0], n-1, argv[2]);
		system(str);}
	}
exit(0);
}
