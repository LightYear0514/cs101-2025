#include <stdio.h>


void printRow(int i, int j) {
    if (j == 1) {
        printf("%d*%d=%d\t", i, j, i * j);
    } else {
        printRow(i, j - 1);
        printf("%d*%d=%d\t", i, j, i * j);
    }
}


void printTable(int i) {
    if (i == 1) {
        printRow(1, 9);
        printf("\n");
    } else {
        printTable(i - 1);
        printRow(i, 9);
        printf("\n");
    }
}

int main() {
    printTable(9);  
    return 0;
}
