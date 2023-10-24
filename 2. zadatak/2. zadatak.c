/*
Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste,
B. ispisuje listu,
C. dinamicki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. brise odredeni element iz liste
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
}personstr;

typedef personstr* person;

int menu();
int insert(person head);
int display(person head);
int insertend(person head);
person searchsurname(person head);
int deleteperson(person head);

int main()
{
	int n = 0;

	personstr head;
	head.next = NULL;

	do {
		n = menu();
		switch (n)
		{
		case 1:
			insert(&head);
			break;

		case 2:
			display(head.next);
			break;

		case 3:
			insertend(&head);
			break;

		case 4:
			searchsurname(head.next);
			break;

		case 5:
			deleteperson(&head);
			break;

		default:
			break;
		}
	} while (n != 6);

	return 0;
}

int menu()
{
	int x;

	textcolor();

	printf("Pritisnite 1 za dodavanje osobe na pocetak liste\n");
	printf("Pritisnite 2 za ispis liste\n");
	printf("Pritisnite 3 za dodavanje osobe na kraj liste\n");
	printf("Pritisnite 4 za pronalazak osobe s liste\n");
	printf("Pritisnite 5 za brisanje osobe sa liste\n");
	printf("Pritisnite 6 za izlazak iz programa\n");

	scanf("%d", &x);

	return x;
}

int insert(person head)
{
	person ptr = malloc(sizeof(personstr));
	system("cls");

	printf("Unesite ime osobe:\n");
	scanf("%s", ptr->name);
	printf("Unesite ime prezime:\n");
	scanf("%s", ptr->surname);
	printf("Unesite godinu rodenja osobe:\n");
	scanf("%d", &ptr->birthyear);

	printf("\n-----------------\n\n");

	ptr->next = head->next;
	head->next = ptr;

	return 0;
}

int display(person head)
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
			printf("%s\t%s\t%d\n", head->name, head->surname, head->birthyear);
			head = head->next;
		}
	}

	printf("\n-----------------\n\n");

	return 0;
}

int insertend(person head)
{
	person ptr = malloc(sizeof(personstr));
	system("cls");

	printf("Unesite ime osobe:\n");
	scanf("%s", ptr->name);
	printf("Unesite prezime osobe:\n");
	scanf("%s", ptr->surname);
	printf("Unesite godinu rodenja osobe:\n");
	scanf("%d", &ptr->birthyear);

	printf("\n-----------------\n\n");

	ptr->next = NULL;

	if (head->next == NULL)
	{
		head->next = ptr;
	}
	else
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = ptr;
	}

	return 0;
}

person searchsurname(person head)
{
	char tempc[MAX_CHAR];

	system("cls");

	if (head == NULL)
	{
		printf("Lista je prazna\n");
	}
	else
	{
		printf("Unesi prezime za pretragu:\n");
		scanf("%s", tempc);
		while (head != NULL && strcmp(tempc, head->surname) != 0)
		{
			head = head->next;
		}
		if (head == NULL)
		{
			printf("Prezime %s ne postoji na listi\n\n", tempc);
		}
		else
		{
			printf("\n-----------------\n\n");
			printf("\n%s\t%s\t\t%d\n", head->name, head->surname, head->birthyear);
		}
	}

	printf("\n-----------------\n\n");

	return head;
}

int deleteperson(person head)
{
	person temp = head;
	char tempc[MAX_CHAR];

	system("cls");

	printf("Unesite prezime koje zelite izbrisati:\n");
	scanf("%s", tempc);

	while (head != NULL && strcmp(tempc, head->next->surname) != 0)
	{
		head = head->next;
	}
	if (head == NULL)
	{
		printf("Ne postoji to prezime!\n\n");
	}
	else
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
		printf("\nUspjesno ste izbrisali prezime %s s liste\n", tempc);
	}

	printf("\n-----------------\n\n");
}
