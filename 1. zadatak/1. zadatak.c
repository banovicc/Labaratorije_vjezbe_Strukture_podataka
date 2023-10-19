/*
Napisati program koji prvo procita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i ucitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrzi ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TASK_FAILED -1
#define MAX_CHAR 30
#define MAX_LINE 1024

typedef struct {
	char name[MAX_CHAR];
	char surname[MAX_CHAR];
	int mark;
}student;

int rowsreader();
int readingdata(student* studentptr, int rowsnumber);
int displaystudents(student* studentptr, int rowsnumber);

int main()
{
	int rowsnumber;

	rowsnumber = rowsreader();

	student* studentptr = malloc(sizeof(student) * rowsnumber);

	readingdata(studentptr, rowsnumber);
	displaystudents(studentptr, rowsnumber);

	free(studentptr);

	return 0;
}

int rowsreader()
{
	int count = 0;
	char buffer[MAX_LINE];

	FILE* fptr = fopen("Student.txt", "r");

	if (fptr == NULL)
	{
		printf("Nije bilo moguce otvoriti file za citanje\n");
		return TASK_FAILED;
	}

	while (!feof(fptr))
	{
		fgets(buffer, MAX_LINE, fptr);
		count++;
	}

	fclose(fptr);

	return count;
}

int readingdata(student* studentptr, int rowsnumber)
{
	FILE* fptr = fopen("Student.txt", "r");

	for (int i = 0; i < rowsnumber; i++)
	{
		fscanf(fptr, "%s %s %d", studentptr[i].name, studentptr[i].surname, &studentptr[i].mark);
	}

	fclose(fptr);

	return 0;
}

int displaystudents(student* studentptr, int rowsnumber)
{
	FILE* fptr = fopen("Student.txt", "r");

	printf("IME\tPREZIME\tOCJENA\tAPSOLUTNI BODOVI\n");

	for (int i = 0; i < rowsnumber; i++)
	{
		printf("%s\t%s\t%d\t%.2f\n", studentptr[i].name, studentptr[i].surname, studentptr[i].mark, (float)studentptr[i].mark / 50 * 100);
	}

	fclose(fptr);

	return 0;
}