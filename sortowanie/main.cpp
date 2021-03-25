#include <stdio.h>
#include <iostream>
#include "scalanie.hh"
#include "scalanie.cpp"


using namespace std;



int main(){

clock_t start, stop;
double czas;
int ile_tab,rozmiar,poczatek;
poczatek=0;
bool flag=0;
float procent=0;
int i=0;

srand(time(NULL));

while(i!=6){


cout<< "Podaj ilosc tablic do posortowania:";
cin >> ile_tab;

int **tablica;
    tablica= new int*[ile_tab];

cout<< "Podaj rozmiar tablicy:";
cin >> rozmiar;
cout<<endl;

  for (int i=0; i<ile_tab; i++)
tablica[i]=new int[rozmiar];

for (int i=0; i<ile_tab; i++){
for (int j=0; j<rozmiar; j++){
         tablica[i][j]=rand() %101;
         }
    }




cout<<"Wybierz jaka tablice chcesz sortowac:"<<endl;
cout<<"1. Tablica losowa"<<endl;
cout<<"2. Tablica, ktora w czesci jest juz posortowana"<<endl;
cout<<"3. Tablica posortowana w odwrotnej kolejnosci"<<endl;

cin>>i;

switch(i){

case 1:

break;

case 2:

cout<<"Podaj procent, w jakim tablica ma byc posortowana:";
cin >> procent;

 for (int i=0; i<ile_tab; i++){
quick_sort<int>(tablica[i],poczatek,rozmiar*procent/100);
 }


break;

case 3:

for (int i=0; i<ile_tab; i++){
quick_sort<int>(tablica[i],poczatek,rozmiar);
 }
for (int i=0; i<ile_tab; i++){
odwroc<int>(tablica[i],rozmiar-1);
}
break;

}


while(i!=5){
  
  cout<<endl<<"Wybierz algorytm sortowania:"<<endl;
cout<<"1. Sortowanie przez scalanie"<<endl;
cout<<"2. Quick-sorting"<<endl;
cout<<"3. Sprawdz czy tablica jest posortowana poprawnie"<<endl;
cout<<"4. Wyswietl tablice"<<endl;
cout<<"5. Wczytaj nowa tablice"<<endl;
cout<<"6. Shell-sort"<<endl;
cout <<"7. Zamknij program"<<endl;

cin>>i;
cout<<endl;
switch(i){


case 1:

int ** tablica_p;
  tablica_p= new int*[ile_tab];

      for (int i=0; i<ile_tab; i++)
tablica_p[i]=new int[rozmiar];
      

start=clock();
 for (int i=0; i<ile_tab; i++){
sortujemy<int>(tablica[i],tablica_p[i],poczatek,rozmiar-1);
 }

stop=clock();
czas=(double)(stop-start)/CLOCKS_PER_SEC;

cout<<"czas:"<<czas<<"s"<<endl;

for(int i=0; i<ile_tab; ++i){
delete [] tablica_p[i];
}
delete [] tablica_p;

break;

case 2:
start=clock();
for (int i=0; i<ile_tab; i++){
quick_sort<int>(tablica[i],poczatek,rozmiar-1);
 }
stop=clock();
czas=(double)(stop-start)/CLOCKS_PER_SEC;

cout<<"czas:"<<czas<<"s"<<endl;
break;


case 3:
bool flag;
for (int i=0; i<ile_tab; i++){
flag=poprawnosc<int>(tablica[i],rozmiar);

}
if(flag==true){
  cout<< "Tablica posortowana poprawnie"<<endl;
}
else 
cout << "Tablica posortowana niepoprwanie"<<endl;

break;

case 4:

 for (int i=0; i<ile_tab; i++){
for (int j=0; j<rozmiar; j++){
cout<<tablica[i][j]<<" ";
}
cout<<endl;
 }

break;

case 6:

start=clock();

for (int i=0; i<ile_tab; i++){
ShellSort<int>(tablica[i],rozmiar);
}
stop=clock();
czas=(double)(stop-start)/CLOCKS_PER_SEC;

cout<<"czas:"<<czas<<"s"<<endl;

break;


case 7:
exit(1);



}
}
}
}









