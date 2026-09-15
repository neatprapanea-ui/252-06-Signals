#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_alarm(int sig) {
  for (int i = 0; i < 5; i++)
    printf("Alarm!!! \n");
}

int main(void) {
  int pid;
  printf("Alarm clock is starting...\n");
  pid = fork();
  
  if (pid == 0){
      sleep(3);
      kill(getppid(), SIGALRM); //ให้ตัวลูกเป็นตัวส่งสัญญาณเอง ไม่ได้ใช้ฟังก์ชันในการส่ง
      //เอา IDพ่อแม่มาร แล้วส่ง SIGALRM ไปให้พ่อกับแม่
      exit(0);
    }
  printf("Waiting for alarm...\n");
  (void)signal(SIGALRM, my_alarm);
  pause();
  printf("Done!\n");
  exit(0);
}