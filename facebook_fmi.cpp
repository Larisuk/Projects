/*Ionuț tocmai a terminat liceul și susține examenul de admitere la facultate.Știind că s - a pregătit foarte bine pentru examen, el dorește să își anunțe reușita după examen printr - o postare pe Facebook.
Ionuț cunoaște n utilizatori reprezentați de numerele de la 1 la n, între care există m relații de prietenie de forma i j, unde i și j sunt utilizatori, iar n și m sunt numere naturale nenule.Un utilizator nu poate fi prieten cu el însuși, iar o relație de prietenie între doi utilizatori ne spune că fiecare dintre ei este prieten cu celălalt.

Întrucât dorește ca postarea lui să fie cât mai răspândită, Ionuț vrea să afle care sunt utilizatorii cei mai bine conectați din mulțimea sa de cunoscuți, pentru ca eventual să le ceară prietenia.Pentru aceasta, Ionuț trebuie să găsească cea mai mare submulțime de utilizatori cunoscuți, în care fiecare utilizator din această submulțime are cel puțin k prieteni aflați la rândul lor în submulțime, unde k este un număr natural nenul.

Ajutați - l pe Ionuț să se determine și să se afișeze, printr - o soluție de complexitate timp cât mai bună, în funcție de datele de intrare, membrii celei mai mari submulțimi de utilizatori, cu proprietatea că fiecare utilizator din această submulțime are cel puțin k prieteni aflați la rândul lor în submulțime.*/

#include <iostream>
        #include<fstream>

        using namespace std;

        ifstream f("fb_fmi.in");
        ofstream g("fb_fmi.out");

        bool a[1001][1001];

       short int vecini[1001];



        void verificare_vecini(int &x,int n,int k)
        {
            if(vecini[x]<k && vecini[x]!=0)
           {
               for(int i=1;i<=n;i++)
                if(a[x][i]==1){vecini[x]--;vecini[i]--;
                                                a[x][i]=a[i][x]=0;}
            
            vecini[x]=0;
            x=0;
           } 
        }

       


        int main()
        {
            int n,x,b,i,j,m,k;
            f>>n;
            f>>m;
            f>>k;
            int cm=m;
            while(cm)
            {
                f>>x;
                f>>b;
                a[x][b]=1;
                a[b][x]=1;
                vecini[x]++;
                vecini[b]++;
                cm--;

            }
            int numarare=0;

            for(i=1;i<=n;i++)
              {
                verificare_vecini(i,n,k);

              }
              for(i=1;i<=n;i++)
                if(vecini[i]>=k)numarare++;

            g<<numarare<<'\n';
            for(i=1;i<=n;i++)
                if(vecini[i]>=k)g<<i<<" ";
            f.close();
            g.close();
            return 0;
    }
