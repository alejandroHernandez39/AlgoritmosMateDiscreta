#include "ServicioFactorizacionPrima.h"

vector<FactorPrimo> ServicioFactorizacionPrima::factorizar(long long numero) {
    vector<FactorPrimo> factores;
    for (long long i = 2; i * i <= numero; ++i) {
        int exponente = 0;
        while (numero % i == 0) {
            numero /= i;
            ++exponente;
        }
        if (exponente > 0) {
            factores.push_back(FactorPrimo(i, exponente));
        }
    }
    if (numero > 1) {
        factores.push_back(FactorPrimo(numero, 1));
    }
    return factores;
}

int ServicioFactorizacionPrima::divisores(const vector<FactorPrimo>& factores) {
    int totalDivisores = 1;
    for (const auto& factor : factores) {
        totalDivisores *= (factor.getExponente() + 1);
    }
    return totalDivisores;
}