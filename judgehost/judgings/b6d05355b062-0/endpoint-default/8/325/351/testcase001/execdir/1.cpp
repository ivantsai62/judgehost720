//uva11764
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int testcase = 0, N, i, h, l, c, d, T;
	scanf("%d", &T);
	while(T--) {
		testcase++;
		h = l = 0;
		scanf("%d", &N);
		N--;
		scanf("%d", &c);
		for(i = 0; i < N; i++) {
			scanf("%d", &d);
			if(d > c)
				h++;
			else if(d < c)
				l++;
			c = d;
		}
		printf("Case %d: %d %d\n", testcase, h, l);
	}
	return 0;
}