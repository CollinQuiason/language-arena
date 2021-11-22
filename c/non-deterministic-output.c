#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int initialPrimeIterator = 2;
	_Bool compositePrimeNumbers[n];



	printf("Prime Numbers from 2 -> %d\n", n);
	for (int i = initialPrimeIterator; i < n; i += initialPrimeIterator) {
		compositePrimeNumbers[i-1] = true;
	}
	printf("Done...\n");

	printf("Printing prime numbers from 2-> %d\n", n);
	for (int i = 2; i < n; i++) {
		if (!compositePrimeNumbers[i]){
			printf("%d\n", i + 1);	
		}
	}

	return 0;
}
