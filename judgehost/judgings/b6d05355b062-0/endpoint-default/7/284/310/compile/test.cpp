//uva11942
#include <cstdio>
#include <iostream>

using namespace std;

int a[10];

bool ordered() {
	int *p = &a[-1];
	int i;
	if (p[1] > p[2]) { // dec
		for (i = 2; i <= 10; ++i)
			if (p[i-1] < p[i])
				return false;
	}
	else { // p[1] < p[2],  inc
		for (i = 2; i <= 10; ++i)
			if (p[i-1] > p[i])
				return false;
	}
	return true;
}

int main() {
	int i, t;
	scanf("%d", &t);
	printf("Lumberjacks:\n");
	while (t--) {
		for (i = 0; i < 10; ++i)
			scanf("%d", &a[i]);

		if (ordered()) printf("Ordered\n");
		else printf("Unordered\n");
	}
	return 0;
}