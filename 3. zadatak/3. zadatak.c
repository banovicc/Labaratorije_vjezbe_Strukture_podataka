/*
2. Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste,
B. ispisuje listu,
C. dinamicki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. brise odredeni element iz liste

3. Prethodnom zadatku dodati funkcije:
A. dinamicki dodaje novi element iza odredenog elementa,
B. dinamicki dodaje novi element ispred odredenog elementa,
C. sortira listu po prezimenima osoba,
D. upisuje listu u datoteku,
E. cita listu iz datoteke.
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
int searchsurname(person head);
int deleteperson(person head);
int insertbefore(person head);
int insertafter(person head);
int sort(person head);
int replace(person j, person jnext);
int fileinsert(person head);
int filereader(int x);
int deleteall(person head);

int main()
{
	int n = 0;
	int x = 0;

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

		case 6:
			insertbefore(&head);
			break;

		case 7:
			insertafter(&head);
			break;

		case 8:
			sort(&head);
			break;

		case 9:
			x = fileinsert(head.next);
			break;

		case 10:
			filereader(x);
			break;

		default:
			return 0;
			break;
		}
	} while (n != 11);

	deleteall(&head);

	return 0;
}

int menu()
{
	int x;

	printf("Pritisnite 1 za dodavanje osobe na pocetak liste\n");
	printf("Pritisnite 2 za ispis liste\n");
	printf("Pritisnite 3 za dodavanje osobe na kraj liste\n");
	printf("Pritisnite 4 za pronalazak osobe s liste\n");
	printf("Pritisnite 5 za brisanje osobe sa liste\n");
	printf("Pritisnite 6 za unos osobe prije odredene osobe\n");
	printf("Pritisnite 7 za unos osobe poslje odredene osobe\n");
	printf("Pritisnite 8 za sortiranje liste\n");
	printf("Pritisnite 9 za upis liste u datoteku\n");
	printf("Pritisnite 10 za ispis liste iz datoteke\n");
	printf("Pritisnite 11 za izlazak iz programa\n");

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
		printf("Lista je prazna\n");
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

int searchsurname(person head)
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
	if (head->next == NULL)
	{
		system("cls");
		printf("Lista je prazna\n");
		printf("\n-----------------\n\n");

		return 0;
	}

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

int insertbefore(person head)
{
	system("cls");

	if (head->next == NULL)
	{
		printf("Lista je prazna:\n");
		printf("\n-----------------\n\n");
		return 0;
	}

	person ptr = malloc(sizeof(personstr));
	char tempc[CHAR_MAX];

	printf("Unesite ime osobe:\n");
	scanf("%s", ptr->name);
	printf("Unesite prezime osobe:\n");
	scanf("%s", ptr->surname);
	printf("Unesite godinu rodenja osobe:\n");
	scanf("%d", &ptr->birthyear);

	printf("Unesite prezime ispred kojeg zelite dodati unesenu osobu:\n");
	scanf("%s", tempc);

	while (head->next != NULL && strcmp(head->next->surname, tempc) != 0)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		printf("Prezime koje ste naveli se nalazi u listi:\n");
	}
	else
	{
		ptr->next = head->next;
		head->next = ptr;
	}
	printf("\n-----------------\n\n");
}

int insertafter(person head)
{
	system("cls");

	if (head->next == NULL)
	{
		printf("Lista je prazna:\n");
		printf("\n-----------------\n\n");
		return 0;
	}

	person ptr = malloc(sizeof(personstr));
	char tempc[CHAR_MAX];

	printf("Unesite ime osobe:\n");
	scanf("%s", ptr->name);
	printf("Unesite prezime osobe:\n");
	scanf("%s", ptr->surname);
	printf("Unesite godinu rodenja osobe:\n");
	scanf("%d", &ptr->birthyear);

	printf("Unesite prezime iza kojeg zelite dodati unesenu osobu:\n");
	scanf("%s", tempc);

	while (head->next->next != NULL && strcmp(head->surname, tempc) != 0)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		printf("Prezime koje ste naveli se nalazi u listi:\n");
	}
	else
	{
		ptr->next = head->next;
		head->next = ptr;
		printf("Prezime ste uspjesno dodali iza %s", tempc);
	}
	printf("\n-----------------\n\n");
}

int sort(person head)
{
	person j, j_prev, end;

	char tempc[MAX_CHAR];
	int tempi;

	end = NULL;
	while (head->next != end)
	{
		j_prev = head;
		j = head->next;

		while (j->next != end)
		{
			if (strcmp(j->surname, j->next->surname) < 0)
			{
				replace(j, j->next);
			}

			j_prev = j;
			j = j->next;
		}
		end = j;
	}
	return 0;
}

int replace(person j, person jnext)
{
	system("cls");

	char tempc[MAX_CHAR];
	int tempi;

	strcpy(tempc, j->name);
	strcpy(j->name, jnext->name);
	strcpy(jnext->name, tempc);

	strcpy(tempc, j->surname);
	strcpy(j->surname, jnext->surname);
	strcpy(jnext->surname, tempc);

	tempi = j->birthyear;
	j->birthyear = jnext->birthyear;
	jnext->birthyear = tempi;

	return 0;
}

int fileinsert(person head)
{
	if (head == NULL)
	{
		printf("Lista je prazna\n");
		printf("\n-----------------\n\n");
		return 0;
	}

	FILE* fptr = fopen("persons.txt", "w");

	if (fptr == NULL)
	{
		printf("Neuspjesno otvaranje datoteke");
		return 0;
	}

	fprintf(fptr, "IME\tPREZIME\t\tGODINA RODENJA\n");

	while (head != NULL)
	{
		fprintf(fptr, "%s\t%s\t\t%d\n", head->name, head->surname, head->birthyear);
		head = head->next;
	}

	system("cls");

	printf("Upis je uspjesno obavljen:\n");
	printf("\n-----------------\n\n");

	fclose(fptr);

	return 1;
}

int filereader(int x)
{
	system("cls");

	if (x == 0)
	{
		printf("Datoteka je prazna\n");
		printf("\n-----------------\n\n");
		return 0;
	}

	FILE* fptr = fopen("persons.txt", "r");

	if (fptr == NULL)
	{
		printf("Datoteka se nije uspjela otvoriti\n");
		printf("\n-----------------\n\n");
		return 0;
	}

	char tempn[MAX_CHAR], temps[MAX_CHAR];
	int tempb;

	while (fgetc(fptr) != '\n');

	printf("IME\tPREZIME\t\tGODINA RODENJA\n");

	while (fscanf(fptr, "%s\t%s\t%d", tempn, temps, &tempb) != EOF)
	{
		printf("%s\t%s\t\t%d\n", tempn, temps, tempb);
	}

	printf("\n-----------------\n\n");

	fclose(fptr);

	return 0;
}

int deleteall(person head)
{
	if (head->next == NULL)
	{
		return 0;
	}
	person temp;

	while (head->next != NULL)
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);

		head = head->next;
	}
	return 0;
}