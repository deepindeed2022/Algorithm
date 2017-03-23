#include <stdio.h>
struct student
{
	char name[12];
	char score;
};
int main(int argc, char const *argv[])
{
	struct student a[100], t;
	int i, j, n;
	FILE* f = fopen(argv[1], "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; ++i)
	{
		fscanf(f, "%s %d", a[i].name, &a[i].score);
	}

	for (i = 0; i < n-1; ++i)
	{
		for (j = 0; j < n-i; ++j)
		{
			if(a[j].score < a[j+1].score)
			{
				t = a[j]; a[j] = a[j+1];a[j+1]=t;
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		printf("%s\n", a[i].name);
	}
	return 0;
}