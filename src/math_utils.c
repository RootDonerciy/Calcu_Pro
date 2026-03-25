#include "include/math_utils.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(double n) {
    if (n < 0) return -1; // Invalid
    double f = 1;
    for(int i = 1; i <= n; ++i) {
        f *= i;
    }    
    return f;
}

int gcd(int n_1, int n_2) {
    n_1 = abs(n_1);
    n_2 = abs(n_2);
    
    while (n_2 != 0) {
        int temp = n_2;  // Fixed: use int, not double
        n_2 = n_1 % n_2; 
        n_1 = temp;
    }
    return n_1;
}

int lcd(int n_1, int n_2) {
    return (n_1 * n_2) / gcd(n_1, n_2);
}

double min(double n_1, double n_2) {
    return (n_1 < n_2) ? n_1 : n_2;
}

double max(double n_1, double n_2) {
    return (n_1 > n_2) ? n_1 : n_2;
}

double absolute(double n) {
    if(n < 0) return n * (-1.0);
    return n;
}

double percentage(double n) {
    return n * (1.0/100.0);
}

double calculatePercentage(double value, double percent) {
    return (value * percent) / 100.0;
}

double percentage_inc(double n) {
    return n + percentage(n);
}

double percentage_dec(double n) {
    return n - percentage(n);
}

double power(double n, double p) {
    return pow(n, p);  
}

double logarithm(double n, double p) {
    if (n <= 0 || n == 1 || p <= 0) return -1; 
    return log(p) / log(n);  
}

char* isPrime(int n) {
    if (n <= 1) return "It's not prime";
    if (n == 2) return "It's prime";
    if (n % 2 == 0) return "It's not prime";
    
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return "It's not prime";
    }
    return "It's prime";
}

int sumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        int a = n % 10;
        sum += a;
        n/=10;
    }
    return n;
}

