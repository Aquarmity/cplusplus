#include <iostream>
#include <cmath>
using namespace std;

/*calculates, using A=P(1+r/n)^nt,
  how long it will take for you to have more money than Elon Musk,
  assuming a net worth of $264.6 billion
*/

int main() {
  float p, r, n;
  cout << "Starting amount: ";
  cin >> p;
  cout << endl << "rate (decimal): ";
  cin >> r;
  cout << endl << "times compounded per year: ";
  cin >> n;

  float a = 264600000000/p;
  r = 1 + (r/n);
  float t = (log10(a)/log10(r))/n;
  if (t < 0) {t = 0;}
  cout << "It will take you " << t << " years in order to become richer than Elon Musk.";

  return 0;
}

