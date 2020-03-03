/*Se dă un şir cu n elemente, numere întregi.Determinaţi secvenţa de elemente cu suma maximă.*/
#include <iostream>
#include<fstream>
#define INT_MAX -99999

using namespace std;

ifstream f("secvsummax.in");
ofstream g("secvsummax.out");

int maxxACUM=0;
int maxxTOTAL=INT_MAX;

int v[100001],n;

int stabilire(int &poz)
{   int ok=0,maxx=v[1];
    for(int i=1;i<=n;i++)
    {
        if(v[i]>=0)
        {
            ok=1;
        }
        else if(v[i]>maxx)
        {maxx=v[i];
            poz=i;
        }
    }
    if(ok==1) return 1;
    else return maxx;
}

int kadane(int &pif,int &pff)
{   int pi=1;
    for(int i=1;i<=n;i++)
    {
        maxxACUM+=v[i];
        if(maxxACUM<0)
            {
                maxxACUM=0;
                pi=i+1;
            }
        else if(maxxACUM>maxxTOTAL)
                {
                    maxxTOTAL=maxxACUM;
                    if(pif!=pi)
                    {

                        pff=pi;
                        pif=pi;
                    }
                    else{
                        pff=pff+i-pff;
                    }

                }
    }
}


int main()
{   int pif=0,pff=0;
    f>>n;
    for(int i=1;i<=n;i++)
        f>>v[i];
    if(stabilire(pif)<0)
    {stabilire(pif);
    g<<pif<<" "<<pif<<" ";}
    else {
            kadane(pif,pff);
            g<<pif<<" "<<pff;
        }
    f.close();
    g.close();

    return 0;
}
