#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#define M 110

/*void mana(int sig){
	if (sig == SIGUSR1){
		printf("SEGNALE DI TERMINAZIONE\n");
		exit(1);
	}
}
 
int main(){
	(void) signal (SIGUSR1,mana);
	int file[2],val;
	pid_t pid;
	FILE *fp;
	fp = fopen("son1.txt","r");
	if (fp == NULL){
		printf("errore apertura file.\n");
		exit(-1);
	}
	char stringa[M]={}, letta[M]={};
	val = pipe(file);
	if (val == -1){
		printf("errore creazione pipe\n");
		exit(-2);
	}
	if ((pid=fork())){
		//padre
		close(file[1]);
		while(1){
			read(file[0],letta,M);
			fprintf(stdout,"LEGGO: %s\n",letta);
		}
	}
	else if (pid == 0){
		//figlio
		close(file[0]);
		while(fgets(stringa,M,fp)!=NULL){
			write(file[1],stringa,M);
			printf("SCRIVO: %s\n",stringa);
		}
		fclose(fp);
		kill(getppid(),SIGUSR1);
	}
	else if (pid == -1){
		printf("errore creazione figlio.\n");
		exit(-3);
	}
	return 0;
}*/
int lu = 1;
pid_t pid;

void man(int sig){
	if(sig == SIGINT){
		sleep(1);
		printf("PADRE RICEVE SIGINT E LO MANDA A FIGLIO\n");
		lu=0;
		kill(pid,sig);
	}	
}

void figlio (int sig){
	if (sig == SIGINT)
		exit(3);
}

int main(){
	FILE *fp;
	int file[2],n=0;
	char letti[M]={}, scritti[M]={};
	if ((fp = fopen("son1.txt","r"))==NULL){
		printf("errore apertura file.\n");
		exit(-1);
	}
	if (pipe(file)==-1){
		printf("errore apertura pipe\n");
		exit(-2);
	}
	if ((pid = fork())==-1){
		printf("errore generazione processo fork.\n");
		exit(-3);
	}
	else if (pid== 0){
		//figlio
		signal(SIGINT,figlio);
		close(file[0]);
		while(fgets(letti,M,fp)!=NULL){
			n++;
			write(file[1],letti,M);
		}
		fclose(fp);
		printf("HO LETTO %d RIGHE, HO FINITO\n",n);
		kill(getppid(),SIGINT);
		pause();
	}
	else if (pid){
		//padre
		signal(SIGINT,man);
		close(file[1]);
		while(lu==1){
			read(file[0],scritti,M);
			printf("STAMPO: %s\n",scritti);
		}
		printf("sono arrivato alla waitpid\n");
		waitpid(pid,0,0);
	}
	return 0;
}
