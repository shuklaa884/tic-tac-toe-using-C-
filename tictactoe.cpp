#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

//declaring the matrix  which will be storing the player moves
char mat[3][3];
/*the array will store the numerical data and will be used in 
computation of winner or looser*/
int move[9]={0,0,0,0,0,0,0,0,0};
//calling the main function to restart the game again.
int main();
//initialising the matrix mat
void initialise()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j]='|';
}
//checking winner move
int horizontal()
{
	for(int i=0;i<3;i++)
	{
		if(mat[i][0]==mat[i][1]&& mat[i][1]==mat[i][2])
		return 1;
	}
	return 0;
}
int vertical()
{
	for(int j=0;j<3;j++)
	{
		if(mat[0][j]==mat[1][j]&& mat[1][j]==mat[2][j])
		return 1;
	}
	return 0;
}
int diagonal()
{
	if(mat[0][0]==mat[1][1]&& mat[1][1]==mat[2][2])
	return 1;


	if(mat[0][2]==mat[1][1]&& mat[1][1]==mat[2][0])
	return 1;

	
	return 0;
}
//function to check whether the player has won or not
void ifwin()
{
	int n;
	if(horizontal()==1||vertical()==1||diagonal()==1)
	{
		printf("\n********WINNER FOUND*********");
		printf("\n\n\n\t\t\t GAmeOvEr");
		
		printf("\n\t\tpress 1 to RESTART  game and 0 to EXIT:\t");
		scanf("%d",&n);
		if(n==0)
		exit(0);
		else
		main();
		
	return;
	}
}

int check(int m)
{
	for(int i=0;i<9;i++)
	if(move[i]==m)
	return 0;

return 1;	
}
//displaying the update
void display()
{

	for(int i=0;i<3;i++)
	{
		printf("\n\t\t\t");
		for(int j=0;j<3;j++)
		{
			printf("%c\t",mat[i][j]);
		}
		printf("\n");
	}
}

main()
{
	//visula effects and colouring
	system("cls");
	printf("\n\n");
	for(int h=0;h<80;h++)
	printf("\xdb");
	printf("\n\n");
	printf("\t\t\t-------TiC TaC ToE-------\n\n\n");
	system("color 8");
	int choice=0;
	char player;
	initialise();//calling method
	display();//method calling
// user Input

for(int i=1;i<=9;i++)
{
	
	printf("\n This game requires the players to input the block no. from  1  to  9\n");
	if(i%2==0)
	{	
		printf("\n Player 2:\n");
		player='O';	
	}
	else
	{
		printf("\n Player 1:\n");
		player='X';
	}
	

	scanf("%d",&choice);
	if(check(choice)){

	switch(choice)
	{
		case 1: system("cls");mat[0][0]=player;move[0]=1;display();
		break;
		case 2:	system("cls");mat[0][1]=player;move[1]=2;display();
		break;
		case 3:system("cls");mat[0][2]=player;move[2]=3;display();
		break;
		case 4:system("cls");mat[1][0]=player;move[3]=4;display();
		break;
		case 5: system("cls");mat[1][1]=player;move[4]=5;display();
		break;
		case 6: system("cls");mat[1][2]=player;move[5]=6;display();
		break;
		case 7: system("cls");mat[2][0]=player;move[6]=7;display();
		break;
		case 8: system("cls");mat[2][1]=player;move[7]=8;display();
		break;
		case 9: system("cls");mat[2][2]=player;move[8]=9;display();
		break;
		default: printf("\n\tIn appropriate move try again: ");i--;
	
	}
	
		if(i>4)
		{
			ifwin();
		
		}
	}
	else
	{
		printf("\n\t\t\tInvalid move");i--;
	}

}
}