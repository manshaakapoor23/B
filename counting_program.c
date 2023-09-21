#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <time.h>

int main(int count, char *scheduler[]) {
    struct sched_param param;
    param.sched_priority = 0;

    int scheduler;
    if (strcmp(scheduler[1], "SCHED_FIFO")) {
        scheduler = SCHED_FIFO;
        if (sched_setscheduler(0, scheduler, &param) == -1) {
            perror("sched_setscheduler");
            return EXIT_FAILURE;
        }
    } else if (strcmp(scheduler[1], "SCHED_OTHER")) {
        scheduler = SCHED_OTHER;
        if (sched_setscheduler(0, scheduler, &param) == -1) {
            perror("sched_setscheduler");
            return EXIT_FAILURE;
        }
    } else if (strcmp(scheduler[1],"SCHED_RR")) {
        policy = SCHED_RR;
        if (sched_setscheduler(0, scheduler, &param) == -1) {
            perror("sched_setscheduler");
            return EXIT_FAILURE;
        }
    }

    int i=0;
    while(i< pow(2,32)){
        i++;
    }
    return 0;

}
