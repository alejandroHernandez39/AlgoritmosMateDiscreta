#pragma once

#include "ResultadoEuclides.h"

class IServicioEuclides {
public:
	virtual ResultadoEuclides calcular(long long a, long long b) = 0;
	virtual ResultadoEuclides calcular(int cantidad, const vector<long long> numeros) = 0;

	virtual ~IServicioEuclides() {}
};