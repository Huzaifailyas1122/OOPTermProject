#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h> 

using namespace std;

class date {
private:
	int day, month, year;
public:
	date();
	date(int, int, int);
	void Setday(int);
	void Setmonth(int);
	void Setyear(int);
	int Getday();
	int Getmonth();
	int Getyear();
	void display();
};

date::date() :day(0), month(0), year(0)
{}

date::date(int D, int M, int Y) : day(D), month(M), year(Y)
{}

void date::Setday(int Day)
{
	this->day = Day;
}

void date::Setmonth(int Month)
{
	this->month = Month;
}

void date::Setyear(int Year)
{
	this->year = Year;
}

int date::Getday()
{
	return day;
}
int date::Getmonth()
{
	return month;
}
int date::Getyear()
{
	return year;
}

void date::display()
{
	cout << day << "/" << month << "/" << year << endl;
}