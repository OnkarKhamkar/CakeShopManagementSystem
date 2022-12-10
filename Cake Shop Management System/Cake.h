#pragma once
#include<iostream>
#include<cstring>
#include<windows.h>
#include<iomanip>
using namespace std;

class Cake
{
	int cake_id;
	char name[30];
	float price;
	int qty;
	public:
		Cake();
		Cake(int, char*, float, int);
		void display();
		int getCakeid();
		char* getName();
		float getPrice();
		int getQty();
		void setCakeid(int);
		void setName(char*);
		void setPrice(float);
		void setQty(int);
		
};
