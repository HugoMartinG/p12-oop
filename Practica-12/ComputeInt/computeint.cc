#include<iostream>
using namespace std;

class ComputeInt{
    
    //Atributos
    private:
    int numero_;
    int numero2_;
    public:
    //Constructor de la clase
    ComputeInt(int numero, int numero2): numero_(numero), numero2_(numero2) {}

    //Getter del numero
    int GetNum() const{ return numero_; }

    //Metodo para el factorial
    int Factorial(){
        int res = 1;
        for (int i  = 1; i <= numero_; i++) res *= i;
        return res;
    }

    //Metodo para la suma en serie
    int SumSerie(){
        int res = 0;
        for (int i  = 0; i <= numero_; i++) res += i;
        return res;
    }

    //Metodo para saber si es primo.
    bool IsPrime() {
        if (numero_ == 0 || numero_ == 1 || numero_ == 4) return false;
        for (int i = 2; i < numero_ / 2; i++) {
            if (numero_ % i == 0) return false;
        }
        return true;
    }

    //Metodo para saber si un numero es primo perfecto
    //void AreRelativePrimes()
    //{
   //     if (__gcd(numero_, numero2_) == 1)
   //         cout << "Co-Prime" << endl;
   //     else
   //         cout << "Not Co-Prime" << endl;
   // }
};

int main(){
 ComputeInt computation(2, 3); 
  cout << computation.Factorial() << endl; 
  cout << computation.SumSerie() << endl; 
  cout << computation.IsPrime() << endl; 
  //cout << computation.AreRelativePrimes() << endl;
  return 0;

}