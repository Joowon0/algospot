#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int num, wordlen;
  char word[80], outword[80];
  
  cin >> num;
  for (int i = 1; i <= num; i++) {
    int erasenum = 0;
    word[0] = 0;
    outword[0] = 0;
    
    cin >> erasenum;
    cin >> word;
    wordlen = strlen(word);
    
    if (word[0] == 0)
      outword[0] = 0;
    else if (strlen(word) > 0 ) {
      if(erasenum > 1)
	memmove( outword, word, erasenum-1);
      memmove( outword + erasenum - 1, word + erasenum, wordlen - erasenum);
      outword[wordlen-1] = 0;
    }
    else {
      memmove( outword, word, wordlen);
      outword[wordlen] = 0;
    }

    //cout << word << endl;
    cout << i << " " << outword << endl;
  }
  
  return 0;
}
