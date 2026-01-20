#include <iostream>
#include <vector>
#include <string>
#include "corenumeric.h"

struct Vector2D {
    double x, y;
    // Requerido por sum (Addable) y mean (Divisible)
    Vector2D operator+(const Vector2D& other) const { return {x + other.x, y + other.y}; }
    Vector2D operator/(std::size_t n) const { return {x / n, y / n}; }
};

int main() {
    // --- CASOS QUE COMPILAN ---
    std::vector<double> v1 = {10.0, 20.0, 30.0};
    auto m1 = core_numeric::mean(v1); // OK: double es Divisible
    std::cout << "Mean double: " << m1 << std::endl;

    std::vector<Vector2D> v2 = {{0,0}, {10,10}};
    auto m2 = core_numeric::mean(v2); // OK: Vector2D tiene operator
    std::cout << "Mean Vector2D: (" << m2.x << "," << m2.y << ")" << std::endl;


    // --- CASO QUE NO COMPILA ---
    /*
    std::vector<std::string> v3 = {"A", "B"};
    auto m3 = core_numeric::mean(v3);
    // ERROR: Falla el concept 'Divisible'
    // std::string no soporta la operación division '/' por un size_t
    */
}