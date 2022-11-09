
#include "Pessoa.h"


Pessoa::Pessoa(){}
Pessoa::Pessoa(string nome, int cc, int nif): nome(nome), cc(cc), nif(nif){}
Pessoa::~Pessoa(){
    //
}

string Pessoa::obtemNomePessoa() const{
    return this->nome;
}

void Pessoa::alteraNomePessoa(string nome){
    this->nome = nome;
}

int Pessoa::obtemCcPessoa() const{
    return this->cc;
}

int Pessoa::obtemNifPessoa() const{
    return this->nif;
}


//Pessoa Pessoa::obtemPessoa(const Pessoa p) const{
Pessoa Pessoa::obtemPessoa() const{
    return Pessoa(this->nome, this->cc, this->nif);
}