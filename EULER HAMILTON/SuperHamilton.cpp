#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int N = 25;
int adjMat[N][N];
int parent[N];
bool visited[N] = { 0 };

char Mat[N][N];

int numberOfVertices=0;
int hamiltonPaths = 0;


void dfs(int v, int Size,int end)
{
    if (Size == numberOfVertices && v==end) {

        hamiltonPaths++;
        return;
    }

    visited[v] = 1;

    for (int i = 0; i < N; i++) {

        
        if (adjMat[v][i] == 1 && (!visited[i])) {
            parent[i] = v;
            dfs(i,Size+1,end);
        }
    }

    visited[v] = 0;
}

int main() 
{
    int Rows, Cols;
    std::cin >> Rows >> Cols;
    std::vector<std::vector<int>> ValueMatr;
    int counter = 0;

    for (int i = 0; i < Rows; ++i)
    {
        std::vector<int> temp;
        for (int j = 0; j < Cols; ++j)
        {
            temp.push_back(counter);
            counter++;
        }
        ValueMatr.push_back(temp);
    }
    numberOfVertices = Rows * Cols;
    char str;
    int DFStart = 0;
    int DFSend = 0;
    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < Cols; ++j)
        {
            std::cin >> str;
            Mat[i][j] = str;
            if (str == 's')
            {
                DFStart = ValueMatr[i][j];
            }

            else if(str=='e')
            {
                DFSend = ValueMatr[i][j];
            }
            else if (str == 'x')
            {
                numberOfVertices--;
            }
        }
    }
    
    int from, to;
    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < Cols; ++j)
        {
            
            if (j + 1 < Cols)
            {
                from = ValueMatr[i][j];
                to = ValueMatr[i][j + 1];
                if (Mat[i][j + 1] != 'x' && Mat[i][j]!= 'x')
                {
                    
                    adjMat[from][to] = 1;
                    adjMat[to][from] = 1;
                }
                
            }
            if (i + 1 < Rows)
            {
                from = ValueMatr[i][j];
                to = ValueMatr[i+1][j];
                if (Mat[i + 1][j] != 'x' && Mat[i][j] != 'x')
                {
                    adjMat[from][to] = 1;
                    adjMat[to][from] = 1;
                }
            }
            
        }
    }

    parent[0] = -1;
    dfs(DFStart, 1,DFSend);


    std::cout << hamiltonPaths;
    return 0;
}