#include<iostream>
using namespace std;

class complex{
    private:
        float x;
        float y;
    public:
        // constructor
        complex(float x, float y=0){
             this->x = x;
             this->y = y;
             }
             // default constructor
         complex(){}
         //copy constructor
         complex(complex &c){
             this->x = c.x;
             this->y = c.y;
             }
	 
        friend istream& operator >>(istream& , complex&);
        friend ostream& operator <<(ostream& , complex);

        friend complex operator +(complex, complex);
     
        friend complex operator *(complex, complex);
        };
        
        complex operator +(complex d, complex c){
            return complex(c.x + d.x ,  c.y + d.y);
                } 

        complex operator *(complex c, complex d){
             return complex(c.x*d.x - c.y*d.y, d.x*c.y + d.y*c.x);
             } 

           

        istream& operator >>(istream& cin, complex& c){
            return cin>>c.x>>c.y;
        }    
        ostream& operator <<(ostream& cout, complex c){
            return cout<<c.x<<" "<<c.y;
        }
            
int main(){
    complex c1(1,2), c2(2,3), c3,c4, c6(1);
    cout << "enter data: ";
    cin >> c1;
    c4 = c1*c2;
    c3 = 1+c4*5;
    
    cout<<c3;
    
    }
    