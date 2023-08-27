#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

void manager(int sig){
	if (sig == SIGUSR1){
		printf("segnale ricevuto : %d\n",sig);
		kill(getppid(),SIGUSR2);
		
	}
	else if (sig==SIGUSR2){
		printf("segnale ricevuto : %d\n",sig);
		kill(getppid(),SIGUSR1);
	}
	else if (sig==SIGINT){
		printf("segnale SIGINT ricevuto dal figlio: %d\n",getpid());
		kill(getppid(),SIGINT);
		exit(1);}
}

void managerPadre(int sig){
	if (sig == SIGUSR1)
		printf("segnale ricevuto dal padre : %d\n",sig);
	else if (sig==SIGUSR2)
		printf("segnale ricevuto dal padre: %d\n",sig);
	else if (sig==SIGINT){
		printf("segnale SIGINT ricevuto dal padre: %d\n",getpid());
		exit(1);}
}

int main(int argc, char **argv){

int pid, sig, i, v[3]={12,10,2};

	signal(SIGUSR1,manager);
	signal(SIGUSR2,manager);
	signal(SIGINT,manager);

if ((pid=fork())==0){
	//pidFiglio = getpid();
	printf("sono nel figlio : %d\n",getpid());
	for (i=1;i<65;i++)
		signal(i,manager);
	while(1){
		pause();
	}
}
else {
	signal(SIGUSR1,managerPadre);
	signal(SIGUSR2,managerPadre);
	signal(SIGINT,managerPadre);

	printf("sono nel padre.\n");
	sig=atoi(argv[1]);
	sleep(3);
	kill(pid,sig);
	pause();
	for(i=0;i<3;i++){
		sleep(1);
		kill(pid,v[i]);
		pause();
	}
	waitpid(pid,0,0);
}

return 0;
}
