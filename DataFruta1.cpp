#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lista 
{
public:
    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
};

class Data 
{
public:
    int dia, mes, ano;

    Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

    static int compara(const Data& d1, const Data& d2) {
        if (d1.ano != d2.ano) return d1.ano - d2.ano;
        if (d1.mes != d2.mes) return d1.mes - d2.mes;
        return d1.dia - d2.dia;
    }

    string toString() {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
};

class ListaNomes : public Lista 
{
private:
    vector<string> lista;

public:
    void entradaDeDados() override {
        int n;
        cout << "Quantos nomes deseja inserir? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            string nome;
            cout << "Digite o nome " << i + 1 << ": ";
            cin >> nome;
            lista.push_back(nome);
        }
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        int meio = lista.size() / 2;
        if (lista.size() % 2 == 0) {
            cout << "A mediana da lista de nomes eh: " << lista[meio - 1] << " e " << lista[meio] << endl;
        } else {
            cout << "A mediana da lista de nomes eh: " << lista[meio] << endl;
        }
    }

    void mostraMenor() override {
        if (!lista.empty()) {
            cout << "O primeiro nome alfabeticamente na lista de nomes eh: " << lista[0] << endl;
        } else {
            cout << "A lista de nomes esta vazia." << endl;
        }
    }

    void mostraMaior() override {
        if (!lista.empty()) {
            cout << "O ultimo nome alfabeticamente na lista de nomes eh: " << lista.back() << endl;
        } else {
            cout << "A lista de nomes esta vazia." << endl;
        }
    }
};

class ListaDatas : public Lista 
{
private:
    vector<Data> lista;

public:
    void entradaDeDados() override {
        int n;
        cout << "Quantas datas deseja inserir? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite a data (dia mes ano) " << i + 1 << ": ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
            return Data::compara(d1, d2) < 0;
        });

        int meio = lista.size() / 2;
        Data mediana1 = lista[meio];
        Data mediana2 = lista[meio - 1];

        if (lista.size() % 2 == 0) {
            if (mediana1.ano == mediana2.ano && mediana1.mes == mediana2.mes) {
                
                if (Data::compara(mediana1, mediana2) < 0) {
                    swap(mediana1, mediana2);
                }
                cout << "A mediana da lista de datas eh: " << mediana2.toString() << endl;
            } else {
                cout << "A mediana da lista de datas eh: " << mediana2.toString() << " e " << mediana1.toString() << endl;
            }
        } else {
            cout << "A mediana da lista de datas eh: " << mediana1.toString() << endl;
        }
    }

    void mostraMenor() override {
        if (!lista.empty()) {
            auto menorData = min_element(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "A primeira data cronologicamente na lista de datas eh: " << menorData->toString() << endl;
        } else {
            cout << "A lista de datas esta vazia." << endl;
        }
    }

    void mostraMaior() override {
        if (!lista.empty()) {
            auto maiorData = max_element(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "A altima data cronologicamente na lista de datas eh: " << maiorData->toString() << endl;
        } else {
            cout << "A lista de datas esta vazia." << endl;
        }
    }
};

class ListaSalarios : public Lista 
{
private:
    vector<float> lista;

public:
    void entradaDeDados() override {
        int n;
        cout << "Quantos salarios deseja inserir? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            float salario;
            cout << "Digite o salario " << i + 1 << ": ";
            cin >> salario;
            lista.push_back(salario);
        }
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        int meio = lista.size() / 2;
        if (lista.size() % 2 == 0) {
            cout << "A mediana da lista de salarios eh: " << (lista[meio - 1] + lista[meio]) / 2 << endl;
        } else {
            cout << "A mediana da lista de salarios eh: " << lista[meio] << endl;
        }
    }

    void mostraMenor() override {
        if (!lista.empty()) {
            cout << "O menor salario na lista de salarios eh: " << *min_element(lista.begin(), lista.end()) << endl;
        } else {
            cout << "A lista de salarios esta vazia." << endl;
        }
    }

    void mostraMaior() override {
        if (!lista.empty()) {
            cout << "O maior salario na lista eh: " << *max_element(lista.begin(), lista.end()) << endl;
        } else {
            cout << "A lista de salarios esta vazia." << endl;
        }
    }
};

class ListaIdades : public Lista 
{
private:
    vector<int> lista;

public:
    void entradaDeDados() override {
        int n;
        cout << "Quantas idades deseja inserir? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int idade;
            cout << "Digite a idade " << i + 1 << ": ";
            cin >> idade;
            lista.push_back(idade);
        }
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        int meio = lista.size() / 2;
        if (lista.size() % 2 == 0) {
            cout << "A mediana da lista de idades eh: " << (lista[meio - 1] + lista[meio]) / 2 << endl;
        } else {
            cout << "A mediana da lista de idades eh: " << lista[meio] << endl;
        }
    }

    void mostraMenor() override {
        if (!lista.empty()) {
            cout << "A menor idade na lista de idades eh: " << *min_element(lista.begin(), lista.end()) << endl;
        } else {
            cout << "A lista de idades esta vazia." << endl;
        }
    }

    void mostraMaior() override {
        if (!lista.empty()) {
            cout << "A maior idade na lista de idades eh: " << *max_element(lista.begin(), lista.end()) << endl;
        } else {
            cout << "A lista de idades esta vazia." << endl;
        }
    }
};

int main() 
{
    vector<Lista*> listaDeListas;

    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);

    ListaDatas listaDatas;
    listaDatas.entradaDeDados();
    listaDeListas.push_back(&listaDatas);

    ListaSalarios listaSalarios;
    listaSalarios.entradaDeDados();
    listaDeListas.push_back(&listaSalarios);

    ListaIdades listaIdades;
    listaIdades.entradaDeDados();
    listaDeListas.push_back(&listaIdades);

    for (Lista* l : listaDeListas) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }

    return 0;
}