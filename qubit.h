#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <complex>

class QUBITS{
    public:
        std::complex<double> amplitude0;
        std::complex<double> amplitude1;

        QUBITS() : amplitude0(0.0, 1.0), amplitude1(0.0, 0.0) {}

        QUBITS(std::complex<double> a0, std::complex<double> a1) : amplitude0(a0), amplitude1(a1)
        {
            normalize();
        }
        void normalize()
        {
            double normVal = sqrt(norm(amplitude0) + norm(amplitude1));
            amplitude0 /= normVal;
            amplitude1 /= normVal;
        }
        void apply_gate(const std::vector<std::vector<std::complex<double>>>& gate)
        {
            std::complex<double> newAmp0 = gate[0][0] * amplitude0 + gate[0][1] * amplitude1;
            std::complex<double> newAmp1 = gate[1][0] * amplitude0 + gate[1][1] * amplitude1;
            amplitude0 = newAmp0;
            amplitude1 = newAmp1;
        }
        int measure() const
        {
            double prob0 = norm(amplitude0);
            double prob1 = norm(amplitude1);
            double randomVal = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

            if(randomVal < prob0)
                return 0;
            else
                return 1;
        }
        void print() const
        {
            std::cout << amplitude0 << " 0|> + " << amplitude1 << " 1|>" << std::endl; 
        }
};