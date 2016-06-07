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

void morse(int longCode, int shortCode, int nth) {
  int i, tempX, count, cases[300];

  if ( nth == 1) {
    //printf("\nBase Case\n");
    for (i = 0; i < longCode; i++)
      printf("a");
      //printf("%c", 45);
    for (i = 0; i < shortCode; i++)
      printf("b");
    //printf("%c", 111);

    printf("\n");
    return;
  }

    
  tempX = longCode+shortCode;
  for (i=longCode; i>=0; i--) {
      cases[i] = composition( tempX-1, shortCode-1);
      tempX--;
      //printf("%d\n",cases[i]);
    }

  /*
    printf("\n");
    for (i = 0; i <= longCode; i++)
      printf("%d ", cases[i]);
    printf("\n");

  */
    for (count = 0; count <= longCode; count++) {
      nth -= cases[count];
      //printf("%d ", nth);
      
      if (nth <= 0) {
	nth += cases[count];
	break;
      }
    }
    //printf("%d %d\n\n", count, nth);


    for (i = 0; i < longCode - count; i++)
      printf("a");
      //printf("%c", 45);
    printf("b");
    //printf("%c", 111);

    morse(longCode-i, shortCode-1, nth);
}


int main () {
  int numcases, longCode, shortCode, nth;
  int i, tempX, count, cases[100];
  
  scanf("%d", &numcases);

  while(numcases--) {
    scanf("%d %d %d", &longCode, &shortCode, &nth);
    //printf("%d %d %d %d\n", numcases, longCode, shortCode, nth);

    morse(longCode, shortCode, nth);
  }
  return 0;
}
