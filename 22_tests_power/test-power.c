#include <stdlib.h>
#include <stdio.h>

unsigned power(unsigned x, unsigned y);

int main (){
       
      if(power(0,0)!=1){
	exit(EXIT_FAILURE);
      };
             
      if(power(0,1)!=0){
	exit(EXIT_FAILURE);
      };
        	     
      if(power(1,0)!=1){
	exit(EXIT_FAILURE);
      };
      
      if(power(1,1)!=1){
	exit(EXIT_FAILURE);
      };
       	     
      if(power(-1,1)!=-1){
	exit(EXIT_FAILURE);	
      };
           
      if(power('a',2)!=9409){
	exit(EXIT_FAILURE);
      };
 
      return EXIT_SUCCESS; 
}
