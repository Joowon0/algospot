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

  //get case num
  cin >> cases;

  while(cases--) {
    //get input
    for(i = 0; i< 8; i++) {
      cin >> names[i] >> scores[i][0] >> scores[i][1] >> scores[i][2];
    }

    //get myteam name
    cin >> playteam;
    for(i = 0; i< 8; i++) { // fint myteam place
      if (playteam == names[i]) {
	myteam = i;
        break;
      }
    }

    //get left play nums
    cin >> i;
    i *= 2; // 'case there's 2 for each play
    while(i--) {
      cin >> playteam;
      if (playteam == names[myteam]) { // if my team, wins
	scores[myteam][0]++;
      }
      else { // if not myteam, lose (or draw)
	for(int j = 0; j < 8; j++) {
	  if (playteam == names[j]) {
	    scores[j][2]++;
	    break;
	  }
	}
      }
    }

    // calcul winRate
    winRate[myteam] = (float) scores[myteam][0] / (scores[myteam][0]+scores[myteam][1]+scores[myteam][2]);
    biggerTeams = 0;
    for(i = 0; i < 8; i++) {
      winRate[i] =  (float) scores[i][0] / (scores[i][0]+scores[i][1]+scores[i][2]);
      if (winRate[i] > winRate[myteam]) { // if winRate is bigger than myteam
	biggerTeams++; 
      }
      
    }

    if (biggerTeams < 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    /*
    // this is for testing
    for(i = 0; i< 8; i++) {
      cout << names[i] << " " << scores[i][0] << " "  <<
	scores[i][1] << " " << scores[i][2] << " " << winRate[i] << endl;
    }
    cout << endl;
    */
  }
  return 0;
}
