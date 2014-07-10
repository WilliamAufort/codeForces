/***************************************\
|            A. Winner                  |
| time limit per test : 1 second        |
| memory limit per test : 64 megabytes  |
| input : standard input                |
| output : standard output              |
\***************************************/

/*

The winner of the card game popular in Berland "Berlogging" is determined according to 
the following rules. If at the end of the game there is only one player with the maximum 
number of points, he is the winner. The situation becomes more difficult if the number of 
such players is more than one. During each round a player gains or loses a particular 
number of points. In the course of the game the number of points is registered in the 
line "name score", where name is a player's name, and score is the number of points 
gained in this round, which is an integer number. If score is negative, this means that 
the player has lost in the round. So, if two or more players have the maximum number of 
points (say, it equals to m) at the end of the game, than wins the one of them who scored 
at least m points first. Initially each player has 0 points. It's guaranteed that at the 
end of the game at least one player has a positive number of points.

Input

The first line contains an integer number n (1  ≤  n  ≤  1000), n is the number of rounds 
played. Then follow n lines, containing the information about the rounds in "name score" 
format in chronological order, where name is a string of lower-case Latin letters with 
the length from 1 to 32, and score is an integer number between -1000 and 1000, inclusive.

Output

Print the name of the winner.

*/


#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>

int stringToInt( std::string word ) {
  int number ;
  std::istringstream(word) >> number ; 
  return number ;
}

int getNumberPlayers (void) {
  std::string ligne;
  getline(std::cin,ligne);
  return stringToInt(ligne) ;
}

int main ( int argc, char * argv[] ) {
  std::freopen("input.txt","r",stdin); 
  int n = getNumberPlayers() ;
  int i ;
  std::string ligne;

  std::map<std::string,int> scores ;
  std::map<std::string,int>::iterator it ;
  for ( i = 0 ; i < n ; i++ ) {
      getline(std::cin,ligne);
      std::istringstream iss(ligne);
      std::string mot;
      iss >> mot ;
      std::string name = mot ;
      iss >> mot ;
      int score = stringToInt(mot);
      if (scores.find(name) != scores.end()) {
          scores[name] += score ;
          std::cout << name << " modifie : new score : " << scores[name] << std::endl ;
      }
      else {
          scores.insert(std::pair<std::string,int>(name,score)) ;
          std::cout << name << " insere : score : " << scores[name] << std::endl ;
      }
  }
  std::string winner = (scores.begin())->first ;
  int maxScore = (scores.begin())->second ;
  for ( it = scores.begin() ; it != scores.end() ; ++it ) {
      if ( it->second > maxScore ) {
          maxScore = it->second ;
          winner = it->first ;
      }
  }
  std::cout << winner <<  std::endl ;
  return 0 ;
}
  
      
  
