#include <iostream>
#include "rings.hpp"

int main(){
    std::cout<< "Test for ring (field) mod 7:\n";
    Ring<7> a = 5;
    Ring<7> b = 3;
    std::cout<< "Two numbers: \na = " << a << " and b = "<< b <<"\n";
    std::cout<< "a+b: " << (a + b) <<"\n";
    std::cout<< "a-b: " << (a - b) <<"\n";
    std::cout<< "b-a: " << (b - a) <<"\n";
    std::cout<< "a*b: " << (a * b) <<"\n";
    std::cout<< "a/b: " << (a / b) <<"\n";

    std::cout<< "a==b: " << (a == b) <<"\n";
    std::cout<< "a!=b: " << (a != b) <<"\n";
    std::cout<< "a>=b: " << (a >= b) <<"\n";
    std::cout<< "a<=b: " << (a <= b) <<"\n";
    std::cout<< "a<b: " << (a < b) <<"\n";
    std::cout<< "a>b: " << (a > b) <<"\n";

    std::cout<< "---------------------" <<"\n";

    std::cout<< "a+=b: " << (a += b) <<"\n";
    std::cout<< "new a: " << a <<"\n";
    std::cout<< "a-=b: " << (a -= b) <<"\n";
    std::cout<< "new a: " << a <<"\n";
    std::cout<< "a*=b: " << (a *= b) <<"\n";
    std::cout<< "new a: " << a <<"\n";
    std::cout<< "a/=b: " << (a /= b) <<"\n";
    std::cout<< "new a: " << a <<"\n";
    std::cout<< "a=b: " << (a = b) <<"\n";
    std::cout<< "new a: " << a <<"\n";
    std::cout<< "---------------------" <<"\n";

    std::cout<< "Test inversions" <<"\n";
    
    b = 1;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";

    b = 2;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";

    b = 3;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";

    b = 4;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";

    b = 5;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";
   
    b = 6;
    std::cout<< "b: " << b <<"\n";
    std::cout<< "b inversion: " << b.get_inverse() <<"\n";


    try{
        std::cout<< "Test for ring mod 10:\n";
        Ring<10> c = 3;
        Ring<10> d = 9;
        std::cout<< "Two numbers: \nc = " << c << " and d = "<< d <<"\n";
        std::cout<< "c+d: " << (c + d) <<"\n";
        std::cout<< "c-d: " << (c - d) <<"\n";
        std::cout<< "d-c: " << (d - c) <<"\n";
        std::cout<< "c*d: " << (c * d) <<"\n";
        std::cout<< "c/d: " << (c / d) <<"\n";
    }catch(char const* e){
        std::cout<<e;
    }
}