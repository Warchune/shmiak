#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

/* Глобальная структура с аргументами. */
struct globalArgs{
    float coefficient;  /* Единицы измерения. */
    float step; /*Шаг изменения высоты. */
    float height; /* Начальная высота. */
} globalArgs;

/* Строка с опциями. */
static const char *optString = "c:s:h?";

int main(int argc, char *argv[]) {
    float speed, shift;
    globalArgs.coefficient = 1.0; /* Изначально м/с. */
    globalArgs.step = 0;
    const struct option long_options[] = {
            {"coefficient", 1, NULL, 'c'},
            {"step", 1, NULL, 's'},
            {"help", 0, NULL, 'h'},
            {NULL, 0, NULL, 0}
    };
    int opt = 0;
    while( (opt = getopt_long( argc, argv, optString, long_options, NULL)) != -1){
        switch(opt){
            case 'c':
                if (strcmp("kmh", optarg) == 0) {
                    globalArgs.coefficient = 3.6; /* Км/ч. */
                }
                break;
            case 's':
                globalArgs.step = atoi(optarg);
                break;
            case 'h':
            case '?':
                printf("shmiak - программа, считающая скорость (м/с) падения в вакуме с определенной высоты (м) через фиксированный шаг (10%% oт высоты).\n"
                       "\n"
                       "shmiak [float: height]\n"
                       "\n"
                       "   -c                 : опция с аргументом ""kmh"" позволяет получать скорость в км/ч. \n"
                       "   -s [flota: step]   : оция позволяет установить шаг, через который будет производиться расчет скорости.\n"
                       "   -h                 : справка о программе.\n");
                return 0;
            default:
                break;
        }
    }
    globalArgs.height = atoi(argv[optind]);
    if (globalArgs.height <= 0){
        printf("Error: height > 0.\n");
        return 0;
    }

    /* Если шаг не задан, то он равен 10% от высоты. */
    if (globalArgs.step == 0){
        globalArgs.step = globalArgs.height / 10;
    }
    if (globalArgs.step >= globalArgs.height){
        printf("Error: step > height.\n");
        return 0;
    }

    shift = globalArgs.step; /* Суммарный сдвиг от начальной высоты. */
    printf("height | speed\n");
    while((globalArgs.height - shift) >= 0){
        speed = sqrt(2.0 * 10.0 * shift) *  globalArgs.coefficient;
        printf("%6.2f | %6.2f \n", globalArgs.height - shift, speed);
        shift += globalArgs.step;
    }

    return 0;
}
