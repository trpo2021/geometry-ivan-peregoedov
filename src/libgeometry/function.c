#include <ctype.h>
#include <libgeometry/function.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *check_symbol(char *point, char symbol) {
  while (*point != '\n') {
    if (*point == symbol) {
      point++;
      return point;
    }
    if (*point == ' ') {
      point++;
    } else {
      printf("Excepted '%c'\n", symbol);
      return 0;
    }
  }
  if (*point == '\n') {
    printf("Excepted '%c'\n", symbol);
    return 0;
  }
  return point;
}

char *check_digit(char *point, double *number) {
  char *end;
  while (isdigit(*point) == 0) {
    if (*point == ' ') {
      point++;

    } else if (*point == '-') {
      point++;

      if (*point == '-') {
        printf("an extra minus\n");
        exit(0);
      }
    } else {
      (printf("Excpected one or more elements of circle\n"));
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

char *check_end(char *point) {
  while (*point != '\n') {
    if (*point != ' ') {
      printf("Excepted stop\n");
      return 0;
    }
    point++;
  }
  return point;
}
struct circle_elements {
  double x;
  double y;
  double r;
} circle;
char *check_circle(char *point) {
  if ((point = check_symbol(point, '(')) == 0) {
    return 0;
  }

  if ((point = check_digit(point, &circle.x)) == 0) {
    return 0;
  }
  if ((point = check_digit(point, &circle.y)) == 0) {
    return 0;
  }
  if ((point = check_symbol(point, ',')) == 0) {
    return 0;
  }
  if ((point = check_digit(point, &circle.r)) == 0) {
    return 0;
  }
  if ((point = check_symbol(point, ')')) == 0) {
    return 0;
  }
  if (check_end(point) == 0) {
    return 0;
  }
  return point;
}
