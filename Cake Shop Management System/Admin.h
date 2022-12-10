#include"Cake.h"
#include<fstream>

class Admin
{
	int count;
	public:
		Admin();
		void AddCake(Cake&);
		void DisplayCake();
		void SearchCake(int);
		void UpdateCake(int);
		void DeleteCake(int);
};
