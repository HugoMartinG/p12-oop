#include <iostream>

class Racional {
public:
    // Constructor por defecto
    Racional() : numerador(0), denominador(1) {}

    // Constructor parametrizado
    Racional(int numerador, int denominador) : numerador(numerador), denominador(denominador) {}

    // Métodos para escribir y leer un objeto de tipo Racional
    void escribir() const {
        std::cout << numerador << '/' << denominador << '\n';
    }

    void leer() {
        std::cin >> numerador >> denominador;
    }

    // Métodos para realizar operaciones con objetos de tipo Racional
    Racional sumar(const Racional& otro) const {
        int nuevo_numerador = numerador * otro.denominador + otro.numerador * denominador;
        int nuevo_denominador = denominador * otro.denominador;
        return Racional(nuevo_numerador, nuevo_denominador);
    }

    Racional restar(const Racional& otro) const {
        int nuevo_numerador = numerador * otro.denominador - otro.numerador * denominador;
        int nuevo_denominador = denominador * otro.denominador;
        return Racional(nuevo_numerador, nuevo_denominador);
    }

    Racional multiplicar(const Racional& otro) const {
        int nuevo_numerador = numerador * otro.numerador;
        int nuevo_denominador = denominador * otro.denominador;
        return Racional(nuevo_numerador, nuevo_denominador);
    }

    Racional dividir(const Racional& otro) const {
        int nuevo_numerador = numerador * otro.denominador;
        int nuevo_denominador = denominador * otro.numerador;
        return Racional(nuevo_numerador, nuevo_denominador);
    }

    // Método para comparar objetos de tipo Racional
    bool es_igual(const Racional& otro) const {
        return numerador == otro.numerador && denominador == otro.denominador;
    }

private:
    int numerador;
    int denominador;
};

int main() {
    // Crear dos objetos de tipo Racional
    Racional r1(1, 2);
    Racional r2(1, 3);
    return 0;
}