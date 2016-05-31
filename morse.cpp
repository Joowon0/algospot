//
// Name : Joowon Byun
// Date : May 31th 2016
//
// morse code
// - : long code  (ascii 45)
// o : short code (ascii 111)
//
#include <stdio.h>

int composition(int n, int r) {
  int x = 1, y = 1, i;
  for (i = n; i > n-r; i--)
    x *= i;
  for (i = 1; i <= r; i++)
    y *= i;

  return x/y;
}


int main () {
  int numcases, longCode, shortCode, nth;
  int i, tempX, tempY, cases[100];
  
  scanf("%d", &numcases);

  while(numcases--) {
    scanf("%d %d %d", &longCode, &shortCode, &nth);
    //printf("%d %d %d %d\n", numcases, longCode, shortCode, nth);

    tempX = longCode+shortCode;
    for (i=longCode; i>=0; i--) {
      cases[i] = composition( tempX-1, shortCode-1);
      tempX--;
      //printf("%d\n",cases[i]);
    }

    for (i = 0; i <= longCode; i++)
      printf("%d ", cases[i]);
    printf("\n");
  }
  return 0;
}
