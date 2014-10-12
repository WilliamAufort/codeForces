/**************************************\
|         A. Theatre Square            |
| time limit per test :2 seconds       |
| memory limit per test : 64 megabytes |
| input :standard input                |
| output :standard output              |
\**************************************/

/*

Theatre Square in the capital city of Berland has a rectangular shape with the size n × m
meters. On the occasion of the city's anniversary, a decision was taken to pave the
Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover
the surface larger than the Theatre Square, but the Square has to be covered. It's not
allowed to break the flagstones. The sides of flagstones should be parallel to the sides
of the Square.

Input

The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, 
m, a ≤ 109).

Output

Write the needed number of flagstones.

*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

// Convert string to int

long long int stringToInt( std::string word ) {
  long long int number ;
  std::istringstream(word) >> number ; 
  return number ;
}

int main ( int argc, char * argv[] ) {
  // read numbers 
  std::string ligne;
  getline(std::cin,ligne);
  std::istringstream iss(ligne);
  std::string mot;
  int compteur = 0 ;
  std::vector<long long int> datas ;
  while( iss >> mot ) {
      datas.push_back(stringToInt(mot));
      compteur++ ;
  }
  // need 3 numbers
  if (compteur != 3) { 
      std::cerr << " Not the good number of arguments : need n , m, a " << std::endl ;
      return -1  ;
  }
  long long int n = datas[0] ;
  long long int m = datas[1] ;
  long long int a = datas[2] ;
  // Calculations 
  std::cout << (((n-1)/a)+1)*(((m-1)/a)+1) << std::endl ;
  return 0 ;
}

  
  














