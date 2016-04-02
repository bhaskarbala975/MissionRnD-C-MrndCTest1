/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head)
{
	int count = 0,date1=0,month1=0,year1=0,date2=0,month2=0,year2=0,res,temp=0,res2;
	struct node* t1;
	t1 = date1head;
	while (count < 2)
	{
		date1 = date1 * 10 + (t1->data);
		count++;
		t1 = t1->next;
	}
	while (count<4)
	{ 
		month1 = month1 * 10 + (t1->data);
		t1 = t1->next;
		count++;
	}
	while (count < 8)
	{
		year1 = year1 * 10 + (t1->data);
		count++;
		t1 = t1->next;
	}
	t1 = date2head;
	while (count < 2)
	{
		date2 = date2 * 10 + (t1->data);
		count++;
		t1 = t1->next;
	}
	while (count<4)
	{
		month2 = month2 * 10 + (t1->data);
		t1 = t1->next;
		count++;
	}
	while (count < 8)
	{
		year2 = year2 * 10 + (t1->data);
		count++;
		t1 = t1->next;
	}
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (date1 == date2)
				return 0;
			else
			{
				res = date1 - date2;
				if (res > 0)
					return res;
				else
					return (res*-1);
			}
		}
	}
	else if (year1 != year2)
	{
		if (month1 == month2)
		{
			res = (year1 - year2);
				temp = res;
			while (temp < 4)
			{
				temp = temp - 4;
				count++;
			}
			res2 = (month1 - month2);
			if (res2 < 0)
				res2 = (res2 * 30 * -1);
			else
				res2 = res2 * 30;
			return (res * 365 + count+res2+(date1-date2));
		}
	}
	/**/
}