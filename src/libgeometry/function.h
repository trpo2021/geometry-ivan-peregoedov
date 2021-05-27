#pragma once

typedef struct {
    double x;
    double y;
    double r;
    double P;
    double A;
} circle_elements;

#define amount_cir 3

circle_elements circle[amount_cir];

char* figure_calling(char* point, char* endPOINT, char* figure);

char* check_symbol(char* point, char symbol);

char* check_coord(char* point, double* number);

double perimetr(circle_elements circle);

double area(circle_elements circle);

char* check_rad(char* point, double* number);

char* check_end(char* point);

int check_circle(
        char* point,
        char* endPOINT,
        char* figure,
        circle_elements* circle,
        int n);

double distance_between_points(double x1, double y1, double x2, double y2);

int intersection(circle_elements circle_i, circle_elements circle_j, int n);
