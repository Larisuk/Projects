/*Fie n un număr natural nenul. Fie v un vector cu n poziții numerotate de la 1 la n și elemente
numere naturale diferite, de la 1 la n, într-o ordine oarecare. Pentru i și j numere naturale între 1
și n, numim FLIP(n, v, i, j) operația care inversează ordinea elementelor din v situate pe pozițiile
de la i la j.
a) Să se scrie în limbaj de programare o procedură (sau funcție) care implementează operația
FLIP(n, v, i, j).
b) Să se scrie un program care sortează crescător vectorul v, folosind pentru schimbarea
ordinii elementelor în v doar operația FLIP(n, v, 1, k), cu k de la 2 la n.
c) Considerăm că n este o putere a lui 2 (n = 2m
, cu m număr natural nenul) și vectorul v are
proprietatea că pentru orice i de la 1 la m și orice j de la 1 la 2m-i
, există k de la 1 la 2m-i
,
astfel încât pe pozițiile din v de la 2i
(j-1)+1 la 2i
j se află numerele naturale de la 2i
(k-1)+1
la 2i
k, într-o ordine oarecare. Să se scrie un program care sortează crescător vectorul v,
folosind pentru schimbarea ordinii elementelor în v doar operația FLIP(n, v, 2i
(j-1)+1, 2i
j),
cu i de la 1 la m și j de la 1 la 2m-i
, printr-un algoritm mai eficient decât cel implementat la
punctul b), care se bazează pe proprietatea vectorului v. 
*/
#include <iostream>

void v_swap(int i, int j, unsigned int v[])
{
    int aux = v[i];
    v[i] = v[j];
    v[j]= aux;
}

void FLIP(size_t n, unsigned int v[], int i, int j)
{
    int jumatate = (i+j)/2+1;
    for(i; i < jumatate; i++, j--)
        v_swap(i,j,v);
}

void afis(size_t n, unsigned int v[])
{
    for(int i = 1; i <= n; i++)
        std::cout<<v[i]<<" ";
}

size_t find_poz(int n, unsigned v[])
{
    for(int i=1;i<=n;i++)
        if(v[i]==n)return i;
}

void sortareFLIP(size_t n, unsigned int v[])
{   while(n>1)
    {
        int maxx=find_poz(n,v);
        FLIP(n,v,1,maxx);
        FLIP(n,v,1,n);
        n--;
    }
}

int main()
{
    unsigned int v[100];
    size_t n;

    std::cin>>n;

    for(size_t i = 1; i <= n; i++)
    {
        std::cin >> v[i];
    }
    sortareFLIP(n,v);
    afis(n,v);
    return 0;
}
