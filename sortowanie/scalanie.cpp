#include "scalanie.hh"
#include <algorithm>

template<typename TYP>
void scal(TYP* tab, TYP* tablica_p, int poczatek, int srodek, int koniec){


int pomoc=poczatek;
int pierwsza=poczatek;
int druga=srodek+1;

for(int i=poczatek; i<=koniec; ++i){
tablica_p[i]=tab[i];
}


while(pierwsza<=srodek && druga<=koniec)
{

if(tab[pierwsza]<tab[druga]){

  tablica_p[pomoc]=tab[pierwsza];
pierwsza++;
pomoc++;
}

else{

tablica_p[pomoc]=tab[druga];
pomoc++;
druga++;

}
}

while(pierwsza<=srodek)

{
tablica_p[pomoc]=tab[pierwsza];
pomoc++;
pierwsza++;

}


for(int i=poczatek; i<=koniec; i++){

tab[i]=tablica_p[i];

}
}

template<typename TYP>
void sortujemy(TYP *tab,TYP *tablica_p,int poczatek, int koniec){


if(poczatek<koniec){

int srodek=(poczatek+koniec)/2;


sortujemy(tab, tablica_p,poczatek,srodek);
 
sortujemy(tab,tablica_p, srodek+1,koniec);



scal(tab,tablica_p, poczatek,srodek,koniec);

}

return;
 }




template<typename TYP>
 void quick_sort(TYP *tab,int poczatek, int koniec){

{
    
    int i = poczatek;
    int j = koniec;
    int pivot = tab[(i+j)/2];
    int pomoc;

    while (i <= j)
    {
        while (tab[i] < pivot)
            i++;
        while (tab[j] > pivot)
            j--;
        if (i <= j)
        {
pomoc= tab[i];
     tab[i] = tab[j];
            tab[j] = pomoc;
    
            i++;
            j--;
        }
    }
    if (j > poczatek)
        quick_sort(tab, poczatek, j);
    if (i < koniec)
        quick_sort(tab, i, koniec);
}
 }


template<typename TYP>
 void odwroc(TYP *tab,int rozmiar){

for(int i=0; i<=rozmiar; i++){

swap(tab[i],tab[rozmiar]);
rozmiar--;
}
 }


 
	
template<typename TYP>
void ShellSort(TYP *tab, int rozmiar)
{
	int d, j, k, pomoc;
	
	for(d = rozmiar/2; d > 0; d = d/2)
	{
		for(j = d; j < rozmiar; j++)
		{
			for(k = j-d; k >= 0; k = k-d)
			{
			
				if(tab[k+d] >= tab[k])
                
				break;
				
				else
				{
					pomoc = tab[k];
					tab[k] = tab[k+d];
					tab[k+d] = pomoc;
				}
			}
        }
	}
}



template<typename TYP>
bool poprawnosc(TYP *tab, int rozmiar){
for(int i=0; i<rozmiar; ++i)
if(tab[i-1]>tab[i]){
return false;
}
return true;
}
