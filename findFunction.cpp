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

void tableSearch(struct set** table, int size, char buf[])
{
	struct set* temp;
	int index;
	bool flag = false;
	index = asciiFunction(buf, size);
	temp = (*table)[index].next;
	if (strcmp(buf, (*table)[index].name) == 0)
	{
		printf("\n----------------------------\n");
		printf("Name: %s\n", (*table)[index].name);
		printf("Port: %d\n", (*table)[index].port);
		printf("IP: ");
		printf("%d", (*table)[index].id / 100000);
		printf("%d", (*table)[index].id % 100000 / 10000);
		printf("%d.", (*table)[index].id % 10000 / 1000);
		printf("%d", (*table)[index].id % 1000 / 100);
		printf("%d", (*table)[index].id % 100 / 10);
		printf("%d\n", (*table)[index].id % 10);
		printf("----------------------------\n");
		return;
	}
	if (temp != NULL)
	{
		do
		{
			if (strcmp(buf, temp->name) == 0)
			{
				flag = true;
				printf("\n----------------------------\n");
				printf("Name: %s\n", temp->name);
				printf("Port: %d\n", temp->port);
				printf("IP: ");
				printf("%d", temp->id / 100000);
				printf("%d", temp->id % 100000 / 10000);
				printf("%d.", temp->id % 10000 / 1000);
				printf("%d", temp->id % 1000 / 100);
				printf("%d", temp->id % 100 / 10);
				printf("%d\n", temp->id % 10);
				printf("----------------------------\n");
			}
			temp = temp->next;
		} while (temp != NULL);
	}
	if (flag == false)
	{
		printf("There is no such people\n");
	}
}