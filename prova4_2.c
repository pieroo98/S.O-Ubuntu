#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#define M 110
int main(){
	char nome[M]={}, cha;
	int i=0;
	while((cha=fgetc(stdin))!=EOF){
		if (cha>=97 && cha<= 122){
			cha = cha -32;
			nome[i]=cha;
			i++;
		}
		else {
			nome[i] = cha;
			i++;
		}
	}
	printf("stringa modificata : \n%s",nome);
	return 0;
}


