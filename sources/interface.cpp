#include "../headers/interface.h"
#include <iostream>

void demanderlancement()
{
   int continuer = 1;
   int x=0, y=0, z=0, vx=0, vy=0, vz=0;
   while (continuer==1)
   {
      std::cout << "Quelles sont les coordonees du satellite? (x,y,z/vx,vy,vz)" << std::endl;
      std::cin >> x >> y >> z >> vx >> vy >> vz;
      std::cout << "Voulez-vous lancer un nouveau satellite (Y:1/N:0) " << std::endl;
      std::cin >> continuer;
   }

}
