#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
	int dia, mes, ano;

public:
	Data() : dia(1), mes(1), ano(2000) {}

	static int compara(const Data &d1, const Data &d2)
	{
		if (d1.ano < d2.ano)
		{
			return -1;
		}
		else if (d1.ano > d2.ano)
		{
			return 1;
		}
		else if (d1.mes < d2.mes)
		{
			return -1;
		}
		else if (d1.mes > d2.mes)
		{
			return 1;
		}
		else if (d1.dia < d2.dia)
		{
			return -1;
		}
		else if (d1.dia > d2.dia)
		{
			return 1;
		}
		return 0;
	}

	bool operator<(const Data &outraData) const // Overload < para evitar erro de compilação
	{
		if (ano < outraData.ano)
		{
			return true;
		}
		else if (ano > outraData.ano)
		{
			return false;
		}
		else if (mes < outraData.mes)
		{
			return true;
		}
		else if (mes > outraData.mes)
		{
			return false;
		}
		return dia < outraData.dia;
	}

	Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

	string toString() const
	{
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};


template <typename T>
class Lista
{
protected:
	vector<T> elementos;

public:
	void adicionar(const T &elemento)
	{
		elementos.push_back(elemento);
	}

	void remover(const T &elemento)
	{
		for (auto it = elementos.begin(); it != elementos.end(); ++it)
		{
			if (*it == elemento)
			{
				elementos.erase(it);
				break;
			}
		}
	}

	void listar()
	{
		for (const auto &elemento : elementos)
		{
			cout << elemento << " ,";
		}
	}

	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
};

// daqui pra cima está tudo certo
// implementando lista nomes
class ListaNomes : public Lista<string>{
public:
	void entradaDeDados() override
	{
		int n;
		cout << "Quantos nomes deseja inserir? ";
		cin >> n;
		cin.ignore();

		for (int i = 0; i < n; i++)
		{
			string nome;
            cout << "Nome " << i + 1 << ": ";
            getline(cin, nome);
			adicionar(nome);
		}
	}

	void mostraMediana() override {
        	if (elementos.empty()) {
            		cout << "A lista de nomes esta vazia." << endl;
            	return;
        	}
        	cout << "Calculando a mediana dos nomes..." << endl;
        	sort(elementos.begin(), elementos.end()); // Ordena a lista

        	int tamanho = elementos.size();
        	int meio1 = tamanho / 2 - 1;

        	// Se a quantidade de elementos é par, escolha o primeiro deles
        	if (tamanho % 2 == 0) {
            		cout << "Mediana: " << elementos[meio1] << endl;
        	}
		else {
            		cout << "Mediana: " << elementos[meio1 + 1] << endl;
        	}
    	}
	void mostraMenor() override {
		cout << "Mostrando o primeiro nome alfabeticamente..." << endl;
		if (!this->elementos.empty()) {
			cout << "Menor nome: " << *min_element(this->elementos.begin(), this->elementos.end()) << endl;
		}
	}

	void mostraMaior() override {
		cout << "Mostrando o último nome alfabeticamente..." << endl;
		if (!this->elementos.empty()) {
			cout << "Maior nome: " << *max_element(this->elementos.begin(), this->elementos.end()) << endl;
		}
	}
};

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ListaDatas  : public Lista<Data>{
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override {
		int N, dia, mes, ano;
		cout << "Digite a quantidade de datas que serão armazenadas na lista";
		cin >> N;
		for(int i=0;i<N;i++){
			cout << "Digite o dia, mes e ano da data" << endl;
			cin >> dia >> mes >> ano;
			lista.push_back(Data (dia,mes,ano));
		}
	}
	
	vector<Data> organizaDatas() {
		int N = lista.size();
		if(N==0){
			cout << "Lista vazia" << endl;
			return lista;
		}
		vector<Data> listaOrganizada = lista;
		bool trocou;
		for(int i=0;i<N-1;i++){
			trocou = false;
			for(int j=0; j < n-i-1; j++){
				if( Data::compara(listaOrganizada[j],listaOrganizada[j+1]) == 1){
					swap(listaOrganizada[j],listaOrganizada[j+1]);
					trocou = true;
				}
			}
			if (trocou == false){
				break;
			}
		}
		return listaOrganizada;
	}

	void mostraMediana() override {
		vector<Data> listaOrganizada = organizaDatas();
		int N = listaOrganizada.size();
		if (N==0){
			cout<< "Lista vazia";
			return;
		}
		cout << listaOrganizada[N/2].toString() << endl;
	}
	
	void mostraMenor() override {
		vector<Data> listaOrganizada = organizaDatas();
		if (listaOrganizada.size()==0){
			cout<< "Lista vazia";
			return;
		}
		vector<Data>::iterator it = listaOrganizada.begin();
		cout << it->toString() << endl;
	}
	void mostraMaior() override {
				vector<Data> listaOrganizada = organizaDatas();
		if (listaOrganizada.size()==0){
			cout<< "Lista vazia";
			return;
		}
		vector<Data>::iterator it = listaOrganizada.end();
		cout << it->toString() << endl;
	}
};
//lita salario
class ListaSalarios : public Lista<float>
{

public:
	void entradaDeDados() override
	{
		int qtde;
		cout << "Quantos salários você deseja adicionar? ";
		cin >> qtde;

		for (int i = 0; i < qtde; i++)
		{
			float salario;
			cout << "Digite o salário " << (i + 1) << ": ";
			cin >> salario;
			adicionar(salario);
		}
	}

