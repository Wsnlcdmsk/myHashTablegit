#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<map>
#include<string>
#include<iostream>
#define MAX 20

struct set
{
	char name[20];
	int id;
	int port;
	struct set* next;
};

int asciiFunction(char* str, int size);
void readFunction(int size, struct set** table);
void tableSearch(struct set** table, int size, char buf[]);
void deleteElement(struct set** table, int* size, char buf1[]);
void addFunction(struct set** table, int* size, char buf1[]);
bool search(struct set** table, int size, int* a, int* b, char* buf);
void cleaningFunction(struct set** table, int size);
void cleaningFunction(struct set** table, int size);

using namespace std;

int main()
{
	srand(time(NULL));
	struct set* table = NULL;
	int size, size1, chois, temp;
	char buffer[MAX];
	double mytime = 0.0, time = 0.0;
	string bf;
	printf("Enter the size of the table\n");
	do
	{
		scanf("%d", &size);
		if (size < 1 || size> 4945)
		{
			system("cls");
			printf("There is no so people\nEnter other number\n");
		}
	} while (size < 1 || size> 4945);
	size1 = size;
	clock_t begin = clock();
	table = (struct set*)calloc(size, sizeof(struct set));
	readFunction(size, &table);
	clock_t end = clock();
	mytime += (double)(end - begin) / CLOCKS_PER_SEC;
	map <int, char*> book;
	map <int, char*> ::iterator it;
	FILE* file;
	begin = clock();
	file = fopen("nameOfPeople.txt", "r");
	for (int i = 0; i < size1; i++)
	{
		fscanf(file, "%s", buffer);
		book.insert(make_pair(asciiFunction(buffer, size1), buffer));
	}
	fclose(file);
	end = clock();
	time += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Diference: %lf\n", mytime - time);
	while (true)
	{
		printf("Options:\n1.Add person\n2.Delete person\n3.Find person\n4.Exit\n");
		scanf("%d", &chois);
		switch (chois)
		{
		case 1:
			mytime = 0.0, time = 0.0;
			printf("Enter the name of person\n");
			scanf("%s", &buffer);
			begin = clock();
			addFunction(&table, &size, buffer);
			end = clock();
			mytime += (double)(end - begin) / CLOCKS_PER_SEC;
			begin = clock();
			size1++;
			book.insert(make_pair(asciiFunction(buffer, size1), buffer));
			end = clock();
			time += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("Diference: %lf\n", mytime - time);
			break;
		case 2:
			mytime = 0.0, time = 0.0;
			printf("Enter the name of person\n");
			cin >> buffer;
			begin = clock();
			deleteElement(&table, &size, buffer);
			end = clock();
			mytime += (double)(end - begin) / CLOCKS_PER_SEC;
			begin = clock();
			book.erase(asciiFunction(buffer, size1));
			end = clock();
			time += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("Diference: %lf\n", mytime - time);
			break;
		case 3:
			mytime = 0.0, time = 0.0;
			printf("Enter the name of person\n");
			cin >> buffer;
			begin = clock();
			tableSearch(&table, size, buffer);
			end = clock();
			mytime += (double)(end - begin) / CLOCKS_PER_SEC;
			it = book.find(asciiFunction(buffer, size));
			printf("Diference: %lf\n", mytime - time);
			break;
		case 4:
			cleaningFunction(&table, size);
			free(table);
			return 0;
			break;
		default:
			printf("There is no such option\n");
			break;
		}
	}
}