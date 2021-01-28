//uva406
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b) ? (a) : (b)))
#define MIN(a, b) (((a) < (b) ? (a) : (b)))

int main(int argc, const char **argv) {
	bool is_not_prime[1001] = {false};
	int primes[1001] = {0}; // this will store 2, 3, 5, 7, 11, ..., in that order
	int pi[1001] = {0}; // pi[i] is the number of primes that are <= i
	int N, C;
	pi[1] = 1;

	// determine which numbers are primes
	for (int i = 2; i <= 1000; ++i) {
		if (!is_not_prime[i]) // i is a prime
			// remove all multiples of i from the list of possible primes
			for (int j = 2; i * j <= 1000; ++j) {
				is_not_prime[i * j] = true;
			}
	}

	// compute the pi function
	for (int i = 2; i <= 1000; ++i)
		pi[i] = pi[i - 1] + (is_not_prime[i] ? 0 : 1);

	// store the primes in primes[]
	int k = 0;
	for (int i = 1; i <= 1000; ++i)
		if (!is_not_prime[i])
			primes[k++] = i;

	while (scanf("%d", &N) > 0 && scanf("%d", &C) > 0) {
		printf("%d %d:", N, C);

		for (int i = MAX((pi[N] + 1)/ 2 - C, 0); i < MIN(pi[N] / 2 + C, pi[N]); ++i)
			printf(" %d", primes[i]);

		printf("\n\n");
	}

	return 0;
}
