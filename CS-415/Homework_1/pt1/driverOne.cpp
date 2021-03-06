#include <iostream>
#include <fstream>
#include "extendedNum.h"
#include <gmp.h>
#include <string>
#include <sstream> 

using namespace std;

int main (int argc, char *argv[])
{
  using namespace std; 
  
  if (argc != 2) 
    {
      cout << "Usage:" << argv[0] << "inputfile" << endl;
      return 1;
    }
  
  ifstream inFile (argv[1]);

  if (!inFile) 
    {
      cout << "Error opening input file: " << argv[1] << endl;
      return 1;
    }  

  

  mpz_t x,y,d,a,b;
  string a_temp, b_temp, d_temp;
  
  
  inFile >> a_temp;
  inFile >> b_temp;
  inFile >> d_temp;
  
  mpz_init_set_str(x, "0", 10);
  mpz_init_set_str(y, "1", 10);
  mpz_init_set_str(d, d_temp.c_str() , 10);
  mpz_init_set_str(a, a_temp.c_str() , 10);
  mpz_init_set_str(b, b_temp.c_str() , 10);
    

  eea(x,y,d,a,b);

  inFile.close();
  
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(d);
  mpz_clear(a);
  mpz_clear(b);
  
  return 0;
}
