#pragma once


#include "IServicioEuclides.h";

class ServicioEuclides : public IServicioEuclides {
	public:
		ResultadoEuclides calcular(long long a, long long b) override;
		ResultadoEuclides calcular(int cantidad, const vector<long long> numeros) override;
};
