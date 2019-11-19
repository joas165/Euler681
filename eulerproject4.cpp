#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <vector>    
#include <algorithm>    
 
    struct qualiteral
{
public:
int n = 6;
int a = 2;
int b = 2;
int c = 3;
int d = 3;

bool QuadliteralChecker(int a, int b, int c, int d) 
{
if(d < a + b + c)
    return true;
return false;
}

int IntSemiperimeter(int a, int b, int c, int d )
    {
    int y = a + b + c + d;
    if(y % 2 == 0) 
        return y/2; 
return 0;   
    } 

int SP()
    {    
        std::vector<int> possibilities (n*n*n*n);   
        int s = 0;
        for(int i = 1; i <= n; ++i)
            {
                for(int j=i; j <= n; ++j)    
                    {
                        for(int k=j; k <= n; ++k)
                        {
                            for(int l=k; l <= n; ++l)
                                 {
                                      
                                    if(IntAreaCyclic(i,j,k,l) <= n) 
                                        {
                                        if(QuadliteralChecker(i,j,k,l) == true && CyclicChecker(i,j,k,l) == false)
                                                   {
                                                    std::cout << i << j << k << l << "\n"; 
                                                   }                                           
                                        if(QuadliteralChecker(i,j,k,l) == true && CyclicChecker(i,j,k,l) == true)  
                                        {
                  
                                                    possibilities[s] = i + j + k + l;
                                                    ++s;
                                        }   
                                        else
                                        {
                                                    possibilities[s] = 0;
                                                    ++s;
                                        }
                                        }
                                    
                                    
                                
                                 }}}}  
        
    
        
        
        int y = 0;
        for(int i = 0; i < possibilities.size(); ++i)
            {
            y += possibilities[i];
            }
            
    return y;
    }
int IntCyclicSquaredArea(int a, int b, int c, int d)
{
    
    int s = IntSemiperimeter(a,b,c,d);
    if (s == 0)
        return 0;    
    return (s - a)*(s - b)*(s - c)*(s - d);


}
bool IsSquare(int a)
    {
        for(int i = 1; i <= a; ++i) 
        {       
            if(a == i*i)
                return true;
        } 
    return false;
    }



int IntAreaCyclic(int a, int b, int c, int d) 
{
    int y = IntCyclicSquaredArea(a,b,c,d);
    if(IsSquare(y) == true)
        return std::sqrt(y);
return n+1;
} 
bool CyclicChecker(int a, int b, int c, int d)
{
     //all possible cosines of angles
float a1 = a/b;  
float a2 = a/c;
float a3 = a/d;  // exactly 3 of these are valid for any order of sides a,b,c and d.
float b2 = b/c;  // we always divide by hypotenuse
float b3 = b/d;
float c3 = c/d;   

 //corresponding possible angles
float za1 = std::acos(a1);
float za2 = std::acos(a2);
float za3 = std::acos(a3);
float zb2 = std::acos(b2);
float zb3 = std::acos(b3);
float zc3 = std::acos(c3);

//corresponding tangets of angles
float ya1 = std::atan(a1);
float ya2 = std::atan(a2);
float ya3 = std::atan(a3);      // We will use arcustangent if the corresponding sides are equally great
float yb2 = std::atan(b2);
float yb3 = std::atan(b3);
float yc3 = std::atan(c3);



    
 const float PI = 2*std::acos(0.0);   
 // checking if opposite angles are complementary   
if(a < b && b < c && c < d)    
{
    if(std::abs(za1 + zc3 - PI) < 0.001 || std::abs(za2 + zb3 - PI) < 0.001 || std::abs(za3 + zb2 - PI) < 0.001) 
        
    {
        return true;
    }
    else
    {
        return false;
    }
}    
return true;
}
};
int main()
{
int n;
std::cout << "Give an positive integer \n";
std::cin >> n;
qualiteral q;
q.n = n;
std::cout << "SP(" << n << ") = " << q.SP() << ".\n";

return 0;

}
