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

int asciiFunction(char* str, int size)
{
	int temp = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		temp += (int)str[i];
	}
	return temp % size;
}


bool search(struct set** table, int size, int* a, int* b, char* buf)
{
	struct set* temp;
	int index;
	index = asciiFunction(buf, size);
	temp = (*table)[index].next;
	if (strcmp(buf, (*table)[index].name) == 0)
	{
		*a = (*table)[index].port;
		*b = (*table)[index].id;
		return true;
	}
	if (temp != NULL)
	{
		do
		{
			if (strcmp(buf, temp->name) == 0)
			{
				*a = temp->port;
				*b = temp->id;
				return true;
			}
			temp = temp->next;
		} while (temp != NULL);
	}
}

void cleaningFunction(struct set** table, int size)
{
	struct set* temp1;
	struct set* temp2;
	for (int i = 0; i < size; i++)
	{
		temp1 = (*table)[i].next;
		while (temp1 != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			free(temp2);
		}
	}
}