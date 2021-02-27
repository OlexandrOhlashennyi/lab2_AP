#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void getDate(char s[], int n) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char montharr[][10] = { "січня", "лютого", "березня", "квітня", "травня", "червня", "липня", "серпня", "вересня", "жовтня", "листопада", "грудня" };
	if (n < 1 || n > 365) {
		strcpy(s, "");
		return;
	}
	int month = 0, days = 0, i = 0;
	while (days + daysInMonth[i] < n) {
		days += daysInMonth[i++];
		month++;
	}
	days = n - days;
	_itoa(days, s, 10);
	strcat(s, " ");
	strcat(s, montharr[month]);
}

int main() {
	system("chcp 1251"); system("cls");
	int n;
	char s[12];
	do {
		printf("Введіть номер дня року(нуль -- кінець): ");
		scanf("%d", &n);
		getDate(s, n);
		puts(s);
		getchar();
	} while (n != 0);
	return 0;
}