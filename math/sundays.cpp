#include <iostream>
using namespace std;

const unsigned int Sunday = 1;

unsigned int getWeekday(unsigned long long year, unsigned int month, unsigned int day)
{

	if (month <= 2)
	{
		month += 12;
		year--;
	}

	return (day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

int main()
{
	int y1 = 1901, m1 = 1, d1 = 1;

	int y2 = 2000, m2 = 12, d2 = 31;

	if (y2 < y1 || (y2 == y1 && m2 < m1))
	{
		swap(y1,  y2);
		swap(m1, m2);
	}

	unsigned long long currentYear  = y1;
	unsigned int       currentMonth = m1;
	if (d1 > 1)
	{
		currentMonth++;

		if (currentMonth > 12)
		{
			currentMonth -= 12;
			currentYear++;
		}
	}

	unsigned int sum = 0;

	while (currentYear + 2800 < y2)
	{
		currentYear += 2800;
		sum += 4816;
	}

	while (currentMonth < m2 || currentYear < y2)
	{
		if (getWeekday(currentYear, currentMonth, 1) == Sunday)
			sum++;

		currentMonth++;

		if (currentMonth > 12)
		{
			currentMonth -= 12;
			currentYear++;
		}
	}
	if (getWeekday(currentYear, currentMonth, 1) == Sunday) {
		sum++;
	}

	cout << sum << endl;

	return 0;
}