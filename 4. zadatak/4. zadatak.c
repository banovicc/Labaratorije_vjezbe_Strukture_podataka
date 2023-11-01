/*
4. Napisati program za zbrajanje i mnozenje polinoma.Koeficijenti i eksponenti se
citaju iz datoteke.
Napomena: Eksponenti u datoteci nisu nuzno sortirani.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024

typedef struct nebitno {
	int koef;
	int pot;
	struct nebitno* next;
}person_;

typedef person_* person;

int readfile(person head1, person head2);
int display(person head);
int multiply(person head1, person head2, person headm);
int insert(person head, int koef, int pot);
int add(person head1, person head2, person heads);
int deleteall(person head);

int main()
{
	person_ head1;
	person_ head2;
	person_ headm;
	person_ heads;

	head1.next = NULL;
	head2.next = NULL;
	headm.next = NULL;
	heads.next = NULL;

	readfile(&head1, &head2);

	multiply(head1.next, head2.next, &headm);
	add(head1.next, head2.next, &heads);

	printf("Prvi polinom:\n");
	display(head1.next);

	printf("\nPrvi polinom:\n");
	display(head2.next);

	printf("\nUmnozak polinoma:\n");
	display(headm.next);

	printf("\nZbroj polinoma:\n");
	display(heads.next);

	deleteall(&head1);
	deleteall(&head2);
	deleteall(&headm);
	deleteall(&heads);

	return 0;
}

int readfile(person head1, person head2)
{
	char buffer[MAX_LINE];
	int buffercout = 0;
	int bctr = 0;
	int tempk = 0, tempp = 0;

	FILE* fptr = NULL;
	fptr = fopen("Polinomi.txt", "r");

	fgets(buffer, MAX_LINE, fptr);

	person temp = head1;

	while (sscanf(buffer + bctr, "%dx^%d %n", &tempk, &tempp, &buffercout) == 2)
	{
		bctr += buffercout;
		insert(head1, tempk, tempp);
	}

	fgets(buffer, 1024, fptr);
	bctr = 0;

	temp = head2;

	while (sscanf(buffer + bctr, "%dx^%d %n", &tempk, &tempp, &buffercout) == 2)
	{
		bctr += buffercout;
		insert(head2, tempk, tempp);
	}

	fclose(fptr);
}

int display(person head)
{
	if (head == NULL)
	{
		return;
	}

	while (head != NULL)
	{
		printf("%dx^%d ", head->koef, head->pot);
		head = head->next;
	}
	printf("\n");
}

int multiply(person head1, person head2, person headm)
{
	person temp = head2;
	while (head1 != NULL)
	{
		head2 = temp;
		while (head2 != NULL)
		{
			insert(headm, head2->koef * head1->koef, head2->pot + head1->pot);
			head2 = head2->next;
		}
		head1 = head1->next;
	}
}

int insert(person head, int koef, int pot)
{
	while (head->next != NULL && head->next->pot != pot)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		person ptr = malloc(sizeof(person_));
		ptr->koef = koef;
		ptr->pot = pot;

		while (head->next != NULL && head->next->pot < pot)
			head = head->next;

		ptr->next = head->next;
		head->next = ptr;
	}
	else
	{
		head->next->koef += koef;
	}
}

int add(person head1, person head2, person heads)
{
	while (head1 != NULL && head2 != NULL)
	{
		if (head2->pot == head1->pot)
		{
			insert(heads, head2->koef + head1->koef, head1->pot);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head2->pot > head1->pot)
		{
			insert(heads, head1->koef, head1->pot);
			head1 = head1->next;
		}
		else if (head1->pot > head2->pot)
		{
			insert(heads, head2->koef, head2->pot);
			head2 = head2->next;
		}
	}
	if (head2 == NULL)
	{
		while (head1 != NULL)
		{
			insert(heads, head1->koef, head1->pot);
			head1 = head1->next;
		}
	}
	if (head1 == NULL)
	{
		while (head2 != NULL)
		{
			insert(heads, head2->koef, head2->pot);
			head2 = head2->next;
		}
	}
}

int deleteall(person head)
{
	person temp;

	while (head->next != NULL)
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}