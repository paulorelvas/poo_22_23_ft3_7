#include <iostream>
#include <sstream>
#include <vector>
#include "Pessoa.h"

using namespace std;

#ifndef FT_3_7_V2_RC_REGISTOCIVIL_H
#define FT_3_7_V2_RC_REGISTOCIVIL_H

class RegistoCivil {
private:
    vector<Pessoa*> pessoas;
    Pessoa * p;
public:
    RegistoCivil();
    RegistoCivil(const RegistoCivil &r);
    RegistoCivil(const Pessoa &pessoa);

    ~RegistoCivil();
    void adicionarPessoa(string nome, int cc, int nif);

    void eliminarPessoa(int cc);
    string listarPessoas() const;

    Pessoa * devolvePessoa(int cc);
    Pessoa * devolvePessoa(string nome);
    void alteraNomePessoa(string nome);

    RegistoCivil &operator=(const Pessoa &pessoa);
    // RegistoCivil &operator=(const RegistoCivil &r);
};

#endif //FT_3_7_V2_RC_REGISTOCIVIL_H
