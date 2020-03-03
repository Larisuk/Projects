/*Parcul oraşului a fost neglijat mult timp, astfel că acum toate aleile sunt distruse.Prin urmare, anul acesta Primăria şi - a propus să facă reamenajări.
Parcul are forma unui pătrat cu latura de n metri și este înconjurat de un gard care are exact două porți.Proiectanții de la Primărie au realizat o hartă a parcului și 
au trasat pe hartă un caroiaj care împarte parcul în nxn zone pătrate cu latura de 1 metru.Astfel harta parcului are aspectul unei matrice pătratice cu n linii și n coloane.
Liniile și respectiv coloanele sunt numerotate de la 1 la n.Elementele matricei corespund zonelor pătrate de latură 1 metru.O astfel de zonă poate să conțină un copac sau 
este liberă.Edilii orașului doresc să paveze cu un număr minim de dale pătrate cu latura de 1 metru zonele libere(fără copaci) ale parcului, astfel încât să se obțină o alee
continuă de la o poartă la alta.Scrieți un program care să determine numărul minim de dale necesare pentru construirea unei alei continue de la o poartă la cealaltă.*/
#include <iostream>
#include<fstream>
#include<queue>

using namespace std;

ifstream f("alee.in");
ofstream g("alee.out");

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int a[176][176];

unsigned short int cx[30000];
unsigned short int cy[30000];


void lee(int st,int dr,int n)
{
   int pi,pj;
   while(st<=dr)
    {
        pi=cx[st];
        pj=cy[st];
    
        for(int i=0;i<4;i++)
        {
            int pii=pi+dx[i];
            int pjj=pj+dy[i];
            if(pii>0 && pjj>0 && pii<=n && pjj<=n )
            {
                if(a[pii][pjj]==0)
                {
                    a[pii][pjj]=a[pi][pj]+1;
                    cx[dr]=pii;
                    cy[dr]=pjj;
                    dr++;
                }
            }
        }
       
       st++;

    }
}


int main()
{
    int n,m,x,y,xi,yi,xf,yf;
    f>>n;
    f>>m;
    while(m)
    {   f>>x>>y;
        a[x][y]=-1;
        m--;
    }
    f>>xi>>yi>>xf>>yf;
 cx[0]=xi;
    cy[0]=yi;
    a[xi][yi]=1;
    lee(0,1,n);
    g<<a[xf][yf];
    f.close();
    g.close();
    return 0;
}
