//we only know pseudo codes
//we have to figure out the c

#include<iostream>
#include <cstdlib>
#include<ctime>
#include<cstring>

using namespace std;

int random_no(int x);
int show_hang(int y);

int main()
{
	int select,l,i,j,k;
	static int flag=0;
	int life = 5;
	/*
	words =["APPLE","FIRE","HANGMAN","PIZZA","AWESOME","MAXIMOFF","UPPERCASE"]
	option=["A food or company","It burns","you are playing","we all want to eat","barney","quicksliver","lowercasee"]
	*/
	const char *options[]={"APPLE","FIRE","HANGMAN","PIZZA","AWESOME","MAXIMOFF","UPPERCASE"};
	const char *hint[]={"A food or company","It burns","you are playing","we all want to eat","barney","quicksliver","lowercasee"};
	char guess;

	select = random_no(7);
	cout<<"HINT : "<<hint[select];
	l = strlen(options[select]);

	char answer[l];
	char output[l];

	strcpy(answer,options[select]);

	for(i=0;i<l;i++)
	{
		output[i] = '_' ;
		output[l] = '\0' ;
	}

	cout<<"\n\t****\tPLAY THE HANGMAN\t****\n";
	
	for(i = 0 ; i < l ; i++)
	{
			cout<<" ";
			cout<<output[i];
	}
	cout<<"\n";

	//main loop
	while(life>0)
	{
		flag= 0;
		cout<<"\nCHANCES LEFT: "<<life<<"\n";
	
		cout<<"\n";

		cout<<"GUESS A LETTER (a to z) = ";
		cin >> guess;
		cout<<"\n";

		for(j=0;j<l;j++)
		{	
			if(answer[j]==toupper(guess))
			{	
					output[j]=toupper(guess);
					flag= 1;
			}
		}
			if(flag==0)
			{
				life-=1;			
			}
		
		for(i = 0 ; i < l ; i++)
		{
			cout<<" ";
			cout<<output[i];
		}

		if(strcmp(output,answer)==0)
		{	
			cout<<"\n";
			cout<<"\n\t****\tCONGRATULATIONS YOU WON\t****\t\n";
			cout<<"\n\tYOU GUESSED :\t"<<answer;
			break;
		}
		cout<<"\n";
		show_hang(life);
		cout<<"\n";
	}//end while

	if(life==0 && strcmp(output,answer)!=0)
	{
		cout<<"\n\t****\tSORRY YOU LOST\t****\t\n";
		cout<<"\n\t****\tTRY AGAIN\t****\t\n";
	}

	cout<<"\n";
return (0);	
}

int show_hang(int y)
{
	switch(y)
	{
		case 0:
		{
			cout<<" ----- \n";
			cout<<"   |   \n";
			cout<<"   |   \n";
 			cout<<"  ___  \n";
			cout<<" |. .| \n";
			cout<<" |___| \n";
			cout<<"   |   \n";
			cout<<"  /|\\  \n";
     		cout<<" / | \\  \n";
			cout<<"   |     \n";
			cout<<"  / \\  \n";
			cout<<" /   \\  \n";
			break;
		}
		case 1:
		{
			cout<<" ----- \n";
			cout<<"   |   \n";
			cout<<"   |   \n";
			cout<<"  ___  \n";
			cout<<" |. .| \n";
			cout<<" |___| \n";
			cout<<"   |   \n";
			cout<<"  /|\\ \n";
     		cout<<" / | \\  \n";
			cout<<"   |     \n";
			cout<<"  /    \n";
			cout<<" /      \n";
			break;
		}
		case 2:
		{
			cout<<" ----- \n";
			cout<<"   |   \n";
			cout<<"   |   \n";
			cout<<"  ___  \n";
			cout<<" |. .| \n";
			cout<<" |___| \n";
			cout<<"   |   \n";
			cout<<"  /|\\  \n";
     		cout<<" / | \\ \n";
			cout<<"   |     \n";
			break;
		}
	case 3:
		{
			cout<<" ----- \n";
			cout<<"   |   \n";
			cout<<"   |   \n";
			cout<<"  ___   \n";
			cout<<" |. .| \n";
			cout<<" |___| \n";
			cout<<"   |   \n";
			cout<<"  /|   \n";
     		cout<<" / |   \n";
			cout<<"   |   \n";
			break;
		}
		case 4:
		{
			cout<<" ----- \n";
			cout<<"   |   \n";
			cout<<"   |   \n";
			cout<<"  ___  \n";
			cout<<" |. .| \n";
			cout<<" |___| \n";
			cout<<"   |   \n";
			cout<<"   |  \n";
			break;
		}
		case 5:
		{
			cout<<" ----- \n";
			cout<<"   |  \n";
			cout<<"   |  \n";
			break;
		}
		default:
			cout<<"\n";
			break;
	}
}


int random_no(int x)
{
	srand(time(NULL));
	return (rand() % x);
}
