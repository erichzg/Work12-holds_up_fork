#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {

  printf("Pre-fork message\n");

  int status;

  int f1 = fork();

  if (f1) {
     f1 = fork();
  }

  if (!(f1)) {
    printf("child pid: %d\n", getpid());
    //distinct seeds plus time for obscurity
    srand(getpid() + time(NULL));
    int sleep_amount = rand() % 16 + 4;
    sleep(sleep_amount);
    printf("child done napping\n");
    return sleep_amount;
  }

  else {
    printf("completed child process pid: %d\n",  wait(&status));
    printf("Slept for: %d s\n", WEXITSTATUS(status));
    printf("Parent completed\n");
	   
  }
  
}
