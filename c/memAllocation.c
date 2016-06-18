#include <stdio.h>
#include <stdlib.h> //malloc

struct testStruct 
{
	int 	a;
	char	b;
};

union testUnion
{
	int 	a;
	char	b;
};

void demoStaticMemAllocation()
{
	struct testStruct 	s1, s2, s3;
	int			i;
	union testUnion		u1, u2, u3; 
	char			c;
	short int		is;
	char			d[10], e[10];

	printf("===================================================\n");
	printf("Static memory allocation\n");
	printf("===================================================\n");
	printf("Address of s1 = %p, Sizeof of s1 = %d\n", &s1, sizeof(s1));
	printf("Address of s2 = %p, Sizeof of s2 = %d\n", &s2, sizeof(s2));
	printf("Address of s3 = %p, Sizeof of s3 = %d\n", &s3, sizeof(s3));
	printf("Address of u1 = %p, Sizeof of u1 = %d\n", &u1, sizeof(u1));
	printf("Address of u2 = %p, Sizeof of u2 = %d\n", &u2, sizeof(u2));
	printf("Address of u3 = %p, Sizeof of u3 = %d\n", &u3, sizeof(u3));
	printf("Address of c  = %p, Sizeof of c  = %d\n", &c, sizeof(c));
	printf("Address of i  = %p, Sizeof of i  = %d\n", &i, sizeof(i));
	printf("Address of is  = %p, Sizeof of is  = %d\n", &is, sizeof(is));
	printf("Address of d  = %p, Sizeof of d  = %d\n", &d, sizeof(d));
	printf("Address of e  = %p, Sizeof of e  = %d\n", &e, sizeof(e));
	printf("\n");
}

void demoDynamicMemAllocation()
{
	struct testStruct 	*s1 = NULL, *s2 = NULL, *s3 = NULL;
	union testUnion		*u1 = NULL, *u2 = NULL, *u3 = NULL; 
	char			*c = NULL;
	int			*i = NULL;
	short int		*is = NULL;
	char			*d = NULL, *e = NULL;

	printf("===================================================\n");
	printf("Dynamic memory allocation\n");
	printf("===================================================\n");

	s1 = (struct testStruct*)malloc(sizeof(s1));
	if (!s1)
	{
		perror("ERROR :: Memory allocation for s1");
		return;
	}

	s2 = (struct testStruct*)malloc(sizeof(s2));
	if (!s2)
	{
		perror("ERROR :: Memory allocation for s2");
		return;
	}

	s3 = (struct testStruct*)malloc(sizeof(s2));
	if (!s3)
	{
		perror("ERROR :: Memory allocation for s3");
		return;
	}

	u1 = (union testUnion*)malloc(sizeof(u1));
	if (!u1)
	{
		perror("ERROR :: Memory allocation for u1");
		return;
	}

	u2 = (union testUnion*)malloc(sizeof(u2));
	if (!u2)
	{
		perror("ERROR :: Memory allocation for u2");
		return;
	}

	u3 = (union testUnion*)malloc(sizeof(u2));
	if (!u3)
	{
		perror("ERROR :: Memory allocation for u3");
		return;
	}

	c = (char*)malloc(sizeof(c));
	if(!c)
	{
		perror("ERROR: Memory allocation for c\n");
		return;
	}

	i = (int*)malloc(sizeof(i));
	if(!i)
	{
		perror("ERROR: Memory allocation for i\n");
		return;
	}

	is = (short int*)malloc(sizeof(is));
	if(!is)
	{
		perror("ERROR: Memory allocation for is\n");
		return;
	}

	d = (char*)malloc(10);
	if(!d)
	{
		perror("ERROR: Memory allocation for d\n");
		return;
	}

	e = (char*)malloc(10);
	if(!e)
	{
		perror("ERROR: Memory allocation for e\n");
		return;
	}

	printf("s1 = %p\n", s1);
	printf("s2 = %p\n", s2);
	printf("s3 = %p\n", s3);
	printf("u1 = %p\n", u1);
	printf("u2 = %p\n", u2);
	printf("u3 = %p\n", u3);
	printf("c  = %p\n", c);
	printf("i  = %p\n", i);
	printf("is  = %p\n", is);
	printf("d  = %p\n", d);
	printf("e  = %p\n", e);

	printf("\n");
}

int main()
{
	demoStaticMemAllocation();
	demoDynamicMemAllocation();
	return 0;
}
