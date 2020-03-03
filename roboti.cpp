/*//Dat un labirint patratic,sa se gaseasca cel mai scurt drum prin care un robotel poate sa iasa din labirint.*/
#include <iostream>
#include<fstream>
#include<queue>
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={-1,1,0,0};
int a[1001][1001];

ifstream f("roboti.in");
ofstream g("roboti.out");

queue<int>cx;
queue<int>cy;



void drum(int n,int m)
{   int pi,pj,i;
    while(!cx.empty())
   {
      pi=cx.front();
    pj=cy.front();
    cx.pop();
    cy.pop();
      for(i=0;i<4;i++)
       {
           int pii=pi+dx[i];
          int  pjj=pj+dy[i];
        if(pii>=0 && pii<n && pjj>=0 &&pjj<m)
          {
            if(a[pii][pjj]==0)


            {
                a[pii][pjj]=a[pi][pj]+1;
                cx.push(pii);
                cy.push(pjj);


            }


          }

       }
    }
}

int main()
{
    int n,m,i,j,xi,yi,xf,yf;
    f>>n>>m;
    for(i=0;i<n;i++)
    {   j=0;
        while(j<m)
        {
            f>>a[i][j];
           if(a[i][j]==1)a[i][j]=-1;
            j++;
        }
    }
    f>>xi>>yi;
    f>>xf>>yf;
    cx.push(xi-1);
    cy.push(yi-1);

    a[xi-1][yi-1]=1;
    drum(n,m);
    if(a[xf-1][yf-1]==0 or a[xf-1][yf-1]==-1)g<<"-1";
    else g<<a[xf-1][yf-1]-1;
    f.close();
    g.close();
    return 0;
}
