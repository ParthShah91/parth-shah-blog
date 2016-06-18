#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define DUMP_STR         "Hello world\n"
#define MAX_SAMPLES        1000

int main(int argc, char *argv[])
{
        char preference = 0;
        struct timespec before[MAX_SAMPLES], after[MAX_SAMPLES];
        FILE *fp = NULL;
        int i = 0;
        long sum = 0;

        if(argc < 2)
        {
                printf("Usage: ./a.out <1/2>\n");
                printf("\t1 - Write to file\n");
                printf("\t2 - Write to console\n");
                return -1;
        }

        preference = atoi(argv[1]);
        printf("preference : %d\n", preference);
        if (preference == 1)
        {
                fp = fopen("/tmp/t1", "w");
                if (!fp)
                {
                        perror("File open");
                        return -1;
                }
        }
        else if (preference == 2)
        {
                fp = stdout;
        }
        else
        {
                printf("ERROR: Invalid preference. Valid values 1/2\n");
        }
        while(i < MAX_SAMPLES)
        {
                clock_gettime(CLOCK_REALTIME, &before[i]);
                fwrite(DUMP_STR, strlen(DUMP_STR), 1, fp);
                clock_gettime(CLOCK_REALTIME, &after[i]);
                i++;
        }

        for (i = 0; i < MAX_SAMPLES; i++)
        {
                sum += after[i].tv_nsec - before[i].tv_nsec;
        }
        printf("Average : %ld\n", sum / MAX_SAMPLES);
        return 0;
}
