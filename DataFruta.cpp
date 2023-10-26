#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Data {

    int dia, mes, ano;

    public:
        int compararCom(const Data& outraData) const {
            if (ano < outraData.ano)
                return -1;
            else if (ano > outraData.ano)
                return 1;
            else {
                if (mes < outraData.mes)
                    return -1;
                else if (mes > outraData.mes)
                    return 1;
                else {
                    if (dia < outraData.dia)
                        return -1;
                    else if (dia > outraData.dia)
                        return 1;
                    else
                        return 0;
                }
            }
        }

        static bool compararData (Data& data1, Data& data2)  {
        if (data1.ano < data2.ano) {
            return true;
        } else if (data1.ano > data2.ano) {
            return false;
        } else {
            if (data1.mes < data2.mes) {
                return true;
            } 
			else if (data1.mes > data2.mes) {
                return false;
            } 
			else {
                return data1.dia < data2.dia;
            }
        }
    }

        Data(int _dia, int _mes, int _ano) {
            dia = _dia;
            mes = _mes;
            ano = _ano;
        }

        int getDia() const {
            return dia;
        }

        int getMes() const {
            return mes;
        }

        int getAno() const {
            return ano;
        }

        string toString() {
            string ret = "";
		    ret.append(dia < 10 ? "0" + to_string(dia) : to_string(dia));
		    ret.append("/");
		    ret.append(mes < 10 ? "0" + to_string(mes) : to_string(mes));
		    ret.append("/");
		    ret.append(to_string(ano));
            return ret;
        }
};

class Lista {
    public:
        virtual void entradaDeDados() = 0;
        virtual void mostraMediana() = 0;
        virtual void mostraMenor() = 0;
        virtual void mostraMaior() = 0;
        virtual void listarEmOrdem() = 0;
};

class ListaDatas : public Lista {
    vector<Data> dados;

    public:
        void entradaDeDados() override {
            int numElementos;
            string dataBuffer;
            cout << "Quantos elementos para Data? ";
            cin >> numElementos;
            cin.ignore();

            for (int i = 0; i < numElementos; i++) {
                
                cout << "Digite a data " << i + 1 << " (dd/mm/aaaa): ";
                getline(cin >> ws, dataBuffer);
			    int dia, mes, ano;
			    char delimitador;

			    istringstream stream(dataBuffer);
			    stream >> dia >> delimitador >> mes >> delimitador >> ano;

			    if (delimitador == '/') {
				    Data data(dia, mes, ano);
				    dados.push_back(data);
			    } 
                else {
                    cout << dia << mes << ano;
                    cerr << "Formato de data inválido." << endl;
                }
		
            }
            
        }

        void mostraMediana() override {
            if (dados.empty()) {
                cout << "A lista de datas está vazia." << endl;
                return;
            }
            sort(dados.begin(), dados.end(), Data::compararData);

            int tamanho = dados.size();
            
            if (tamanho % 2 != 0) {
                Data mediana = dados[tamanho / 2];
                cout << "Mediana: " << mediana.toString() << endl;
            } else {
                
                Data mediana = dados[tamanho / 2 - 1];
                cout << "Mediana: " << mediana.toString() << endl;
            }
        }

        void mostraMenor() override {
            if (dados.empty()) {
                cout << "A lista de datas está vazia." << endl;
                return;
            }

            Data menor = dados[0]; 

            for (const Data& data : dados) {
                if (data.compararCom(menor) < 0) {
                    menor = data; 
                }
            }

            cout << "Menor data: " << menor.toString() << endl;
        }

        void mostraMaior() override {
            if (dados.empty()) {
                cout << "A lista de datas está vazia." << endl;
                return;
            }

            Data maior = dados[0]; 

            for (const Data& data : dados) {
                if (data.compararCom(maior) > 0) {
                    maior = data; 
                }
            }

            cout << "Maior data: " << maior.toString() << endl;
        }

        void listarEmOrdem() override {
            int n;
            cout << "Classificar quantas Datas? " << endl;
            cin >> n;
            if (dados.empty()) {
                cout << "A lista de datas está vazia." << endl;
                return;
            }

            cout << "Exibindo " << n << " datas da lista:" << endl;
            for (int i = 0; i < min(n, static_cast<int>(dados.size())); i++) {
                cout << i+1 << "- " << dados[i].toString() << endl;
            }
        }
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
        void entradaDeDados() override {
            int numElementos;
            cout << "Quantos elementos para Nome? ";
            cin >> numElementos;
            cin.ignore();

            for (int i = 0; i < numElementos; i++) {
                string nomes;
                cout << "Digite o(s) nome(s) " << i + 1 << ": ";
                cin >> nomes;

                lista.push_back(nomes);
            }
        }

        void mostraMediana() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            sort(lista.begin(), lista.end());

