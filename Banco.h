
#include<iostream>
#include<vector>
#include<sstream>
#include "Conta.h"

using namespace std;

#ifndef FT_3_7_V2_RC_BANCO_H
#define FT_3_7_V2_RC_BANCO_H


class Banco {
private:
    string nome;
    vector<Conta> contas;
public:
    Banco(string nome);
    ~Banco();

    void adicionarConta(Conta c);
    Conta obtemConta(const int cc)const;
    void eliminarConta(int cc);
    int obtemSomaSaldos() const;
    int obtemSaldoConta(int cc) const;
    string obtemTitularConta(int cc) const;

    string getAsString();

    void depositar(int quantia, int cc);
    void levantar(int quantia, int cc);
    string obtemClientes() const;

};


#endif //FT_3_7_V2_RC_BANCO_H
