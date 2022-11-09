
#include "Conta.h"
Conta::Conta(){}
Conta::Conta(const Pessoa * p, int saldo): pessoa(p), saldo(saldo){
    cout << "-- a criar uma conta para: " << this->pessoa->obtemNomePessoa() << endl;
}
Conta::~Conta(){}

int Conta::obtemSaldo() const{
    return saldo;
}
void Conta::aumentaSaldo(int valorMovimento){
    saldo+=valorMovimento;
}
void Conta::diminuiSaldo(int valorMovimento){
    saldo-=valorMovimento;
    if(saldo < 0)
        saldo = 0;
}
string Conta::obtemTitularConta() const{
    return pessoa->obtemNomePessoa();
}

bool Conta::obtemConta(int cc) const{
    if (this->pessoa->obtemCcPessoa() == cc)
        return true;
    return false;
}
/*Pessoa Conta::obtemTitular()const{
    return Pessoa(this->pessoa);
}*/

string Conta::titularConta()const{
    ostringstream os;
    os << endl << "Titular da conta: " << this->pessoa->obtemNomePessoa();
    return os.str();
}