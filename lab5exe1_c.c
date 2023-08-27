#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
int i;
for (i=0; i<2; i++)
{
if (fork ())
fork ();
}
printf ("%d\n", i);
return 0;
}
