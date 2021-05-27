#include <ctype.h>
#include <libgeometry/function.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* figure_call(char* point, char* endPOINT, char* figure)
{
    char figure_check[6] = "circle";
    while (isalpha(*endPOINT) != 0)
        endPOINT++;
    if ((endPOINT - point) <= 6) {
        if (strncasecmp(figure, figure_check, 6) == 0) {
            point = endPOINT;

            return point;
        } else if (strncasecmp(figure, figure_check, 6) == 0) {
            return endPOINT;
        }
    } else if (strncasecmp(figure, figure_check, endPOINT - point) == 0) {
        point = endPOINT;
        return point;
    }

    return NULL;
}

char* check_symbol(char* point, char symbol)
{
    while (*point != '\n') {
        if (*point == symbol) {
            point++;
            return point;
        }
        if (*point == ' ') {
            point++;
        } else {
            return NULL;
        }
    }
    return NULL;
}

char* check_coord(char* point, double* number)
{
    char* end;
    while (isdigit(*point) == 0) {
        if (*point == ' ') {
            point++;

        } else if (*point == '-') {
            point++;

            if (isdigit(*point) != 0) {
                *number = strtod(point, &end);
                point = end;
                *number = *number * (-1);
                return point;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (isdigit(*point) != 0) {
        *number = strtod(point, &end);
        point = end;
        return point;
    }
    return point;
}

double save(double* number, double save_num)
{
    save_num = *number;
    return save_num;
}

double perimetr(circle_elements circle)
{
    return 2 * M_PI * circle.r;
}

double area(circle_elements circle)
{
    return M_PI * circle.r * circle.r;
}

char* check_rad(char* point, double* number)
{
    char* end;
    while (isdigit(*point) == 0) {
        if (*point == ' ') {
            point++;

        } else if (*point == '-') {
            return 0;
        }

        else {
            return 0;
        }
    }

    if (isdigit(*point) != 0) {
        *number = strtod(point, &end);
        point = end;

        return point;
    }
    return point;
}

char* check_end(char* point)
{
    while (*point != '\n') {
        if (*point != ' ') {
            printf("Excepted stop\n");
            return 0;
        }
        point++;
    }
    return point;
}

double number;

int check_circle(
        char* point,
        char* endPOINT,
        char* figure,
        circle_elements* circle,
        int n)
{
    if ((point = figure_call(point, endPOINT, figure)) == NULL) {
        return 1;
    }
    if ((point = check_symbol(point, '(')) == NULL) {
        return 2;
    }
    if ((point = check_coord(point, &number)) == 0) {
        return 3;
    }
    circle[n].x = number;

    if ((point = check_coord(point, &number)) == 0) {
        return 4;
    }
    circle[n].y = number;

    if ((point = check_symbol(point, ',')) == 0) {
        return 5;
    }
    if ((point = check_rad(point, &number)) == 0) {
        return 6;
    }
    circle[n].r = number;

    if ((point = check_symbol(point, ')')) == 0) {
        return 7;
    }
    if (check_end(point) == 0) {
        return 8;
    }

    return 0;
}

double distance_between_points(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(y1 - x1, 2) + pow(y2 - x2, 2));
}

int intersection(circle_elements circle_i, circle_elements circle_j, int n)
{
    double lenght, sum_r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum_r = fabs(circle_i.r + circle_j.r);
                lenght = distance_between_points(
                        circle_j.x, circle_i.x, circle_j.y, circle_i.y);
                if (lenght <= sum_r)
                    return 1;
            }
        }
    }
    return 0;
}
