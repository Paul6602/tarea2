#include <iostream>
#include "corenumeric.h"

int main() {
    // --- CASOS QUE COMPILAN ---
    auto s1 = core_numeric::sum_variadic(1, 2, 33, 4); // Enteros
    auto s2 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0); // Doubles
    
    std::cout << "Sum Variadic: " << s1 << std::endl;
    std::cout << "Mean Variadic: " << s2 << std::endl;

    // --- CASO QUE NO COMPILA ---
    /*
    auto s3 = core_numeric::sum_variadic("Hola", "Mundo");
    // ERROR: Falla el concept 'Addable' en los parámetros del pack Args...
    // const char* (strings literales) no se pueden sumar directamente con '+'.
    */

}