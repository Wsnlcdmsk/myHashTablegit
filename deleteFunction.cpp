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

void deleteElement(struct set** table, int* size, char buf1[])
{
	struct set* nw;
	struct set* temp = NULL;
	struct set* prev = NULL;
	struct set* onemore = NULL;
	char buf[MAX];
	int index, u1, u2;
	if (search(table, *size, &u1, &u2, buf1) == false)
	{
		printf("There is no such people\n");
		return;
	}
	(*size)--;
	nw = (struct set*)calloc(*size, sizeof(struct set));
	for (int i = 0; i < (*size) + 1; i++)
	{
		onemore = &((*table)[i]);
		do
		{
			strcpy(buf, onemore->name);
			index = asciiFunction(buf, *size);
			onemore = onemore->next;
			if (strcmp(buf1, buf) == 0)
			{
				continue;
			}
			temp = (nw)[index].next;
			prev = &((nw)[index]);
			while (prev->next != NULL)
			{
				prev = prev->next;
			}
			if ((nw)[index].id == 0)
			{
				strcpy((nw)[index].name, buf);
				search(table, (*(size)-1), &u1, &u2, buf);
				(nw)[index].port = u1;
				(nw)[index].id = u2;
				(nw)[index].next = NULL;
			}
			else
			{
				while (temp != NULL && temp != temp->next)
				{
					temp = temp->next;
				}
				temp = (struct set*)calloc(1, sizeof(struct set));
				strcpy(temp->name, buf);
				search(table, (*(size)-1), &u1, &u2, buf);
				temp->port = u1;
				temp->id = u2;
				temp->next = NULL;
				prev->next = temp;
			}
		} while (onemore != NULL);
	}
	cleaningFunction(table, *size);
	*table = nw;
}