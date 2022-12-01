#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxi 1000

int n , m , edges[maxi][maxi] , number_of_neighbors[maxi] , number_of_vers_in_comp[maxi] , vers_in_comp[maxi][maxi] , number_of_comps = 0;
bool mark[maxi];

/*
 * first Name: Farzam
 * last Name: Koohi Ronaghi
 * student Id: 401106403
 * date: 1401/09/10
 * this code is a simple dfs code
 */

void get_edges(int num_of_edges)
{
    memset(number_of_neighbors , 0 , sizeof(number_of_neighbors));
    for (int i = 0; i != num_of_edges; i++)
    {
        int x , y;
        scanf("%d %d" , &x , &y);
        edges[x][number_of_neighbors[x]] = y;
        number_of_neighbors[x]++;
        edges[y][number_of_neighbors[y]] = x;
        number_of_neighbors[y]++;
    }
}

bool dfs(int v)
{
    if (mark[v])
        return false;
    mark[v] = true;
    vers_in_comp[number_of_comps][number_of_vers_in_comp[number_of_comps]] = v;
    number_of_vers_in_comp[number_of_comps]++;
    for (int i = 0; i != number_of_neighbors[v]; i++)
    {
        int u = edges[v][i];
        dfs(u);
    }
    return true;
}

int main()
{
    // we have n vertices with m edges and we want to do a navigation and find components of graph
    // our vertices are 0-base
    memset(mark , false , sizeof(mark));
    scanf("%d %d" , &n , &m);
    get_edges(m);
    for (int i = 0; i != n; i++)
    {
        bool res = dfs(i);
        if (res)
            number_of_comps++;
    }
    printf("We have %d components in our graph!\nour components are like this:\n" , number_of_comps);
    for (int i = 0; i != number_of_comps; i++)
    {
        printf("%d: " , i+1);
        for (int j = 0; j != number_of_vers_in_comp[i]; j++)
        {
            printf("%d " , vers_in_comp[i][j]);
        }
        printf("\n");
    }
}