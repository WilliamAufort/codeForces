/***************************************\
|      C. Alice, Bob and Chocolate      |
| time limit per test : 2 seconds       | 
| memory limit per test : 64 megabytes  |
| input : standard input                |
| output : standard output              |
\***************************************/

/*

Alice and Bob like games. And now they are ready to start a new game.
They have placed n chocolate bars in a line. 
Alice starts to eat chocolate bars one by one from left to right, and Bob — from right to left.
For each chocololate bar the time, needed for the player to consume it, is known (Alice and Bob eat them with equal speed).
When the player consumes a chocolate bar, he immediately starts with another.
It is not allowed to eat two chocolate bars at the same time, to leave the bar unfinished and to make pauses.
If both players start to eat the same bar simultaneously, Bob leaves it to Alice as a true gentleman.

How many bars each of the players will consume?

Input :

The first line contains one integer n (1 ≤ n ≤ 105) — the amount of bars on the table. 
The second line contains a sequence t1, t2, ..., tn (1 ≤ ti ≤ 1000), where ti is the time (in seconds) needed
to consume the i-th bar (in the order from left to right).

Output :

Print two numbers a and b, where a is the amount of bars consumed by Alice, and b is the amount of bars consumed by Bob.

*/

#include <iostream>
#include <sstream>
#include <vector>


int stringToInt( std::string word ) {
  int number ;
  std::istringstream(word) >> number ; 
  return number ;
}

int getNumberBars (void) {
  std::string ligne;
  getline(std::cin,ligne);
  return stringToInt(ligne) ;
}

std::vector<int> getTimes (int nbBars) {
  std::string ligne, mot;
  std::vector<int> times;
  getline(std::cin,ligne);
  std::istringstream iss(ligne);
  for (int i = 0; i < nbBars; i++) {
    iss >> mot ;
    times.push_back(stringToInt(mot));
  }
  return times ;
}

int main (int argc, char * argv[]) {
  int nbBars = getNumberBars();
  std::vector<int> times = getTimes(nbBars);
  int alice = 0 ;
  int bob = nbBars-1;
  while ( bob - alice > 1) { 
    if (times[alice] < times[bob]) {
      times[bob] -= times[alice] ;
      alice++ ;
    }
    else if (times[alice] > times[bob]) {
      times[alice] -= times[bob] ;
      bob-- ;
    } 
    else {
      alice++ ;
      bob-- ;
    }
  }
  std::cout << alice+1 << " " << nbBars-alice-1 << std::endl ;
  return 0 ;
}

