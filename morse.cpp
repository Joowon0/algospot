//
// Name : Joowon Byun
// Date : May 31th 2016
//
// morse code
// - : long code
// o : short code
//
#include <stdio.h>

int main () {
  int numcases, longCode, shortCode, nth;
  scanf("%d", &numcases);

  while(numcases--) {
    scanf("%d %d %d", &longCode, &shortCode, &nth);

    
    printf("%d %d %d %d\n", numcases, longCode, shortCode, nth);
  }
  return 0;
}
