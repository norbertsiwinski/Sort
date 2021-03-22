#include <stdio.h>
#include <iostream>


using namespace std;

void scal(int **tab, int**tablica_p, int poczatek, int srodek, int koniec, int k){


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




void sortuj(int **tab,int **tablica_p,int poczatek, int koniec, int rozmiar_tab){


if(poczatek<koniec){

int srodek=(poczatek+koniec)/2;


sortuj(tab, tablica_p,poczatek,srodek, rozmiar_tab);
 
sortuj(tab,tablica_p, srodek+1,koniec, rozmiar_tab);




 for(int k=0;k<rozmiar_tab; k++){
scal(tab,tablica_p, poczatek,srodek,koniec, k);

}
 }

 
  }



void quick_sort(int *tab,int poczatek, int koniec){

int i=poczatek;
int j=poczatek;
int srodek=(poczatek+koniec)/2;
int piwot=tab[srodek];


swap(tab[srodek],tab[koniec-1]);

for(i; i<koniec; i++){


if(tab[i]<piwot){

      swap(tab[i],tab[j]);
      j++;
}
}
swap(tab[koniec-1],tab[j]);

if(poczatek<j-1)
quick_sort(tab,poczatek,j-1);


if(j+1<koniec)
quick_sort(tab,j+1,koniec);

}


int main(){


int rozmiar_tab;
int rozmiar;
cout<<"wpisz ile tablic ma sortowac: ";
cin>>rozmiar_tab;
cout<<"wpisz rozmiar tablicy: ";
cin>>rozmiar;


clock_t start, stop;
double czas;

srand(time(NULL));

    int **tablica;
    tablica= new int*[rozmiar_tab];


      for (int i=0; i<rozmiar_tab; i++){
tablica[i]=new int[rozmiar];
      }

    for (int i=0; i<rozmiar_tab; i++){

       for (int j=0; j<rozmiar; j++){
        
    tablica[i][j]=rand() %101;
    }
    }


 int ** tablica_p;
  tablica_p= new int*[rozmiar_tab];


      for (int i=0; i<rozmiar_tab; i++){
tablica_p[i]=new int[rozmiar];
      }


int poczatek=0;
/*
sortuj(tablica, poczatek, rozmiar-1, rozmiar_tab);

    
  cout<<"przed sortowaniem:"<<endl;
    for (int i=0; i<rozmiar; i++){
    cout<<tablica[i]<<" "<<endl;
    
    }

/*

 sortuj(*tablica, poczatek, (rozmiar*0.97)-1);

cout<< "po sortowaniu polowy"<<endl;

for (int i=0; i<rozmiar; ++i){

 cout<<tablica[i]<<endl;
  
}

*/
/*
      for (int i=0; i<rozmiar_tab; i++){

       for (int j=0; j<rozmiar; j++){

        cout<<tablica[i][j]<<" ";
   
    }
    cout<<endl;
      }

*//*
start=clock();

sortuj(tablica, tablica_p, poczatek, rozmiar-1, rozmiar_tab);

stop=clock();
czas=(double)(stop-start)/CLOCKS_PER_SEC;

cout<<"czas"<<czas;

for(int i=0; i<rozmiar_tab; ++i){
delete [] tablica_p[i];
}
delete [] tablica_p;
*/
/*
cout<<"posrotwanie";


      for (int i=0; i<rozmiar_tab; i++){

       for (int j=0; j<rozmiar; j++){

        cout<<tablica[i][j]<<" ";
   
    }

cout<<endl;
*/

 for (int i=0; i<rozmiar_tab; i++){

       for (int j=0; j<rozmiar; j++){

        cout<<tablica[i][j]<<" ";
   
       }
       cout<<endl;
 }


 for (int i=0; i<rozmiar_tab; i++){
quick_sort(tablica[i],poczatek,rozmiar);

}

cout<<"sort";
for (int i=0; i<rozmiar_tab; i++){

       for (int j=0; j<rozmiar; j++){

        cout<<tablica[i][j]<<" ";
   
       }
       cout<<endl;
 }




}
