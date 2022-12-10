#include"User.h"
User::User()
{
	cnt=0;
	ifstream fileCount("cnt.txt");
	if(!fileCount)
	{
		ofstream rCnt("cnt.txt");
		rCnt<<cnt;
		rCnt.close();
	}
	else
	{
		fileCount>>cnt;
		fileCount.close();		
	}
}
/////////////////////////////////////////////////////////////////
void User::ViewAllCake()
{
	ifstream file1("cakeData.dat",ios_base::binary);
	ofstream file2("user.dat",ios_base::binary);
	if(!file1)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		Cake c;
		file1.read((char *)&c,sizeof(c));
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		do
		{	
			file2.write((char *)&c,sizeof(c));
			c.display();
			file1.read((char *)&c,sizeof(c));			
		}
		while(!file1.eof());
		file1.close();
		file2.close();
	}
}
/////////////////////////////////////////////////////////////////
void User::SearchCakeByName(char* nm)
{
	ifstream file2("user.dat",ios_base::binary);
	if(!file2)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		bool found=false;
		Cake c;
		file2.read((char *)&c,sizeof(c));
		do
		{
			if(strcmp(c.getName(),nm)==0)
			{
				found = true;
				cout<<"\n\t\tRecord Found\n";
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
				cout<<"\n\t\t-----------------------------------------------------------------\n";
				c.display();
				break;
			}
			file2.read((char *)&c,sizeof(c));
		}
		while(!file2.eof());
		file2.close();
		if(!found)
		{
			cout<<"\n\t\tRecord not found";
		}
	}
}
/////////////////////////////////////////////////////////////////
void User::AddToCart()
{
	ifstream file2("user.dat",ios_base::in);
	if(!file2)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		bool found=false;
		Cake c;
		char ans;
		file2.read((char *)&c,sizeof(c));
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		do
		{	
			c.display();
			file2.read((char *)&c,sizeof(c));			
		}
		while(!file2.eof());
		file2.close();
		int cid,qty,y;
		do
		{
			ifstream file2("user.dat",ios_base::in);
			ofstream cart("cart.dat",ios_base::binary|ios_base::app);
			cout<<"\n\t\tEnter the cake ID you want to buy: ";
			cin>>cid;
			file2.read((char *)&c,sizeof(c));
			do
			{
				if(c.getCakeid()==cid)
				{
					found = true;
					cout<<"\n\t\tEnter the quantity you want to buy: ";
					cin>>qty;
					
					if(c.getQty()>=qty)
					{
						c.setQty(qty);
						cart.write((char *)&c,sizeof(c));
						cout<<"\n\t\tCake having Id as "<<cid<<" added to cart successfully";
						ofstream fileCount("cnt.txt");
						cnt++;
						fileCount<<cnt;
						fileCount.close();
					}
					else
					{
						cout<<"\n\t\tEntered quantity is greater than quantity available";
					}
				}
				file2.read((char *)&c,sizeof(c));
				
			}
			while(!file2.eof());
			file2.close();
			cart.close();
			cout<<"\n\t\tDo you want to add more cakes then press 1 if not press 0: ";
			cin>>y;
		}while(y==1);
		
		if(!found)
		{
			cout<<"\n\t\tRecord not found";
		}
	}
}
/////////////////////////////////////////////////////////////////
void User::ShowCart()
{
	ifstream cart("cart.dat",ios_base::binary|ios_base::in|ios_base::app);
	if(!cart)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		int cnt; 
	    ifstream cnt1("cnt.txt",ios_base::in); 
	    cnt1>>cnt; 
	    cnt1.close();
	    if(cnt==0)
	    {
	      cout<<"\n\t\tCart is empty, Nothing to show";
	      return;  
	    }
		Cake c;
		int sum=0,total=0;
		cart.read((char *)&c,sizeof(c));
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		do
		{
			c.display();
			sum = c.getPrice()*c.getQty();
			total= sum + total;
			cart.read((char *)&c,sizeof(c));
			
		}while(!cart.eof());
		cart.close();
		cout<<"\n\n";
		cout<<"\n\t\t------------------------------\n";
		cout<<"\n\t\tBill Amount: "<<total;
		cout<<"\n\t\t------------------------------\n";
		double gst= total * 0.18;
		cout<<"\n\t\t(18%) GST on amount:  "<<gst;  
	    double amt = total +gst; 
	    cout<<"\n\t\t-------------------------------\n"; 
	    cout<<"\n\t\tTotal Bill after adding GST: "<<amt; 
	    cout<<"\n\t\t-------------------------------\n";	
	}
}
/////////////////////////////////////////////////////////////////
void User::DeleteFromCart()
{
	ifstream cart("cart.dat",ios::binary|ios_base::in);
	if(!cart)
	{
		cout<<"\n\t\tFile doesnt exist";
		return;
	}
	else
	{
		int cnt; 
	    ifstream cnt1("cnt.txt",ios_base::in); 
	    cnt1>>cnt; 
	    cnt1.close();
	    if(cnt==0)
	    {
	      cout<<"\n\t\tCart is empty, Nothing to delete";
	      return;  
	    }
		Cake c;
		cart.read((char *)&c,sizeof(c));
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\n\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";
		do
		{
			c.display();
			cart.read((char *)&c,sizeof(c));
		}
		while(!cart.eof());
		cart.close();
		int id,qt;	
		bool found=false;
		ifstream cart("cart.dat",ios::binary|ios_base::in);
		ofstream cart2("cart2.dat",ios::binary|ios_base::out);
		cout<<"\n\t\tEnter the cake Id you want to delete: ";
		cin>>id;
		cart.read((char *)&c,sizeof(c));
		do
		{
			if(c.getCakeid()!=id)
			{
				cart2.write((char *)&c,sizeof(c));
			}
			if(c.getCakeid()==id)
			{
				found=true;
				cout<<"\n\t\tCake Id "<<id<<" is successfully deleted";
			}
			cart.read((char *)&c,sizeof(c));
		}
		while(!cart.eof());
		cart.close();
		cart2.close();
		if(!found)
		{
			cout<<"\n\t\tYou have entered wrong cake ID";
		}
		remove("cart.dat");
		rename("cart2.dat","cart.dat");
	}
}
/////////////////////////////////////////////////////////////////
void User::BuyCake()
{ 
	ifstream cart("cart.dat",ios_base::binary|ios_base::in); 
  	if(!cart) 
  	{ 
	    cout<<"\n\t\tfile doesnt exist"; 
	    return; 
	} 
	else 
	{ 
	    int cnt; 
	    ifstream cnt1("cnt.txt",ios_base::in); 
	    cnt1>>cnt; 
	    cnt1.close();
	    if(cnt==0)
	    {
	      cout<<"\n\t\tYou have not added cake to the cart,first add to cart then buy.";
	      return;  
	    }
	    int count; 
	    ifstream cnt2("count.txt",ios_base::in); 
	    cnt2>>count; 
	    cnt2.close(); 
	    Cake *c2 = new Cake [cnt];  
	    int j=0; 
	    bool found = false; 
	    Cake crt; 
	    double sum =0,total=0; 
	    cart.read((char*)&crt,sizeof(crt)); 
	    cout<<"\n\t\t-----------------------------------------------------------------\n";
		cout<<"\n\t\tCake Id\t\t Name of cake\t\t Price\t\t Quantity";
		cout<<"\n\t\t-----------------------------------------------------------------\n";

		do 
    	{ 
      		crt.display(); 
      		c2[j] = crt; 
      		j++; 
      		sum = crt.getPrice() * crt.getQty(); 
      		total = sum + total; 
      		cart.read((char*)&crt,sizeof(crt)); 
    	}while(!cart.eof()); 
    	cart.close();
        
    	cout<<"\n\n";
		cout<<"\n\t\t------------------------------\n";
		cout<<"\n\t\tBill Amount: "<<total;
		cout<<"\n\t\t------------------------------\n";
		double gst= total * 0.18;
		cout<<"\n\t\t(18%) GST on amount:  "<<gst; 
    	cout<<"\n\t\t---------------------------------\n"; 
    	double amt = total +gst; 
    	cout<<"\n\t\tTotal Bill after adding GST: "<<amt; 
    	cout<<"\n\t\t-------------------------------\n";

		ifstream f1("cakeData.dat",ios_base::binary|ios_base::in); 
    	char ans; 
    	cout<<"\n\t\tDo you wish to buy (y/n) = "; 
    	cin>>ans; 
    	if(ans=='y'|| ans=='Y') 
    	{ 
      		Cake *c1 = new Cake [count];  
      		int i=0,n=0;  
      		Cake Ucake; 
      		f1.read((char*)&Ucake,sizeof(Ucake));  
      		do 
      		{ 
        		ifstream cart("cart.dat",ios_base::in); 
        		Cake CtCake; 
        		cart.read((char*)&CtCake,sizeof(CtCake)); 
        		do 
        		{ 
          			if(Ucake.getCakeid()==CtCake.getCakeid()) 
          			{ 
            			Ucake.setQty(Ucake.getQty()-CtCake.getQty());  
          			}	 
          			cart.read((char*)&CtCake,sizeof(CtCake)); 
          
        		}while(!cart.eof()); 
        		cart.close(); 
        		c1[i]=Ucake; 
        		i++; 
        		f1.read((char*)&Ucake,sizeof(Ucake)); 
        	}while(!f1.eof()); 
        	f1.close();  
        	ofstream f3("cakeData.dat",ios_base::binary|ios_base::out);
         
        	for(int k=0;k<count;k++) 
        	{ 
          		f3.write((char*)&c1[k],sizeof(c1[k])); 
        	} 
        	f3.close(); 
        	cout<<"\n\t\tPurchased Sucessfull..\n";
        	cout<<"\n\t\tThank You!!!\n";  
    	} 
    	else 
    	{ 
      		cout<<"\n\t\tOrder cancelled!!!";
			return; 
    	}	 
    	remove("cart.dat"); 
    	remove("cnt.txt"); 
  	} 
}
/////////////////////////////////////////////////////////////////
