#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

volatile bool flag[2] = {false, false};

void* process0(void* arg) {
  printf("P0 quiere entrar - Lee bandera de P1: %s\n", flag[1] ? "true":"false");
   /* Primero lee el estado de la bandera de P1
     como no hay procesos en la SC, entrará*/
  while (flag[1]); 
  /* Simulamos un pequeño delay para forzar la ocurrencia del error */
  usleep(100000);

  flag[0] = true;
  printf(">>> P0 entra a SC y coloca su bandera en true <<<\n");
  sleep(2);
  printf("<<< P0 sale de SC >>>\n");
  flag[0] = false;

  return NULL;
}

void* process1(void* arg) {
  printf("P1 quiere entrar - Lee bandera de P0: %s\n", flag[0] ? "true":"false");
  while (flag[0]);
  usleep(100000);

  flag[1] = true;
  printf(">>> P1 entra a SC y coloca su bandera en true <<<\n");
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
