#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int pid;

void manager(int sig){
	if (sig==SIGCHLD){
		exit(0);
	}
	else if (sig==SIGINT){
		kill(pid,sig);
	}
}

void manager2( int sig){
	if (sig==SIGINT){
		printf("il mio pid e' : %d\n",getpid());
		exit(0);}
}

int main(int argc, char **argv){


signal(SIGCHLD,manager);
signal(SIGINT,manager);
pid=fork();

if (pid==0){
	signal(SIGINT,manager2);
	printf("sono nel figlio, pid : %d\n",pid);
	pause();
	exit(0);
}

else if (pid<0)
	printf("errore");

else{
	printf("sono nel padre, pid : %d\n",getpid());
	while(1){
		pause();
	}
} 

return 0;}
