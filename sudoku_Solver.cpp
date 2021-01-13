#include<iostream>
using namespace std;

void Input(int grid[9][9])
{
    int i,j;
    cout<<"Input the grid\n\n";

    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
          cin>>grid[i][j];
}
bool check_input(int grid[9][9])
{
    int i,j,c=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grid[i][j]<0 || grid[i][j]>9)
            {
                cout<<"Invalid grid !! ";
                return true;
            }
            if(grid[i][j]!=0)
                c++;
        }
    }
    if(c==81)
    {
       cout<<"grid is completely filled!!\n\n no solution found!!\n";
       return true;
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grid[i][j]>9 || grid[i][j]<0)
            {
                cout<<"Invalid grid!!/n";
                return true;
            }
            if(grid[i][j]!=0)
            {
                for(int k=j+1;k<9;k++)
                {
                     //check occurrence in row
                     if(grid[i][j]==grid[i][k])
                     {
                        cout<<"Invalid sudoku!! r\n";
                        return true;
                      }
                }

                for(int k=i+1;k<9;k++)
                {
                     //check occurrence in column
                     if(grid[i][j]==grid[k][j])
                     {
                        cout<<"Invalid sudoku!! c\n";
                        return true;
                     }
                }

               //check occurrence in 3*3 grid
                int row=i-i%3,col=j-j%3;
                for(int k=0;k<3;k++)
                {
                    for(int q=0;q<3;q++)
                    {
                     if((k+row)!=i && (col+q)!=j)
                     {
                        if(grid[k+row][q+col]==grid[i][j])
                        {
                        cout<<"Invalid sudoku please re-enter the correct one!!/n";
                        return true;
                        }
                      }
                    }
                }
            }

        }
    }
    return false;

}
bool check_num(int grid[9][9],int r,int c,int num)
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            if(grid[r][j]==num)
                return false;
            if(grid[j][c]==num)
                return false;
        }

    int row=r-r%3,col=c-c%3;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(grid[row+i][col+j]==num)
                return false;

 return true;
}
bool solve_sudoku(int grid[9][9],int r,int c)
{
      if(c==9)
      {
          r++;
          c=0;
      }
      if(r==9)
        return true;
      if(grid[r][c]>0)
        return solve_sudoku(grid,r,c+1);

      for(int i=1;i<=9;i++)
      {
          int num=i;
          if(check_num(grid,r,c,num))
          {
            grid[r][c]=num;
            if(solve_sudoku(grid,r,c+1))
            return true;
          }
          grid[r][c]=0;
      }
      return false;
}

void print(int grid[9][9])
{
    int i,j;
    cout<<"\n";
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
        cout<<grid[i][j]<<" ";
      cout<<"\n";
    }

}
int main()
{
   int grid[9][9];
  //input the grid to solve
   Input(grid);
  //check the input sudoku is valid or not
   if(check_input(grid))
     return 0;
  //solution for the input sudoku
   else if(solve_sudoku(grid,0,0))
       print(grid); //printing the solution
    else
        cout<<"no solution exists\n";   //if no solution found
    return 0;
}
