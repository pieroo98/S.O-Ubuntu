#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int P36911();
void P2_10();

int main(){
	pid_t pid;
	printf("processo P1\n");
	pid = fork();
	if (pid==0)
		P36911();
	else if (pid > 0){
		P2_10();
		waitpid(pid,0,0);
		sleep(2);
	}
	else{
		printf("errore generazione P2-P3\n");
		exit(-1);
	}
	printf("processo P12\n");
	return 0;
}

void P2_10(){
	pid_t pid2, pid4;
	printf("processo P2\n");
	sleep(2);
	pid2 = fork();
	if (pid2 <0 ){
		printf("errore generazione P3-P4\n");
		exit(-1);
	}
	else if ( pid2 > 0){
		printf("processo P4\n");
		sleep(2);
		pid4 = fork();
		if (pid4<0){
			printf("errore generazione P3-P4\n");
			exit(-1);
		}
		else if (pid4 == 0){
			printf("processo P8\n");
			sleep(1);
			exit(1);
		}
		else{
			printf("processo P7\n");
			sleep(2);
			waitpid(pid4,0,0);
		}
		
	}
	else {
		printf("processo P5\n");
		sleep(4);
		exit(2);
	}
	waitpid(pid2,0,0);
	printf("processo P10\n");
}

int P36911(){
	pid_t pid3;
	printf("processoP3\n");
	sleep(2);
	pid3 = fork();
	if (pid3<0){
		printf("errore generazione P6-P9\n");
		exit(-1);
	}
	else if(pid3== 0){
		printf("processo P6\n");
		sleep(2);
		exit(4);
	}
	else {
		waitpid(pid3,0,0);
		printf("processo P9\n");
		sleep(2);
		printf("processo P11\n");
		sleep(1);
	}
	exit(6);
}


