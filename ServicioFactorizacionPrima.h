#pragma once

#include "IServicioFactorizacionPrima.h"

class ServicioFactorizacionPrima : public IServicioFactorizacionPrima {
	public:
		vector<FactorPrimo> factorizar(long long numero) override;
		int divisores(const vector<FactorPrimo>& factores) override;
};