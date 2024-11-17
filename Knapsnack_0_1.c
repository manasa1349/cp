#include <stdio.h>

// A utility function that returns the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity cap
int knapSack(int cap, int wt[], int val[], int n) 
{ 
    int i, j; 
    int K[n + 1][cap + 1]; 

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= cap; j++) { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
            else if (wt[i - 1] <= j) 
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]); 
            else 
                K[i][j] = K[i - 1][j]; 
        } 
    } 

    return K[n][cap]; 
} 

// Driver Code
int main() 
{ 
    int profit[] = { 10, 40, 30, 50 }; 
    int weight[] = { 5, 4, 6, 3 }; 
    int cap = 5; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    printf("Maximum profit: %d\n", knapSack(cap, weight, profit, n)); 
    return 0; 
} 
// ans 50
