#include <iostream>
#include <vector>
#include <string>
#include "corenumeric.h"

// Clase para probar objetos (Requerimiento 8)
struct Vector3D {
    double x, y, z;
    // Para cumplir con Numeric (Addable, Multipliable, Comparable)
    Vector3D operator+(const Vector3D& other) const { return {x+other.x, y+other.y, z+other.z}; }
    Vector3D operator*(const Vector3D& other) const { return {x*other.x, y*other.y, z*other.z}; }
    bool operator<(const Vector3D& other) const {
        return (x*x + y*y + z*z) < (other.x*other.x + other.y*other.y + other.z*other.z);
    }
};

int main() {
    // --- CASO VÁLIDO ---
    std::vector<int> v_int = {10, 50, 30};
    std::cout << "Max int: " << core_numeric::max(v_int) << std::endl; // Debe compilar

    std::vector<Vector3D> v_vec = {{1,1,1}, {5,5,5}};
    auto m_vec = core_numeric::max(v_vec); // Debe compilar al ser Numeric

    // --- CASO INVÁLIDO ---
    /*
    std::vector<std::string> data = {"a", "b", "c"};
    auto v = core_numeric::max(data);
    // ERROR: std::string no cumple con el concept 'Numeric'
    // Específicamente, no cumple 'Multipliable' porque no tiene operador '*' definido.
    */

}