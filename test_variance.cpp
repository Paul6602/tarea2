#include <iostream>
#include <vector>
#include <string>
#include "corenumeric.h"

int main() {
    // --- CASO QUE COMPILA ---
    std::vector<double> data = {39.2, 48.8, 50.1, 37.6, 45.3};
    auto v = core_numeric::variance(data); // OK: double es Addable
    std::cout << "Variance: " << v << std::endl;

    // --- CASO QUE NO COMPILA ---
    /*
    std::vector<std::string> data_str = {"hola", "mundo", "c++"};
    auto v_err = core_numeric::variance(data_str);
    // ERROR: std::string no cumple los concepts Addable / Comparable requeridos.
    // No funciona ya que variance usa 'mean' y multiplicaciones que string no posee.
    */

}