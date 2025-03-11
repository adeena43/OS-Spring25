#include "temperature.h"

double celsius_to_fahrenheit(double c)
{
    return (c*9.0/5.0) + 32;
}

double fahrenheit_to_celsius(double f)
{
    return (f - 32) * 5.0/9.0;
}