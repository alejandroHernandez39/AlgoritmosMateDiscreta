#pragma once

#include<vector>

using namespace std;

class ResultadoEuclides {
	private:
		long long mcd;
		long long mcm;


	public:
		ResultadoEuclides(long long mcd, long long mcm);

		long long getMCD() const;
		long long getMCM() const;
};