//uva10026
#include<cstdio>
#include<algorithm>

using namespace std;

struct job{
	int num;
	double fine_per_day;
};

bool cmp(struct job a, struct job b) {
	if(a.fine_per_day != b.fine_per_day)
		return a.fine_per_day > b.fine_per_day;
	else
		return a.num < b.num;
}

int main(void) {
	int total, num_job, day, i, j;
	double fine;
	struct job work[1001];

	scanf("%d", &total);
	for(j = 0; j < total; j++) {
		if(j)
			printf("\n");
		scanf("%d", &num_job);
		for(i = 0; i < num_job; i++) {
			scanf("%d%lf", &day, &fine);
			work[i].num = i + 1;
			work[i].fine_per_day = (double)fine / day;
		}
		sort(work, work+num_job, cmp);
		printf("%d", work[0].num);
		for(i = 1; i < num_job; i++) {
			printf(" %d", work[i].num);
		}
		printf("\n");
	}
	return 0;
}