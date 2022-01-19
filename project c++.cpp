#include <iostream>
using namespace std;

void printIntroMenu();
void printMainMenu(int k);
void start();
void login();
void createAccount();
int exit();

struct BankAcc
{
	int idd;
	int pass;
	double money;
	
};
BankAcc save[3];

char menuInput,l,c,q,d,w,r,mainInput;


int main()
{
	cout<<"\t\tHi! Welcome to Harimau ATM Machine!\n";
	start();
	
	return 0;
}

void printIntroMenu()
{
	cout<<"\nl -> Login\nc -> Create New Account\nq -> Quit";
	cout<<endl<<endl<<"> ";
	cin>>menuInput;
	
	switch(menuInput)
	{
		case 'l' : login();
		case 'c' : createAccount();				
		case 'q' : exit(0);
				 	 
	}
}

void printMainMenu(int k)
{
	
	double take,deposit;
	char input;
	cout<<endl<<"\n\nd -> Deposit Money\nw -> Withdraw Money"
        <<"\nr -> Request Balance\nq -> Quit\n\n> ";
        
    cin>>input;
	
    switch(input)
    {
	
	case 'd' :
		 	cout<<"\nAmount of deposit : RM";
			cin>>deposit;
			save[k].money = save[k].money + deposit;
			printMainMenu(k);
			break;
		  
   	case 'w' :
     		cout<<"\nAmount of withdrawal: RM";
     		cin>>take;
     		save[k].money = save[k].money - take;
     		printMainMenu(k);
     		break;
		 
    case 'r' :	
     		cout<<"\nYour balance is RM"<<save[k].money;
     		printMainMenu(k);
     		break;
		 
	case 'q' :
			cout<<"\n\t\tThanks for stopping by!";
		 	exit(0);
		 	break;
	}
 }
	 

void start()
{
	cout<<"\t    Please select an option from the menu below:\n\n";
	printIntroMenu();
}

void createAccount()
{	
	for(int i=0;i<3;i++)
	{
		if(save[i].idd==0 && save[i].pass == 0)
		{
			cout<<endl<<endl<<"Please enter your user id: ";
			cin>>save[i].idd;
			cout<<"\nPlease enter your password: ";
			cin>>save[i].pass;
			
			cout<<endl<<"Thank You! Your account has been created!\n\n";
			printIntroMenu();
		}
	}
}

void login()
{
	int id, password;
	
	cout<<endl<<endl<<"Please enter your user id: ";
	cin>>id;
	cout<<"\nPlease enter your password: ";
	cin>>password;
	
	for(int i=0;i<3;i++)
	{
		if(save[i].idd == id && save[i].pass == password)
		{
			cout<<"\nAccess Granted!";
			printMainMenu(i);
		}
	}
	for(int i=0;i<3;i++)
	{
		if(save[i].idd != id && save[i].pass != password)
		{
			cout<<"\n**** LOGIN FAILED! ****\n\n";
			start();
		}
	}
}
