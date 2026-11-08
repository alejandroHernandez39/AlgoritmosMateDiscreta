#pragma once

class FactorPrimo {
	private: 
		long long factor;
		int exponente;

	public:
		FactorPrimo(long long factor, int exponente);
		long long getFactor() const;
		int getExponente() const;
};
