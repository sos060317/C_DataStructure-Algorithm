#include <stdio.h>

int main()
{
	int i = 1;
	int* p = &i;
	int** pp = &p;

	printf("i = %d\n", i);

	*p = 10; // i�� ����Ű�� �����Ƿ� i�� ���� �ٲ��.
	printf("i = %d, *q = %d, **pp = %d\n", i, *p, **pp);

	**pp = 100; // **pp -> *p -> i�� ����Ű�� �ǰ� �ᱹ i�� ���� �ٲ��.
	printf("i = %d, *q = %d, **pp = %d\n", i, *p, **pp);

	return 0;
}