#include <iostream>
using namespace std;
class Animal{
    public:
    Animal(){
        cout<<"Animal"<<endl;
    }
    void walk(){
        cout<<"Walking"<<endl;    
    }
};
class Tiger : virtual public Animal{
    public:
    Tiger(){
        cout<<"Tiger"<<endl;
    }
    void walk(){
        cout<<"Walking TIger"<<endl;    
    }
};
class Lion: virtual public Animal{
    public:
    Lion(){
        cout<<"Lion"<<endl;
    }
    void walk(){
        cout<<"Walking Lion"<<endl;    
    }
};
class Liger: public Tiger, public Lion{
    public:
    Liger(){
        cout<<"Liger"<<endl;
    }
    void walk(){
        cout<<"Walking Liger"<<endl;    
    }
};
int main() {
    Liger a;
    a.walk();
}
