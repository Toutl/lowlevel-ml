#include <stdio.h>

int data[][2] = {
  {1, 3},
  {2, 4},
  {3, 2},
  {4, 6},
};

#define ssize sizeof(data) / sizeof(data[0])

float
sum(int var)
{
  float n = 0;
  for (int i = 0; i < ssize; i++)
  {
    n += df[i][var];
  }
  printf("%f\n", n);
  return n;
}

float
powr(float n)
{
  n *= n;
  return n;
}

float
sum_2(int var)
{
  float n = 0;
  for (int i = 0; i <= ssize; i++)
  {
    n += powr(df[i][var]);
  }
  printf("%f\n", n);
  return n;
}

float
sum_x_y(void)
{}

float
pendiente(int x, int y)
{
  float m;
  m = (ssize * 1/*suma x*y */) / (ssize * sum_2(x) - powr(sum(x)));
  return m;
}

float b(int x, int y)
{
  float b;
  b = (sum(y) - pendiente(1, 0) * sum(x)) / ssize;
  return b;
}

int main(void)
{
  printf("%f", pendiente(1, 0));
  printf("%f", b(1, 0));

  return 0;
}
