#include"Admin.h"
Admin::Admin()
{
	int count=0;
	ifstream file("count.txt");
	if(!file)
	{
		ofstream rCount("count.txt");
		rCount<<count;
		rCount.close();
	}
	else
	{
		file>>count;
		file.close();		
	}
}
/////////////////////////////////////////////////////////
void Admin::AddCake(Cake &c)
{
	ifstream file("count.txt");
	int count;
	file>>count;
	file.close();
	
	count++;
	ofstream file1("count.txt");
	file1<<count;
	file1.close();
	
	ofstream file2("cakeData.dat",ios_base::binary|ios_base::app);
	file2.write((char *)&c,sizeof(c));
	file2.close();
}
/////////////////////////////////////////////////////////
void Admin::DisplayCake()
{
	ifstream file("cakeData.dat",ios_base::binary);
	if(!file)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		Cake c;
		file.read((char *)&c,sizeof(c));
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		do
		{	
			c.display();
			file.read((char *)&c,sizeof(c));			
		}
		while(!file.eof());
		file.close();
	}
}
/////////////////////////////////////////////////////////
void Admin::SearchCake(int cid)
{
	ifstream file("cakeData.dat",ios_base::binary);
	if(!file)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		bool found = false;
		Cake c;
		file.read((char *)&c,sizeof(c));
		
		do
		{	
			if(c.getCakeid()==cid)
			{
				found = true;
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				c.display();
				break;
			}
			file.read((char *)&c,sizeof(c));				
		}
		while(!file.eof());
		file.close();
		
		if(!found)
		{
			cout<<"\n\t\tRecord not found";
		}
	}
}
/////////////////////////////////////////////////////////
void Admin::UpdateCake(int cid)
{
	ifstream file1("count.txt");
	int count;
	file1>>count;
	file1.close();
	
	Cake *p = new Cake[count];
	ifstream file("cakeData.dat",ios_base::binary);
	if(!file)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		bool found = false;
		Cake c;
		int i=0;
		file.read((char *)&c,sizeof(c));
		do
		{				
			
			if(c.getCakeid()==cid)
			{
				found = true;
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				c.display();
				char ans;
				cout<<"\n\t\tDo you wish to change name of cake(y/n)? ";
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new name: ";
					char name[20];
					cin>>name;
					c.setName(name);
				}
				cout<<"\n\t\tDo you wish to change price of cake(y/n)? ";
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new price: ";
					float p;
					cin>>p;
					c.setPrice(p);
				}
				cout<<"\n\t\tDo you wish to change quantity of cakes(y/n)? ";
				cin>>ans;
				if(ans == 'y' || ans == 'Y')
				{
					cout<<"\n\t\tEnter new Quantity: ";
					int q;
					cin>>q;
					c.setQty(q);
				}				
			}
			p[i] = c;
			i++;
			file.read((char *)&c,sizeof(c));			
			
		}while(!file.eof());
		file.close();
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\n\t\tData updated\n";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		for(int i=0;i<count;i++)
		{
			p[i].display();
		}
		
		if(!found)
		{
			cout<<"\n\t\tRecord not found";
			return;
		}
		else
		{
			ofstream file2("cakeData.dat",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				file2.write((char *)&p[i],sizeof(p[i]));
			}
			file2.close();
		}
	}
}
/////////////////////////////////////////////////////////
void Admin::DeleteCake(int cid)
{
	ifstream file1("count.txt");
	int count;
	file1>>count;
	file1.close();
	
	ifstream file2("cakeData.dat",ios_base::binary);
	ofstream file3("temp.dat",ios_base::binary);
	if(!file2)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		Cake c;
		file2.read((char *)&c,sizeof(c));
		while(!file2.eof())
		{
			if(c.getCakeid()!=cid)
			{
				file3.write((char *)&c,sizeof(c));
			}
			if(c.getCakeid()==cid)
			{
				cout<<"\n\t\tCake details of id "<<cid<<" successfully deleted";
			}
			file2.read((char *)&c,sizeof(c));
		}
	}
	file2.close();
	file3.close();
	remove("cakeData.dat");
	rename("temp.dat","cakeData.dat");	
}
/////////////////////////////////////////////////////////
