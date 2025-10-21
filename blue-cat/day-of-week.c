#include <stdio.h>

// Note:
//   In this algorithm January and February are counted as months 13 and 14 of
//   the previous year. E.g. if it is 2 February 2010 (02/02/2010 in
//   DD/MM/YYYY), the algorithm counts the date as the second day of the
//   fourteenth month of 2009 (02/14/2009 in DD/MM/YYYY format) So the adjusted
//   year above is:
//     adjYear = the actual year, for months from March to December.
//     adjYear = the previous year, for January and February.
int getAdjustedYear(int year, int month) {
  if (month < 3) {
    return year - 1;
  }
  return year;
}

int main() {
  // 输入年月日
  int year, month, day;
  scanf("%d.%d.%d", &year, &month, &day);

  // Zeller公式计算星期几

  // the day of the month
  const int dayOfMonth = day;

  // month (3 = March, 4 = April, 5 = May, ..., 14 = February)
  const int convertedMonth = (month < 3) ? month + 12 : month;

  const int adjustedYear = getAdjustedYear(year, month);
  const int yearOfCentury = adjustedYear % 100;

  // Zero-based century (actually ⌊ adjustedYear/100 ⌋)
  const int zeroBasedCentury = adjustedYear / 100;

  const int week =
      (dayOfMonth + (13 * (convertedMonth + 1)) / 5 + yearOfCentury +
       yearOfCentury / 4 + zeroBasedCentury / 4 - 2 * zeroBasedCentury) %
      7;
  // (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
  const char *days[] = {"星期六", "星期日", "星期一", "星期二",
                        "星期三", "星期四", "星期五"};

  // 输出结果
  printf("%s\n", days[week]);

  return 0;
}