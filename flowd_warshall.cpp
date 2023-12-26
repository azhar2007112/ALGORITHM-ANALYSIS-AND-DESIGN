#include<iostream>


using namespace std;


#define v 4

#define INF 99999999
void printsolution(int dis[][v]);

void floyd(int dis[][v])
{

    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }


    printsolution(dis);

}


void printsolution(int dis[][v])
{
    cout<<"for shortest distance between the pair of vertices";

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(dis[i][j]==INF)
                cout<<"INF"
                <<" ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;

    }

}

int main()
{

    int graph[v][v]={
                      {0,5,INF,10},
                      {INF,0,3,INF},
                      {INF,INF,0,1},
                      {INF,INF,INF,0},
                    };


                    floyd(graph);




    return 0;
}
//modify it to find the shortest path
