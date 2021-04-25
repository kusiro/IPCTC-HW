#include <stdio.h>

int main() {
  double x, y;
  int z;
  scanf("%lf %lf %d", &x, &y, &z);
  if (z == 0)
  {
    printf("%d\n", (int)(x * y));
  } else if (z == 1)
  {
    printf("%.1lf\n", x * y);
  } else if (z == 2)
  {
    printf("%.2lf\n", x * y);
  }
  else if (z == 3)
  {
    printf("%.3lf\n", x * y);
  }
  else if (z == 4)
  {
    printf("%.4lf\n", x * y);
  }
  else if (z == 5)
  {
    printf("%.5lf\n", x * y);
  }
  else
  {
    printf("%.6lf\n", x * y);
  }
}