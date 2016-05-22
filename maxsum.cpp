//
// Name : Joowon Byun
// Date : May 19th 2016
//
// maxsum.cpp
//
#include <stdio.h>

int main() {
  int caseNum, testcases, tempNum, max, tempsum;
  scanf("%d", &caseNum);
  //cin >> caseNum;

  while(caseNum--) {
    scanf("%d", &testcases);

    tempsum = max = 0;
    for (int i = 0; i < testcases; i++) {
      scanf("%d",&tempNum);
      tempsum += tempNum;
      if (tempsum < 0) // if sum is less than 0
	tempsum = 0;
      if (tempsum > max)
	max = tempsum;
    }
    printf("%d\n", max);
  }
  return 0;
}
