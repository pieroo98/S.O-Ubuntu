#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#define M 50

pid_t pid1, pid2;

void manager(int sig){
	if(sig == SIGCHLD){
		printf("segnale SIGCHLD letto.\n");
	}
}

int main(){
	(void) signal(SIGCHLD,manager);
	int fd1, fd2, letti1, letti2; 
	char riga[M+1] = {};
	char riga2[M+1] = {};
	if((pid1=fork())==0){
		printf("pid primo figlio = %d\n",getpid());
		pause();
		fd1 = open("son1.txt",O_RDONLY);
		letti1 = read(fd1,riga,50);
		if (letti1==50)
			printf("letti 50 byte di fd1\n");
		printf("%s\n",riga);
		exit(2);
	}
	else if (pid1>0){
		pid2=fork();
		if (pid2 ==0){
			printf("pid secondo figlio = %d\n",getpid());
			fd2 = open("son2.txt",O_RDONLY);
			letti2 = read(fd2,riga2,50);
			if (letti2==50)
				printf("letti 50 byte di fd2\n");
			printf("%s\n",riga2);
			kill(pid1,SIGCHLD);
			exit(3);
		}
		else if (pid2){
			waitpid(pid2,0,0);
		}
		waitpid(pid1,0,0);
	}
	return 0;
}
