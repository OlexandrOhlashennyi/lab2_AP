#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* getDate(char[], int);					//прототип ф-ії отримання дати за номером дня
char* concat(char[], int, const char*);		//прототип ф-ії об'єднання рядків

int main() {
	system("chcp 1251"); system("cls");
	int n;
	char s[13];
	do {
		printf("Введіть номер дня року(нуль -- кінець): ");
		scanf("%d", &n);
		puts(getDate(s, n));
		getchar();
	} while (n != 0);
	return 0;
}

char* getDate(char s[], int n) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		//кількості днів у місяцях
	const char* montharr[] = { "січня", "лютого", "березня", "квітня", "травня", "червня", "липня", "серпня", "вересня", "жовтня", "листопада", "грудня" }; //назви місяців
	if (n < 1 || n > 365) { //перевірка правильності введення
		strcpy(s, "");
		return s;
	}
	int month = 0, days = 0, i = 0;
	while (days + daysInMonth[i] < n) {
		days += daysInMonth[i++];
		month++;
	}
	days = n - days;
	concat(s, days, montharr[month]); //об'єднання назви місяця і дня
	return s;
}

char* concat(char s[], int a, const char *month) {
	_itoa(a, s, 10);
	strcat(s, " ");
	strcat(s, month);
	return s;
}