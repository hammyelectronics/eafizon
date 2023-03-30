#include "Producto.h"
#include <iostream>
using namespace std;

// clase nodo
class Node {
public:
  Producto *producto;
  Node *next = NULL;

  Node(string name, string tipo, int count, int price) {
    if (tipo == "deportivo") {
      producto = new Deportivo(name, tipo, count, price);
    } else if (tipo == "tecnologico") {
      producto = new Tecnologico(name, tipo, count, price);
    }
  }
  Node(string name, string tipo, int count, int price, int impuesto){
    producto= new Extranjero(name,tipo,count, price,impuesto);
  }
};