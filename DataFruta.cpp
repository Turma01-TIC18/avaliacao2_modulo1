#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data : public Lista {
    vector<Data> dados;
    int dia, mes, ano;

    public:
        void entradaDeDados() override {
                int dia, mes, ano;

                int numElementos;
                cout << "Quantos elementos vão existir na lista de Datas? ";
                cin >> numElementos;
                cin.ignore();

                for (int i = 0; i < numElementos; i++) {
                    
                    cout << "Digite a data " << i + 1 << " (dia mês ano): ";
                    cin >> dia >> mes >> ano;

                    Data data(dia, mes, ano);

                    dados.push_back(data);
                }
                
            }

        void mostraMediana() override {
            if (dados.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

        
        sort(dados.begin(), dados.end(), Data::compara);

        int tamanho = dados.size();

        
        if (tamanho % 2 != 0) {
            Data mediana = dados[tamanho / 2];
            cout << "Mediana: " << mediana.toString() << endl;
        } else {
            
            Data mediana1 = dados[(tamanho - 1) / 2];
            Data mediana2 = dados[tamanho / 2];

            
            int dia = (mediana1.getDia() + mediana2.getDia()) / 2;
            int mes = (mediana1.getMes() + mediana2.getMes()) / 2;
            int ano = (mediana1.getAno() + mediana2.getAno()) / 2;

            Data mediana(dia, mes, ano);
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
            cout << "Classificar quantos nomes? " << endl;
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

        static int compara(Data d1, Data d2) {
            return d1.compararCom(d2);
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
            ret.append(to_string(dia));
            ret.append("/");
            ret.append(to_string(mes));
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





class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	    void entradaDeDados() override {
            
        }

        void mostraMediana() override {
            
        }

        void mostraMenor() override {
            
        }

        void mostraMaior() override {
           
        }
        void listarEmOrdem() override {
            
        }
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:
	
	    void entradaDeDados() override {
            
        }

        void mostraMediana() override {
            
        }

        void mostraMenor() override {
            
        }

        void mostraMaior() override {
            
        }
        void listarEmOrdem() override {
            
        }
};

class ListaIdades : public Lista  {
	vector<int> lista;
	
	public:
		void entradaDeDados() override {
            
        }

        void mostraMediana() override {
        
        }

        void mostraMenor() override {
            
        }

        void mostraMaior() override {
            
        }
        void listarEmOrdem() override {
                        
        }
	
};

int main() {
    vector<Lista*> listaGeral;

    gerarData listaData;
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