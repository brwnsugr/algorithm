//한줄씩 스캔 받기 
#include <stdio.h>


char s[111];
int main() {
	while (scanf("%[^\n]\n", s) == 1) {
		printf("%s\n", s);
	}
	return 0;
}