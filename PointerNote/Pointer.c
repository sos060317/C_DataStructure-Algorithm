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

	// 같은 숫자끼리 값이 같다.
	printf("%p\n", **pp); //1
	printf("%p\n", *pp);  //2	
	printf("%p\n", pp);	  //3
	printf("%p\n", &p);   //3
	printf("%p\n", p);	  //2
	printf("%p\n", *p);	  //1
	printf("%p\n", i);	  //1

	return 0;
}