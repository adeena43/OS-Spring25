#include <stdio.h>
#include "temperature.h"

int main() {
    double temp;
    char unit;
    
    printf("Enter temperature with unit (C/F): ");
    scanf("%lf %c", &temp, &unit);
    
    if (unit == 'C' || unit == 'c') {
        printf("%.2f C = %.2f F\n", temp, celsius_to_fahrenheit(temp));
    } else if (unit == 'F' || unit == 'f') {
        printf("%.2f F = %.2f C\n", temp, fahrenheit_to_celsius(temp));
    } else {
        printf("Invalid unit. Use 'C' for Celsius or 'F' for Fahrenheit.\n");
    }
    
    return 0;
}