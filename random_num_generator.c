#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandoms(int min, int max, int count) {
  
    for (int i = 0; i < count; i++) {
        int rd_num = rand() % (max - min + 1) + min;
        printf("%d, ", rd_num);
    }
}

int main() {
    int min = -100, max = 100, count = 100;
    printRandoms(min, max, count);
	printf("\n");
    return 0;
}