	void mostraMediana() override
	{
		cout << "Mediana da lista de salários: " << endl;
		vector<float> sortedSalarios = elementos;
		sort(sortedSalarios.begin(), sortedSalarios.end()); // Ordena os salários em ordem crescente

		int size = sortedSalarios.size();
		float medianSalary;

		if (size % 2 == 1)
		{
			// Quantidade ímpar de salários
			medianSalary = sortedSalarios[size / 2];
		}
		else
		{
			// Quantidade par de salários
			int middleIndex = size / 2;
			float salary1 = sortedSalarios[middleIndex - 1];
			float salary2 = sortedSalarios[middleIndex];
			medianSalary = (salary1 + salary2) / 2;
		}

		cout << "Mediana: " << medianSalary << endl;
	}

	void mostraMenor() override
	{
		cout << "Menor dos salários: " << endl;
		if (!elementos.empty())
		{
			float menorSalario = elementos[0];
			for (const float &salario : elementos)
			{
				if (salario < menorSalario)
				{
					menorSalario = salario;
				}
			}
			cout << "Menor salário: " << menorSalario << endl;
		}
		else
		{
			cout << "A lista de salários está vazia." << endl;
		}
	}
	void mostraMaior() override
	{
		cout << "Maior dos salários: " << endl;
		if (!elementos.empty())
		{
			float maiorSalario = elementos[0];
			for (const float &salario : elementos)
			{
				if (salario > maiorSalario)
				{
					maiorSalario = salario;
				}
			}
			cout << "Maior salário: " << maiorSalario << endl;
		}
		else
		{
			cout << "A lista de salários está vazia." << endl;
		}
	}
};

// implementando lista idades
class ListaIdades : public Lista<int>{
public:
    void entradaDeDados() override
    {
        int n;
        cout << "Quantas idades deseja inserir? ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int idade;
            cout << "Digite a " << (i + 1) << "ª idade: ";
            cin >> idade;
            adicionar(idade);
        }
    }

    void mostraMediana() override
    {
        cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
        vector<int> sortedIdades = elementos;
        sort(sortedIdades.begin(), sortedIdades.end()); // Ordena as idades em ordem crescente

        int size = sortedIdades.size();
        int medianAge;

        if (size % 2 == 1)
        {
            // Quantidade ímpar de idades
            medianAge = sortedIdades[size / 2];
        }
        else
        {
            // Quantidade par de idades
            int middleIndex = size / 2;
            int age1 = sortedIdades[middleIndex - 1];
            int age2 = sortedIdades[middleIndex];
            medianAge = (age1 + age2) / 2;
        }

        cout << "Mediana: " << medianAge << endl;
    }

    void mostraMenor() override
    {
        cout << "Aqui vai mostrar a menor das idades" << endl;
        if (!elementos.empty())
        {
            int menorIdade = elementos[0];
            for (const int &idade : elementos)
            {
                if (idade < menorIdade)
                {
                    menorIdade = idade;
                }
            }
            cout << "Menor idade: " << menorIdade << endl;
        }
        else
        {
            cout << "A lista de idades está vazia." << endl;
        }
    }
    void mostraMaior() override
    {
        cout << "Aqui vai mostrar a maior das idades" << endl;
        if (!elementos.empty())
        {
            int maiorIdade = elementos[0];
            for (const int &idade : elementos)
            {
                if (idade > maiorIdade)
                {
                    maiorIdade = idade;
                }
            }
            cout << "Maior idade: " << maiorIdade << endl;
        }
        else
        {
            cout << "A lista de idades está vazia." << endl;
        }
    }
};
 
int main () {
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
	
}
    

