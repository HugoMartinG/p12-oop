#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Enumeración para representar las direcciones del robot
enum Direction {
  North,
  East,
  South,
  West
};

// Clase que representa al robot
class Robot {
  private:
    // Coordenadas x e y del robot
    int x, y;
    
    // Dirección actual del robot
    Direction direction;

  public:
    // Constructor que inicializa al robot en la posición (0, 0) mirando hacia el norte
    Robot() : x(0), y(0), direction(North) {}

    // Método para girar el robot a la derecha
    void turnRight() {
      direction = (Direction)((direction + 1) % 4);
    }

    // Método para girar el robot a la izquierda
    void turnLeft() {
      direction = (Direction)((direction + 3) % 4);
    }

    // Método para avanzar el robot
    void advance() {
      switch (direction) {
        case North:
          y++;
          break;
        case East:
          x++;
          break;
        case South:
          y--;
          break;
        case West:
          x--;
          break;
      }
      if (x > 10){
        cout << "Se ha salido del tablero, pruebe a ir en otra direccion." << endl;
        x--;
      }else if(y >10){
        cout << "Se ha salido del tablero, pruebe a ir en otra direccion." << endl;
        y--;
      }else if(x <-10){
        cout << "Se ha salido del tablero, pruebe a ir en otra direccion." << endl;
        x++;
      }else if(y < -10){
        cout << "Se ha salido del tablero, pruebe a ir en otra direccion." << endl;
        y++;
      }
    }

    // Método para obtener la posición actual del robot
    pair<int, int> getPosition() {
      return make_pair(x, y);
    }

    // Método para obtener la dirección actual del robot
    Direction getDirection() {
      return direction;
    }
};

int main() {
  // Creamos una instancia del robot
  Robot robot;

  //Creamos el menu de interaccion
  int numero;
  while(cin >>numero){
    cout << "Menu:" << endl;
   cout << "1.Girar a la derecha" << endl;
    cout << "2.Girar a la izquierda" << endl;
    cout << "3.Avanzar" << endl;
    
    switch (numero){
      case 1:
        robot.turnRight();
        break;
      case 2:
        robot.turnLeft();
        break;
      case 3:
        robot.advance();
        break;
    }

    // Obtenemos la posición final y dirección del robot
    pair<int, int> position = robot.getPosition();
   Direction direction = robot.getDirection();

    // Mostramos la posición final y dirección del robot
    cout << "El robot esta en la posicion (" << position.first << ", " << position.second << ") y mirando hacia el ";
    switch (direction) {
      case North:
       cout << "Norte." << endl;
       break;
      case East:
        cout << "Este." << endl;
        break;
      case South:
        cout << "Sur." << endl;
       break;
      case West:
        cout << "Oeste." << endl;
        break;
    }
    cout << "inserte su eleccion: ";
  } 
  return 0;
}