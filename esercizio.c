#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define M 50

int main(int argc, char **argv){
	int *vettore, dim=0, i=0;
	pid_t pid;
	if (argc!=2){
		printf("errore numero argomenti, manca il parametro\n");
		exit(-1);
	}
	dim = atoi(argv[1]);
	vettore = malloc(dim*sizeof(int));
	for (i=0;i< dim; i++){
		printf("\ninserisci l'elemento %d : ",i);
		scanf("%d",&vettore[i]);
	}
	for (i=0;i< dim; i++){
		printf("%d\n",vettore[i]);
	}

	for (i=0;i< dim -1; i++){
		pid = fork();
		if (pid!=0){
			wait((int *)0);
			break;
		}
	}
	printf(" elemento %d in posizione %d dal figlio %d\n",vettore[i],i,getpid());
	return 0;
}
