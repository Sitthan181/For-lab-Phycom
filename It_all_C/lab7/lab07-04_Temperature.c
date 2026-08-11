#include <stdio.h>
double celsiusToFahrenheit(double celcius);
double fahrenheitToCelcius(double fahrenheit);
void printFarenheit(double fahrenheit);
void printCelcius(double celcius);

int main(){
    double num;
    char txt;
    double C, F;
    scanf("%lf %c", &num, &txt);
    if (txt == 'c' || txt == 'C'){
        F = celsiusToFahrenheit(num);
        printFarenheit(F);
    } else {
        C = fahrenheitToCelcius(num);
        printCelcius(C);
    }
    return 0;
}

double celsiusToFahrenheit(double celcius){
    double ans;
    ans = 32 + celcius * (180.0/100.0);
    return ans;
}

double fahrenheitToCelcius(double fahrenheit){
    double ans;
    ans = (fahrenheit - 32) / (180.0/100.0);
    return ans;
}

void printFarenheit(double fahrenheit){
    printf("%.2lf f", fahrenheit);
}

void printCelcius(double celcius){
    printf("%.2lf c", celcius);
}