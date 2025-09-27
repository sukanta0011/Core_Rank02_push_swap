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
    int min = -1000, max = 1000, count = 1000;
    printRandoms(min, max, count);
	printf("\n");
    return 0;
}