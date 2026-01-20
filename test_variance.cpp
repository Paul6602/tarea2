#include <iostream>
#include <vector>
#include <string>
#include "corenumeric.h"

int main() {
    // --- CASO QUE COMPILA ---
    std::vector<double> data = {1.0, 2.0, 3.0};
    auto v = core_numeric::variance(data); // OK: double es Addable
    std::cout << "Variance: " << v << std::endl;

    // --- CASO QUE NO COMPILA ---
    /*
    std::vector<std::string> data_str = {"a", "b", "c"};
    auto v_err = core_numeric::variance(data_str);
    // ERROR: std::string no cumple los concepts Addable / Comparable requeridos.
    // No funciona ya que variance usa 'mean' y multiplicaciones que string no posee.
    */
}