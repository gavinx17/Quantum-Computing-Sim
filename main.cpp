#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <ctime>
#include <cstdlib>
#include "qubit.h"

using namespace std;

int main()
{
    srand(time(NULL));
    std::cout.flush();

    QUBITS qubit;
    qubit.print();

    vector<vector<complex<double>>> H = {
        {1.0 / sqrt(2), 1.0 / sqrt(2)},
        {1.0 / sqrt(2), -1.0 / sqrt(2)}
    };
    qubit.apply_gate(H);
    qubit.print();

    int measuremeant = qubit.measure();
    std::cout << "Measurement: " << measuremeant << std::endl;

    return 0;
}