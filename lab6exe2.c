#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
char str[100];
int i;
sleep(2);
fork();
for (i=0;i<2;i++){
	if(fork()!=0){
		sprintf(str,"echo system with i=%d",i);
		system(str);}
	else{
		sprintf(str,"exec with i=%d",i);
		execlp("echo","mypgrm",str,NULL);}
	sleep(2);
	}
return (0);
}
