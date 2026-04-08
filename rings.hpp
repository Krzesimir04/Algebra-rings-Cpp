#pragma once
#include <iostream>

template <int N>
class Ring{
    private:
        int x;

        static int gcd(unsigned int a, unsigned int b){
            int tmp;
            while(a > 0){
                tmp = a;
                a = b % a;
                b = tmp;
            }
            return b;
        }

        static int inverse(int y){
            if(gcd(y,N) != 1){
                throw "there is no inverse for that number in the ring.\n";
                return 0;
            }
            int y_cpy = y, N_cpy = N; 
            int a0 = 1, a1 = 0;
            int q, tmp_y, tmp_a;
            
            while (N_cpy != 0) {
                q = y_cpy / N_cpy;
                tmp_y = y_cpy;

                y_cpy = N_cpy;
                N_cpy = tmp_y % N_cpy;

                tmp_a = a0;

                a0 = a1;
                a1 = tmp_a - q * a1;
            }
                    
            int a = a0;
            while (a <= 0) {
                a += N;
            }
            return a%N;
        }
        static int inverse_for_sums(int y){
            return N-(y%N);
        }
    public:
        Ring(unsigned int x = 0){
            this->x = x % N;
        }
        
        int get(){
            return this->x;
        }
        int get_inverse(){
            return inverse(this->x);
        }
        int get_inverse_for_sums(){
            return inverse_for_sums(this->x);
        }
        
        Ring& operator =(const int new_x){
            this->x = (this->x = new_x % N);
            return *this;
        }
        Ring& operator +=(const Ring& other){
            this->x = ((this->x + other.x) % N);
            return *this;
        }
        Ring& operator -=(const Ring& other){
            this->x = (((this->x + Ring::inverse_for_sums(other.x))+N) % N);
            return *this;
        }
        Ring& operator *=(const Ring& other){
            this->x = (((this->x * other.x)) % N);
            return *this;
        }
        Ring& operator /=(const Ring& other){
            this->x = (((this->x * Ring::inverse(other.x))) % N);
            return *this;
        }

        Ring operator +(const Ring& other){
            return Ring((this->x + other.x) % N);
        }
        Ring operator -(const Ring& other){
            return Ring((this->x + Ring::inverse_for_sums(other.x)) % N);
        }
        Ring operator *(const Ring& other){
            return Ring((this->x * other.x) % N);
        }
        Ring operator /(const Ring& other){
            return Ring((this->x * Ring::inverse(other.x)) % N);
        }

        bool operator ==(const Ring& other){
            return ((this->x%N) == (other.x % N));
        }
        bool operator !=(const Ring& other){
            return ((this->x%N) != (other.x % N));
        }
        bool operator <(const Ring& other){
            return ((this->x%N) < (other.x % N));
        }
        bool operator >(const Ring& other){
            return ((this->x%N) > (other.x % N));
        }
        bool operator <=(const Ring& other){
            return ((this->x%N) <= (other.x % N));
        }
        bool operator >=(const Ring& other){
            return ((this->x%N) >= (other.x % N));
        }
        friend std::ostream& operator<<(std::ostream& os, const Ring& r) {
            return os << r.x;
        }
};

