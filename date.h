#pragma once
struct Date
{
	int year;
	int month;
	int day;
	Date(int day, int month, int year) : year(year), month(month), day(day) {}
};