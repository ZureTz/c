#include <math.h>
#include <stdio.h>

int main() {
  float a_length = 0, b_length = 0, c_length = 0;
  printf("请输入三角形的三条边 a, b, c 的长度 : ");
  scanf("%f,%f,%f", &a_length, &b_length, &c_length);

  if (!(a_length + b_length > c_length && a_length + c_length > b_length &&
        b_length + c_length > a_length)) {
    printf("该三边不符合构成三角形的条件\n");
    return -1;
  }

  const float s = 1.0 / 2 * (a_length + b_length + c_length);
  const float area =
      sqrtf(s * (s - a_length) * (s - b_length) * (s - c_length));

  printf("a = %7.2f, b = %7.2f, c = %7.2f\n", a_length, b_length, c_length);
  printf("s = %7.2f, area = %7.4f\n", s, area);

  return 0;
}