//#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main () {
  int cases, i;
  string names[8];
  int scores[8][3];
  int myteam;
  string playteam;
  float winRate[8];
  int biggerTeams;

  cin >> cases;

  while(cases--) {
    for(i = 0; i< 8; i++) {
      cin >> names[i] >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }
    
    cin >> playteam;
    for(i = 0; i< 8; i++) {
      if (playteam == names[i]) {
	myteam = i;
        break;
      }
    }

    cin >> i;
    i *= 2;
    while(i--) {
      cin >> playteam;
      if (playteam == names[myteam]) {
	scores[myteam][0]++;
      }
      else {
	for(int j = 0; j < 8; j++) {
	  if (playteam == names[j]) {
	    scores[j][2]++;
	    break;
	  }
	}
      }
    }

    winRate[myteam] = (float) scores[myteam][0] / (scores[myteam][0]+scores[myteam][1]+scores[myteam][2]);
    biggerTeams = 0;
    for(i = 0; i < 8; i++) {
      winRate[i] =  (float) scores[i][0] / (scores[i][0]+scores[i][1]+scores[i][2]);

      if (winRate[i] > winRate[myteam]) {
	biggerTeams++;
      }
      
    }

    if (biggerTeams < 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    /*
    for(i = 0; i< 8; i++) {
      cout << names[i] << " " << scores[i][0] << " "  <<
	scores[i][1] << " " << scores[i][2] << " " << winRate[i] << endl;
    }
    cout << endl;
    */
  }
  return 0;
}
