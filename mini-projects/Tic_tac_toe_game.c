/* TIC TAC TOE GAME */
#include<stdio.h>
#include<conio.h>	// use for getch()
#include<stdlib.h>

char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwinner();		//this function will check if there is winner
void drawboard();		// this function will draw the structure of the game

int main()
{
	int player = 1, i, choice;
	char mark;	//it will mark 'X' & 'O'
	do{
		drawboard();
		player = (player % 2) ? 1 : 2;	//if player is divisible by 2, its will return 1 or else 2
		
		
		printf("Player %d, pls enter ur choice : ", player);
		scanf("%d", &choice);
		
		mark = (player == 1) ? 'X' : 'O';		//if its player 1 then it will mark 'X'
		
		if(choice == 1 && square[1] == '1')	//it means player chose 1, check if its position is empty
			square[1] = mark;
		else if(choice == 2 && square[2] == '2')
			square[2] = mark;
		else if(choice == 3 && square[3] == '3')
			square[3] = mark;
		else if(choice == 4 && square[4] == '4')
			square[4] = mark;
		else if(choice == 5 && square[5] == '5')
			square[5] = mark;
		else if(choice == 6 && square[6] == '6')
			square[6] = mark;
		else if(choice == 7 && square[7] == '7')
			square[7] = mark;
		else if(choice == 8 && square[8] == '8')
			square[8] = mark;
		else if(choice == 9 && square[9] == '9')
			square[9] = mark;
		else{
			printf("INVALID OPTION!!!!\n");
			player--;
			getch();
		}
		i = checkwinner();		//1 = winner, -1 = still in progress, 0 = draw/tie
		player++;
	}while(i == -1);
	
	drawboard();
	if(i == 1)
		printf("--> Player %d won the game\n", --player); // since we incremented player, so we have to decrease it now
	else
		printf("--> Game is draw\n");

	getch();
	return 0;
}

int checkwinner()
{
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	
	//it means that if the game is tie, the position will be either mark as 'X' or 'O' instead of "1", "2", "3", "4",... till "9".
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

void drawboard()
{
	system("Color 4F");
	printf("\n\n	Tic Tac Toe Game \n\n");
	printf("   Player 1 - (X) \t Player 2 - (O)\n\n\n");
	printf("      |      |      \n");
	printf("  %c   |  %c   |  %c   \n", square[1], square[2], square[3]);
	printf("______|______|______\n");
	printf("      |      |      \n");
	printf("  %c   |  %c   |  %c   \n", square[4], square[5], square[6]);
	printf("______|______|______\n");
	printf("      |      |      \n");
	printf("  %c   |  %c   |  %c   \n", square[7], square[8], square[9]);
	printf("______|______|______\n");
	printf("      |      |      \n\n\n");
}

