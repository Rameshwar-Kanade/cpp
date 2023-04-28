//pow() function available is used to calculate the power of a number without actually knowing which algorithm function uses to calculate the power. Thus, we can say that header files hides all the implementation details from the user.


#include <iostream>  
#include<math.h>  
using namespace std;  
int main()  
{    
 int n = 4;  
   int power = 3;  
   int result = pow(n,power);         // pow(n,power) is the  power function  
   std::cout << "Cube of n is : " <<result<< std::endl;  
   return 0;  
}  