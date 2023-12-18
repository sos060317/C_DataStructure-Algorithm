#include <stdio.h>

int main()
{
	int i = 1;
	int* p = &i;
	int** pp = &p;

	printf("i = %d\n", i);

	*p = 10; // i를 가르키고 있으므로 i의 값이 바뀐다.
	printf("i = %d, *q = %d, **pp = %d\n", i, *p, **pp);

	**pp = 100; // **pp -> *p -> i를 가르키고 되고 결국 i의 값이 바뀐다.
	printf("i = %d, *q = %d, **pp = %d\n", i, *p, **pp);

	return 0;
}