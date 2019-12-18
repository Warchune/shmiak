#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

struct globalArgs_t{
    char help;
} globalArgs;

static const char *optString = "Il:o:vh?";

static const struct option longOpts[] = {
        { "help", no_argument, NULL, 'h' },
        { NULL, no_argument, NULL, 0 }
};
int main(int argc, char *argv[]) {
    int opt = 0;
    int longIndex = 0;

    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    while( opt != -1){
        switch(opt){
            case 'h':
            case '?':
                printf("Нечего думать, иди прыгай!\n");
                return 0;
            default:
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }

    float height, step;
    float v, h;

    if (argc < 2 || argc > 3){
        printf("Error: не верно указаны аргументы.\n%s height [step]\n", argv[0]);
        return 0;
    }

    if ((height = atoi(argv[1])) < 1){
        printf("Error: неверно указаны аргументы.\nheigh > 1\n");
        return 0;
    }

    if (argc == 3) {
        if ((step = h = atoi(argv[2])) < 1) {
            printf("Error: неверно указан аргумент.\n%s step\n", argv[0]);
            return 0;
        }
        if (height < step){
            return 0;
        }
    }
    else {
        step = h = height / 10;
    }

    printf("Высота | Скорость\n");
    while((height - h) >= 0){
        v = sqrt(2.0 * 10.0 * h);
        printf("%6.2f | %6.2f \n", height - h, v);
        h += step;
    }

    return 0;
}
