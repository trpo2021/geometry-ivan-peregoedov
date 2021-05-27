#include "ctest.h"
#include <libgeometry/function.h>
#include <math.h>
#include <stdio.h>

CTEST(check_circle, Correct)
{
    int n = 1;
    char figure[] = {"circle  (2 2, 3) \n"};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, Error_name)
{
    int n = 1;
    char figure[] = {"cicpg  (2 2, 3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_left_bracket)
{
    int n = 1;
    char figure[] = {"circle 2 2 , 3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 2;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_x)
{
    int n = 1;
    char figure[] = {"circle (k 2 , 3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 3;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_y)
{
    int n = 1;
    char figure[] = {"circle  (2 y, 3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 4;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_comma)
{
    int n = 1;
    char figure[] = {"circle  (2 2 3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 5;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_r)
{
    int n = 1;
    char figure[] = {"circle  (2 2, -3) "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 6;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, ERROR_right_bracket)
{
    int n = 1;
    char figure[] = {"circle  (2 2, 3 "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 7;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_circle, Error_EOF)
{
    int n = 1;
    char figure[] = {"circle  (2 9, 7)    end? "};
    char* point = figure;
    char* endPOINT = figure;
    circle_elements circle[n];

    int real = check_circle(point, endPOINT, figure, circle, n);

    int exp = 8;

    ASSERT_EQUAL(exp, real);
}

CTEST(calculations_circle, perimetr)
{
    circle_elements circle;
    circle.r = 2;

    double real = perimetr(circle);

    double exp = 12.56637;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(calculation_circle, area)
{
    circle_elements circle;
    circle.r = 2;

    double real = area(circle);

    double exp = 12.56637;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(calculation_circle, side_length)
{
    double x1, y1, x2, y2;
    x1 = 0;
    y1 = 0;
    x2 = 1;
    y2 = 2;
    double real = fabs(distance_between_points(x2, x1, y2, y1));

    double exp = 2.236;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(collisions, circle_collision)
{
    int n = 2;
    circle_elements circle[n];
    circle[0].x = 4;
    circle[0].y = 3;
    circle[0].r = 5;
    circle[1].x = 4;
    circle[1].y = 4;
    circle[1].r = 4;

    int real = intersection(circle[0], circle[1], n);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(collisions, Circle_not_collision)
{
    int n = 2;
    circle_elements circle[n];
    circle[0].x = 56;
    circle[0].y = 48;
    circle[0].r = 1;
    circle[1].x = 5;
    circle[1].y = 2;
    circle[1].r = 1;

    int real = intersection(circle[0], circle[1], n);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}