            int tamanho = lista.size();
            if (tamanho % 2 != 0) {
                string mediana1 = lista[tamanho / 2];
                cout << "Mediana: " << mediana1 << endl;
            } else {
                string mediana2 = lista[tamanho / 2 - 1];
                cout << "Mediana: " << mediana2 << endl;
            }
        }

        void mostraMenor() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            string menor = *min_element(lista.begin(), lista.end());
            cout << "Menor elemento: " << menor << endl;
        }

        void mostraMaior() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            string maior = *max_element(lista.begin(), lista.end());
            cout << "Maior elemento: " << maior << endl;
        }

        void listarEmOrdem() override {
            int n;
            cout << "Classificar quantos nomes? " << endl;
            cin >> n;
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            cout << "Exibindo " << n << " nomes da lista:" << endl;
            for (int i = 0; i < min(n, static_cast<int>(lista.size())); i++) {
                cout << i+1 << "- " << lista[i] << endl;
            }
        }
};

class ListaSalarios : public Lista {
    vector<float> lista;
	
	public:
	
        void entradaDeDados() override {
            int numElementos;
            cout << "Quantos elementos para Salário? ";
            cin >> numElementos;
            cin.ignore();

            for (int i = 0; i < numElementos; i++) {
                float listas;
                cout << "Digite o(s) salário(s) " << i + 1 << " em R$ ";
                cin >> listas;

                lista.push_back(listas);
            }
        }

        void mostraMediana() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            sort(lista.begin(), lista.end());

            int tamanho = lista.size();
            if (tamanho % 2 != 0) {
                float mediana1 = lista[tamanho / 2];
                cout << "Mediana: R$ " << fixed << setprecision(2) << mediana1 << endl;
            } else {
                float mediana2 = lista[tamanho / 2 - 1];
                cout << "Mediana: R$ " << fixed << setprecision(2) << mediana2 << endl;
            }
        }

        void mostraMenor() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            float menor = *min_element(lista.begin(), lista.end());
            cout << "Menor elemento: R$ " << fixed << setprecision(2) << menor << endl;
        }

        void mostraMaior() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            float maior = *max_element(lista.begin(), lista.end());
            cout << "Maior elemento: R$ " << fixed << setprecision(2) << maior  << endl;
        }

        void listarEmOrdem() override {
            int n;
            cout << "Classificar quantos salários? " << endl;
            cin >> n;
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            cout << "Exibindo " << n << " salário(s) da lista:" << endl;
            for (int i = 0; i < min(n, static_cast<int>(lista.size())); i++) {
                cout << i+1 << " - R$" << fixed << setprecision(2) << lista[i] << endl;
            }
        }
};

class ListaIdades : public Lista  {
	vector<int> lista;
	
	public:
		void entradaDeDados() override {
            int numElementos;
            cout << "Quantos elementos para Idade? ";
            cin >> numElementos;
            cin.ignore();

            for (int i = 0; i < numElementos; i++) {
                float listas;
                cout << "Digite a(s) idade(s) " << i + 1 << ": ";
                cin >> listas;

                lista.push_back(listas);
            }
        }

        void mostraMediana() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            sort(lista.begin(), lista.end());

            int tamanho = lista.size();
            if (tamanho % 2 != 0) {
                float mediana1 = lista[tamanho / 2];
                cout << "Mediana: " << mediana1 << endl;
            } else {
                float mediana2 = lista[tamanho / 2 - 1];
                cout << "Mediana: " << mediana2 << endl;
            }
    	}

        void mostraMenor() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            float menor = *min_element(lista.begin(), lista.end());
            cout << "Menor elemento: " << menor << endl;
        }

        void mostraMaior() override {
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            float maior = *max_element(lista.begin(), lista.end());
            cout << "Maior elemento: " << maior << endl;
        }
        void listarEmOrdem() override {
            int n;
            cout << "Classificar quantos idades? " << endl;
            cin >> n;
            if (lista.empty()) {
                cout << "A lista está vazia." << endl;
                return;
            }

            cout << "Exibindo " << n << " idade(s) da lista:" << endl;
            for (int i = 0; i < min(n, static_cast<int>(lista.size())); i++) {
                cout << i+1 << "- " << lista[i] << endl;
            }
        }
	
};

int main() {
    vector<Lista*> listaGeral;

    ListaDatas listaData;
    ListaNomes listaNomes;
    ListaIdades listaIdades;
    ListaSalarios listaSalarios;
    
    listaData.entradaDeDados();
    listaNomes.entradaDeDados();
    listaIdades.entradaDeDados();
    listaSalarios.entradaDeDados();
    

    listaGeral.push_back(&listaData);
    listaGeral.push_back(&listaNomes);
    listaGeral.push_back(&listaIdades);
    listaGeral.push_back(&listaSalarios);
    

    for (Lista* l : listaGeral) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
        l->listarEmOrdem();
    }

    return 0;
}



