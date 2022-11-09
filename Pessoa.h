
#include<iostream>
using namespace std;

#ifndef FT_3_7_V2_RC_PESSOA_H
#define FT_3_7_V2_RC_PESSOA_H

class Pessoa {
private:
    string nome;
    int cc;
    int nif;

public:
    Pessoa();
    Pessoa(string nome, int cc, int nif);
    ~Pessoa();

    string obtemNomePessoa() const;
    void alteraNomePessoa(string nome);
    int obtemCcPessoa() const;
    int obtemNifPessoa() const;
    //Pessoa obtemPessoa(const Pessoa p) const;
    Pessoa obtemPessoa() const;
};


#endif //FT_3_7_V2_RC_PESSOA_H
