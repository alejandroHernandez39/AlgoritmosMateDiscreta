#pragma once

#include "IServicioBinomio.h"

class ServicioBinomio : public IServicioBinomio {
private:
	long long calcularCoeficiente(int n, int k);
	long long calcularPotencia(long long base, int exponente);

	public:
		vector <TerminoBinomio> expandirBinomio(const TerminoBinomio& termino1, const TerminoBinomio& termino2, int exponenteBinomio) override;
		TerminoBinomio encontrarTermino(int indice, const vector<TerminoBinomio>& terminos) override;
		long long encontrarCoeficiente(int indice, const vector<TerminoBinomio>& terminos) override;
};