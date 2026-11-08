#include "FactorPrimo.h";

FactorPrimo::FactorPrimo(long long factor, int exponente) : factor(factor), exponente(exponente) {}

long long FactorPrimo::getFactor() const {
	return factor;
}

int FactorPrimo::getExponente() const {
	return exponente;
}