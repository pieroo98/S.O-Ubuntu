#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int pid, pid2;

void manager(int sig){
	if (sig == SIGUSR1) {
		printf("ho ricevuto il signal dal figlio1 e lo sto mandando a 2\n");
		kill(pid2,SIGUSR1); }
	else if (sig == SIGUSR2 ) {
		printf("ho ricevuto il signal dal figlio2 e lo sto mandando a 1\n");
		kill( pid, SIGUSR2); }
}

void managerFiglio( int sig){
	if ( sig ==SIGUSR1){
		printf("ricevuto\nsto terminando figlio 2\n");
		exit(0);}
	else if (sig == SIGUSR2){
		printf("ricevuto\nsto terminando figlio 1\n");
		exit(0);}
}

int main(int argc, char **argv){

signal(SIGUSR1, manager);
signal(SIGUSR2, manager);

pid = fork();
if (pid < 0){
	printf("errore fork");
	exit(0); }
else if (pid == 0 ){
	signal(SIGUSR2, managerFiglio);
	printf("sono nel figlio 1\n");
	sleep(2);
	kill(getppid(),SIGUSR1);
	pause();
	exit(0);
}
else if (pid > 0){
	printf("sono nel padre\n");
	//pause();
	pid2 = fork();
	if (pid2 <0 ){
		printf("errore fork 2");
		exit(0); }
	else if ( pid2 == 0){
		signal(SIGUSR1,managerFiglio);
		printf("sono nel figlio 2\n");
		pause();
		sleep(1);
		kill(getppid(),SIGUSR2 );
		exit(0);
		}
	else if (pid2 > 0){
		printf("sono nel padre\n");
		pause();
		}

}

return 0;
}

