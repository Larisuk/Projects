/*Supărat că fata de care - i plăcea l - a respins, Bogdan și - a făcut bagajele și a pornit într - o excursie de - a lungul întregii lumi.Acesta a vizitat mai toate continentele, însă acum este blocat în Africa din cauza faptului că Bogdan, băiat mai neastâmpărat din fire, s - a apucat să se bată cu țânțarii Mosquito.Bineînțeles că a fost înțepat și că acum trebuie să caute antidot pentru venin, altfel Bogdan se va transforma și el în Mosquito.Acesta s - a dus să - i ceară ajutorul lui Aashiq, care îi spune următoarele : “Te voi vindeca de înțepături dacă reușești să duci la bun sfârșit sarcina pe care ți - o dau.”, însă Bogdan nu prea se pricepe la sarcini complicate, așa că vă roagă să rezolvați voi cerința în locul lui.

Dându - se trei numere naturale, a, n, k, trebuie să aflați valoarea următoarei expresii : ak•ak + 2k•...•ak + 2k + ... + nk.Antidotul pentru înțepăturile de Mosquito necesită foarte multă muncă, motiv pentru care vor trebui îndeplinite t teste.*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define MOD 1000000007

unsigned long long lgpow(long long n, long long p)
{
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		return lgpow(n * n % MOD, p / 2) % MOD;
	}
	else
	{
		return n * lgpow(n * n % MOD, p/2) % MOD;
	}
}

int main()
{
	ifstream f("mosquito.in");
	ofstream g("mosquito.out");

	long long t, n, a, k;
	f >> t;

	while(t)
	{
		f >> a;
		f >> n;
		f >> k;

		long long x = 0;
		long long v = 1;
        if(n==1){v=lgpow(a,k)%MOD;
                 g<<v<<'\n';
                }
		else if (a == 1)
			g << 1 <<'\n';

		else
		{

			for (long long j = 1; j <= n; j++)
            {
				x = x + (k * ((j * (j + 1)) / 2));
			}
			v = lgpow(a, x) % MOD;

			g << v << '\n';
		}

		t--;

	}
	f.close();
	g.close();

	return 0;
}
