#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "Recomendador.h"

using namespace std;

int main() 
{

    Recomendador recomendador = Recomendador();
  

  ProductoNetflix pnet = ProductoNetflix();
  pnet.getSistema();

  ProductoPrime pprime = ProductoPrime();
  pprime.getSistema();

  ProductoDisney pdisney = ProductoDisney();
  pdisney.getSistema();
  return 0;
  
}
