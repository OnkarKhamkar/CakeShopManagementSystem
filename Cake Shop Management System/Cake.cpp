#include"Cake.h"

Cake::Cake()
{
	this->cake_id=0;
	strcpy(name," ");
	this->price=0;
	this->qty=0;
}
///////////////////////////////////
Cake::Cake(int cid, char* nm, float p, int q)
{
	this->cake_id=cid;
	strcpy(this->name,nm);
	this->price=p;
	this->qty=q;
}
///////////////////////////////////
void Cake::display()
{
	cout<<"\t\t"<<cake_id<<"\t\t  "<<name<<"\t\t  "<<price<<"\t\t   "<<qty<<"\n";
}
///////////////////////////////////
int Cake::getCakeid()
{
	return cake_id;
}
///////////////////////////////////
char* Cake::getName()
{
	return name;
}
///////////////////////////////////
float Cake::getPrice()
{
	return price;
}
///////////////////////////////////
int Cake::getQty()
{
	return qty;
}
///////////////////////////////////
void Cake::setCakeid(int cid)
{
	cake_id=cid;
}
///////////////////////////////////
void Cake::setName(char* nm)
{
	strcpy(name,nm);
}
///////////////////////////////////
void Cake::setPrice(float p)
{
	price=p;
}
///////////////////////////////////
void Cake::setQty(int q)
{
	qty=q;
}
///////////////////////////////////


