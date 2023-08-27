#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

pid_t pid;

void manager( int sig){
	if (sig == SIGCHLD){
	}
	else if (sig == SIGINT){
		printf("il padre ha ricevuto il segnale SIGINT.\n");
		kill(pid,SIGINT);
	}
}

void figlio( int sig){
	if (sig == SIGINT)
		printf("il figlio ha ricevuto il segnale SIGINT.\n");
}
 
int main(){
	(void) signal(SIGCHLD,manager);
	(void) signal(SIGINT, manager);
	pid = fork();
	if (pid ==0){
		(void) signal(SIGINT,figlio);
		pause();
		printf("pid del figlio = %d .\n",getpid());
		exit(1);
	}
	else if (pid){
		pause();
		printf("credo che abbia terminato il figlio con un SIGINT\n");
		waitpid(pid,0,0);
	}
	return 0;
}




