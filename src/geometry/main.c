#include <ctype.h>
#include <libgeometry/function.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define amount_cir 3

int main()
{
    int n = 0;
    char figure[100];
    char* endPOINT = figure;
    char* point = figure;
    circle_elements circle[amount_cir];
    int i, j;

    while (n != amount_cir) {
        fgets(figure, sizeof(figure), stdin);
        point = figure;
        endPOINT = figure;

        int search_ERROR = check_circle(point, endPOINT, figure, circle, n);

        if (search_ERROR == 0) {
            circle[n].P = perimetr(circle[n]);
            circle[n].A = area(circle[n]);

            n++;
        } else {
            switch (search_ERROR) {
            case 1:
                printf("Expected 'circle'\n");
                break;
            case 2:
                printf("Expected '('\n");
                break;
            case 3:
                printf("Expected x\n");
                break;
            case 4:
                printf("Expected y\n");
                break;
            case 5:
                printf("Expected ','\n");
                break;
            case 6:
                printf("Expected r\n");
                break;
            case 7:
                printf("Expected ')'\n");
                break;
            case 8:
                printf("Wrong end\n");
                break;
            }
        }
    }

    printf("\n\n");

    int check_intersections[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            check_intersections[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j)
                check_intersections[i][j]
                        = intersection(circle[i], circle[j], n);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d) circle(%f  %f, %f)\n",
               i + 1,
               circle[i].x,
               circle[i].y,
               circle[i].r);
        printf("Perimetr: %f\n", circle[i].P);
        printf("Area: %f\n", circle[i].A);
        for (j = 0; j < n; j++) {
            if (check_intersections[i][j] == 1)
                printf("\t %d. circle\n", j + 1);
        }
        printf("\n");
    }
    return 0;
}
