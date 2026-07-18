#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

volatile bool flag[2] = {false, false};

void* process0(void* arg) {
    printf("P0 quiere entrar\n");
    flag[0] = true;

    while (flag[1]) {
        printf("P0 cede el turno\n");
        flag[0] = false;
        usleep(200000);
        printf("P0 vuelve a intentarlo\n");
        flag[0] = true;
    }

    printf(">>> P0 ENTRA <<<\n");
    sleep(1);
    printf("<<< P0 SALE >>>\n");
    flag[0] = false;
    return NULL;
}

void* process1(void* arg) {
    printf("P1 quiere entrar\n");
    flag[1] = true;
    while (flag[0]) {
        printf("P1 cede el turno\n");
        flag[1] = false;
        usleep(200000);
        printf("P1 vuelve a intentarlo\n");
        flag[1] = true;
    }

    printf(">>> P1 ENTRA <<<\n");
    sleep(1);
    printf("<<< P1 SALE >>>\n");
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
