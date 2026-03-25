#include "include/arithmetic.h"
#include "include/trigono.h"
#include "include/math_utils.h"
#include "include/geometric/2D/triangle.h"
#include "include/geometric/2D/circle.h"
#include "include/geometric/2D/square.h"
#include "include/geometric/2D/rectangle.h"
#include "include/geometric/2D/rhombus.h"
#include "include/geometric/2D/paralelogram.h"
#include "include/geometric/2D/trapesoid.h"
#include "include/geometric/3D/cone.h"
#include "include/geometric/3D/cube.h"
#include "include/geometric/3D/cylinder.h"
#include "include/geometric/3D/spher.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
static void enable_ansi() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE) return;
    DWORD mode;
    if (!GetConsoleMode(h, &mode)) return;
    SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#endif

void save_history(const char* operation, double result);
void print_banner();
void arithmetic_menu();
void trigono_menu();
void geometry_menu();
void show_history();

void save_history(const char* operation, double result) {
    FILE* file = fopen("history.txt", "a");
    if (file == NULL) return;
    time_t now = time(NULL);
    char* timecurr = ctime(&now);
    timecurr[strlen(timecurr) - 1] = '\0';
    fprintf(file, "[%s] %s = %.2f\n", timecurr, operation, result);
    fclose(file);
}

