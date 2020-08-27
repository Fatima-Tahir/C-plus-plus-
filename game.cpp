# include <iostream>
# include <conio.h>
# include <ctime>
# include <cstdlib>
# include <stdio.h>
using namespace std;
#define UP 80
#define LEFT 77
#define RIGHT 75
#define DOWN 72
const int rows=3;
const int cols=3;
void display(int * a[])
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void slideTile(int * board[],int move)
{
	int emptyRow;
	int emptyCol;
	bool legalMoves[4] = {1,1,1,1}; //All set to true
	for(int r = 0; r <rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(board[r][c] == 0) //Find location of empty space
			{
				emptyRow = r;
				emptyCol = c;
			}
		}
	}
	
	if(emptyRow + 1 >= rows) //Can i move up?
		legalMoves[2] = false; //If no, set move flag to false
	else if(emptyRow - 1 < 0) //Move down?
		legalMoves[3] = false;
	if(emptyCol - 1 < 0) //Move right?
		legalMoves[1] = false;
	else if(emptyCol + 1 >= cols) //Move left?
		legalMoves[0] = false;

	 //Replace zero space with space to the left right up or down.
	
	if(move==0)
	{
	
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow][emptyCol + 1];
			board[emptyRow][emptyCol + 1] = 0;
			emptyCol = emptyCol+1;
		}
	}
	else if(move==1)
	{
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow][emptyCol - 1];
			board[emptyRow][emptyCol- 1] = 0;
			emptyCol = emptyCol-1;
		}
	}
	else if(move==2)
	{
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow+1][emptyCol];
			board[emptyRow+1][emptyCol] = 0;
			emptyRow = emptyRow+1;
		}
	}
	else if(move==3)
	{
	
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow-1][emptyCol];
			board[emptyRow-1][emptyCol] = 0;
			emptyRow = emptyRow-1;
		}
	}
}
void challegeState(int * board[],int row,int col)
{
	for(int i=1;i<100;i++)
	{
		int x=rand()%4;
		slideTile(board,x);
	}
	display(board);
}
bool solvedBoard(int * solveBoard[],int * board[])
{
	bool flag=true;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(solveBoard[i][j]!=board[i][j])
			{
				flag=false;
				return flag;
			}
			else 
				flag=true;
		}
	}
	return flag;
}
int main()
{
	char input;
	bool invalid = false;
	int sec=time(NULL);
	srand(sec);
	int row,col,k=1;
	int * board[3];
	int * solveBoard[3];
	for(int i=0;i<rows;i++)
	{
		solveBoard[i]=new int [cols];
		board[i]=new int[cols];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			solveBoard[i][j]=0;
			board[i][j]=0;
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(k<rows*cols)
			{
			board[i][j]=k;
			solveBoard[i][j]=k;
			}
			else 
			{
				solveBoard[i][j]=0;
				board[i][j]=0;
				row=i;
				col=j;
			}
		k++;
		}
	}
	display(board); 
	char ch;
	cout<<"Press Y to play and And E to Exit";
	cin>>ch;
	while(cin.fail() ||  ch !='Y' &&  ch!='E')
	{
		cout<<"Wrong Input.Enter Again";
		cin>>ch;
		if(ch=='Y' ||  ch=='E')
			break;
	}
	if(ch=='Y')
	{
		challegeState(board,row,col);
		while(!solvedBoard(solveBoard,board))
		{
			input = getch();
			system("CLS");
			if(input== UP)
				slideTile(board,2);
			else if(input ==LEFT)
				slideTile(board,0);  
			else if(input==DOWN)
				slideTile(board,3);
			else if(input==RIGHT)
				slideTile(board,1);
			else
				invalid = true;
			if(invalid)
				invalid = false;
		   display(board);
		}
		cout<<"Hurrahhhhh !!!! .. Finally You Won"<<endl;
	}	
	else if(ch=='E') 
	{
		while(true)
		{
			cout<<"Okay !! You Exit "<<endl;
			break;
		}
	}
delete []board;
return 0;
}