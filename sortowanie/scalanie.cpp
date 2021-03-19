#include "scalanie.hh"

template<typename TYP>
void scal(TYP**tab, TYP**tablica_p, int poczatek, int srodek, int koniec, int k, int rozmiar_tab){


int pomoc=poczatek;
int pierwsza=poczatek;
int druga=srodek+1;

for(int i=poczatek; i<=koniec; ++i){
tablica_p[k][i]=tab[k][i];
}





while(pierwsza<=srodek && druga<=koniec)
{

if(tab[k][pierwsza]<tab[k][druga]){

  tablica_p[k][pomoc]=tab[k][pierwsza];
pierwsza++;
pomoc++;
}

else{

tablica_p[k][pomoc]=tab[k][druga];
pomoc++;
druga++;

}
}

while(pierwsza<=srodek)

{
tablica_p[k][pomoc]=tab[k][pierwsza];
pomoc++;
pierwsza++;

}

while (druga<=srodek){
tablica_p[k][pomoc] = tab[k][druga];
druga++;
pomoc++;

}


for(int i=poczatek; i<=koniec; i++){

tab[k][i]=tablica_p[k][i];

}

}


template<typename TYP>
void sortuj(int **tab,int **tablica_p,int poczatek, int koniec, int rozmiar_tab){



if(poczatek<koniec){

int srodek=(poczatek+koniec)/2;


sortuj(tab, tablica_p,poczatek,srodek, rozmiar_tab);
 
sortuj(tab,tablica_p, srodek+1,koniec, rozmiar_tab);


 for(int k=0;k<rozmiar_tab; k++){
scal(tab,tablica_p, poczatek,srodek,koniec, k, rozmiar_tab);

}
 }

 
  }
