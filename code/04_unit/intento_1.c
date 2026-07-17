#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

volatile int turn = 0;

void* process0(void* arg) {
  for (int i = 0; i < 3; i++) {
    printf("P0 trabaja 3 segundos fuera de la SC\n");
    sleep(3);
    while (turn != 0);

    printf("P0 entra en la sección crítica durante 1 segundo\n");
    sleep(1);
    printf("P0 sale y cambia el turno\n\n");

    turn = 1;

    sleep(1);
  }
  return NULL;
}

void* process1(void* arg) {
  for (int i = 0; i < 3; i++) {
    printf("P1 esta listo y espera para poder entrar a la SC.\n\n");
    while (turn != 1);

    printf("P1 entra en la sección crítica\n");
    sleep(0.2);
    printf("P1 sale y cambia el turno\n\n");

    turn = 0;
  }
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
