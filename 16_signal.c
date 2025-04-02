#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
// Signal handler function
{
if(signo==SIGINT)
	// we are handling SIGINT (ctrl+c)
	printf("\nReceived SIGINT\n");
}

int main()
{
	printf("\nTry to kill me...\nmy pid:%d\n",getpid());
	if(signal(SIGINT,sig_handler)==SIG_ERR)
		//sig_handler function is registered in the kernel
		printf("\nCant catch...\n");
	//by passing it as the second arguement to the function 'signal'.
	while(1)
	sleep(1);
	return 0;
}