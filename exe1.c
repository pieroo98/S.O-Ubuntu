#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int a, b;

void manager(int sig){

	if (sig==SIGUSR1){
		printf("la differenza e' : %d \n",a-b);}

	else if (sig ==SIGUSR2){
		printf("la somma e' : %d \n",a+b);}

	else if (sig == SIGINT){
		printf("sto terminando\n");
		exit(0);
	}
}

int main (int argc, char**argv){
	setbuf(stdout, 0);
	(void) signal (SIGUSR1,manager);
	(void) signal (SIGUSR2,manager);
	(void) signal (SIGINT,manager);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("PID= %d\n", getpid());
	while(1){
		pause();}
	return 0;
}
