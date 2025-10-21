#include <stdio.h>

int main() {
  // 输入年月日
  int year, month, day;
  scanf("%d.%d.%d", &year, &month, &day);

  // Zeller公式计算星期几

  // the day of the month
  int dayOfMonth = day;

  // month (3 = March, 4 = April, 5 = May, ..., 14 = February)
  int convertedMonth = month;
  if (convertedMonth < 3) {
    convertedMonth += 12;
  }

  // int adjustedYear = getAdjustedYear(year, month);
  int adjustedYear = year;
  if (month < 3) {
    adjustedYear -= 1;
  }

  int yearOfCentury = adjustedYear % 100;

  // Zero-based century (actually ⌊ adjustedYear/100 ⌋)
  int zeroBasedCentury = adjustedYear / 100;

  int week =
      (dayOfMonth + (13 * (convertedMonth + 1)) / 5 + yearOfCentury +
       yearOfCentury / 4 + zeroBasedCentury / 4 - 2 * zeroBasedCentury - 1) %
      7;

  // 避免负数结果
  if (week < 0) {
    week += 7;
  }

  // 输出结果
  // (0 = 星期日, 1 = 星期一, ..., 6 = 星期六)
  switch (week) {
  case 0:
    printf("星期日\n");
    break;
  case 1:
    printf("星期一\n");
    break;
  case 2:
    printf("星期二\n");
    break;
  case 3:
    printf("星期三\n");
    break;
  case 4:
    printf("星期四\n");
    break;
  case 5:
    printf("星期五\n");
    break;
  case 6:
    printf("星期六\n");
    break;
  default:
    break;
  }

  return 0;
}