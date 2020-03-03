/*Metoda Bucket Sort constă în distribuirea elementelor în mai multe grupe, numite “bucket-uri”. Apoi fiecare bucket este sortat individual folosind un algoritm de sortare oarecare.*/
#include <iostream>
#include<fstream>

using namespace std;

int v[10001];

ifstream f("bucketsort.in");
ofstream g("bucketsort.out");

void divide(int v[],int d,int st,int dr)
{
    if(st <dr)

        {
            int m=(st+dr)/2;
            int aux=v[st];
            v[st]=v[dr];
            v[dr]=aux;
            int i=st,l=0,j=dr;
            while(i<j)
            {
                if(v[i]>v[j] && d==0)
                {
                    int aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                    l=1-l;
                }
                else if(d==1 && v[i]<v[j])
                {

                    int aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                    l=1-l;

                }
                i+=l;
                j-=1-l;
            }
            divide(v,d,st,i-1);
            divide(v,d,i+1,dr);
        }



}

int main()
{
    int n,d,i=1,nr;
    f>>n;
    int cn=n;
    while(cn)
    {   f>>nr;
        v[i]=nr;
        i++;
        cn--;
    }
    f>>d;
    divide(v,d,1,n);
    for(int i=1;i<=n;i++)
        g<<v[i]<<" ";
    return 0;
}
