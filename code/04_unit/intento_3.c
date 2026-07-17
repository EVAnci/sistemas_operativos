#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

volatile bool flag[2] = {false, false};

void* process0(void* arg) {
  printf("P0 quiere entrar - Coloca bandera en true\n");
  flag[0] = true;
  usleep(100000);
  printf("P0 lee bandera de P1: %s\n", flag[1] ? "true, espera":"false, continua");
  while (flag[1]); 
  printf(">>> P0 entra a SC <<<\n");
  sleep(2);
  printf("<<< P0 sale de SC >>>\n");
  flag[0] = false;

  return NULL;
}

void* process1(void* arg) {
  printf("P1 quiere entrar - Coloca bandera en true\n");
  flag[1] = true;
  usleep(100000);
  printf("P1 lee bandera de P0: %s\n", flag[0] ? "true, espera":"false, continua");
  while (flag[0]);
  printf(">>> P1 entra a SC <<<\n");
  sleep(2);
  printf("<<< P1 sale de SC >>>\n");
  flag[1] = false;

  return NULL;
}

int main() {
  pthread_t t0, t1;

  pthread_create(&t0, NULL, process0, NULL);
  pthread_create(&t1, NULL, process1, NULL);

  pthread_join(t0, NULL);
  pthread_join(t1, NULL);

  return 0;
}
