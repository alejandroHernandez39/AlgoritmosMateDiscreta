#include "ServicioEuclides.h"
#include <iostream>

ResultadoEuclides ServicioEuclides::calcular(long long a, long long b) {
    long long originalA = a;
    long long originalB = b;
    ResultadoEuclides resultado(0, 0);

    while (b != 0) {
        long long cociente = a / b;
        long long residuo = a % b;
        a = b;
        b = residuo;
    }

    long long mcd = a;
    long long mcm = (originalA * originalB) / mcd;
    resultado = ResultadoEuclides(mcd, mcm);

    return resultado;
}

ResultadoEuclides ServicioEuclides::calcular(int cantidad, const vector<long long> numeros) {
	if (cantidad <= 0 || numeros.empty()) {
		throw std::invalid_argument("La cantidad de numeros debe ser mayor que cero y el vector no debe estar vacio.");
	}
	long long mcd = numeros[0];
	long long mcm = numeros[0];
	for (int i = 1; i < cantidad; ++i) {
		mcd = calcular(mcd, numeros[i]).getMCD();
		mcm = (mcm * numeros[i]) / calcular(mcm, numeros[i]).getMCD();
	}
	return ResultadoEuclides(mcd, mcm);
}