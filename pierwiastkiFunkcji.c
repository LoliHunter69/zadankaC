#include<stdio.h>
#include<math.h>

//liczy delte
int delta(int a, int b, int c){
    return pow(b,2)-4*a*c;
}

//liczy pierwiastek funkcji | znak okresla czy pierwiastek delty odejmujemy czy dodajemy w mianowniku
double pierwiastki(int a, int b, int c, char deltaSign){
    if(deltaSign=='+') return ((0-b+sqrt(delta(a,b,c)))/(2*a));
    else if(deltaSign=='-') return ((0-b-sqrt(delta(a,b,c)))/(2*a));
}

//wyswietla wyniki
void showRoots(double x1, double x2, int a, int b, int c){
    //sprawdza czy oba wyniki są równe ( czy delta rowna jest 0 )
    if(x1==x2) printf("\n\nPierwiastkiem funkcji f(x) = %dx^2 + %dx + %d jest\n\nx = %lf\n\n", a, b, c, x1); 
    else printf("\n\nPierwiastkami funkcji f(x) = %dx^2 + %dx + %d sa\n\nx1 = %lf\nx2 = %lf\n\n", a, b, c, x1, x2); 
}

//informacje o programie
void menu(){
     printf("Program liczy pierwiastki funkcji kwadratowej f(x) = ax^2 + bx + c\n\nPodaj kolejno wartosc zmiennych a, b, c:\n");
}

//wczytywanie wartosci zmiennej
int readInt(int a){
    printf("\nPodaj wartosc zmiennej: ");
    scanf("%d", &a);
    return a;
}

int checkA(int a){
    if(a!=0) return 1;
    else return 0;
}

int main(){

    //wyswietla informacje o programie
    menu();

    int a,b,c;
    double x1,x2;

    //pobiera wartosci zmiennych
    a = readInt(a);
    b = readInt(b);
    c = readInt(c);

    //sprawdza czy funkcja jest kwadratowa
    if(!checkA(a)) { printf("\nFunkcja nie jest funkcja kwadratowa.\n\n"); return 0; }

    //sprawdza czy funkcja ma pierwiastki w zbiorze liczb rzeczywistych
    if(delta(a,b,c)<0) { printf("\n\nDla funkcji f(x) = %dx^2 + %dx + %d nie ma pierwiastkow w zbiorze liczb rzeczywistych\n\n", a, b, c); return 0; }

    //liczy pierwiastki funkcji
    x1 = pierwiastki(a, b, c, '+');
    x2 = pierwiastki(a, b, c, '-');

    //pokazuje wynik
    showRoots(x1, x2, a, b, c);

    return 0;
}
