#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main (){
int i;
for (i=1; i<=2; i++)
{
if (!fork ())
printf ("%d\n", i);
}
printf ("%d\n", i);
return 0;
}
