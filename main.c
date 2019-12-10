#include <stdio.h>
#include <math.h>

int main() {
    float max, step;
    float v, s;

    scanf("%g%g", &max, &step);
    s = step;
    printf("Высота | Скорость\n");
    while((max - step) >= 0){
        v = sqrt(2.0 * 10.0 * step);
        printf("%6g | %g \n", max - step, v);
        step += s;
    }
    return 0;
}