#include"Cake.h"
#include<fstream>
class User
{
	int cnt;
	public:
		User();
		void ViewAllCake();
		void SearchCakeByName(char*);
		void AddToCart();
		void ShowCart();
		void DeleteFromCart();
		void BuyCake();
};
