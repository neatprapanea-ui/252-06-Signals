#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_alarm(int sig) {
  for (int i = 0; i < 5; i++)
    printf("Alarm!!! \n");
}

int main(void)
{
    signal(SIGALRM, my_alarm); //Signal Handerler
    alarm(3);
    pause(); printf("Demo!\n"); exit (0);
}

//this prog run by Asynchronous form 