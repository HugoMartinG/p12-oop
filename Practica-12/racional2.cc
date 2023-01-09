#include <iostream>

using namespace std;

// Clase Racional para representar números racionales
class Racional {
  private:
    // Atributos privados para almacenar el numerador y el denominador
    int numerador;
    int denominador;

  public:
    // Constructor para inicializar el número racional con su numerador y denominador
    Racional(int numerador, int denominador) : numerador(numerador), denominador(denominador) {}

    // Método para obtener el numerador
    int getNumerador() {
        return numerador;
    }

    // Método para obtener el denominador
    int getDenominador() {
        return denominador;
    }

    // Método para simplificar el número racional
    void simplificar() {
        // Encontramos el máximo común divisor (mcd) entre el numerador y el denominador
        int mcd = 1;
        int menor = (numerador < denominador) ? numerador : denominador;
        for (int i = 2; i <= menor; i++) {
            if (numerador % i == 0 && denominador % i == 0) {
                mcd = i;
            }
        }

        // Dividimos el numerador y el denominador por el mcd para simplificar el número racional
        numerador /= mcd;
        denominador /= mcd;
    }

    // Sobrecarga del operador de suma para permitir la adición de dos números racionales
    Racional operator+(Racional otro) {
        // Calculamos el numerador y el denominador del resultado de la suma
        int nuevoNumerador = numerador * otro.denominador + otro.numerador * denominador;
        int nuevoDenominador = denominador * otro.denominador;

        // Creamos un nuevo objeto de la clase Racional para almacenar el resultado
        Racional resultado(nuevoNumerador, nuevoDenominador);

        // Simplificamos el resultado
        resultado.simplificar();

        return resultado;
    }

    // Sobrecarga del operador de resta para permitir la sustracción de dos números racionales
    Racional operator-(Racional otro) {
        // Calculamos el numerador y el denominador del resultado de la resta
        int nuevoNumerador = numerador * otro.denominador - otro.numerador * denominador;
        int nuevoDenominador = denominador * otro.denominador;

        // Creamos un nuevo objeto de la clase Racional para almacenar el resultado
        Racional resultado(nuevoNumerador, nuevoDenominador);

        // Simplificamos el resultado
        resultado.simplificar();

        return resultado;
    }
};

int main() {
    // Creamos dos números racionales
    Racional a(2, 3);
    Racional b(4, 5);

    // Mostramos los números racionales por pantalla
    cout << a.getNumerador() << "/" << a.getDenominador() << endl;
    cout << b.getNumerador() << "/" << b.getDenominador() << endl;

    // Realizamos una operación de suma y mostramos el resultado por pantalla
    Racional c = a + b;
    cout << c.getNumerador() << "/" << c.getDenominador() << endl;

    // Realizamos una operación de resta y mostramos el resultado por pantalla
    Racional d = a - b;
    cout << d.getNumerador() << "/" << d.getDenominador() << endl;

    return 0;
}
