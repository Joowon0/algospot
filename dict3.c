//
// Name : Joowon Byun
// Date : Jung 7th 2016
//
// morse code
// - : long code  (ascii 45)
// o : short code (ascii 111)
//
#include <stdio.h>

unsigned composition(int n, int r) {
  int i;
  int result = n;

  if (r < 0 || n < 0)
    return 0;
  else if (r > n)
    return 0;
  else if (r == 0 || r == n)
    return 1;
  
  if ( r * 2 > n)
    r = n - r; //reduce by half
  for (i = 2; i <= r; ++i) {
    result *= (n-i+1);
    result /= i;
  }

  return result;
}

void dict(int As, int Bs, int nth) {
  int i, totalHalf;

  if (nth == 1) {
    for (i = 0; i < As; i++)
      printf("a");
    for (i = 0; i < Bs; i++)
      printf("b");

    printf("\n");
    return;
  }

  totalHalf = composition(As + Bs - 1, Bs);
  if (nth <= totalHalf) {
    printf("a");
    return dict(As-1, Bs, nth);
  }
  else {
    printf("b");
    return dict(As, Bs-1, nth - totalHalf);
  }
}

int main() {
  int numcases, As, Bs, nth;

  scanf("%d", &numcases);

  while(numcases--) {
    scanf("%d %d %d", &As, &Bs, &nth);

    if(composition(As + Bs, Bs) < nth)
      printf("NONE\n");
    else
      dict(As, Bs, nth);
  }
  
  return 0;
}
