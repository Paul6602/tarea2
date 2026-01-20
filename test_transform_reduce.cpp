#include <iostream>
#include <vector>
#include <cmath>
#include "corenumeric.h"

// Requerimiento 8: Clase personalizada para el test
struct Esfera {
    double radio;

    // El concept 'Addable' requiere el operador '+'
    Esfera operator+(const Esfera& other) const {
        return { radio + other.radio };
    }
};

int main() {
    // --- CASOS QUE COMPILAN ---
    // --- CASO 1: Tipos fundamentales (int) ---
    // Multiplicamos cada número por 10 y sumamos el resultado
    std::vector<int> numeros = {1, 2, 3, 4};
    auto suma_por_diez = core_numeric::transform_reduce(numeros, [](int x) {
        return x * 10;
    });

    std::cout << "Transform Reduce : " << suma_por_diez << std::endl;
    // Resultado esperado: 100


    // --- CASO 2: Objetos de clase (Esfera) ---
    // Duplicamos el radio de cada esfera y las sumamos
    std::vector<Esfera> esferas = {{1.0}, {2.0}, {3.0}};
    auto resultado_esferas = core_numeric::transform_reduce(esferas, [](Esfera e) {
        return Esfera{ e.radio * 2 };
    });

    std::cout << "Transform Reduce : " << resultado_esferas.radio << std::endl;
    // Resultado esperado: 12.0 (2+4+6)


    // --- CASO QUE NO COMPILA  ---
    /*
    struct NoSumable { int val; };
    std::vector<NoSumable> v_err = {{1}, {2}};

    auto err = core_numeric::transform_reduce(v_err, [](NoSumable n) { return n; });
    // ERROR: El concept 'Addable' falla.
    // La clase 'NoSumable' no tiene definido el operador '+', por lo que no puede reducirse.
    */

    /*
    int no_iterable = 10;
    // auto err2 = core_numeric::transform_reduce(no_iterable, [](int x) { return x; });
    // ERROR: El tipo 'int' no cumple con el concept 'Iterable'.
    // No tiene métodos begin() ni end().
    */

    return 0;
}