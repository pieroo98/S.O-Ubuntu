#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#define M 130

pid_t pid1, pid2;

void manager(int sig){
	if ( sig == SIGUSR1){
		//printf("segnale ricevuto dal figlio 1.\n");
		sleep(1);
		kill(pid2,SIGUSR2);
	}
	else if (sig == SIGUSR2){
		//printf("segnale ricevuto dal figlio 2.\n");
		sleep(1);
		kill(pid1,SIGUSR1);
	}
	else if(sig == SIGINT){
		printf("uno dei due ha terminato.\n");
		kill(pid1,SIGINT);
		kill(pid2,SIGINT);
		sleep(2);
		exit(6);
	}
}

void figlio1(int sig){
	if(sig == SIGUSR1){
	}
	else if (sig == SIGINT){
		exit(1);
	}
}

void figlio2(int sig){
	if(sig == SIGUSR2){
	}
	else if (sig == SIGINT){
		exit(2);
	}
}

int main(){
	(void) signal(SIGUSR1,manager);
	(void) signal(SIGUSR2,manager);
	(void) signal(SIGINT,manager);
	FILE *fp1, *fp2;
	fp1 = fopen("son2.txt","r");
	if (fp1 == NULL){
		printf("errore apertura file son1.txt\n");
		exit(-1);
	}
	fp2 = fopen("son1.txt","r");
	if (fp2 == NULL){
		printf("errore apertura file son2.txt\n");
		exit(-2);
	}
	char buff1[M]={}, buff2[M]={}; 
	if((pid1 = fork())){
		if((pid2 = fork())){
			while(1){
				pause();
			}
			//waitpid(pid2,0,0);
			printf("il figlio 2 ha terminato\n");
		}
		else if (pid2 == 0){
			//figlio2
			(void) signal(SIGUSR2,figlio2);
			(void) signal(SIGINT,figlio2);
			while(fgets(buff2,M,fp2)!=NULL){
				fprintf(stdout,"FIGLIO 2) %s (2)\n",buff2);
				sleep(2);
				kill(getppid(),SIGUSR2);
				pause();
			}
			printf("\n\nIL FIGLIO 2 HA FINITO E MANDA IL SEGNALE AL PADRE\n\n");
			sleep(2);
			kill(getppid(),SIGINT);
			pause();
		}
		//waitpid(pid1,0,0);
		printf("il figlio 1 ha terminato\n");
	}
	else if (pid1 == 0){
		//figlio1
		(void) signal(SIGUSR1,figlio1);
		(void) signal(SIGINT,figlio1);
		while(fgets(buff1,M,fp1)!=NULL){
			pause();
			fprintf(stdout,"FIGLIO 1) %s (1)\n",buff1);
			sleep(2);
			kill(getppid(),SIGUSR1);
		}
		printf("\n\nIL FIGLIO 1 HA FINITO E MANDA IL SEGNALE AL PADRE.\n\n");
		sleep(2);
		kill(getppid(),SIGINT);
		pause();	
	}
	return 0;
}