void print_banner() {
    const char *cyan = "\x1b[36m";
    const char *green = "\x1b[32m";
    const char *yellow = "\x1b[33m";
    const char *reset = "\x1b[0m";
    printf("\n%s=======================================%s\n", cyan, reset);
    printf("%s|%s        %sCALCU_PRO(v_1)%s        %s|%s\n", cyan, green, yellow, green, cyan, reset);
    printf("%s|%s        %sMade by Omer Bagirzade%s        %s|%s\n", cyan, green, yellow, green, cyan, reset);
    printf("%s=======================================%s\n\n", cyan, reset);
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    enable_ansi();
#endif
    int choice;
    while (true) {
        system("cls");
        print_banner();
        printf("1. Arithmetic Operations\n");
        printf("2. Trigonometric Operations\n");
        printf("3. Geometry\n");
        printf("4. Show File History\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arithmetic_menu(); break;
            case 2: trigono_menu(); break;
            case 3: geometry_menu(); break;
            case 4: show_history(); break;
            case 0: return 0;
            default: printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}

void arithmetic_menu() {
    int choice;
    double a, b, result;
    while(1) {
        printf("\n=== ARITHMETIC OPERATIONS ===\n");
        printf("1. Addition (two numbers)\n");
        printf("2. Subtraction (two numbers)\n");
        printf("3. Multiplication (two numbers)\n");
        printf("4. Division (two numbers)\n");
        printf("5. Factorial\n");
        printf("6. GCD (Greatest Common Divisor)\n");
        printf("7. LCM (Least Common Multiple)\n");
        printf("8. Power\n");
        printf("9. Check if Prime\n");
        printf("10. Sum of Digits\n");
        printf("0. Back to main menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = addition_2(a, b);
                printf("Result: %.2f\n", result);
                save_history("Addition", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = substraction_2(a, b);
                printf("Result: %.2f\n", result);
                save_history("Subtraction", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = multiplication_2(a, b);
                printf("Result: %.2f\n", result);
                save_history("Multiplication", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = division_2(a, b);
                printf("Result: %.2f\n", result);
                save_history("Division", result);
                break;
            case 5:
                printf("Enter number: ");
                scanf("%lf", &a);
                result = factorial(a);
                printf("Factorial: %.0f\n", result);
                save_history("Factorial", result);
                break;
            case 6:
                printf("Enter two integers: ");
                scanf("%lf %lf", &a, &b);
                result = gcd((int)a, (int)b);
                printf("GCD: %.0f\n", result);
                save_history("GCD", result);
                break;
            case 7:
                printf("Enter two integers: ");
                scanf("%lf %lf", &a, &b);
                result = (int)a * (int)b / gcd((int)a, (int)b);
                printf("LCM: %.0f\n", result);
                save_history("LCM", result);
                break;
            case 8:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &a, &b);
                result = power(a, b);
                printf("Result: %.2f\n", result);
                save_history("Power", result);
                break;
            case 9:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("%s\n", isPrime((int)a));
                break;
            case 10:
                printf("Enter number: ");
                scanf("%lf", &a);
                result = sumOfDigits((int)a);
                printf("Sum of digits: %.0f\n", result);
                save_history("Sum of Digits", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void trigono_menu() {
    int choice;
    double angle, result;
    while(1) {
        printf("\n=== TRIGONOMETRIC OPERATIONS ===\n");
        printf("1. Sine\n");
        printf("2. Cosine\n");
        printf("3. Tangent\n");
        printf("4. Cotangent\n");
        printf("5. Secant\n");
        printf("6. Cosecant\n");
        printf("7. Arcsine\n");
        printf("8. Arccosine\n");
        printf("9. Arctangent\n");
        printf("10. Arccotangent\n");
        printf("11. Degrees to Radians\n");
        printf("12. Radians to Degrees\n");
        printf("0. Back to main menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = sine(angle);
                printf("sin(%.2f) = %.4f\n", angle, result);
                save_history("Sine", result);
                break;
            case 2:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = cosine(angle);
                printf("cos(%.2f) = %.4f\n", angle, result);
                save_history("Cosine", result);
                break;
            case 3:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = tang(angle);
                printf("tan(%.2f) = %.4f\n", angle, result);
                save_history("Tangent", result);
                break;
            case 4:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = cot(angle);
                printf("cot(%.2f) = %.4f\n", angle, result);
                save_history("Cotangent", result);
                break;
            case 5:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = sec(angle);
                printf("sec(%.2f) = %.4f\n", angle, result);
                save_history("Secant", result);
                break;
            case 6:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = cosec(angle);
                printf("cosec(%.2f) = %.4f\n", angle, result);
                save_history("Cosecant", result);
                break;
            case 7:
                printf("Enter value: ");
                scanf("%lf", &angle);
                result = arcsin(angle);
                printf("arcsin(%.4f) = %.2f\n", angle, result);
                save_history("Arcsine", result);
                break;
            case 8:
                printf("Enter value: ");
                scanf("%lf", &angle);
                result = arccos(angle);
                printf("arccos(%.4f) = %.2f\n", angle, result);
                save_history("Arccosine", result);
                break;
            case 9:
                printf("Enter value: ");
                scanf("%lf", &angle);
                result = arctan(angle);
                printf("arctan(%.4f) = %.2f\n", angle, result);
                save_history("Arctangent", result);
                break;
            case 10:
                printf("Enter value: ");
                scanf("%lf", &angle);
                result = arccot(angle);
                printf("arccot(%.4f) = %.2f\n", angle, result);
                save_history("Arccotangent", result);
                break;
            case 11:
                printf("Enter angle in degrees: ");
                scanf("%lf", &angle);
                result = deg_to_rad(angle);
                printf("%.2f = %.4f radians\n", angle, result);
                save_history("Deg to Rad", result);
                break;
            case 12:
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                result = rad_to_deg(angle);
                printf("%.4f radians = %.2f\n", angle, result);
                save_history("Rad to Deg", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void geometry_2d_menu();
void geometry_3d_menu();
void triangle_menu();
void circle_menu();
void square_menu();
void rectangle_menu();
void rhombus_menu();
void paralelogram_menu();
void trapesoid_menu();
void cone_menu();
void cube_menu();
void cylinder_menu();
void sphere_menu();

void geometry_menu() {
    int choice;
    while(1) {
        printf("\n=== GEOMETRY ===\n");
        printf("1. 2D Geometry\n");
        printf("2. 3D Geometry\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: geometry_2d_menu(); break;
            case 2: geometry_3d_menu(); break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void geometry_2d_menu() {
    int choice;
    while(1) {
        printf("\n=== 2D GEOMETRY ===\n");
        printf("1. Triangle\n");
        printf("2. Circle\n");
        printf("3. Square\n");
        printf("4. Rectangle\n");
        printf("5. Rhombus\n");
        printf("6. Parallelogram\n");
        printf("7. Trapezoid\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: triangle_menu(); break;
            case 2: circle_menu(); break;
            case 3: square_menu(); break;
            case 4: rectangle_menu(); break;
            case 5: rhombus_menu(); break;
            case 6: paralelogram_menu(); break;
            case 7: trapesoid_menu(); break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void geometry_3d_menu() {
    int choice;
    while(1) {
        printf("\n=== 3D GEOMETRY ===\n");
        printf("1. Cone\n");
        printf("2. Cube\n");
        printf("3. Cylinder\n");
        printf("4. Sphere\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: cone_menu(); break;
            case 2: cube_menu(); break;
            case 3: cylinder_menu(); break;
            case 4: sphere_menu(); break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void triangle_menu() {
    int choice;
    double a, b, c, side, h, angle, result;
    while(1) {
        printf("\n=== TRIANGLE ===\n");
        printf("1. Check if triangle\n");
        printf("2. Triangle type\n");
        printf("3. Perimeter\n");
        printf("4. Area (side x height)\n");
        printf("5. Area (two sides x angle)\n");
        printf("6. Area (Heron's formula)\n");
        printf("7. Altitude\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a, b, c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                printf("%s\n", check_triangle(a, b, c));
                break;
            case 2:
                printf("Enter a, b, c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                printf("%s\n", triang_type(a, b, c));
                break;
            case 3:
                printf("Enter a, b, c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                result = triang_perim(a, b, c);
                printf("Perimeter: %.2f\n", result);
                save_history("Triangle Perimeter", result);
                break;
            case 4:
                printf("Enter side and height: ");
                scanf("%lf %lf", &side, &h);
                result = triang_area_1(side, h);
                printf("Area: %.2f\n", result);
                save_history("Triangle Area (side x height)", result);
                break;
            case 5:
                printf("Enter two sides and angle (degrees): ");
                scanf("%lf %lf %lf", &a, &b, &angle);
                result = triang_area_2(a, b, angle);
                printf("Area: %.2f\n", result);
                save_history("Triangle Area (two sides x angle)", result);
                break;
            case 6:
                printf("Enter a, b, c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                result = triang_area_3(a, b, c);
                printf("Area: %.2f\n", result);
                save_history("Triangle Area (Heron)", result);
                break;
            case 7:
                printf("Enter a, b, c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                result = triang_altit(a, b, c);
                printf("Altitude to c: %.2f\n", result);
                save_history("Triangle Altitude", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void circle_menu() {
    int choice;
    double r, d, angle, result;
    while(1) {
        printf("\n=== CIRCLE ===\n");
        printf("1. Diameter\n");
        printf("2. Circumference\n");
        printf("3. Area\n");
        printf("4. Arc length\n");
        printf("5. Sector area\n");
        printf("6. Chord length\n");
        printf("7. Tangent length\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = circ_diameter(r);
                printf("Diameter: %.2f\n", result);
                save_history("Circle Diameter", result);
                break;
            case 2:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = circum(r);
                printf("Circumference: %.2f\n", result);
                save_history("Circle Circumference", result);
                break;
            case 3:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = circ_area(r);
                printf("Area: %.2f\n", result);
                save_history("Circle Area", result);
                break;
            case 4:
                printf("Enter radius and angle (degrees): ");
                scanf("%lf %lf", &r, &angle);
                result = arc(r, angle);
                printf("Arc length: %.2f\n", result);
                save_history("Circle Arc", result);
                break;
            case 5:
                printf("Enter radius and angle (degrees): ");
                scanf("%lf %lf", &r, &angle);
                result = circ_sector_area(r, angle);
                printf("Sector area: %.2f\n", result);
                save_history("Circle Sector Area", result);
                break;
            case 6:
                printf("Enter radius and angle (degrees): ");
                scanf("%lf %lf", &r, &angle);
                result = chord(r, angle);
                printf("Chord: %.2f\n", result);
                save_history("Circle Chord", result);
                break;
            case 7:
                printf("Enter distance from center and radius: ");
                scanf("%lf %lf", &d, &r);
                result = circ_tangent(d, r);
                printf("Tangent: %.2f\n", result);
                save_history("Circle Tangent", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void square_menu() {
    int choice;
    double a, d, result;
    while(1) {
        printf("\n=== SQUARE ===\n");
        printf("1. Diagonal\n");
        printf("2. Perimeter\n");
        printf("3. Area (by side)\n");
        printf("4. Area (by diagonal)\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = sqr_diagonal(a);
                printf("Diagonal: %.2f\n", result);
                save_history("Square Diagonal", result);
                break;
            case 2:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = sqr_per(a);
                printf("Perimeter: %.2f\n", result);
                save_history("Square Perimeter", result);
                break;
            case 3:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = sqr_area_1(a);
                printf("Area: %.2f\n", result);
                save_history("Square Area (side)", result);
                break;
            case 4:
                printf("Enter diagonal: ");
                scanf("%lf", &d);
                result = sqr_area_2(d);
                printf("Area: %.2f\n", result);
                save_history("Square Area (diagonal)", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void rectangle_menu() {
    int choice;
    double a, b, d, h, angle, result;
    while(1) {
        printf("\n=== RECTANGLE ===\n");
        printf("1. Perimeter\n");
        printf("2. Diagonal\n");
        printf("3. Area (sides)\n");
        printf("4. Area (diagonal x angle)\n");
        printf("5. Area (diagonal x height)\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a, b: ");
                scanf("%lf %lf", &a, &b);
                result = rec_per(a, b);
                printf("Perimeter: %.2f\n", result);
                save_history("Rectangle Perimeter", result);
                break;
            case 2:
                printf("Enter a, b: ");
                scanf("%lf %lf", &a, &b);
                result = rec_diagonal(a, b);
                printf("Diagonal: %.2f\n", result);
                save_history("Rectangle Diagonal", result);
                break;
            case 3:
                printf("Enter a, b: ");
                scanf("%lf %lf", &a, &b);
                result = rec_area_1(a, b);
                printf("Area: %.2f\n", result);
                save_history("Rectangle Area (sides)", result);
                break;
            case 4:
                printf("Enter diagonal and angle (degrees): ");
                scanf("%lf %lf", &d, &angle);
                result = rec_area_2(d, angle);
                printf("Area: %.2f\n", result);
                save_history("Rectangle Area (diagonal x angle)", result);
                break;
            case 5:
                printf("Enter diagonal and height: ");
                scanf("%lf %lf", &d, &h);
                result = rec_area_3(d, h);
                printf("Area: %.2f\n", result);
                save_history("Rectangle Area (diagonal x height)", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void rhombus_menu() {
    int choice;
    double a, d, d1, d2, h, angle, A, result;
    while(1) {
        printf("\n=== RHOMBUS ===\n");
        printf("1. Perimeter\n");
        printf("2. Diagonal 1 (by area and diagonal)\n");
        printf("3. Diagonal 2 (by side and other diagonal)\n");
        printf("4. Diagonal 3 (by side and angle)\n");
        printf("5. Height\n");
        printf("6. Area (side x height)\n");
        printf("7. Area (diagonals)\n");
        printf("8. Area (side x angle)\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = rhomb_per(a);
                printf("Perimeter: %.2f\n", result);
                save_history("Rhombus Perimeter", result);
                break;
            case 2:
                printf("Enter area and diagonal: ");
                scanf("%lf %lf", &A, &d);
                result = rhomb_diagonal_1(A, d);
                printf("Diagonal: %.2f\n", result);
                save_history("Rhombus Diagonal 1", result);
                break;
            case 3:
                printf("Enter side and other diagonal: ");
                scanf("%lf %lf", &a, &d);
                result = rhomb_diagonal_2(a, d);
                printf("Diagonal: %.2f\n", result);
                save_history("Rhombus Diagonal 2", result);
                break;
            case 4:
                printf("Enter side and angle (degrees): ");
                scanf("%lf %lf", &a, &angle);
                result = rhomb_diagonal_3(a, angle);
                printf("Diagonal: %.2f\n", result);
                save_history("Rhombus Diagonal 3", result);
                break;
            case 5:
                printf("Enter side and angle (degrees): ");
                scanf("%lf %lf", &a, &angle);
                result = rhomb_height(a, angle);
                printf("Height: %.2f\n", result);
                save_history("Rhombus Height", result);
                break;
            case 6:
                printf("Enter side and height: ");
                scanf("%lf %lf", &a, &h);
                result = rhomb_area_1(a, h);
                printf("Area: %.2f\n", result);
                save_history("Rhombus Area (side x height)", result);
                break;
            case 7:
                printf("Enter d1 and d2: ");
                scanf("%lf %lf", &d1, &d2);
                result = rhomb_area_2(d1, d2);
                printf("Area: %.2f\n", result);
                save_history("Rhombus Area (diagonals)", result);
                break;
            case 8:
                printf("Enter side and angle (degrees): ");
                scanf("%lf %lf", &a, &angle);
                result = rhomb_area_3(a, angle);
                printf("Area: %.2f\n", result);
                save_history("Rhombus Area (side x angle)", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void paralelogram_menu() {
    int choice;
    double a, b, h, angle, d_curr, result;
    while(1) {
        printf("\n=== PARALLELOGRAM ===\n");
        printf("1. Perimeter\n");
        printf("2. Diagonal 1\n");
        printf("3. Diagonal 2\n");
        printf("4. Area (diagonals x angle)\n");
        printf("5. Area (sides x angle)\n");
        printf("6. Area (side x height)\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a, b: ");
                scanf("%lf %lf", &a, &b);
                result = par_per(a, b);
                printf("Perimeter: %.2f\n", result);
                save_history("Parallelogram Perimeter", result);
                break;
            case 2:
                printf("Enter a, b and angle (degrees): ");
                scanf("%lf %lf %lf", &a, &b, &angle);
                result = par_diagonal_1(a, b, angle);
                printf("Diagonal: %.2f\n", result);
                save_history("Parallelogram Diagonal 1", result);
                break;
            case 3:
                printf("Enter a, b and first diagonal: ");
                scanf("%lf %lf %lf", &a, &b, &d_curr);
                result = par_diagonal_2(a, b, d_curr);
                printf("Diagonal: %.2f\n", result);
                save_history("Parallelogram Diagonal 2", result);
                break;
            case 4:
                printf("Enter d1, d2 and angle (degrees): ");
                scanf("%lf %lf %lf", &a, &b, &angle);
                result = par_area_1(a, b, angle);
                printf("Area: %.2f\n", result);
                save_history("Parallelogram Area (diagonals x angle)", result);
                break;
            case 5:
                printf("Enter a, b and angle (degrees): ");
                scanf("%lf %lf %lf", &a, &b, &angle);
                result = par_area_2(a, b, angle);
                printf("Area: %.2f\n", result);
                save_history("Parallelogram Area (sides x angle)", result);
                break;
            case 6:
                printf("Enter side and height: ");
                scanf("%lf %lf", &a, &h);
                result = par_area_3(a, h);
                printf("Area: %.2f\n", result);
                save_history("Parallelogram Area (side x height)", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void trapesoid_menu() {
    int choice;
    double a, b, c, h, angle, result;
    while(1) {
        printf("\n=== TRAPEZOID ===\n");
        printf("1. Midline\n");
        printf("2. Perimeter\n");
        printf("3. Height\n");
        printf("4. Area (midline x height)\n");
        printf("5. Area (sides x angle)\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a, b: ");
                scanf("%lf %lf", &a, &b);
                result = midline(a, b);
                printf("Midline: %.2f\n", result);
                save_history("Trapezoid Midline", result);
                break;
            case 2:
                printf("Enter a, b, c (parallel sides + leg): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                result = trap_per(a, b, c);
                printf("Perimeter: %.2f\n", result);
                save_history("Trapezoid Perimeter", result);
                break;
            case 3:
                printf("Enter leg and angle (degrees): ");
                scanf("%lf %lf", &c, &angle);
                result = trap_height(c, angle);
                printf("Height: %.2f\n", result);
                save_history("Trapezoid Height", result);
                break;
            case 4:
                printf("Enter a, b, h: ");
                scanf("%lf %lf %lf", &a, &b, &h);
                result = trap_area_1(a, b, h);
                printf("Area: %.2f\n", result);
                save_history("Trapezoid Area (midline x height)", result);
                break;
            case 5:
                printf("Enter a, b, leg and angle (degrees): ");
                scanf("%lf %lf %lf %lf", &a, &b, &c, &angle);
                result = trap_area_2(a, b, c, angle);
                printf("Area: %.2f\n", result);
                save_history("Trapezoid Area (sides x angle)", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void cone_menu() {
    int choice;
    double r, h, l, R, result;
    while(1) {
        printf("\n=== CONE ===\n");
        printf("1. Slant height\n");
        printf("2. Lateral surface area\n");
        printf("3. Total surface area\n");
        printf("4. Volume\n");
        printf("5. Frustum slant height\n");
        printf("6. Frustum lateral area\n");
        printf("7. Frustum volume\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = slant_height(r, h);
                printf("Slant height: %.2f\n", result);
                save_history("Cone Slant Height", result);
                break;
            case 2:
                printf("Enter radius and slant height: ");
                scanf("%lf %lf", &r, &l);
                result = cone_later_area(r, l);
                printf("Lateral area: %.2f\n", result);
                save_history("Cone Lateral Area", result);
                break;
            case 3:
                printf("Enter radius and slant height: ");
                scanf("%lf %lf", &r, &l);
                result = cone_total_area(r, l);
                printf("Total area: %.2f\n", result);
                save_history("Cone Total Area", result);
                break;
            case 4:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = cone_volume(r, h);
                printf("Volume: %.2f\n", result);
                save_history("Cone Volume", result);
                break;
            case 5:
                printf("Enter small r, big R and height: ");
                scanf("%lf %lf %lf", &r, &R, &h);
                result = frustum_slant_height(r, R, h);
                printf("Frustum slant height: %.2f\n", result);
                save_history("Frustum Slant Height", result);
                break;
            case 6:
                printf("Enter small r, big R and slant height: ");
                scanf("%lf %lf %lf", &r, &R, &l);
                result = frustum_later_area(r, R, l);
                printf("Frustum lateral area: %.2f\n", result);
                save_history("Frustum Lateral Area", result);
                break;
            case 7:
                printf("Enter small r, big R and height: ");
                scanf("%lf %lf %lf", &r, &R, &h);
                result = frustum_volume(r, R, h);
                printf("Frustum volume: %.2f\n", result);
                save_history("Frustum Volume", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void cube_menu() {
    int choice;
    double a, result;
    while(1) {
        printf("\n=== CUBE ===\n");
        printf("1. Volume\n");
        printf("2. Total surface area\n");
        printf("3. Lateral surface area\n");
        printf("4. Space diagonal\n");
        printf("5. Face diagonal\n");
        printf("6. Perimeter\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = cube_volume(a);
                printf("Volume: %.2f\n", result);
                save_history("Cube Volume", result);
                break;
            case 2:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = cube_total_area(a);
                printf("Total area: %.2f\n", result);
                save_history("Cube Total Area", result);
                break;
            case 3:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = cube_later_area(a);
                printf("Lateral area: %.2f\n", result);
                save_history("Cube Lateral Area", result);
                break;
            case 4:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = diagonal_own(a);
                printf("Space diagonal: %.2f\n", result);
                save_history("Cube Space Diagonal", result);
                break;
            case 5:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = diagonal_face(a);
                printf("Face diagonal: %.2f\n", result);
                save_history("Cube Face Diagonal", result);
                break;
            case 6:
                printf("Enter side: ");
                scanf("%lf", &a);
                result = cube_per(a);
                printf("Perimeter: %.2f\n", result);
                save_history("Cube Perimeter", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void cylinder_menu() {
    int choice;
    double r, h, h_mid, h_min, h_max, result;
    while(1) {
        printf("\n=== CYLINDER ===\n");
        printf("1. Lateral surface area\n");
        printf("2. Total surface area\n");
        printf("3. Volume\n");
        printf("4. Diagonal\n");
        printf("5. Axial section area\n");
        printf("6. Axial section perimeter\n");
        printf("7. Oblique volume\n");
        printf("8. Oblique lateral area\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = cylin_later_area(r, h);
                printf("Lateral area: %.2f\n", result);
                save_history("Cylinder Lateral Area", result);
                break;
            case 2:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = cylin_total_area(r, h);
                printf("Total area: %.2f\n", result);
                save_history("Cylinder Total Area", result);
                break;
            case 3:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = cylin_volume(r, h);
                printf("Volume: %.2f\n", result);
                save_history("Cylinder Volume", result);
                break;
            case 4:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = cylin_diagonal(r, h);
                printf("Diagonal: %.2f\n", result);
                save_history("Cylinder Diagonal", result);
                break;
            case 5:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = axial_select_area(r, h);
                printf("Axial section area: %.2f\n", result);
                save_history("Cylinder Axial Section Area", result);
                break;
            case 6:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = axial_select_per(r, h);
                printf("Axial section perimeter: %.2f\n", result);
                save_history("Cylinder Axial Section Perimeter", result);
                break;
            case 7:
                printf("Enter radius and mid height: ");
                scanf("%lf %lf", &r, &h_mid);
                result = oblique_volume(r, h_mid);
                printf("Oblique volume: %.2f\n", result);
                save_history("Cylinder Oblique Volume", result);
                break;
            case 8:
                printf("Enter radius, min height and max height: ");
                scanf("%lf %lf %lf", &r, &h_min, &h_max);
                result = oblique_later_area(r, h_min, h_max);
                printf("Oblique lateral area: %.2f\n", result);
                save_history("Cylinder Oblique Lateral Area", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void sphere_menu() {
    int choice;
    double r, h, result;
    while(1) {
        printf("\n=== SPHERE ===\n");
        printf("1. Volume\n");
        printf("2. Surface area\n");
        printf("3. Diameter\n");
        printf("4. Great circle area\n");
        printf("5. Great circle perimeter\n");
        printf("6. Segment volume\n");
        printf("7. Segment area\n");
        printf("8. Sector volume\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = spher_volume(r);
                printf("Volume: %.2f\n", result);
                save_history("Sphere Volume", result);
                break;
            case 2:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = spher_area(r);
                printf("Surface area: %.2f\n", result);
                save_history("Sphere Surface Area", result);
                break;
            case 3:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = spher_diameter(r);
                printf("Diameter: %.2f\n", result);
                save_history("Sphere Diameter", result);
                break;
            case 4:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = big_circle_area(r);
                printf("Great circle area: %.2f\n", result);
                save_history("Sphere Great Circle Area", result);
                break;
            case 5:
                printf("Enter radius: ");
                scanf("%lf", &r);
                result = big_circle_per(r);
                printf("Great circle perimeter: %.2f\n", result);
                save_history("Sphere Great Circle Perimeter", result);
                break;
            case 6:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = segment_volume(r, h);
                printf("Segment volume: %.2f\n", result);
                save_history("Sphere Segment Volume", result);
                break;
            case 7:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = segment_area(r, h);
                printf("Segment area: %.2f\n", result);
                save_history("Sphere Segment Area", result);
                break;
            case 8:
                printf("Enter radius and height: ");
                scanf("%lf %lf", &r, &h);
                result = sector_volume(r, h);
                printf("Sector volume: %.2f\n", result);
                save_history("Sphere Sector Volume", result);
                break;
            case 0: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void show_history() {
    FILE* file = fopen("history.txt", "r");

    if (file == NULL) return;

    printf("\n======== HISTORY ========\n");
    char line[200];
    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}