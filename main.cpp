#include <iostream>
#include "puzzle.h"
#include <string>
#include<typeinfo>
using namespace std;

int main()
{

   cout<<"choices are : \n";
   cout<<"1. puzzle1 \n";
   cout<<"2. puzzle2 \n";
   cout<<"3. puzzle3 \n";

   cout<<"enter your choice :";
   string puzz;
   cin>>puzz;
   //if(typeid(puzz).name()=="Ss")
   if(puzz=="puzzle1" ||puzz=="puzzle2"||puzz=="puzzle3")
   gensuccesssors(puzz);
   else
    cout<<"wrong choice (enter only string) \n";

    return 0;
}
