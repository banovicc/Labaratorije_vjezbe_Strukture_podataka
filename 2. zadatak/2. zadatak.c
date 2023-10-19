/*
2. Definirati strukturu osoba(ime, prezime, godina rodenja) i napisati program koji :
A.dinamicki dodaje novi element na pocetak liste,
B.ispisuje listu,
C.dinamicki dodaje novi element na kraj liste
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 30

typedef struct _person {
	char name[MAX_CHAR];
	char surname[MAX_CHAR];
	int birthyear;
	struct _person* next;
}person;

int insert(person** head);
int insertend(person** head);
int display(person* head);

int main()
{
	person* head = malloc(sizeof(person));
	head = NULL;

	insert(&head);

	insertend(&head);

	display(head);

	return 0;
}

int insert(person** head)
{
	int test = 1;

	while (test)
	{
		person* ptr = malloc(sizeof(person));

		printf("Unesite ime %d. osobe(0 za prekid unosa)\n", test);
		scanf("%s", ptr->name);
		if (strcmp(ptr->name, "0") == 0)
		{
			return 0;
		}

		printf("Unesite prezime %d. osobe(0 za prekid unosa)\n", test);
		scanf("%s", ptr->surname);
		if (strcmp(ptr->surname, "0") == 0)
		{
			return 0;
		}

		printf("Unesite godinu rodenja %d. osobe(0 za prekid unosa)\n", test);
		scanf("%d", &ptr->birthyear);
		if (ptr->birthyear == 0)
		{
			return 0;
		}

		test++;

		ptr->next = *head;
		*head = ptr;
	}
}

int insertend(person** head)
{
	int test = 1;

	while (test)
	{
		person* ptr = malloc(sizeof(person));

		printf("Unesite ime %d. osobe za unos na kraj liste(0 za prekid unosa)\n", test);
		scanf("%s", ptr->name);
		if (strcmp(ptr->name, "0") == 0)
		{
			return 0;
		}

		printf("Unesite prezime %d. osobe za unos na kraj liste(0 za prekid unosa)\n", test);
		scanf("%s", ptr->surname);
		if (strcmp(ptr->surname, "0") == 0)
		{
			return 0;
		}

		printf("Unesite godinu rodenja %d. osobe za unos na kraj liste(0 za prekid unosa)\n", test);
		scanf("%d", &ptr->birthyear);
		if (ptr->birthyear == 0)
		{
			return 0;
		}

		test++;
		ptr->next = NULL;

		if (*head == NULL)
		{
			*head = ptr;
		}
		else
		{
			person* temp = *head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}
}

int display(person* head)
{
	system("cls");

	if (head == NULL)
	{
		printf("Lista je prazna");
	}
	else
	{
		printf("IME\tPREZIME\t\tGODINA RODENJA\n");

		while (head != NULL)
		{
			printf("%s\t%s\t\t%d\n", head->name, head->surname, head->birthyear);
			head = head->next;
		}
	}

	return 0;
}