#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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
    printf("sleep time: %d\n", sleep_amount);
    printf("child released\n");
  }

  else {
    printf("completed pid: %d\n", (int) wait(&status);
  }
  return 0;
}
