#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

void manager(int sig){
	if(sig==SIGUSR1)
		printf("ricevuto segnale %d dal padre %d\n",sig,getppid());
	else if(sig == SIGUSR2)
		printf("ricevuto segnale %d dal padre %d\n",sig,getppid());
	else if (sig== SIGINT){
		printf("ricevuto segnale %d dal padre %d\n",sig,getppid());
		exit(1);
	}
}
int main(){
	int n, i, v[3] = {10, 12, 2},stato;
	printf("inserisci un numero : ");
	scanf("%d",&n);
	pid_t pid;
	(void) signal(SIGUSR1,manager);
	(void) signal(SIGUSR2,manager);
	(void) signal(SIGINT,manager);
	for(i=0;i<n;i++){
		sleep(2);
		pid = fork();
		if (pid == 0)
			break;
		else{
			printf("padre = %d, figlio %d-esimo = %d\n",getpid(),i,pid);
			kill(pid,v[i]);
		}
	}
	for(i=0;i<n;i++)
		wait(&stato);
	return 0;
}
