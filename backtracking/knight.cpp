#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define N 8
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << sol[x][y] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, int sol[N][N]){
    
    if(x>= 0 && x < N  && y >= 0 && y<N && sol[x][y] == -1) return true;
    
    return false;
}
bool solveKTUtil(int x_move, int y_move, int move_i, int sol[N][N], int xMove[], int yMove[]){
    
    if(move_i == N*N) return true;
    
    for(int k = 0; k<8; k++){
        
        int x = x_move + xMove[k];
        int y = y_move + yMove[k];
        
        if(isSafe(x, y, sol)){
            
            sol[x][y] = move_i;
            if(solveKTUtil(x, y, move_i+1, sol, xMove, yMove)) return true;
            sol[x][y] = -1;
        }
    }
    
    return false;
}
void solveKT(){
    
    int sol[N][N];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 

    sol[0][0] = 0;
    
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return;
    }
    else
        printSolution(sol);
 
    return;
}
int main()
{
    solveKT();
    return 0;
}
