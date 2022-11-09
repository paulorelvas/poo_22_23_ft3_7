#include <iostream>
#include <fstream>
#include "Pessoa.h"
#include "Conta.h"
#include "Banco.h"
#include "RegistoCivil.h"

using namespace std;
int main() {
    cout << "---- FT3_7::RegistoCivil ----" << endl;

    RegistoCivil registo;
    ifstream file("pessoas.txt" );
    // Caso não consiga abrir o ficheiro em modo leitura
    if (!file){
        // Escreve mensagem de erro
        cerr << "Não foi possível abrir o ficheiro pessoas.txt!\n";
        return 1;
    }

    int numOfLines = 0;
    string strInput;

    while(getline(file, strInput) && numOfLines < 10){
        cout << strInput << endl;
        numOfLines++;
        istringstream iss(strInput);
        string s, s1, s2;
        int cc;
        int nif;

        while ( getline( iss, s, ' ' ) ) {
            // coloca em s a primeira parte da string - até ao primeiro espaço
            // cout << s.c_str() << endl;
            // coloca em cc a string até ao 2º espaço e em nif a string até ao final da linha
            iss >> cc >> nif;
        }
        registo.adicionarPessoa(s.c_str(), cc, nif);
        // cout << endl << "<-- " << s.c_str() << " -- " << nif << " -- " << cc << "-->" << endl;
    }

    cout << endl << "listar pessoas registadas" << endl;
    cout << registo.listarPessoas();

    Banco bpo{"Banco Popular Orçamental"};
    Banco btd{"Banco Transformador Dinheiro"};
    Banco bbd{"Banco Bom Dinheiro"};

    /*
     // -- usado apenas como teste ---
    Pessoa *p = registo.devolvePessoa(92345619);
    cout  << endl << "Pesquisa de pessoa pelo CC {92345619}: "  << p->obtemNomePessoa();
    p->alteraNomePessoa("Ahmir");
    cout  << endl << "Nome da pessoa com CC {92345619} alterado para: "  << p->obtemNomePessoa();

    cout << endl << "listar pessoas registadas" << endl;
    cout << registo.listarPessoas();*/

    bbd.adicionarConta({registo.devolvePessoa(92345619), 1050});
    bbd.adicionarConta({registo.devolvePessoa(13345611), 250});
    bbd.adicionarConta({registo.devolvePessoa(12999694), 650});

    bbd.depositar(323, 92345619);

    cout << "Saldo total de todos os clientes: " << bbd.obtemSomaSaldos();
    cout << bbd.obtemClientes();

    btd.adicionarConta({registo.devolvePessoa(92345619), 366050});
    btd.adicionarConta({registo.devolvePessoa(12345695), 2500});
    btd.depositar(325, 92345619);

    cout << "Saldo total de todos os clientes: " << btd.obtemSomaSaldos();
    cout << btd.obtemClientes();

    // -------------- usa o operador de atribuição ------
    // chamado quando um objeto inicializado é atribuído um novo valor de outro objeto já existente
    // nesta caso, a um objeto do tipo RegistoCivil inicializado com construtor por omissão é atribuído
    // um objeto do tipo Pessoa
    RegistoCivil r_aux;
    // r_aux.operator=(*registo.devolvePessoa("Antunes"));
    r_aux = *(registo.devolvePessoa("Antunes"));
    //r_aux = *p;

    cout << endl << "listar pessoas r_aux" << endl;
    cout << endl << r_aux.listarPessoas();

    //p->alteraNomePessoa("Ahmiratin");

    cout << endl << "listar pessoas r_aux" << endl;
    cout << endl << r_aux.listarPessoas();

    r_aux.alteraNomePessoa("Rita");
    cout << endl << "--- listar pessoas r_aux após alterar nome titular conta ---" << endl;
    cout << endl << r_aux.listarPessoas();

    cout << endl << "listar pessoas registadas" << endl;
    cout << registo.listarPessoas();

    registo.eliminarPessoa(92345619);

    cout << endl << "listar pessoas registadas após eliminar pessoa com cc 92345619" << endl;
    cout << registo.listarPessoas();

    // -------------- usa o construtor por cópia::RegistoCivil to RegistoCivil------
    RegistoCivil r_temp(r_aux);
    // RegistoCivil r_temp;
    // r_temp = r_aux;

    cout << endl << "listar pessoas registadas::r_temp" << endl;
    cout << r_temp.listarPessoas();
    r_temp.alteraNomePessoa("Joana");
    cout << endl << "--- listar pessoas r_temp após alterar nome titular conta r_aux para Joana ---" << endl;
    cout << r_temp.listarPessoas();

    cout << endl << "--- listar pessoas r_aux após alterar nome titular conta em r_temp para Joana ---" << endl;
    cout << r_aux.listarPessoas();

    // -------------- usa o construtor por cópia::Pessoa to RegistoCivil------
    // Chamado ao criar um novo objeto a partir de outro objeto já existente - cópia do objeto original
    const Pessoa p1 {"Andaluzia", 212345619, 505456190 };
    RegistoCivil rc(p1);
    //rc = p1;

    cout << endl << "listar pessoas registadas::rc" << endl;
    cout << rc.listarPessoas();

    // registo.adicionarPessoa(p1.obtemNomePessoa(), p1.obtemCcPessoa(), p1.obtemNifPessoa());
    // cout << endl << "listar pessoas registadas após adicionar pessoa de rc::rc" << endl;
    // cout << registo.listarPessoas();

    //rc.alteraNomePessoa("Ana");
    //cout << rc.listarPessoas();
    //cout << p1.obtemNomePessoa();
    // delete p;

    return 0;
}
