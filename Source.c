#include <stdio.h>
#include<stdlib.h>
#include <locale.h>


unsigned int main()
{
	
	setlocale(LC_ALL, "Rus");

	
	FILE* file = 0;
	fopen_s(&file, "..\\textFile.txt", "w");

	

	 int N, max, min;
	printf("N= \t");
	scanf_s("%d", &N);
	fprintf(file, "N= %d\n", N);
	printf("max= \t");
	scanf_s("%d", &max);
	printf("min= \t");
	scanf_s("%d", &min);
	int i = 0;
	
	
	unsigned int* massic;
	massic = (unsigned int*)malloc(N * sizeof(unsigned int));

	if (N <= 0)
	{
		printf("ÎØÈÁÊÀ N<=0!:(\n");
		return 0;
	}
	if (max < min )
		
	{
		printf("ÎØÈÁÊÀ max<min!:(\n");
		return 0;
	}
	if (massic == 0)
	{
		printf("ÎØÈÁÊÀ massic==0!:(\n");
		return 0;
	}
	
	for (i = 0; i < N; i++)
	{
		massic[i] = rand();
		massic[i] = ((double)rand() / RAND_MAX * (max - min) + min);

		fprintf(file, "%u\n", massic[i]);

	}
	
	fclose(file);
	
	for (i = 0; i < N; i++)
	{
		printf("massic[%d]=%u\n", i, massic[i]);
		}
	free (massic);
  return 0;
}

