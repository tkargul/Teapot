//https://www.youtube.com/watch?v=cn1r_4kvJv8 
// 12:41 min

#include <stdio.h>
const float cp_Woda = 4200; // ciepło właśiwe wody J/kgK
 char *START="Program Czajnik - obliczenia kosztow gotowania wody w czajniku elektrycznym";
 float ObliczCzas(float masaWody,const float cp_Woda, float T1, float T2, float wspSprawnosci, float mocCzajnika_W); //oblicza czas gotowania wody w sekundach

int main(){
    float mocCzajnika_W;          // moc użytego czajnika w watach
    float masaWodyKg;           // masa wody w czajniku w kg
    float czasGotowania;        // czas gotowanai wody przez czajnik 
    float kosztkWh;
    
    float T1=25.0f;             // temperatura początkowa wody 25 stopni celctisza
    float T2=100.0f;            // temperatura końcowa 100 stopni celciusza
    float wspSprawnosci;    // zakładana sprawnośc czajnika 100%
    
    float zuzycieEnergii_kWh;   // do wyliczenia żucie pradu w kilowatogodzinach w ciągu miesiąca
    int ileRazy;                // ile razy dziennie gotuje wode w czajniku

    printf("%s", START);
    printf("\nWprowadz dane:\n");
    printf("Masa wody gotowanej w kg: ");
    scanf("%f",&masaWodyKg);
    printf("Moc czajnika w  Wattach: ");
    scanf("%f",&mocCzajnika_W);
    printf("Wspolczynnik sprawnosci czajnika w procentach '100%%'): ");
    scanf("%f",&wspSprawnosci);

    czasGotowania = ObliczCzas(masaWodyKg,cp_Woda,T1,T2,wspSprawnosci,mocCzajnika_W);
    printf("\nIle razy w ciagu dnia gotujesz wode ?: ");
    scanf("%d",&ileRazy);

    zuzycieEnergii_kWh = (ileRazy * 30 * ( mocCzajnika_W * ( czasGotowania/3600.0f) ) / 1000.0f);

    printf("W ciagu miesiaca Twoj czajnik zuzywa %g [kWh]", zuzycieEnergii_kWh);
    printf("\nJaki jest 1kwH w gr?: "); // koszt kWh w groszach
    scanf("%f", &kosztkWh);
    float kosztUzycia= (kosztkWh/100)*zuzycieEnergii_kWh; // miesięczny koszt uzycia czajnika
    printf("Koszt miesiecznego uzytkowania czajnika: %g zl",kosztUzycia );
    getchar();
    getchar();
    return 0;
}

//oblicza czas gotowania wody w sek
 float ObliczCzas(float masaWody_Kg,const float cp_Woda, float T1, float T2, float wspSprawnosci, float mocCzajnika_W){
     // Moc=praca/czas. (praca ==ciepło, PRACA czajnika w 100% przemieniane jest w ciepło - )
     //wycliczam ciepło jaka czajnik wykonuje podgrzewając wode od 25C do 100C,
     float Q =(masaWody_Kg * cp_Woda * (T2-T1)); // obliczenie ciepłą w J
     Q=(100.0f/wspSprawnosci)*Q;
     printf("\nTwoj czajnik wykona prace, ktora zamieniana jest na cieplo rowna: %g[J]\n", Q);
     float czasGotowania =(float)Q/mocCzajnika_W;
     printf("Czas, jaki zajmie mu zagotowanie %g[kg] wody, to %g[sek], czyli %g[min]\n",masaWody_Kg, czasGotowania, czasGotowania/60.0);
     printf("Zuzyje przy tym %g [kWh] pradu", (mocCzajnika_W*(czasGotowania/3600.0f))/1000.0f);
     return czasGotowania;
 }