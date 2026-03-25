#include "include/arithmetic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

double addition_2(double a, double b) {
    printf("Result: ");
    return a + b;
}

double addition() {
    double result = 0;
    double input;
    int count = 0;
    char buffer[50];

    printf("Enter the numbers for addition(type q/quit for next operation):\n");

    while (true) {
        printf("%d. number: ", count + 1); 
        fgets(buffer, 50, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
            break;
        } 

        char* endptr;
        input = strtod(buffer, &endptr);
        if(endptr == buffer || *endptr != '\0') {
            printf("Expression must be a number, not character or space!\n");
            continue;
        }

        result += input;
        count++;
    }

    printf("**********RESULT**********\n");
    return result;
}

double substraction_2(double a, double b) {
    printf("Result: ");
    return a - b;
}

double substraction() {
    double arr[100];
    double result = 0;
    double input;
    int count = 0;
    char buffer[50];

    printf("Enter the numbers for substraction(type q/quit for next operation)\n");

    while(true) {
        printf("%d. number: ", count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
            break;
        }

        char* endptr;
        input = strtod(buffer, &endptr);

        if(endptr == buffer || *endptr != '\0') {
            printf("Expression must be a number, not character or space!\n");
            continue;
        }

        arr[count] = input;
        count++;
    }

    for(int i = 1; i < count; ++i) {
        result += arr[i];
    }

    printf("**********RESULT**********\n");
    return arr[0] - result;
}

double multiplication_2(double a, double b) {
    return a * b;
}

double multiplication() {
    double input;
    double result = 1;
    int count = 0;
    char buffer[50];

    printf("Enter the numbers for multiplication(type q/quit for next operation)\n");

    while(true) {
        printf("%d. number: ", count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
            break;
        }

        char* endptr;
        input = strtod(buffer, &endptr);
        if(endptr == buffer || *endptr != '\0') {
            printf("Expression must be a number, not character or space!\n");
            continue;
        }

        result *= input;
        count++;
    }

    printf("**********RESULT**********\n");
    return result;
}

double division_2(double a, double b) {
    return a / b;
}

double division() {
    double* arr = malloc(sizeof(double));
    double input;
    double result = 1;
    int count = 0;
    char buffer[50];

    printf("Enter the numbers for division(type q/quit for next operation)\n");

    while(true) {
        printf("%d. number: ", count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0) {
            break;
        }

        char* endptr;
        input = strtod(buffer, &endptr);
        if(endptr == buffer || *endptr != '\0') {
            printf("Expression must be a number, not character or space!\n");
            continue;
        }

        double* temp = realloc(arr, (count + 1) * sizeof(double));

        if(temp == NULL) {
            printf("Memory Allocation Error!");
            free(arr);
            return 0;
        }

        arr = temp;
        arr[count] = input;
        count++; 
    }

    for(int i=1; i<count; ++i) {
        if(arr[i] == 0) {
            printf("No division by 0\n");
            free(arr);
            return 0;
        }
        result *= arr[i];
    }

    printf("**********RESULT**********\n");

    double final = arr[0] / result;

    free(arr);
    return final;
}