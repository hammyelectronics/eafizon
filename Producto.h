#include <iostream>
using namespace std;

int idGeneral = 1000;

class Producto {
public:
  string nombre;
  string tipo;
  int id;
  int precio;
  int cantidad;
  bool disponibilidad;

  Producto(string n, string t, int c, int p) {
    nombre = n;
    tipo = t;
    cantidad = c;
    precio = p;
    id = idGeneral;
    idGeneral++;
    if (c > 0) {
      disponibilidad = true;
    } else {
      disponibilidad = false;
    }
  }

  virtual float calcular_pago(){
    float total=cantidad*precio;
    return total;
  }
};

// clase producto deportivo, derivada de producto
class Deportivo : public Producto {
public:
  Deportivo(string n, string t, int c, int p) : Producto(n, t, c, p) {}
  float calcular_pago(){
    float total=cantidad*precio;
    return total;
  }
};
// clase producto tecnologico, derivada de producto
class Tecnologico : public Producto {
public:
  Tecnologico(string n, string t, int c, int p) : Producto(n, t, c, p) {}
  float calcular_pago(){
    float total=cantidad*precio;
    return total;
  }
};

// producto extranjero con iva
class Extranjero: public Producto {
public:
  int impuesto;
  Extranjero(string n, string t, int c, int p, int impuesto): Producto(n, t, c, p){
    impuesto=impuesto;
  }
  float calcular_pago(){
    float total=cantidad*precio;
    total += total*(this->impuesto/100);
    return total;
  }
};