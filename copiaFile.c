#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char **argv){

	int fd1, fd2, letti, scritti;
	char buffer[2]={};
	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR );
	printf("valore di fd1 = %d\n",fd1);
	printf("valore di fd2 = %d\n",fd2);
	if (fd1 == -1 || fd2 == -1){
		fprintf(stdout,"errore apertura file lettura e scrittura.\n");
		exit(-1);
	}
	while((letti = read(fd1,buffer,1))> 0 ){
		scritti = write(fd2,buffer,letti);
		if (letti!=scritti){
			fprintf(stdout,"errore scrittura file.\n");
			fprintf(stdout,"letti %d e scritti %d\n",letti, scritti);
			exit(2);
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}
