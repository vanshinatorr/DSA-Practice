https://www.geeksforgeeks.org/problems/sum-of-digits1742/1
//solve in class 

class Solution {
  public:
  
  
  
int findfact(int n ){
      
      
      // base class 
      if ( n ==0 || n == 1 ) {
          return 1  ; 
          
      }
      
      
      
      return n * findfact(n-1) ; 
      
      
}
  
    int factorial(int n) {
        
        
   findfact(n) ; 
   
   return findfact(n); 
        
    }
};
