#include<iostream>
using namespace std;
const int size=9;
void sudokuSolver(arr , row , col )
{
if(row>=9)
{
return;
}
next_col=col+1;
next_row=row;
if(col==9)
{
next_row=row+1;
col=0;
}
if(arr[row][col]==0)
{
for(int i=1 ; i<= size ; i++)
{
if(isSafe(arr , row , col , i ))
{
arr[row][col]=i;
sudokuSolver(arr , next_row , next_col);
}
}
arr[row][col]==0;
return;
}
}
sudokuSolver(arr , next_row , next_col);
}
int main ()
{
int arr[9][9]={0};
sudokuSolver(arr , 0, 0);
return 0;
}

