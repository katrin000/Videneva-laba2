
#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<time.h>

void PrintMassic(unsigned int* massic, int N)
{
	int i = 0;
	for (i = 0; i < N; i++) {
printf("massic[%d]=%u\n", i, massic[i]);
}
}
void Puzirec(unsigned int* a,  int l)
{
	int i, j;
	int temp = 0;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < l - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
   }
}

void vstavka(unsigned int* a,  int l)
{
	int i, j;
	 int temp = 0;
	for (i = 1; i < l; i++)
	{
		temp = a[i];
				for (j = i-1; j > 0; j--)
				{
					if (a[j] > temp)
					{
						a[j + 1] = a[j];
           }
				}
	          a[j + 1] = temp;
	}
}

void qSort(unsigned int* mas,  int l,  int u) {
	 int i = l;
	 int j = u;
	 int temp = 0;
	 int x = mas[(l + u) / 2];
	do {
		while (mas[i] < x) ++i;
		while (mas[j] > x) --j;
		if (i <= j) {
			temp = mas[i];
			mas[i] = mas[j];
			mas[j] = temp;
			i++;
			j--;
		}
	} while (i < j);
	if (l < j)
		qSort(mas, l, j);
	if (i < u)
		qSort(mas, i, u);
}
void bistro(unsigned int *a, int l)
{
	qSort(a, 0, l - 1);

}


int main()
{
	setlocale(LC_ALL, "Rus");

	
	 int N = 0;
	 int i = 0;
	 int max;
	 int min;


	
	int a = 0;
	int b = 0;
	 unsigned int* massic=0;
	 
	 FILE* file;
	 fopen_s(&file, "..\\textFile.txt", "r");

	 fscanf_s(file, "N= %u\n", &N);
	
	
	
	massic = (unsigned int*)malloc(N * sizeof(unsigned int));
	
	for (i = 0; i < N; i++)
	{
		massic[i] = 0;

	}
	
	srand(time(0));
	for (i = 0; i < N; i++)
	{
		fscanf_s(file, "%u\n", &(massic[i]));
		
	}
	

		do
		{
			printf("Выберите команду:\n1)Печать\n2)Сортировка\n3)Сброс\n4)Выход\n");
			printf("Введите № действия: ");
			scanf_s("%d", &a);
		
			if (a == 1) {
				for (i = 0; i < N; i++) {
					
					PrintMassic(massic, N);
					return 0;


				}
			}
			else if (a == 2) {
				printf("Выберите метод сортировки:\n1. Пузырьком\n2. Вставкой\n3. Быстрая\n");
				printf("Введите № сортировки: ");
				scanf_s("%d", &b);



				if (b == 1) {
					clock_t t1 = clock();
					Puzirec(massic, N);
					clock_t t2 = clock();
					for (i = 0; i < N; i++)
					{
						printf("massic[%d]=%u\n", i, massic[i]);
						

					}
				
					printf("\n\nPuzirec=%lf\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
				}
				if (b == 2) {
					clock_t t1 = clock();
					vstavka(massic, N);
					clock_t t2 = clock();
					for (i = 0; i < N; i++)
					{
						printf("massic[%d]=%u\n", i, massic[i]);


					}
					printf("\n\nvstavka=%lf\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
				}
				if (b == 3) {
					clock_t t1 = clock();
					bistro(massic, N);
					clock_t t2 = clock();
					for (i = 0; i < N; i++)
					{
						printf("massic[%d]=%u\n", i, massic[i]);


					}
					printf("\n\nbistro=%lf\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
				}
				if (b > 3) {
					printf("Ошибка, выберите цифру от 1 до 3!!!");
				}
			}
			else if (a == 3)
			{
				for (i = 0; i < N; i++)
				{
					fscanf_s(file, "%u", &massic[i]);
				}
				printf("Массив сброшен к исходному.\n");
			}

			else if (a == 4)
			{
				printf("Завершение работы.\n");
			}

			else
			{
				printf("!ОШИБКА!\n");
			}
			
		} while (a != 4);

	
		


	fclose(file);
	
	free (massic);
return 0;
		
}