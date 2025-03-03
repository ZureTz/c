#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check(char T[], int lenT, char S[]) {
  int lenS = strlen(S);

  if (lenT == lenS) {
    if (strcmp(T, S) == 0)
      return true;
    for (int i = 0; i < lenT; i++) {
      if (T[i] != S[i]) {
        if (strcmp(&T[i + 1], &S[i + 1]) == 0)
          return true;
        else
          return false;
      }
    }
  } else if (lenT == lenS + 1) {
    for (int i = 0; i < lenS; i++) {
      if (T[i] != S[i]) {
        if (strcmp(&T[i + 1], &S[i]) == 0)
          return true;
        else
          return false;
      }
    }
    return true;
  } else if (lenT + 1 == lenS) {
    for (int i = 0; i < lenT; i++) {
      if (T[i] != S[i]) {
        if (strcmp(&T[i], &S[i + 1]) == 0)
          return true;
        else
          return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  int N;
  char T[500000 + 1] = {};
  if (scanf("%d %s", &N, T) != 2)
    return 1;

  int len = strlen(T);
  int cnt = 0;
  int num[500000] = {};
  char S[500000 + 1] = {};
  for (int i = 0; i < N; i++) {
    memset(S, '\0', strlen(S) + 1);
    if (scanf("%s", S) != 1)
      return 1;

    if (check(T, len, S)) {
      num[cnt] = i + 1;
      cnt++;
    }
  }

  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%d ", num[i]);
  }
  return 0;
}
