#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help();

int main(int argc, char **argv)
{
	printf("\n\t!!!Char to HEX converter!!!\t\n");

	// Check options
	int p_flag = 0;

	int *jumparg;
	if (!(jumparg = calloc(argc, sizeof(int))))
	{
		ferror(stderr);
	}

	for (int i = 0; i < argc; i++)
	{
		if ( (!strcmp("-p",argv[i])) || (!strcmp("-p", argv[i])) || (!strcmp("-print", argv[i])) || (!strcmp("--print", argv[i])) )
		{
			p_flag = 1;
			jumparg[i] = 1;
		}
		if ((!strcmp("-h", argv[i])) || (!strcmp("-H", argv[i])) || (!strcmp("-help", argv[i])) || (!strcmp("--help", argv[i])) || (argc==1))
		{
			jumparg[i] = 1;
			help();
		}
	}

	
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (jumparg[i]) continue;

			FILE *in = NULL;
			FILE *out = NULL;

			char infile[1000];
			char outfile[1000];

			sprintf(infile, "%s", argv[i]);
			sprintf(outfile, "%s%s%s", strtok(argv[i], "."), "HEX", strrchr(infile, '.'));

			in=fopen( infile, "r");
			if (in == NULL) {
				printf("Impossibile aprire il file %s\n", infile);
			}
			else
			{
				out=fopen(outfile, "w");

				if (out == NULL) {
					printf("Impossibile creare il file %s", outfile);
				}
				else
				{
					printf("\n%s -> %s\n", infile, outfile);

					char c;
					while (!feof(in))
					{
						//c = fgetc(in);
						fscanf(in,"%c",&c);
						/*
						if (c == EOF)
						{
							break;
						}
						else*/
						{
							if (p_flag) printf("%c -> %x\n", c, c);
							fprintf(out, "%X ", c);
						}
						
					}
					fclose(in);
					fclose(out);
				}
			}
		}
	}
	printf("\n");
}

void help()
{
	printf("\nchar2hex File1.ext File2.ext [-o] [--option]\nThis program creates new files File1HEX.ext File2HEX.ext with all origin file characters displayed as HEXadecimal values.\n\n");
	printf("-p --print \t displays details on each convertion\n");
	printf("-h --help \t open help page\n");

	//printf("\npress q to quit:");
	//while (getch()!='q') {}
} 