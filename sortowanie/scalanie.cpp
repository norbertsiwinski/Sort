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
    int pivot = tab[(i + j)/2];
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
int pom[rozmiar];
for(int i=0; i<rozmiar; i++){
pom[i]=tab[i];
}
for(int i=0; i>rozmiar; i++){
tab[rozmiar--]=pom[i];

}
 }

 
	/*
	if(prawy <= lewy) return;
	
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2]; //wybieramy punkt odniesienia
	
	while(1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while(pivot>tab[++i]);
		
		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while(pivot<tab[--j]);
		
		//jesli liczniki sie nie minely to zamień elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if( i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);

}
/*
/*
int i,j;
int srodek=(poczatek+koniec)/2;
int piwot=tab[srodek];
int pomoc;
pomoc= tab[koniec];
            tab[koniec] = tab[srodek];
            tab[srodek] = pomoc;
//swap(tab[srodek],tab[koniec]);

for(j=i=poczatek; i<koniec; i++){


if(tab[i]<piwot){
pomoc= tab[i];
            tab[i] = tab[j];
            tab[j] = pomoc;


  //    swap(tab[i],tab[j]);
      j++;
}
}
pomoc= tab[koniec];
            tab[koniec] = tab[j];
            tab[j] = pomoc;

//swap(tab[koniec],tab[j]);

if(poczatek<j-1)
quick_sort(tab,poczatek,j-1);


if(j+1<koniec)
quick_sort(tab,j+1,koniec);

*/

template<typename TYP>
bool poprawnosc(TYP *tab, int rozmiar){
for(int i=0; i<rozmiar; ++i)
if(tab[i-1]>tab[i]){
return false;
}
return true;
}
