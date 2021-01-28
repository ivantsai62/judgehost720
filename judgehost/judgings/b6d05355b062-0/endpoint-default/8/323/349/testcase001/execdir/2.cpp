//uva10082
#include <cstdio>

int main() {
	const char str[]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	char c;
	int i;
	while (( c = getchar()) != EOF) {
		if (c == ' ' || c == '\n')
			putchar(c);
		else {
			for (i = 0; str[i] != c; i++);
			putchar(str[i - 1]);
		}
	}
	return 0;
}