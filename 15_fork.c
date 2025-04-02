#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t childpid;
	int retval;
	int status;
	childpid = fork();
	
	if (childpid >= 0) {
		if (childpid == 0) {
		printf("CHILD: I am child process!\nCHILD: My pid is %d\nCHILD: My parent pid is %d\n", getpid(), getppid());
		printf("CHILD: The value of my copy childpid is %d\n", childpid);
		printf("CHILD: Sleeping for 1 second...\n");
		sleep(1);
		printf("CHILD: Enter an exit value(0 to 255): ");
		scanf("%d", &retval);
		printf("CHILD: Goodbye!\n");
		exit(retval);
	} else {
		printf("PARENT: I am a parent process\nPARENT: My pid is %d\nPARENT: My parent pid is:%d\n", getpid(), getppid());
		printf("PARENT: Here is my pid: %d\n", getpid());
		printf("PARENT: Value of my copy of child pid is: %d\n", childpid);
		printf("PARENT: I will now wait for my child to exit\n");
		wait(&status);
		printf("PARENT: Child's exit code is: %d\n", WEXITSTATUS(status));
		printf("PARENT: Goodbye!\n");
		exit(0);
		}
	}
}