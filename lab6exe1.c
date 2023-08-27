#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

int i = 0;
fprintf(stdout,"%d %d\n",getpid(),++i);
execl(argv[0],"prova", (char *)0);
fprintf(stdout,"end program.\n");
return(1);}
