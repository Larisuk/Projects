/*Josephus și prietenii lui s-au gândit la un joc. Ei se așează într-un cerc și își scriu pe rând pe frunte câte un număr, reprezentând indicativul fiecăruia (1, 2, …, n). 
Toți au la îndemână un marker roșu. Jocul începe de la jucătorul cu numărul 1, care îl va marca cu un X pe cel aflat imediat în stânga sa și care nu a fost deja marcat, 
apoi următorul nemarcat îi va trece un X pe frunte celui din stânga sa și tot așa, până când va rămâne o singură persoană nemarcată, aceasta fiind considerată câștigătoare.*/
#include<iostream>
#include<tgmath.h>
using namespace std;

int putere(long long n,long long p)
{	if(n>p)return putere(n,p*2);
    if(n==p)return 1;

 	return 0;
}

int find_putere(long long n,long long p)
{
    if(n>pow(2,p))return find_putere(n,p+1);
    else return p-1;
}


int main()
{
    long long n;
    cin>>n;
    if(putere(n,1)==1 or n==1)cout<<"1";
    else {
        		long long c=find_putere(n,1);
        		c=pow(2,c);
        		c=n-c;
        		cout<<3+(c-1)*2;

    	}
    return 0;
}
