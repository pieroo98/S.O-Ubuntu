#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int k=0;

void manager(int sig){
printf("pid del padre : %d, pid figlio %d, segnale %d, chiamata %d \n", getppid() ,getpid(), sig, k);
k++;
exit(1);
}

int main(int argc, char **argv){
int i, N, j, pid1;
N=atoi(argv[1]);

for(i=1;i<=N;i++){

	if ((pid1=fork())!=0){
	printf("sono nel padre %d e il pid del figlio %d e': %d\n", 		getpid() ,i,pid1);
	sleep(3);
	kill(pid1,10);}

	else {
	printf("figlio %d",i);
		for(j=1;j<=65;j++)
			signal(j,manager);
		printf("entrato : %d\n",i);
		while(1)
			pause();
		exit(1);}
	sleep(2);
}
return 0;}
