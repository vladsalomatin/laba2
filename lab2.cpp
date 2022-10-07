#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CTR_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <locale>

void shell(int *mass, int n)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i<n; ++i) {
			x = mass[i];
			for (j = i - gap; (x <mass[j]) && (j >= 0); j = j - gap)
				mass[j + gap] = mass[j];
			mass[j + gap] = x;
		}
	}
}
void qs(int *mass, int left, int right)
{
	int i, j;
	int x, y;
	i = left;
	j = right;
	x = mass[(left + right) / 2];
	do {
		while ((mass[i] < x) && (i<right))i++;
		while ((x <mass[j]) && (j >left))j--;
		if (i<= j)
		{
			y = mass[i];
			mass[i] = mass[j];
			mass[j] = y;
			i++; j--;

		}
	} while (i<= j);
	if (left< j) qs(mass, left, j);
	if (i<right) qs(mass, i, right);
}
int comp(const void *i, const void *j) {
	return *(int *)i - *(int *)j;
}
void randmass(int *mass, int n){
	for (int i = 0; i< n; i++) {
		mass[i] = rand() % 100;
	}
}
void vozrmass(int *mass, int n){
	for (int i = 0; i< n; i++) {
		mass[i] = i;
	}
}
void ybmass(int *mass, int n){
	for (int i = 0; i< n; i++) {
		mass[i] = n - i;
	}
}
void vozrybmass(int *mass, int n){
	for (int i = 0; i< n / 2; i++) {
		mass[i] = mass[i-1] + i;
	}
	for (int i = n / 2; i< n; i++) {
		mass[i] = n - i;
	}
}
void sort(FILE *f, int *mass, int n) {
	randmass(mass, n);
	time_t start1 = clock();
	shell(mass, n);
	time_t stop1 = clock();
	double time1 = (stop1 - start1) / 1000.0;
	printf("\n");
	printf("Время сортировки Шелла:  %lf", time1);
	fprintf(f, "Время сортировки Шелла:  %lf\n", time1);
	printf("\n");

	randmass(mass, n);
	time_t start2 = clock();
	qs(mass, 0, n - 1);
	time_t stop2 = clock();
	double time2 = (stop2 - start2) / 1000.0;
	printf("Время быстрой сортировки: %lf", time2);
	fprintf(f, "Время быстрой сортировки: %lf\n", time2);
	printf("\n");

	randmass(mass, n);
	time_t start3 = clock();
	qsort(mass, n, sizeof(int), comp);
	time_t stop3 = clock();
	double time3 = (stop3 - start3) / 1000.0;
	printf("Время встроенной сортировки: %lf", time3);
	fprintf(f, "Время встроенной сортировки: %lf\n\n", time3);
}
void sort1(FILE *f, int *mass, int n) {
	vozrmass(mass, n);
	time_t start1 = clock();
	shell(mass, n);
	time_t stop1 = clock();
	double time1 = (stop1 - start1) / 1000.0;
	printf("\n");
	printf("Время сортировки Шелла:  %lf", time1);
	fprintf(f, "Время сортировки Шелла:  %lf\n", time1);
	printf("\n");

	vozrmass(mass, n);
	time_t start2 = clock();
	qs(mass, 0, n - 1);
	time_t stop2 = clock();
	double time2 = (stop2 - start2) / 1000.0;
	printf("Время быстрой сортировки: %lf", time2);
	fprintf(f, "Время быстрой сортировки: %lf\n", time2);
	printf("\n");

	vozrmass(mass, n);
	time_t start3 = clock();
	qsort(mass, n, sizeof(int), comp);
	time_t stop3 = clock();
	double time3 = (stop3 - start3) / 1000.0;
	printf("Время встроенной сортировки: %lf", time3);
	fprintf(f, "Время встроенной сортировки: %lf\n\n", time3);
}
void sort2(FILE *f, int *mass, int n) {
	ybmass(mass, n);
	time_t start1 = clock();
	shell(mass, n);
	time_t stop1 = clock();
	double time1 = (stop1 - start1) / 1000.0;
	printf("\n");
	printf("Время сортировки Шелла:  %lf", time1);
	fprintf(f, "Время сортировки Шелла:  %lf\n", time1);
	printf("\n");

	ybmass(mass, n);
	time_t start2 = clock();
	qs(mass, 0, n - 1);
	time_t stop2 = clock();
	double time2 = (stop2 - start2) / 1000.0;
	printf("Время быстрой сортировки: %lf", time2);
	fprintf(f, "Время быстрой сортировки: %lf\n", time2);
	printf("\n");

	ybmass(mass, n);
	time_t start3 = clock();
	qsort(mass, n, sizeof(int), comp);
	time_t stop3 = clock();
	double time3 = (stop3 - start3) / 1000.0;
	printf("Время встроенной сортировки: %lf", time3);
	fprintf(f, "Время встроенной сортировки: %lf\n\n", time3);
}
void sort3(FILE *f, int *mass, int n) {
	vozrybmass(mass, n);
	time_t start1 = clock();
	shell(mass, n);
	time_t stop1 = clock();
	double time1 = (stop1 - start1) / 1000.0;
	printf("\n");
	printf("Время сортировки Шелла:  %lf", time1);
	fprintf(f, "Время сортировки Шелла:  %lf\n", time1);
	printf("\n");

	vozrybmass(mass, n);
	time_t start2 = clock();
	qs(mass, 0, n - 1);
	time_t stop2 = clock();
	double time2 = (stop2 - start2) / 1000.0;
	printf("Время быстрой сортировки: %lf", time2);
	fprintf(f, "Время быстрой сортировки: %lf\n", time2);
	printf("\n");

	vozrybmass(mass, n);
	time_t start3 = clock();
	qsort(mass, n, sizeof(int), comp);
	time_t stop3 = clock();
	double time3 = (stop3 - start3) / 1000.0;
	printf("Время встроенной сортировки: %lf", time3);
	fprintf(f, "Время встроенной сортировки: %lf\n\n", time3);
}
int main()
{
	FILE *f;
	int *mass;
	int n;
	f = fopen("f.txt", "w");
	setlocale(LC_ALL, "RUS");
	printf("Размер массива: ");
	scanf_s("%d", &n);

	srand(time(NULL));
	mass = (int*)malloc(n * sizeof(int));

	printf("Случайные числа:");
	fprintf(f, "Случайные числа:\n");
	sort(f, mass, n);
	printf("\n");
	printf("\n");
	printf("Возрастающая последовательность:");
	fprintf(f, "Возрастающая последовательность:\n");
	sort1(f, mass, n);
	printf("\n");
	printf("\n");
	printf("Убывающая последовательность:");
	fprintf(f, "Убывающая последовательность:\n");
	sort2(f, mass, n);
	printf("\n");
	printf("\n");
	printf("Возрастающая / Убывающая последовательность:");
	fprintf(f, "Возрастающая / Убывающая последовательность:\n");
	sort3(f, mass, n);

	fclose(f);
	free(mass);

	getchar();
	getchar();
	return(0);
}
