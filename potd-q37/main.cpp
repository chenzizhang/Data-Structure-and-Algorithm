#include <iostream>
#include "functions.h"
using namespace std;

int main() {


  // 1. does not check only number & short username
  cout << "1st function validUsername(std::string inputUser)" << endl;
  cout << validUsername("13") << endl;

  //2. does not check negative index
  cout << "2nd function arrayIndex(int idx)" << endl;
  for(int i = -3; i < 15; i++){
    cout << arrayIndex(i) << endl;
  }

  //3. ok
  cout << "3rd function countPrimes(int param)" << endl;
  // cout << countPrimes(-1) << endl;
  // cout << countPrimes(0) << endl;
  // cout << countPrimes(1) << endl;
  cout << countPrimes(17) << endl;
  cout << countPrimes(80) << endl;
  cout << countPrimes(100) << endl;
  // cout << countPrimes(101) << endl;

  //4.ok
  cout << "4th function factorial(int fact)" << endl;
  for(int i = 0; i < 13; i++){
    cout << factorial(i) << endl;
  }
  //5.ok
  cout << "5th function samesies(4, 4)" << endl;
  cout << samesies(-(INT_MAX/2), -(INT_MAX/2)) << endl;
  //6. -2147483648
  cout << "6th function absolutely(int y)" << endl;
  cout << absolutely(0) << endl;
  cout << absolutely(-2147483648) << endl;
  //7.ok
  cout << "7th int magnaCalca(int first, int second);" << endl;
  cout<< magnaCalca(-100,100) << endl;

  return 0;
}
