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

	// ���� ���ڳ��� ���� ����.
	printf("%p\n", **pp); //1
	printf("%p\n", *pp);  //2	
	printf("%p\n", pp);	  //3
	printf("%p\n", &p);   //3
	printf("%p\n", p);	  //2
	printf("%p\n", *p);	  //1
	printf("%p\n", i);	  //1

	return 0;
}