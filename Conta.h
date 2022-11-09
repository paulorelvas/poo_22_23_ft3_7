#include <iostream>
#include <vector>
#include <sstream>
#include "Pessoa.h"

using namespace std;

#ifndef FT_3_7_V2_RC_CONTA_H
#define FT_3_7_V2_RC_CONTA_H

class Conta {
private:
    int saldo;
    const Pessoa * pessoa;

public:
    Conta();
    Conta(const Pessoa * p, int saldo=0);
    ~Conta();
    int obtemSaldo() const;
    void aumentaSaldo(int valorMovimento);
    void diminuiSaldo(int valorMovimento);
    string obtemTitularConta() const;
    string titularConta()const;
    bool obtemConta(int cc) const;
    Conta obtemConta(string titular) const;
    //Pessoa obtemTitular() const;

};


#endif //FT_3_7_V2_RC_CONTA_H
