
#include "Banco.h"

Banco::Banco(string nome):nome(nome){}
Banco::~Banco(){
    cout << "A Destruir o banco: " << this->nome << endl;
}
void Banco::adicionarConta(Conta c){
    this->contas.push_back(c);
}
Conta Banco::obtemConta(int cc) const{
    Conta c;
    for(auto el: contas){
        if(el.obtemConta(cc))
            return el;
    }
    return c;
}

void Banco::eliminarConta(int cc){
    vector<Conta>::const_iterator el;
    el = contas.begin();
    while(el != contas.end()){
        if(el->obtemConta(cc))
            contas.erase(el);
        else
            ++el;
    }
}
int Banco::obtemSomaSaldos() const{
    int total=0;
    for (auto &el: contas)
        total += el.obtemSaldo();
    return total;
}
string Banco::getAsString(){
    ostringstream os;
    os << endl << "Nomes dos Titulares" << endl;
    for(auto &el: contas)
        os << el.obtemTitularConta() << endl;
    return os.str();
}

void Banco::depositar(int quantia, int cc){
    for(auto &el: contas)
        if(el.obtemConta(cc))
            el.aumentaSaldo(quantia);
    //conta.aumentaSaldo(quantia, cc);
}

void Banco::levantar(int quantia, int cc){
    for(auto &el: contas)
        if(el.obtemConta(cc)){
            el.diminuiSaldo(quantia);
            if(el.obtemSaldo() < 0)
                el.diminuiSaldo(0);
        }
}
string Banco::obtemClientes() const{
    ostringstream os;
    os << endl << "----- Listagem de Clientes Banco: ---- " << this->nome<< "-----" << endl;
    for(auto &el: contas)
        os << "---- " << el.obtemTitularConta() << endl;
    return os.str();
}

int Banco::obtemSaldoConta(int cc) const{
    for(auto &el: contas)
        if(el.obtemConta(cc))
            return el.obtemSaldo();
    return 0;
}

string Banco::obtemTitularConta(int cc) const{
    ostringstream os;
    for(auto &el: contas)
        if(el.obtemConta(cc))
            os << el.obtemTitularConta();
    return os.str();
}