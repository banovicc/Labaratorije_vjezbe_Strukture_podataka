/*
Napisati program koji iz datoteke cita postfiks izraz i zatim koristenjem stoga racuna
rezultat. Stog je potrebno realizirati preko vezane liste.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

typedef struct nebitno {
	int number;
	struct nebitno* next;
}node_;

typedef node_* node;

int readfromfile(node head);
int push(node head, int x);
int operation(node head, char op);
int delandret(node head);
int printingresult(node head);
int deleteifremain(node head);

int main()
{
	int test;

	node_ head;
	head.next = NULL;

	test = readfromfile(&head);

	if (test == 1)
	{
		deleteifremain(&head);
		return 0;
	}

	printingresult(&head);

	return 0;
}

int readfromfile(node head)
{
	char buffer[MAX_LINE];
	double number = 0, test = 0;
	int bytecount = 0;
	char operazon;

	FILE* fptr = fopen("datoteka.txt", "r");

	if (fptr == NULL)
	{
		return -1;
	}

	fgets(buffer, MAX_LINE, fptr);

	char* bufferptr = buffer;

	while (strlen(bufferptr) > 1 && test == 0)
	{
		if (sscanf(bufferptr, "%lf %n", &number, &bytecount) == 1)
		{
			push(head, (int)number);
		}
		else
		{
			sscanf(bufferptr, "%c", &operazon);
			test = operation(head, operazon);
		}
		bufferptr += bytecount;
	}
	if (strlen(bufferptr) == 1 && test == 0)
	{
		sscanf(bufferptr, "%c", &operazon);
		operation(head, operazon);
	}

	if (test == 1)
	{
		printf("Format postfix izraza nije unesen dobro\n");
		return 1;
	}

	fclose(fptr);

	return 0;
}

int push(node head, int x)
{
	node ptr = malloc(sizeof(node_));
	ptr->number = x;

	ptr->next = head->next;
	head->next = ptr;
}

int operation(node head, char op)
{
	int num1, num2;
	int result = 0;
	int x = 0;

	num1 = delandret(head);
	num2 = delandret(head);

	switch (op)
	{
	case '+':
		result = num1 + num2;
		break;

	case '-':
		result = num2 - num1;
		break;

	case '*':
		result = num2 * num1;
		break;

	default:
		x = 1;
		break;
	}

	push(head, result);
	return x;
}

int delandret(node head)
{
	int x;

	node temp = head->next;

	x = temp->number;

	head->next = temp->next;
	free(temp);

	return x;
}

int printingresult(node head)
{
	if (head->next == NULL)
	{
		printf("Lista je prazna\n");
		return 1;
	}
	printf("Rezultat iznosi: %d\n", head->next->number);
	free(head->next);
	return 0;
}

int deleteifremain(node head)
{
	if (head->next == NULL)
	{
		return 0;
	}
	node temp = head;
	while (head->next != NULL)
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}