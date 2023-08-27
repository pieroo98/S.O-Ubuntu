#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int main (int argc, char**argv){


//argv[1] //segnale da mandare
int sig;
int b = atoi(argv[2]); //pid del processo cui mandare
int ret;

printf("Parametri: %s %s\n", argv[1], argv[2]);

if(strcmp(argv[1], "SIGUSR1")==0)
	ret=kill(b, SIGUSR1);

else if (strcmp(argv[1], "SIGUSR2")==0)
	ret=kill(b, SIGUSR2);

else if (strcmp(argv[1], "SIGKILL")==0)
	ret = kill(b,SIGINT);

printf("Valore di ritorno di kill: %d\n", ret);
perror("");

return 0;
}
