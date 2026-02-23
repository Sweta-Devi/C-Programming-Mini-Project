/* Bank Management Mini Project */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char name[50];
int amt, acc_no;

void divider()
{
	int i; 
	for(i = 0; i < 30; i++)
		printf("-");
}

void menu()
{
	divider();
	printf("\n\tMENU\n");
	printf("1. Deposit Money\n2. Withdraw Money\n3. Transfer Money\n4. Account details\n5. Transaction details\n6. Exit\n\n");
}

void deposit_money()
{
	time_t tm;
	time(&tm);
	FILE *fp = fopen("Account.txt", "a");	//since the amount is being deposited, meaning added to the current amount
	
	int dep_am;
	printf("\nDEPOSITING MONEY!!!!\n");
	printf("Enter the amount to be deposit : ");
	scanf("%d", &dep_am);
	
	amt += dep_am;
	printf("AMOUNT SUCCESSFULLY DEPOSITED!!!\n");
	printf("Current amount : %d\n", amt);
	
	fprintf(fp, "Rs.%d has been deposited to your account.\n", dep_am);	//use for displaying the amount using file handling
	fprintf(fp, "Date / Time of the transaction : %s\n", ctime(&tm));
	
	getch();		//it pauses the program until an input has been received
}

void withdraw_money()
{
	int with_am;
	
	time_t tm;
	time(&tm);
	FILE *fp = fopen("Account.txt", "a");
	
	printf("\tWITHDRAW MONEY \n");
	printf("Enter the amount : ");
	scanf("%d", &with_am);
	
	amt -= with_am;
	
	printf("AMOUNT SUCCESSFULLY WITHDRAW!!!\n\n");
	printf("Current amount : %d\n", amt);
	
	fprintf(fp, "Rs.%d has been withdraw from your account.\n", with_am);	//use for displaying the amount using file handling
	fprintf(fp, "Date / Time of the transaction : %s\n", ctime(&tm));
	getch();		//it pauses the program until an input has been received
}

void transfer_money()
{
	int transfer_am, transfer_no;
	
	time_t tm;
	time(&tm);
	FILE *fp = fopen("Account.txt", "a");
	
	printf("\tTRANSFERING MONEY\n");
	printf("Enter the amount : ");
	scanf("%d", &transfer_am);
	printf("Enter the account no. in which u want to transfer money : ");
	scanf("%d", &transfer_no);
	
	if( amt < transfer_am)
		printf("You don't have sufficient amount.\n");
	else
	{
		amt -= transfer_am;
		printf("\nMONEY SUCCESSFULLY TRANSFERED\n");
		printf("Current Balance : %d\n", amt);
		
		fprintf(fp, "Rs.%d has been transfered from your account to %d account.\n", transfer_am, transfer_no);	
		//use for displaying the amount using file handling	
	}
	fclose(fp);
	getch();		//it pauses the program until an input has been received
}

void account_details()
{
	printf("\n\tACCOUNT DETAILS\n");
	divider();
	printf("\nAccount Holder Name : %s", name);
	printf("\nAccount Number : %d\n", acc_no);
	printf("Current Balance : %d\n", amt);
	
	getch();		//it pauses the program until an input has been received
}

void transaction_details()
{
	FILE *fp = fopen("Account.txt", "r");
	
	char c = fgetc(fp);
	if(c == EOF)
		printf("\nNo Recent Transaction!!!\n");
	else
	{
		printf("\n\tTRANSACTION DETAILS :-\n");
		while( c != EOF)
		{
			printf("%c", c);
			c = fgetc(fp);
		}
	}
	getch();
}


int main()
{
	int choice;
	char ch;
	
	printf("\tEnter details:-\n");
	printf("Enter your name : ");
	scanf(" %[^\n]", &name);		//or use gets(name)
	
	printf("Enter your account number : ");
	scanf("%d", &acc_no);
	
	printf("Enter the amount : ");
	scanf("%d", &amt);
	do
	{
		menu();
		printf("Enter your choice : ");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1 :  printf("\n");
					deposit_money();
					break;
			case 2 :  printf("\n");
					withdraw_money();
					break;
			case 3 :  printf("\n");
					transfer_money();
					break;
			case 4 :  printf("\n");
					account_details();
					break;
			case 5 :  printf("\n");
					transaction_details();
					break; 
			case 6 : exit(1);
			default: break;
		}
		printf("\nDo you wanna continue? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	
	return 0;
}
