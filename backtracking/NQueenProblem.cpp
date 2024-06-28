//assuming one queen can be placed at one row without thread 
#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<char>>&);
void nQueens(vector<vector<char>>&board, int row)
{
if(row==board.size())
{
display(board);
return;
}
for(int j=0 ; j<board.size() ; j++)
{
board[row][j]='Q';
nQueens(board,row+1);
board[row][j]='.';
}
return;
}
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
int main ()
{
int n ;
cout<<"enter the size of chess board"<<endl;
cin>>n;
vector<vector<char>>board(n,vector<char>(n,'.'));
/*for(int i=0 ; i<n ; i++)
{
vector<char>v;
for(int j=0 ; j<n ; j++)
{
v.push_back('.');
}
board.push_back(v);
v.clear();
}
*/
nQueens(board,0);
return 0;
}

