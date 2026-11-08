#include "ResultadoEuclides.h"

ResultadoEuclides::ResultadoEuclides(long long mcd, long long mcm) {
    this->mcd = mcd;
    this->mcm = mcm;
}

long long ResultadoEuclides::getMCD() const {
    return mcd;
}

long long ResultadoEuclides::getMCM() const {
    return mcm;
}