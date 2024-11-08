#include <stdio.h>
#include <math.h>

int board[20], count;

void queen(int row, int n);
int place(int row, int column);
void print(int n);

int main()
{
    int n;
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j) // for nxn board
        {
            if (board[i] == j)
                printf(" 1 "); // queen at i,j position
            else
                printf(" 0 "); // empty slot
        }
        printf("\n");
    }
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0; // conflict found
    }
    return 1; // no conflicts
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column; // no conflicts, so place queen
            if (row == n) // all queens are placed
                print(n); // print the board configuration
            else // try next row
                queen(row + 1, n);
        }
    }
}
