#include <stdio.h>
#include <math.h>

int main() {
    float min, max, step;
    float v, s;

    scanf("%g%g%g", &min, &max, &step);
    s = step;
    printf("Высота | Скорость\n");
    while((max - step) >= min){
        v = sqrt(2.0 * 10.0 * step);
        printf("%6g | %g \n", max - step, v);
        step += s;
    }
    return 0;
}