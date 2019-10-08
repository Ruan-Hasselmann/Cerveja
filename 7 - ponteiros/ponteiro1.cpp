#include <iostream>
#include <stdio.h>
int main() {
	int x = 10;
	int *pX = &x;
	
	printf("%d  -  %p\n",x, &x);
	printf("%p\n",pX);
	
	return 1;
}
