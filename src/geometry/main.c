#include <ctype.h>
#include <libgeometry/function.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circle_elements {
  double x;
  double y;
  double r;
} circle;

int main() {
  char figure[100];
  char *test_point = figure;
  char *point = figure;

  fgets(figure, sizeof(figure), stdin);

  while (isalpha(*point) != 0)
    point++;

  if (strncasecmp(test_point, "circle", 6) == 0) {
    check_circle(point);
  } else {
    printf("Excepted 'circle' \n");
  }
  return 0;
}
