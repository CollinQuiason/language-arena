#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <argp.h>

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 2) {
        printf("Usage: <upperBound> <--visualize>\n");
    } else {
        double time_spent = 0.0;
        int n = atoi(argv[1]);
        int primeIterator = 2;
        bool *compositeNumbers = calloc(n, sizeof(bool));

        printf("Prime Numbers from 2 -> %d\n", n);
        clock_t begin = clock();
        while (primeIterator < n) {
            for (int i = primeIterator * 2; i < n; i += primeIterator) {
                compositeNumbers[i-1] = true; //Is a multiple of the primeIterator
            }
            for (int i = primeIterator; i < n; i++) {
                if (!compositeNumbers[i]) {
                    primeIterator = i + 1;
                    break;
                }
            }
        }
        clock_t end = clock();
        printf("Done...\n");

        printf("Printing prime numbers from 2-> %d\n", n);
        for (int i = 2; i < n; i++) {
            if (!compositeNumbers[i]){
                printf("%d, ", i + 1);
            }
        }
        printf("\n");
        printf("Calculation Time Elapsed: %f",(double)(end - begin) / CLOCKS_PER_SEC);
        free(compositeNumbers);
    }

    return 0;
}
