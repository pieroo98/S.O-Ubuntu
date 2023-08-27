#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	int x = 0;
	if (fork()==0)
	{
		x++;
		if (fork()==0)
		{
			x++;
		}
		else
		{
			wait(NULL);
		}
	}
	else
		wait(NULL);
	printf("%d\n",x);
}
