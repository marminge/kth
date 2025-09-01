#include <stdbool.h>
#include <stdio.h>

typedef struct point {
  float x;
  float y;
} Point;

typedef struct rectangle {
  Point upper_left;
  Point lower_right;
} Rectangle;

float area(Rectangle r) {
  int width = r.lower_right.x - r.upper_left.x;
  int height = r.upper_left.y - r.lower_right.y;
  return width * height * 2;
}

Point center(Rectangle r) {
  float y = (r.upper_left.y + r.lower_right.y) / 2;
  float x = (r.upper_left.x + r.lower_right.x) / 2;
  Point p = {x, y};
  return p;
}

void move(Rectangle *r, float x, float y) {
  r->upper_left.x += x;
  r->upper_left.y += y;
  r->lower_right.x += x;
  r->lower_right.y += y;
}

bool determinePoint(Rectangle r, Point p) {
  return (p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
          p.y <= r.upper_left.y && p.y >= r.lower_right.y);
}

int main(void) {
  Point p1 = {1, 6};
  Point p2 = {4, 1};
  Rectangle r = {p1, p2};
  printf("%.1f\n", area(r));
  Point isTrue = {4, 6};
  Point isFalse = {1, 0.5};
  if (determinePoint(r, isTrue))
    printf("true\n");
  if (!determinePoint(r, isFalse))
    printf("false\n");
  Point p3 = center(r);
  printf("Center point before moving: %.1f,%.1f\n", p3.x, p3.y);
  move(&r, 2, -4);
  Point p4 = center(r);
  printf("Center point after moving: %.1f,%.1f\n", p4.x, p4.y);

  return 0;
}
