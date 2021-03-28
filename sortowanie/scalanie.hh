#include <stdio.h>
#include <iostream>

using namespace std;

template<typename TYP>
void sortujemy(TYP* tab, TYP* tablica_p, int poczatek, int koniec);


template<typename TYP>
void scal(TYP* tab, TYP* tablica_p, int poczatek, int srodek, int koniec);


template<typename TYP>
void quick_sort(TYP*tab, int poczatek, int koniec);

template<typename TYP>
void odwroc(TYP *tab,int rozmiar);

template<typename TYP>
bool poprawnosc(TYP *tab, int rozmiar);

template<typename TYP>
void ShellSort(TYP *a, int n);