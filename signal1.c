#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signint(int sig)
{
	printf("the signal status is %d \n", sig);
	printf("the user is %s \n", getenv("USER"));
	exit(0);
}

int main()
{
	signal(SIGINT, handle_signint);
	printf("press ctrl+c...");
	while (1)
	{
		sleep(1);
	}
	return 0;
}

