
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

void print_help(FILE *fp, char *app)
{
	fprintf(fp, "Usage: %s (<options>) <errorno>\n", app);
	fprintf(fp, "\n");
	fprintf(fp, " -h Print this help\n");
	fprintf(fp, " -v Print version\n");
	fprintf(fp, " -n Also print number with string\n");
	fprintf(fp, "\n");
}

int main(int argc, char **argv)
{
	const char *ops = "hvn?";
	int opt = 0;
	int printnumber = 0;
	
	while( (opt = getopt(argc, argv, ops)) != -1)
	{
		switch(opt)
		{
			case 'h':
				print_help(stdout, argv[0]);
				exit(EXIT_SUCCESS);
				break;
			case 'v':
				printf("Version: %s\n", PACKAGE_VERSION);
				exit(EXIT_SUCCESS);
				break;
			case 'n':
				printnumber = 1;
				break;
			default:
				printf("Unknown option '%c'\n", opt);
				print_help(stderr, argv[0]);
				exit(EXIT_FAILURE);
				break;
		}
	}
	
	while(optind < argc)
	{
		char *arg = argv[optind];
		int err = 0;
		
		if (sscanf(arg, "%d", &err) != 1)
		{
			fprintf(stderr, "Could not parse '%s'\n", arg);
			exit(EXIT_FAILURE);
		}
		
		if (printnumber)
		{
			printf("%d = %s", err, strerror(err));
		}
		else
		{
			printf("%s\n", strerror(err));
		}

		optind++;
	}

	return 0;
}

