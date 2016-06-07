//
// Name : Joowon Byun
// Date : Jung 7th 2016
//
// morse code
// - : long code  (ascii 45)
// o : short code (ascii 111)
//
#include <stdio.h>

unsigned int composition(int n, int r) {
  int i;
  unsigned int result = n;

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

void dict(int As, int Bs, unsigned int nth) {
  int i, count, temp;
  unsigned int cases[300];

  if (nth == 1) {
    for (i = 0; i < As; i++)
      printf("a");
    for (i = 0; i < Bs; i++)
      printf("b");

    printf("\n");
    return;
  }

  // fill cases[]
  temp = As + Bs;
  for (i = As; i >= 0; i--) {
    cases[i] = composition(temp-1, Bs-1);
    temp--;
  }

  // sub nth position
  for(count = 0; count <= As; count++) {
    nth -= cases[count];

    if (nth <= 0) {
      nth += cases[count];
      break;
    }
  }

  // print 'till first B
  for (i = 0; i < As - count; i++)
    printf("a");
  printf("b");

  //do the rest
  dict(count, Bs-1, nth);
}

int main() {
  int numcases, As, Bs;
  unsigned int nth;

  scanf("%d", &numcases);

  while(numcases--) {
    scanf("%d %d %u", &As, &Bs, &nth);

    if(composition(As + Bs, Bs) < nth)
      printf("NONE\n");
    else
      dict(As, Bs, nth);
  }
  
  return 0;
}
