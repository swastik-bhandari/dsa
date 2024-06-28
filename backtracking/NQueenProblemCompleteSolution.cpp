#include<iostream>
#include<vector>
using namespace std;
// function declarations 
void display(vector<vector<char>>&);
bool isSafe(vector<vector<char>>& , int ,int );

// fuction to print the possible solutions for nQueen problem
void nQueens(vector<vector<char>>&board, int row)
{
if(row==board.size())
{
display(board);
return;
}
for(int j=0 ; j<board.size() ; j++)
{
if (isSafe(board, j , row))
{
board[row][j]='Q';
nQueens(board,row+1);
board[row][j]='.';
}
}
return;
}

// displaying possible solutions 
void display(vector<vector<char>>&board)
{
for(int i=0 ; i<board.size() ; i++)
{
for(int j=0 ; j<board.size() ; j++)
{
cout<<board[i][j];
}
cout<<endl;
}
cout<<endl;
}

// checking threads for queen
bool isSafe(vector<vector<char>>&board , int col, int row)
{
//vertical check
for(int i=0 ; i<row ; i++)
{
if(board[i][col]=='Q')
{
return false;
}
}
//horizontal check
for(int i=0 ; i<col ; i++)   // this loops is additions , you can ignore it as ,
{                             // we are placing one queen in one row in each call .
if(board[row][i]=='Q')
{
return false;
}
}
//right diagonal check
for(int i=row ,j=col ; i>=0&&j>=0 ; i-- , j--)
{
if(board[i][j]=='Q')
{
return false;
}
}
//left diagonal check
for(int i=row ,j=col ; i>=0&&j<board.size(); i-- ,j++)
{
if(board[i][j]=='Q')
{
return false;
}
}
return true;
}

//driver code
int main ()
{
int n ;
cout<<"enter the size of chess board"<<endl;
cin>>n;
vector<vector<char>>board(n,vector<char>(n,'.'));
nQueens(board,0);
return 0;
}

