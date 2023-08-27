#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

pid_t pid;

void manager(int sig){
if (sig == SIGUSR1){
	printf("FIGLIO: ricevuto segnale %d(SIGUSR1) da pid %d.\nOra lo mando a %d\n",sig,getppid(),getppid());
	kill(getppid(),SIGUSR2);
}
else if (sig == SIGUSR2){
	printf("FIGLIO: ricevuto segnale %d(SIGUSR2) da pid %d.\n",sig,getppid());
	kill(getppid(),SIGUSR1);
}
else if (sig == SIGINT){
	printf("FIGLIO: segnale %d ricevuto da pid %d\n",sig,getppid());
	kill(getppid(),SIGINT);
	exit(1);}
else
	printf("FIGLIO: segnale ignorato\n");
}

void man(int sig){
	if (sig == SIGUSR1)
		printf("PADRE: ricevuto segnale SIGUSR1 da pid %d.\n",pid);
	else if (sig == SIGUSR2)
		printf("PADRE: ricevuto segnale SIGUSR2 da pid %d.\n",pid);
	else if (sig == SIGINT){
		printf("PADRE: segnale SIGINT ricevuto da pid %d\n",pid);
		exit(2);}
	else
		printf("PADRE: segnale ignorato\n");
}

int main(){
	(void) signal(SIGINT,manager);
	(void) signal(SIGUSR1,manager);
	(void) signal(SIGUSR2,manager);
	int *v, n=3, i;
	v = (int *) malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("inserisci numero : ");
		scanf("%d",&v[i]);}
	pid = fork();
	if (pid==0){
		for (i=1;i<65;i++)
			signal(i,manager);
		printf("il pid del figlio e' = %d\n",getpid());
		while(1){
			printf("figlio entra in pausa...\n\n");
			pause();
			printf("...figlio esce dalla pausa\n");
		}
	}
	else if (pid){
		(void) signal(SIGINT,man);
		(void) signal(SIGUSR1,man);
		(void) signal(SIGUSR2,man);
		printf("il pid del padre e' = %d\n",getpid());
		for(i=0;i<n;i++){
			sleep(4);
			printf("sto mandando il segnale %d...\n",v[i]);
			kill(pid,v[i]);
			printf("padre entra in pausa...\n\n");
			pause();
			printf("padre esce dalla pausa\n");
		}
		waitpid(pid,0,0);
	}
	return 0;
}
