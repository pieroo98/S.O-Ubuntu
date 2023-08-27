#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int leggidinuovo();

int main(int argc, char **argv){

int pid, continua=1, ret, c;
if (argc!=2)
printf("errore parametri incompleti\n");
printf("Parametri: %s \n", argv[1]);
pid = atoi(argv[1]);
do 
{
	c= leggidinuovo();
	switch(c){
	
	case 0 :
		printf("sono dentro somma.\n");
		ret=kill(pid,SIGUSR2);
		printf("Valore di ritorno di kill: %d\n", ret);
		perror("");
		break;

	case 1 :
		printf("sono dentro differenza.\n");
		ret=kill(pid,SIGUSR1);
		printf("Valore di ritorno di kill: %d\n", ret);
		perror("");
		break;

	case 2 :
		printf("sono dentro fine.\n");
		ret=kill(pid,SIGINT);
		printf("Valore di ritorno di kill: %d\n", ret);
		perror("");
		continua=0;
		break;
	}
}while(continua==1);
return 0;
}

int leggidinuovo(){

char c[50]={0}, *trova[3]={"somma","differenza","fine"};

printf("inserisci un comando tra :\n%s %s %s \n",trova[0],trova[1],trova[2]);
scanf("%s",c);

if (strcmp("somma",c)==0){
	printf("posizione trovata : 0\n");
	return  0;}
if (strcmp("differenza",c)==0){
	printf("posizione trovata : 1\n");
	return  1;}
if (strcmp("fine",c)==0){
	printf("posizione trovata : 2\n");
	return  2;}
return -1;
}
