
#include "RegistoCivil.h"

RegistoCivil::RegistoCivil(){
    //p = new Pessoa();
    cout << "A registar pessoa: ";
}

RegistoCivil::~RegistoCivil(){
    delete p;
}

void RegistoCivil::adicionarPessoa(string nome, int cc, int nif){
    p = new Pessoa(nome, cc, nif);
    pessoas.push_back(p);
    //cout << endl << "Pessoas registadas: " << pessoas.size() << endl;
}

void RegistoCivil::eliminarPessoa(int cc){
    // TODO::-- é feito o realloc dos elementos no vetor ao eliminar um elemento
    for(auto & pointer : pessoas)
    {
        if (pointer->obtemCcPessoa() == cc)
        {
            delete pointer;
            pointer = nullptr;
        }
    }
    pessoas.erase(remove(pessoas.begin(), pessoas.end(), nullptr), pessoas.end());
}

string RegistoCivil::listarPessoas() const{
    ostringstream os;
    os << endl << "---- Listagem de Pessoas::RegistoCivil ----" << endl;
    for (auto el: pessoas)
        os << el->obtemNomePessoa() << " " << el->obtemCcPessoa() << " " << el->obtemNifPessoa() << " & " << el << endl;
    return os.str();
}

Pessoa * RegistoCivil::devolvePessoa(int cc){
    for(auto el: pessoas)
        if(el->obtemCcPessoa()==cc)
            return p = el;
    return p;
}

Pessoa * RegistoCivil::devolvePessoa(string nome){
    for(auto el: pessoas)
        if(el->obtemNomePessoa() == nome)
            return p = el;

    return p;
}

void RegistoCivil::alteraNomePessoa(string nome){
    this->p->alteraNomePessoa(nome);
}

//-------------- Begin::Operador de atribuição ----------------------

RegistoCivil &RegistoCivil::operator=(const Pessoa &pessoa) {
    // cout << "operador = P RC" << endl;
    if(this->p == &pessoa){
        return *this;
    }
    //p = new Pessoa;
    //*p = pessoa.obtemPessoa();
    //cout << p->obtemNomePessoa();
    this->adicionarPessoa(pessoa.obtemNomePessoa(), pessoa.obtemCcPessoa(), pessoa.obtemNifPessoa());
    return *this;
}


//-------------- Begin::Construtor de cópia - copia recurso ----------------------

RegistoCivil::RegistoCivil(const Pessoa &pessoa) {
    // cout << "Construtor por cópia = P RC" << endl;
    p = new Pessoa;
    *p = (pessoa.obtemPessoa());
    this->adicionarPessoa(p->obtemNomePessoa(), p->obtemCcPessoa(), p->obtemNifPessoa());
}

RegistoCivil::RegistoCivil(const RegistoCivil &r) {
    // cout << "Construtor por cópia = RC RC" << endl;
    pessoas.clear();
    for(auto *el: r.pessoas){
        p= new Pessoa;
        *p = r.p->obtemPessoa();
        pessoas.push_back(p);
    }

}
