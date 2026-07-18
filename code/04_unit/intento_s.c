#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

volatile bool flag[2] = {false, false};
volatile int turn = 0;

void* process0(void* arg) {
    printf("P0 quiere entrar\n");

    flag[0] = true;
    turn = 1;

    while (flag[1] && turn == 1);

    printf(">>> P0 ENTRA <<<\n");

    sleep(2);

    printf("<<< P0 SALE >>>\n\n");

    flag[0] = false;

    return NULL;
}

void* process1(void* arg) {
    printf("P1 quiere entrar\n");

    flag[1] = true;
    turn = 0;

    while (flag[0] && turn == 0);

    printf(">>> P1 ENTRA <<<\n");

    sleep(2);

    printf("<<< P1 SALE >>>\n\n");

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
