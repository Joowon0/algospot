#include <stdio.h>
#include <algorithm>

int main() {
  char stringin[1000000];
  int caseNum, start, end, temp, i, flag, check;
  
  scanf("%s %d", stringin, &caseNum);
  while(caseNum--) {
    scanf("%d %d", &start, &end);

    
    if (start > end) {
      std::swap(start, end);
      /*
      temp = start;
      start = end;
      end = temp;
      */
    }

    check = stringin[start];
    flag = 1;
    for (i = start+1; i <= end; i++) {
      if (check != stringin[i]) {
	flag = 0;
	break;
      }
    }
    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
