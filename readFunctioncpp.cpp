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

void readFunction(int size, struct set** table)
{
	FILE* file;
	struct set* temp = NULL;
	struct set* prev;
	char buf[MAX];
	int index = 0, u1, u2;
	file = fopen("nameOfPeople.txt", "r");
	for (int i = 0; i < size; i++)
	{
		fscanf(file, "%s", buf);
		index = asciiFunction(buf, size);
		temp = (*table)[index].next;
		prev = &((*table)[index]);
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		if ((*table)[index].id == 0)
		{
			strcpy((*table)[index].name, buf);
			u1 = rand();
			u2 = rand();
			(*table)[index].port = u1 * u2 % 65536;
			u1 = rand();
			u2 = rand();
			(*table)[index].id = 1 + u1 * u2 % 1000000;
			(*table)[index].next = NULL;
		}
		else
		{
			while (temp != NULL)
			{
				temp = temp->next;
			}
			temp = (struct set*)calloc(1, sizeof(struct set));
			strcpy(temp->name, buf);
			u1 = rand();
			u2 = rand();
			temp->port = u1 * u2 % 65536;
			temp->id = 1 + (rand() * rand()) % 1000000;
			temp->next = NULL;
			prev->next = temp;
		}
	}
	fclose(file);
}