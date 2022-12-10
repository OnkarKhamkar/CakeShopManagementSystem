#include "Admin.h"
#include "User.h"
#include<cstring>
#include<conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int choice=0;
	Admin ad;
	User U;
	cout<<"\n\n";
	cout<<"\n\t\t---------------------------";
	cout<<"\n\t\t";
	cout<<"\n\t\tCAKE SHOP MANAGEMENT SYSTEM\n ";
	cout<<"\n\t\t---------------------------";
	cout<<"\n\t\tPress any key to continue.....";
	getch();
	string username="";
	string pswd="";
	bool login=false;
	system("cls");
	while(choice!=3)
  	{
	    system("cls");
	    cout<<"\n\t\t-----------------";
	    cout<<"\n\t\t1.Admin\n";
	    cout<<"\n\t\t2.User\n";
	    cout<<"\n\t\t3.Exit\n";
	    cout<<"\n\t\t-----------------";
	    cout<<"\n\t\tEnter your choice: ";
	    cin>>choice;
		switch(choice)
    	{
      		case 1:
      			{
			        do
			        {
					    cout<<"\n\t\tEnter Username: ";
					    cin>>username;
					    cout<<"\n\t\tEnter Password: ";
					    cin>>pswd;
				        if(username=="Admin" && pswd=="admin@123")
			          	{
			          		login=true;
			            	cout<<"\n\t\t-----------------Successfully Login----------------\n\n ";
							cout<<"\n\t\tPress any key to continue....."; 
			            	getch();    
			            	int ch=0;
			            	while(ch!=6)
			            	{
			              		system("cls");
			              		cout<<"\n\t\t1.Add new cake";
			              		cout<<"\n\t\t2.Display cake";
			              		cout<<"\n\t\t3.Search cake";
			              		cout<<"\n\t\t4.Modify cake";
			              		cout<<"\n\t\t5.Delete cake";
			              		cout<<"\n\t\t6.Back to main menu.";
			              		cout<<"\n\t\t-------------------";
			              		cout<<"\n\t\tEnter your choice: ";
			              		cin>>ch;
			              		switch(ch)
			              		{
			                		case 1:
			                  			{		
											int cake_id;
											char name[20];
											float price;
											int qty;
											cout<<"\n\t\tEnter the cake id: ";
											cin>>cake_id;
											cout<<"\n\t\tEnter the name of cake: ";
											cin>>name;
											cout<<"\n\t\tEnter price of cake: ";
											cin>>price;
											cout<<"\n\t\tEnter the quantity: ";
											cin>>qty;
											Cake c1(cake_id,name,price,qty);
											ad.AddCake(c1);
											cout<<"\n\t\tCake added successfully.....";
											cout<<"\n\t\tPress any key to continue.....";
						                    getch();
			                  			}  
			                  			break;
			                  		case 2:
					                  	{
						                    ad.DisplayCake();
						                    cout<<"\n\t\tPress any key to continue.....";
						                    getch();
					                  	}
					                  	break;
					                case 3:
			                  			{
			                    			cout<<"\n\t\tEnter Cake id: ";
			                    			int cid;
			                    			cin>>cid;
			                    			ad.SearchCake(cid);
			                    			cout<<"\n\t\tPress any key to continue.....";
			                    			getch();
			                  			}
			                  			break;
			                		case 4:
			                  			{
						                    cout<<"\n\t\tEnter cake id to be modify: ";
						                    int cid;
						                    cin>>cid;
						                    ad.UpdateCake(cid);
						                    cout<<"\n\t\tPress any key to continue.....";
						                    getch();
			                  			}
			                  			break;
			                		case 5:
			                  			{
						                    cout<<"\n\t\tEnter cake id to be delete: ";
						                    int cid;
						                    cin>>cid;
						                    ad.DeleteCake(cid);
						                    cout<<"\n\t\tPress any key to continue.....";
						                    getch();
			                  			}
			                  			break;
			                  		case 6:
			            				break;
			                		default:
			                  			cout<<"\n\tInvalid choice!!!";  
			              		}
			            	}
			          	}
			          	else
			          	{
							cout<<"\n\tYou have entered wrong username or password.\n";
			            	cout<<"\n\tPlease try again login\n\n";
			            	getch();
			          	}
			        }while(!login);
				}
      			break;
			case 2:
        		{
          			int ch1=0;
          			while(ch1!=7)
          			{
			            system("cls");
			            cout<<"\n\t\t------------------------";
			            cout<<"\n\t\t1.View all cake";
			            cout<<"\n\t\t2.Search cake by  Name";
			            cout<<"\n\t\t3.Add to cart";
			            cout<<"\n\t\t4.Show cart";
			            cout<<"\n\t\t5.Delete from cart";
			            cout<<"\n\t\t6.Buy Cake";
			            cout<<"\n\t\t7.Back to main menu.";
			            cout<<"\n\t\t------------------------";
			            cout<<"\n\t\tEnter your choice :";
			            cin>>ch1;
            			switch(ch1)
            			{
              				case 1:
                				{
			                 		U.ViewAllCake();
			                 		cout<<"\n\t\tPress any key to continue.....";
			                  		getch();
                				}
                				break;
              				case 2:
                				{
                  					char name[20];
									cout<<"\n\t\tEnter the name of cake: ";
                  					cin>>name;
                  					U.SearchCakeByName(name);
                  					cout<<"\n\t\tPress any key to continue.....";
                  					getch();
                				}
                				break;
              				case 3:
                				U.AddToCart();
                				cout<<"\n\t\tPress any key to continue.....";
                				getch();
                				break;
              				case 4:
                				U.ShowCart();
                				cout<<"\n\t\tPress any key to continue.....";
                				getch();
               					break;
              				case 5:
               		 			U.DeleteFromCart();
               		 			cout<<"\n\t\tPress any key to continue.....";
                				getch();
                				break;
              				case 6:
                				U.BuyCake();
                				cout<<"\n\t\tPress any key to continue.....";
                				getch();
                				break;
              				case 7:
                				break;
              				default:
                				cout<<"\n\tInvalid Choice !!!";
                				break;
            			}
          			}
        		}
        		break;
      		case 3:
        		break;
      		case 10:
        		break;  
      		default:
        		cout<<"\n\tInvalid choice!!!";
       	 		break;    
    	}
  	}
	return 0;
}
