#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float height, step;
    float v, h;

    if (argc < 2 || argc > 3){
        printf("Error: не верно указаны аргументы.\n%s height [step]\n", argv[0]);
        return 0;
    }

    if ((height = atoi(argv[1])) < 1){
        printf("Error: неверно указаны аргументы.\nheigh > step\n");
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
