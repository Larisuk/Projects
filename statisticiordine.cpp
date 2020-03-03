/*Se dau n numere naturale. Să se afișeze al k-ulea cel mai mic element din șir.*/
#include <iostream>
    #include<fstream>
    #include <stdlib.h>
    #include <time.h>

    #define Nmax 4000000


    std::ifstream f("statisticiordine.in");
    std::ofstream g("statisticiordine.out");

    unsigned v[Nmax];

    int pivotare(int st,int dr)
    {   int n=dr-st+1;
        srand(time(NULL));

        int pivot=rand()%n+st;

        std::swap(v[pivot],v[dr]);

        int piv = v[dr];
        int i=st;
        for(int j=st;j<=dr-1;j++)
            if(v[j]<=piv)
        {
            std::swap(v[j],v[i]);
            i++;
        }
        std::swap(v[i],v[dr]);
        return i;
    }

    unsigned quickselect(int st,int dr,int k)
    {
        if(k>0 && k<=dr-st+1)
        {
            int index=pivotare(st,dr);
            if(index-st==k-1)return v[index];
            if(index-st>k-1)return quickselect(st,index-1,k);
            else return quickselect(index+1,dr,k-index+st-1);
        }
    }


    int main()
    {
        int n,k;
        f>>n;
        f>>k;
        for(int i=0;i<n;i++)
            f>>v[i];
        g<<quickselect(0,n-1,k);
        f.close();
        g.close();
        return 0;
    }
