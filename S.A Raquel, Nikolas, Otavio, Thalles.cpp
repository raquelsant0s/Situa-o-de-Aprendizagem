#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void adicionarvenda(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Vendas ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("adicionarvenda.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("adicionarvenda.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas vendas? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Vendas" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Venda " << codigo << " ============== \n\n";
  		cout << "Informe o nome da venda: ";
        getline(cin, nome);
        cout << "Informe o valor da venda: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}	

void listarvenda() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as Vendas ================== \n\n";
	
	fstream fin;
    
    fin.open("adicionarvenda.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Vendas Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Venda " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void atualizarvenda() {
	
	system("cls"); 
	
	cout << "=================== Atualizar dados das vendas ================== \n\n";
	
    fstream fin, fout; 

    fin.open("adicionarvenda.csv", ios::in); 

    fout.open("attadiconarvenda.csv", ios::out); 
  
    int linha1, linha2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo da venda que deseja atualizar os dados: ";
    cin >> linha1;
    cin.sync();

    cout << "==========> Alterar dados da Venda " << linha1 << " <=========== \n\n";
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o valor à vista, Digite 2. \n";
    cout << "Para alterar o % de desconto, Digite 3. \n";
    cout << "Para alterar o valor parcelado, Digite 4. \n";
    cout << "Para alterar quantidade de vezes divididas, Digite 5. \n\n";
    cout << "Para alterar o valor das parcelas, Digite 6. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome da venda <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar valor à vista <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar % de desconto <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "==============> Alterar valor parcelado <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "==============> Alterar quantidade de vezes divididas <================ \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "==============> Alterar valor das parcelas <================ \n\n";
  			indice = 6;
  			break;	
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizarvenda();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) {
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linha2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linha2 == linha1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo;

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) {
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) {
    	cout << "Dados nao encontrados!!\n\n";
    	atualizarvenda(); 
	}

    fin.close(); 
    fout.close(); 

    remove("adicionarvenda.csv"); 
    rename("attadicionarvenda.csv", "adicionarvenda.csv");
} 

void excluirvenda() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Vendas ================== \n\n";

    fstream fin, fout; 

    fin.open("adicionarvenda.csv", ios::in); 

    fout.open("attadicionarvenda.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da venda que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("adicionarvenda.csv");
    rename("attadicionarvenda.csv", "adicionarvenda.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra venda? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirvenda();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarcabos(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Cabos ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_cabos.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_cabos.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos cabos? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " cabos " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Cabos " << codigo << " ============== \n\n";
  		cout << "Informe o nome do cabo desejado: ";
        getline(cin, nome);
        cout << "Informe o valor do cabos: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarcabos(){
	
	system("cls");
	
	cout << "=================== Pesquisar Cabos ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_cabos.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo dos cabos para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Cabos " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarcabos();
}
	
	int op;
	cout << "Deseja buscar outro cabos? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarcabos();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarcabos() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os cabos================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_cabos.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todas cabos ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Cabos " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluircabos() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Cabos ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_cabos.csv", ios::in); 

    fout.open("attperiferico_cabos.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_cabos.csv");
    rename("attperiferico_cabos.csv", "periferico_cabos.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro cabos?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircabos();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarcaixadesom(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Caixas de som ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_caixadesom.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_caixadesom.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas caixas de som? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Caixas de som " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Caixass de som " << codigo << " ============== \n\n";
  		cout << "Informe o nome do aparelho desejada: ";
        getline(cin, nome);
        cout << "Informe o valor do aparelho: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
			
void buscarcaixadesom(){
	
	system("cls");
	
	cout << "=================== Pesquisar Caixas de Som ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_caixadesom.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da caixa de som para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Caixas de Som " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarcaixadesom();
}
	
	int op;
	cout << "Deseja buscar outra caixa? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarcaixadesom();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarcaixadesom() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as caixas ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_caixadesom.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todas Caixas ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Caixas de som " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluircaixadesom() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Caixas ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_caixadesom.csv", ios::in); 

    fout.open("attperiferico_caixadesom.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_caixadesom.csv");
    rename("attperiferico_caixadesom.csv", "periferico_caixadesom.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra caixa de som?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircaixadesom();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarcontrole(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Controles ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_controle.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_controle.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos controles? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " controles " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Controles " << codigo << " ============== \n\n";
  		cout << "Informe o nome do controle desejado: ";
        getline(cin, nome);
        cout << "Informe o valor do controle: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarcontrole(){
	
	system("cls");
	
	cout << "=================== Pesquisar Controles ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_controle.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo dos controles para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Controles " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarcontrole();
}
	
	int op;
	cout << "Deseja buscar outro controles? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarcontrole();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarcontrole() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os controle================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_controle.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todas controle================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Controles " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluircontrole() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Controles ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_controle.csv", ios::in); 

    fout.open("attperiferico_controle.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_controle.csv");
    rename("attperiferico_controle.csv", "periferico_controle.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro controle?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircontrole();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarestabilizador(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos estabilizadores ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_estabilizador.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_estabilizador.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos estabilizadores ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << "estabilizador" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar estabilizadores " << codigo << " ============== \n\n";
  		cout << "Informe o nome do estabilizador: ";
        getline(cin, nome);
        cout << "Informe o valor do estabilizador ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarestabilizador(){
	
	system("cls");
	
	cout << "=================== Pesquisar estabilizadores ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_estabilizador.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do estabilizador para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== estabilizadores " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarestabilizador();
}
	
	int op;
	cout << "Deseja buscar outro estabilizador? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarestabilizador();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarestabilizador() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os estabilizadores ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_estabilizador.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todos estabilizadores================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Estabilizador " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirestabilizador() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos estabilizadores ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_estabilizador.csv", ios::in); 

    fout.open("attperiferico_estabilizador.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_estabilizador.csv");
    rename("attperiferico_estabilizador.csv", "periferico_estabilizador.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro estabilizador? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirestabilizador();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criargabinetes(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Gabinetes ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_gabinete.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_gabinete.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos gabinetes? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " gabinetes" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar gabinetes " << codigo << " ============== \n\n";
  		cout << "Informe o nome do gabinetes: ";
        getline(cin, nome);
        cout << "Informe o valor do gabinetes: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscargabinetes(){
	
	system("cls");
	
	cout << "=================== Pesquisar gabinetes ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_gabinete.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do gabinetes para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== gabinetes " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscargabinetes();
}
	
	int op;
	cout << "Deseja buscar outro gabinete? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscargabinetes();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listargabinetes(){

	
	system("cls"); 
	
	cout << "=================== Listar todos os gabinetes ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_gabinete.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de gabinetes ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Gabinetes " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirgabinetes() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Gabinetes ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_gabinete.csv", ios::in); 

    fout.open("attperiferico_gabinete.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_gabinete.csv");
    rename("attperiferico_gabinete.csv", "periferico_gabinete.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro gabinete? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirgabinetes();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarheadset(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Headsets ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_headset.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_headset.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos headsets? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " headsets" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar headsets " << codigo << " ============== \n\n";
  		cout << "Informe o nome do headsets: ";
        getline(cin, nome);
        cout << "Informe o valor do headsets: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarheadset(){
	
	system("cls");
	
	cout << "=================== Pesquisar Headsets ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_headset.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do headsets para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Headsets " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarheadset();
}
	
	int op;
	cout << "Deseja buscar outro headset? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarheadset();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarheadset() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os headsets ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_headset.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de headsets ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Headsets " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirheadset() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Headsets ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_headset.csv", ios::in); 

    fout.open("attperiferico_headset.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_headset.csv");
    rename("attperiferico_headset.csv", "periferico_headset.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro headset? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirheadset();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarimpressora(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas impressoras ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_impressora.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_impressora.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas impressoras ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " impressoras" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar impressoras " << codigo << " ============== \n\n";
  		cout << "Informe o nome da impressora: ";
        getline(cin, nome);
        cout << "Informe o valor da impressora ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
		
		void buscarimpressora(){
	
	system("cls");
	
	cout << "=================== Pesquisar impressoras ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_impressora.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Suportes para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== impressoras " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarimpressora();
}
	
	int op;
	cout << "Deseja buscar outro Suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarimpressora();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarimpressora() {
	
	system("cls"); 
	
	cout << "=================== Listar todas as impressoras ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_impressora.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de impressora================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== impressoras " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirimpressora() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados da impressora ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_impressora.csv", ios::in); 

    fout.open("attperiferico_impressora.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_impressora.csv");
    rename("attperiferico_impressora.csv", "periferico_impressora.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro impressora? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirimpressora();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarled(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas fitas de LED ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_led.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_led.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas Fitas ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " LED " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Fitas " << codigo << " ============== \n\n";
  		cout << "Informe o nome da fita desejada: ";
        getline(cin, nome);
        cout << "Informe o valor da fita: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarled(){
	
	system("cls");
	
	cout << "=================== Pesquisar Fitas de LED ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_led.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da Fita de LED para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Fitas leds " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarled();
}
	
	int op;
	cout << "Deseja buscar outro LED? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarled();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarled() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os LEDs ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_led.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todos LEDs ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Fita LED " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirled() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos LEDs ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_led.csv", ios::in); 

    fout.open("attperiferico_led.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_led.csv");
    rename("attperiferico_led.csv", "periferico_led.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra Fita LED?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirled();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	}

void criarmicrofone(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos microfones ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_microfone.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_microfone.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos microfones ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << "microfone" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar microfones " << codigo << " ============== \n\n";
  		cout << "Informe o nome do microfone: ";
        getline(cin, nome);
        cout << "Informe o valor do microfone ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
			
void buscarmicrofone(){
	
	system("cls");
	
	cout << "=================== Pesquisar microfones ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_microfone.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do microfone para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== microfones " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarmicrofone();
}
	
	int op;
	cout << "Deseja buscar outro Suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarmicrofone();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarmicrofone() {
	
	system("cls"); 
	
	cout << "=================== Listar todas os microfones ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_microfone.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todos microfones================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Microfone " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirmicrofone() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados da microfones ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_microfone.csv", ios::in); 

    fout.open("attperiferico_microfone.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_microfone.csv");
    rename("attperiferico_microfone.csv", "periferico_microfone.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro microfone? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirmicrofone();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarmonitor(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Monitores ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_monitor.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_monitor.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos monitores? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " monitores" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar monitores " << codigo << " ============== \n\n";
  		cout << "Informe o nome do monitores: ";
        getline(cin, nome);
        cout << "Informe o valor do monitores: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarmonitor(){
	
	system("cls");
	
	cout << "=================== Pesquisar Monitores ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_monitor.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do monitores para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Monitores " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarmonitor();
}
	
	int op;
	cout << "Deseja buscar outro mouse? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarmonitor();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarmonitor() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os monitores ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_monitor.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Monitores Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Monitor " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirmonitor() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Monitores ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_monitor.csv", ios::in); 

    fout.open("attperiferico_monitor.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_monitor.csv");
    rename("attperiferico_monitor.csv", "periferico_monitor.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro monitor? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirmonitor();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarmouse(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Mouses ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_mouses.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_mouse.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos mouses? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " mouses" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar mouses " << codigo << " ============== \n\n";
  		cout << "Informe o nome do mouse: ";
        getline(cin, nome);
        cout << "Informe o valor do mouse: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarmouse(){
	
	system("cls");
	
	cout << "=================== Pesquisar Mouses ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_mouse.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Mouse para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Mouses " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarmouse();
}
	
	int op;
	cout << "Deseja buscar outro mouse? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarmouse();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarmouse() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os mouses ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_mouse.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Mouses Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Mouse " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirmouse() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Mouses ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_mouse.csv", ios::in); 

    fout.open("attperiferico_mouse.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_mouse.csv");
    rename("attperiferico_mouse.csv", "periferico_mouse.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro mouse? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirmouse();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarmousepad(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Mousepads ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_mousepad.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_mousepad.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos mousepads? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " mousepads" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar mousepads " << codigo << " ============== \n\n";
  		cout << "Informe o nome do mousepads: ";
        getline(cin, nome);
        cout << "Informe o valor do mousepads: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarmousepad(){
	
	system("cls");
	
	cout << "=================== Pesquisar mousepads ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_mousepad.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do mousepads para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== mousepads " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarmousepad();
}
	
	int op;
	cout << "Deseja buscar outro mousepad? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarmousepad();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarmousepad() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os mousepads ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_mousepad.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Mousepads ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Mousepads " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirmousepad() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos mousepads ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_mousepad.csv", ios::in); 

    fout.open("attperiferico_mousepad.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_mousepad.csv");
    rename("attperiferico_mousepad.csv", "periferico_mousepad.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro mousepad? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirmousepad();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarnobreak(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos No breakers ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_nobreak.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_nobreak.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos no breakers ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " No Break" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar No breakers " << codigo << " ============== \n\n";
  		cout << "Informe o nome do No break: ";
        getline(cin, nome);
        cout << "Informe o valor do No break: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarnobreak(){
	
	system("cls");
	
	cout << "=================== Pesquisar No breakers ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_nobreak.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do No Break para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== No breakers " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarnobreak();
}
	
	int op;
	cout << "Deseja buscar outro no break? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarnobreak();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarnobreak() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os No Breakers ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_nobreak.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todos No Breakers ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== No Breaker " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirnobreak() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos No Breakers ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_nobreak.csv", ios::in); 

    fout.open("attperiferico_nobreak.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_nobreak.csv");
    rename("attperiferico_nobreak.csv", "periferico_nobreak.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro No Break? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirnobreak();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}	

void criarpendrive(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Pendrive ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_pendrive.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_pendrive.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos pendrives? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " pendrives " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar pendrives " << codigo << " ============== \n\n";
  		cout << "Informe o nome do pendrive desejado: ";
        getline(cin, nome);
        cout << "Informe o valor do pendrive: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarpendrive(){
	
	system("cls");
	
	cout << "=================== Pesquisar pendrives ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_pendrive.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo dos pendrives para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== pendrives " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarpendrive();
}
	
	int op;
	cout << "Deseja buscar outro pendrives? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarpendrive();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarpendrive() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os pendrive ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_pendrive.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todas pendrive ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Pendrive " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirpendrive() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos pendrives ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_pendrive.csv", ios::in); 

    fout.open("attperiferico_pendrive.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_pendrive.csv");
    rename("attperiferico_pendrive.csv", "periferico_pendrive.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro pendrive?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirpendrive();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarsuporteheadset(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Suportes de headsets ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_suporteheadset.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_suporteheadset.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos Suportes de headsets ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Suportes de headsets" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Suportes " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Suportes: ";
        getline(cin, nome);
        cout << "Informe o valor do Suportes: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}	
		
void buscarsuporteheadset(){
	
	system("cls");
	
	cout << "=================== Pesquisar Suportes ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_suporteheadset.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Suportes para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Suportes " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarsuporteheadset();
}
	
	int op;
	cout << "Deseja buscar outro Suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarsuporteheadset();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarsuporteheadset() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Suportes ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_suporteheadset.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Suportes ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Suporte Headset " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirsuporteheadset() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Suportes ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_suporteheadset.csv", ios::in); 

    fout.open("attperiferico_suporteheadset.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_suporteheadset.csv");
    rename("attperiferico_suporteheadset.csv", "periferico_suporteheadset.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirsuporteheadset();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarsuportenote(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Suportes de notebooks ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_suportenote.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_suportenote.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos Suportes de notebooks ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Suportes de notebooks" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Suportes " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Suportes: ";
        getline(cin, nome);
        cout << "Informe o valor do Suportes: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarsuportenote(){
	
	system("cls");
	
	cout << "=================== Pesquisar Suportes ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_suportenote.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Suportes para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Suportes " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarsuportenote();
}
	
	int op;
	cout << "Deseja buscar outro Suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarsuportenote();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarsuportenote() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Suportes ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_suportenote.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de suportes de notebook================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Suporte Notebook " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirsuportenote() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Suportes ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_suportenote.csv", ios::in); 

    fout.open("attperiferico_suportenote.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_suportenote.csv");
    rename("attperiferico_suportenote.csv", "periferico_suportenote.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro suporte? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirsuportenote();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarteclado(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Teclados ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_teclado.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_teclado.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos teclados? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " teclados" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar teclados " << codigo << " ============== \n\n";
  		cout << "Informe o nome do teclados: ";
        getline(cin, nome);
        cout << "Informe o valor do teclados: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarteclado(){
	
	system("cls");
	
	cout << "=================== Pesquisar Teclados ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_teclado.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do teclados para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Teclados " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarteclado();
}
	
	int op;
	cout << "Deseja buscar outro teclado? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarteclado();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarteclado() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os teclados ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_teclado.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Teclados Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Teclado " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirteclado() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Teclados ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_teclado", ios::in); 

    fout.open("attperiferico_teclado.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_teclado.csv");
    rename("attperiferico_teclado.csv", "periferico_teclado.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro teclado? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirteclado();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarwebcam(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas webcam ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("periferico_webcam.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("periferico_webcam.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas webcams? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " webcams " << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar webcams " << codigo << " ============== \n\n";
  		cout << "Informe o nome da webcam desejado: ";
        getline(cin, nome);
        cout << "Informe o valor da webcam: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarwebcam(){
	
	system("cls");
	
	cout << "=================== Pesquisar webcams ================== \n\n";
	
	fstream fin;
	
	fin.open("periferico_webcam.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo dos webcams para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== webcams " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarwebcam();
}
	
	int op;
	cout << "Deseja buscar outro webcams? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarwebcam();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarwebcam() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as webcam ================== \n\n";
	
	fstream fin;
    
    fin.open("periferico_webcam.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de todas webcam ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Webcam " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirwebcam() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das webcams ================== \n\n";

    fstream fin, fout; 

    fin.open("periferico_webcam.csv", ios::in); 

    fout.open("attperiferico_webcam.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("periferico_webcam.csv");
    rename("attperiferico_webcam.csv", "periferico_pendrive.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro webcam?? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirwebcam();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void criarprocessador(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Processadores ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_processador.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_processador.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos Processadores? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Processadores" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Processadores " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Processador: ";
        getline(cin, nome);
        cout << "Informe o valor do Processador: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
		
void buscarprocessador(){
	
	system("cls");
	
	cout << "=================== Pesquisar Processadores ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_processador.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Processador para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Processadores " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarprocessador();
}
	
	int op;
	cout << "Deseja buscar outro processador? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarprocessador();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarprocessador() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Processadores ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_processador.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Processadores Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Processadores " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << " % de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << " em até " << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirprocessador() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Processadores ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_processador", ios::in); 

    fout.open("atthardware_processador.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_processador.csv");
    rename("atthardware_processador.csv", "hardware_processador.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro processador? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirprocessador();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarssd(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos SSD ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_ssd.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_ssd.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos SSD? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " SSD" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar SSD " << codigo << " ============== \n\n";
  		cout << "Informe o nome do SSD: ";
        getline(cin, nome);
        cout << "Informe o valor do SSD: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarssd(){
	
	system("cls");
	
	cout << "=================== Pesquisar SSD ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_ssd.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do SSD para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== SSD " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarssd();
}
	
	int op;
	cout << "Deseja buscar outro SSD? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarssd();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarssd() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os SSD ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_ssd.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de SSD Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== SSD " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirssd() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos SSD ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_ssd", ios::in); 

    fout.open("atthardware_ssd.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do SSD que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_ssd.csv");
    rename("atthardware_ssd.csv", "hardware_ssd.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro SSD? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirssd();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarhd(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos HD ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_hd.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_hd.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos HD? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " HD" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar HD " << codigo << " ============== \n\n";
  		cout << "Informe o nome do HD: ";
        getline(cin, nome);
        cout << "Informe o valor do HD: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}	
		
void buscarhd(){
	
	system("cls");
	
	cout << "=================== Pesquisar HD ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_hd.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do HD para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== HD " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarhd();
}
	
	int op;
	cout << "Deseja buscar outro HD? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarhd();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarhd() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os HD ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_hd.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de HD Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== HD " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirhd() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos HD ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_hd", ios::in); 

    fout.open("atthardware_hd.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do HD que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_hd.csv");
    rename("atthardware_hd.csv", "hardware_hd.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro HD? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirhd();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarvga(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas VGA ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_vga.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_vga.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas VGA? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " VGA" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar VGA" << codigo << " ============== \n\n";
  		cout << "Informe o nome do VGA: ";
        getline(cin, nome);
        cout << "Informe o valor do VGA: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
			
void buscarvga(){
	
	system("cls");
	
	cout << "=================== Pesquisar VGA ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_vga.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da VGA para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== VGA " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarvga();
}
	
	int op;
	cout << "Deseja buscar outra VGA? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarvga();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarvga() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as VGA ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_vga.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de VGA Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== VGA " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirvga() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados de VGA ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_vga", ios::in); 

    fout.open("atthardware_vga.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da VGA que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_vga.csv");
    rename("atthardware_vga.csv", "hardware_vga.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra Fonte de VGA? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirvga();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarplacamae(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Placas Mãe ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_placamae.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_placamae.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas placas mãe? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Placas Mãe" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Memórias " << codigo << " ============== \n\n";
  		cout << "Informe o nome da memória: ";
        getline(cin, nome);
        cout << "Informe o valor da memória: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarplacamae(){
	
	system("cls");
	
	cout << "=================== Pesquisar Placa Mãe ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_placamae.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da placa mãe para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Placa mãe " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarplacamae();
}
	
	int op;
	cout << "Deseja buscar outra placa mãe? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarplacamae();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarplacamae() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as Placas Mãe ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_placamae.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de placas Mãe Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Placa mãe " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirplacamae() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Placas Mãe ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_placamae", ios::in); 

    fout.open("atthardware_placamae.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da placa mãe que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_placamae.csv");
    rename("atthardware_placamae.csv", "hardware_placamae.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra placa mãe? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirplacamae();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarmemoria(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Memórias ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_memoria.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_memoria.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas memórias? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Memórias" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Memórias " << codigo << " ============== \n\n";
  		cout << "Informe o nome da memória: ";
        getline(cin, nome);
        cout << "Informe o valor da memória: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarmemoria(){
	
	system("cls");
	
	cout << "=================== Pesquisar Memórias ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_memoria.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da memória para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Memória " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarmemoria();
}
	
	int op;
	cout << "Deseja buscar outra memória? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarmemoria();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarmemoria() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as Memórias ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_memoria.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Memórias Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Memória " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirmemoria() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Memórias ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_memoria", ios::in); 

    fout.open("atthardware_memoria.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da memoria que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_memoria.csv");
    rename("atthardware_memoria.csv", "hardware_memoria.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra memoria? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirmemoria();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarpastatermica(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Pasta Térmica ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_pastatermica.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_pastatermica.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas Pasta Térmica? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Pasta Térmica" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Pasta Térmica " << codigo << " ============== \n\n";
  		cout << "Informe o nome da Pasta Térmica: ";
        getline(cin, nome);
        cout << "Informe o valor da Pasta Térmica: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
			
void buscarpastatermica(){
	
	system("cls");
	
	cout << "=================== Pesquisar Pasta Térmica ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_pastatermica.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da Pasta Térmica para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Pasta Térmica " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarpastatermica();
}
	
	int op;
	cout << "Deseja buscar outra Pasta Térmica? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarpastatermica();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarpastatermica() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as Pasta Térmica ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_pastatermica.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Pasta Térmica Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Pasta Térmica " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirpastatermica() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados das Pasta Térmica ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_pastatermica", ios::in); 

    fout.open("atthardware_pastatermica.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da Pasta Térmica que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_pastatermica.csv");
    rename("atthardware_pastatermica.csv", "hardware_pastatermica.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra Pasta Térmica? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirpastatermica();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarcooler(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Cooler ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_cooler.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_cooler.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos Cooler? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Cooler" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Cooler " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Cooler: ";
        getline(cin, nome);
        cout << "Informe o valor do Cooler: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}	
		
void buscarcooler(){
	
	system("cls");
	
	cout << "=================== Pesquisar Cooler ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_cooler.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do Cooler para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Cooler " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarcooler();
}
	
	int op;
	cout << "Deseja buscar outro Cooler? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarcooler();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarcooler() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Cooler ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_cooler.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Cooler Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Cooler " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluircooler() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Cooler ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_cooler", ios::in); 

    fout.open("atthardware_cooler.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do Cooler que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_cooler.csv");
    rename("atthardware_cooler.csv", "hardware_cooler.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro Pasta Térmica? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircooler();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarfonte(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novas Fontes de Alimentação ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("hardware_fonte.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("hardware_fonte.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantas fonte de alimentação? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Fonte de Alimentação" << "\n\n";
  
    int codigo;
    string nome, valor, descontopix, valorparce, dividido, valordaparcela;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Fonte de Alimentação " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Fonte de Alimentação: ";
        getline(cin, nome);
        cout << "Informe o valor do Fonte de Alimentação: ";
        getline(cin, valor);
        cin.sync();
        cout << "Informe o desconto via PIX: ";
        getline(cin, descontopix);
        cout << "Informe o valor parcelado: ";
        getline(cin, valorparce);
        cout << "Informe a quantidade de vezes divididas: ";
        getline(cin, dividido);
        cout << "Informe o valor da parcela: ";
        getline(cin, valordaparcela);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << descontopix << ", "
			 << valorparce << ", "
             << dividido << ", "
			 << valordaparcela
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}		
		
void buscarfonte(){
	
	system("cls");
	
	cout << "=================== Pesquisar Fonte de Alimentação ================== \n\n";
	
	fstream fin;
	
	fin.open("hardware_fonte.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo da Fonte de Alimentação para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "============== Fonte de Alimentação " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarfonte();
}
	
	int op;
	cout << "Deseja buscar outra Fonte de Alimentação? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarfonte();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarfonte() {
	
	system("cls"); 
	
	cout << "=================== Listar todos as Fontes de Alimentação ================== \n\n";
	
	fstream fin;
    
    fin.open("hardware_fonte.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Fontes de Alimentação Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Fonte de Alimentação " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n\n";
            cout << "À VISTA: R$" << linhas[2] << "\n\n";
            cout << linhas[3] << "% de desconto via PIX" << "\n\n";
            cout << "R$ " << linhas[4] << "em até" << linhas[5] << "x de R$" << linhas[6] << " sem juros \n\n";
            
        cout << "======================================================== \n\n";

    }
	
}

void excluirfonte() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados de Fonte de Alimentação ================== \n\n";

    fstream fin, fout; 

    fin.open("hardware_fonte", ios::in); 

    fout.open("atthardware_fonte.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo da Fonte de Alimentação que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("hardware_fonte.csv");
    rename("atthardware_fonte.csv", "hardware_fonte.csv"); 
    
    int opex; 
	cout << "Deseja excluir outra Fonte de Alimentação? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirfonte();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarcliente(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Clientes ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("clientes.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo;
	
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("clientes.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos clientes? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << z << " Clientes:" << "\n\n";
  
    int codigo, idade;
    string nome, telefone, email, cpf;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Cliente " << codigo << " ============== \n\n";
  		cout << "Informe o nome do cliente: ";
        getline(cin, nome);
        cout << "Informe o telefone do cliente: ";
        getline(cin, telefone);
        cout << "Informe o e-mail do cliente: ";
        getline(cin, email);
        cout << "Informe o idade do cliente: ";
        cin >> idade;
        cin.sync();
        cout << "Informe o cpf do cliente: ";
        getline(cin, cpf);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << telefone << ", "
             << email << ", "
             << idade << ", "
             << cpf
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
				
void buscarcliente(){
	
	system("cls");
	
	cout << "=================== Pesquisar Clientes ================== \n\n";
	
	fstream fin;
	
	fin.open("clientes.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do cliente para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "==============> Cliente " << linhas[0] << " <================ \n\n";
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarcliente();
}
	
	int op;
	cout << "Deseja buscar outro cliente? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarcliente();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarclientes() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Clientes ================== \n\n";
	
	fstream fin;
    
    fin.open("clientes.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Clientes Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Cliente " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            
        cout << "======================================================== \n\n";

    }
	
}
  
void atualizarcliente() {
	
	system("cls"); 
	
	cout << "=================== Atualizar dados dos Clientes ================== \n\n";
	
    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
  
    int linha1, linha2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo do cliente que deseja atualizar os dados: ";
    cin >> linha1;
    cin.sync();

    cout << "==========> Alterar dados do cliente " << linha1 << " <=========== \n\n";
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o telefone, Digite 2. \n";
    cout << "Para alterar o e-mail, Digite 3. \n";
    cout << "Para alterar a idade, Digite 4. \n";
    cout << "Para alterar o cpf, Digite 5. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do cliente <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar telefone do cliente <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar e-mail do cliente <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "==============> Alterar idade do cliente <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "==============> Alterar CPF do cliente <================ \n\n";
  			indice = 5;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizarcliente();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) {
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linha2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linha2 == linha1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo;

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) {
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) {
    	cout << "Dados nao encontrados!!\n\n";
    	atualizarcliente(); 
	}

    fin.close(); 
    fout.close(); 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv");
} 

void excluircliente() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Clientes ================== \n\n";

    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do cliente que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("clientes.csv");
    rename("attclientes.csv", "clientes.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro cliente? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircliente();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void criarfornecedores(){
	
	system("cls");
	
	cout << "=================== Cadastrar Novos Fornecedores ================== \n\n";
	
	fstream fin, fout;
	
	fin.open("fornecedores.csv", ios::in);
	
	vector<string> linhas;
    string linha, palavra, tempo, n;
	
	int x = 0;
  
  	while(fin >> tempo) {
	
	linhas.clear();
	
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	
	while (getline(s, palavra, virgula)) {
		
	linhas.push_back(palavra);
}
	x = stoi(linhas[0]);
	
}

	fout.open("fornecedores.csv", ios::out | ios::app);
	
	int z;
	    
    cout << "Voce quer cadastrar quantos Fornecedores? ";
	cin >> z;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Fornecedores" << "\n\n";
  
    int codigo;
    string nome, telefone, cnpj;
		
	codigo = x;	
		
	  for (int i = 0; i < z; i++) {
    	
    	codigo++;
  		cout << "=========== Cadastrar Fornecedores " << codigo << " ============== \n\n";
  		cout << "Informe o nome do Fornecedor: ";
        getline(cin, nome);
        cout << "Informe o telefone do Fornecedor: ";
        getline(cin, telefone);
        cin.sync();
        cout << "Informe o CNPJ do Fornecedor: ";
        getline(cin, cnpj);
        cout << "======================================================= \n\n";	
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << telefone << ", "
             << cnpj
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}
			
void buscarfornecedores(){
	
	system("cls");
	
	cout << "=================== Pesquisar Fornecedores ================== \n\n";
	
	fstream fin;
	
	fin.open("fornecedores.csv", ios::in);
	
	int linha1, linha2, cont = 0;
	
	cout << "Digite o codigo do fornecedor para visualizar seus dados: ";
    cin >> linha1;
	
	vector<string> linhas;
	
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
	
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
	
		while (getline(s, palavra, virgula)) {
	
			linhas.push_back(palavra);
	 }
	
		linha2 = stoi(linhas[0]);
	
		if (linha2 == linha1) {
	
			cont = 1;
            cout << "==============> Fornecedor " << linhas[0] << " <================ \n\n";
            cout << "Codigo: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "CNPJ: " << linhas[3] << "\n";
            cout << "======================================================== \n\n";
            break;
        }
    }
	
	if (cont == 0) {
		
		cout << "Dados nao encontrados... \n";
		buscarfornecedores();
}
	
	int op;
	cout << "Deseja buscar outro fornecedor? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;
	
	switch(op) {
    	case 1:
			buscarfornecedores();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
}

void listarfornecedores() {
	
	system("cls"); 
	
	cout << "=================== Listar todos os Fornecedores ================== \n\n";
	
	fstream fin;
    
    fin.open("fornecedores.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "============== Lista de Fornecedores Cadastrados ================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }

		cout << "============== Fornecedores " << linhas[0] << " ================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "CPF: " << linhas[3] << "\n";
            
        cout << "======================================================== \n\n";

    }
	
}
  
void atualizarfornecedores() {
	
	system("cls"); 
	
	cout << "=================== Atualizar dados dos Fornecedores ================== \n\n";
	
    fstream fin, fout; 

    fin.open("fornecedores.csv", ios::in); 

    fout.open("attfornecedores.csv", ios::out); 
  
    int linha1, linha2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "Digite o codigo do fornecedor que deseja atualizar os dados: ";
    cin >> linha1;
    cin.sync();

    cout << "==========> Alterar dados do Fornecedor " << linha1 << " <=========== \n\n";
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o telefone, Digite 2. \n";
    cout << "Para alterar o cnpj, Digite 3. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "==============> Alterar nome do Fornecedor <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "==============> Alterar telefone do Fornecedor <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "==============> Alterar CNPJ do Fornecedor <================ \n\n";
  			indice = 3;
  			break;
  		default:
	        cout << "Opçao Invalida!! \n";
	        atualizarfornecedores();
			break;  			
	  }

    cout << "Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) {
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linha2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linha2 == linha1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo;

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) {
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) {
    	cout << "Dados nao encontrados!!\n\n";
    	atualizarcliente(); 
	}

    fin.close(); 
    fout.close(); 

    remove("fornecedores.csv"); 
    rename("attfornecedores.csv", "clientes.csv");
} 

void excluirfornecedores() {
	
	system("cls"); 
	
	cout << "=================== Excluir dados dos Fornecedores ================== \n\n";

    fstream fin, fout; 

    fin.open("fornecedores", ios::in); 

    fout.open("attfornecedores.csv", ios::out); 
  
    int linha1, linha2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas;

	cout << "Digite o codigo do fornecedor que deseja excluir os dados: ";
    cin >> linha1;

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ',';
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linha2 = stoi(linhas[0]);

        if (linha2 != linha1) {
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close();
    fout.close();

    remove("fornecedores.csv");
    rename("attfornecedores.csv", "fornecedores.csv"); 
    
    int opex; 
	cout << "Deseja excluir outro fornecedor? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirfornecedores();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

void login(){

string cod;
int senha, a;

a = 12345;
// LOGIN


cout << "Digite seu usuário: ";
cin >> cod;

cout << "Digite sua senha: ";
cin >> senha;


if (senha==a){
	
	system("cls");
	
} else{
	
	system("cls");
	cout << "USUÁRIO E/OU SENHA INCORRETOS \n";
	login();

}
}

void hard(){
 	
 	int had, v;
					
				cout << "Digite a opção conforme o número: \n\n";
				cout << "[1] PROCESSADORES \n\n";
				cout << "[2] MEMÓRIAS \n\n";
				cout << "[3] PLACA MÃE \n\n";
				cout << "[4] HD \n\n";
				cout << "[5] SSD \n\n";
				cout << "[6] VGA \n\n";
				cout << "[7] PASTA TÉRMICA \n\n";
				cout << "[8] COOLER \n\n";
				cout << "[9] FONTES DE ALIMENTAÇÃO \n\n";
				cout << "[0] VOLTAR \n\n";	
				
}

void peri(){
 	
 					cout << "Digite a opção conforme o número: \n\n";
					cout << "[1] MOUSE \n\n";
					cout << "[2] MONITORES \n\n";
					cout << "[3] TECLADO \n\n";
					cout << "[4] HEADSET \n\n";
					cout << "[5] MOUSE PAD \n\n";
					cout << "[6] GABINETES \n\n";
					cout << "[7] SUPORTE HEADSET \n\n";
					cout << "[8] SUPORTE P/ NOTEBOOK \n\n";
					cout << "[9] IMPRESSORA \n\n";
					cout << "[10] MICROFONES \n\n";
					cout << "[11] ESTABILIZADOR \n\n";
					cout << "[12] NO BREAK \n\n";
					cout << "[13] FITA DE LED \n\n";
					cout << "[14] CAIXA DE SOM \n\n";
					cout << "[15] CABOS \n\n";
					cout << "[16] CONTROLE WIRELESS \n\n";
					cout << "[17] PEN DRIVE \n\n";
					cout << "[18] WEBCAM \n\n";
					cout << "[0] VOLTAR \n\n";
 	
 }

void produtos(){
	
	system("cls");
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] HARDWARE \n\n";
	cout << "[2] PERIFÉRICOS \n\n";
	cout << "[3] PRODUTOS VENDIDOS \n\n";
	cout << "[0] VOLTAR \n\n";

	
		
}

void clientes(){
	
	system("cls");
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] CADASTRAR NOVO CLIENTE \n\n";
	cout << "[2] LISTAR TODOS \n\n";
	cout << "[3] PESQUISAR CLIENTE \n\n";
	cout << "[4] ATUALIZAR DADOS \n\n";
	cout << "[5] EXCLUIR \n\n";
	cout << "[0] VOLTAR \n\n";

		
		
}

void fornecedor(){
	
	system("cls");
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] CADASTRAR NOVO FORNECEDOR \n\n";
	cout << "[2] LISTAR TODOS \n\n";
	cout << "[3] PESQUISAR FORNECEDOR \n\n";
	cout << "[4] ATUALIZAR DADOS \n\n";
	cout << "[5] EXCLUIR \n\n";
	cout << "[0] VOLTAR \n\n";


}

void cpx(){
	
	
	system("cls");
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] CADASTRAR NOVO HARDWARE\n\n";
	cout << "[2] CADASTRAR NOVO PERIFÉRICO \n\n";
	cout << "[3] EXCLUIR HARDWARE \n\n";
	cout << "[4] EXCLUIR PERIFÉRICO \n\n";
	cout << "[5] PESQUISAR HARDWARE \n\n";
	cout << "[6] PESQUISAR PERIFÉRICO \n\n";
	cout << "[0] VOLTAR \n\n";

		
}

void ajuda(){

	system("cls");
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] COMO RESETAR A SENHA? \n\n";
	cout << "[2] COMO NAVEGAR PELOS MENUS? \n\n";
	cout << "[3] O PROGRAMA É SEGURO? \n\n";
	cout << "[4] CONTATOS PARA SUPORTE: \n\n";
	cout << "[0] VOLTAR \n\n";

}

void sobre(){
	int g;
	system("cls");
	cout << "Desenvolvido com a finalizade de automatizar produtos, cadastros e vendas. \n\n";
	cout << "VERSÃO:  1.0.0.1 \n\n";
	cout << "FORNECIDO POR:  NORT DESENVOLVIMENTOS \n\n";
	cout << "DIREITOS RESERVADOS POR:  GGHARDWARE E NORT DESENVOLVIMENTOS \n\n";
	cout << "[0] VOLTAR \n\n";
}

void menu(){

	
	int a, b, c, d, e, f, g, per, had, p, y, cc, dd, mo, ab, yz, pp, zy, mm, nn, oo, qq, rr, ss, tt, uu, v, qi, qe, qa;
	
	cout << "Digite a opção conforme o número: \n\n";
	cout << "[1] PRODUTOS \n\n";
	cout << "[2] CLIENTES \n\n";
	cout << "[3] FORNECEDORES \n\n";
	cout << "[4] CADASTRAR, PESQUISAR OU EXCLUIR PRODUTOS \n\n";
	cout << "[5] AJUDA \n\n";
	cout << "[6] SOBRE \n\n";
	cout << "[0] ENCERRAR \n\n";
	cin >> a;

	switch (a){
	
	
		
	case 1:
	
	system("cls");
	produtos();
	cin >> b;
	
		switch(b){
				
					case 1:

					system("cls");
					hard();
					cin >> had;
					switch(had){
		
		
		case 1:
			
			system("cls");
			listarprocessador();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
		if (v==0){
							system("cls");
								menu();
										}
			break;
			
		
		case 2:
			
			system("cls");
			listarmemoria();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
							system("cls");
								menu();
										}
			break;
		
		
		case 3:
			
			system("cls");
			listarplacamae();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
							system("cls");
								menu();
										}
			break;
		
		
		case 4:
		
			system("cls");
			listarhd();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
							system("cls");
								menu();
										}
			break;
		
		
		case 5: 
		
			system("cls");
			listarssd();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
							system("cls");
								menu();
										}
			break;
		
		
		case 6:
			
			system("cls");
			listarvga();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
							system("cls");
								menu();
										}
			break;
		
		
		case 7:
		
			system("cls");
			listarpastatermica();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
						system("cls");	
								menu();
										}
			break;
			
		case 8:
			
			system("cls");
			listarcooler();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
			system("cls");
			menu();
										}
			break;
			
		case 9:
			
			system("cls");
			listarfonte();
			cout << "\n\n";
			cout << "[0] VOLTAR ";
			cin >> v;
			system("cls");
			if (v==0){
			system("cls");
			menu();
										}
			break;
			
			case 0:
					
					system("cls");
					if (v==0){
								system("cls");
								menu();
										}
					break;

}

					break;
		
					case 2:
			
					system("cls");
					peri();	
					cin >> per;		
					if (per==0){
						
						menu();
					}
					
					switch(per){
						
						case 1:
						system("cls");
						listarmouse();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
							system("cls");
							menu();
										}
						break;	
						
						case 2:
						system("cls");
						listarmonitor();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 3:
						system("cls");
						listarteclado();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 4:
						system("cls");
						listarheadset();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}	
						break;	
						
						case 5:
						system("cls");
						listarmousepad();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 6:
						system("cls");
						listargabinetes();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 7:
						system("cls");
						listarsuporteheadset();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 8:
						system("cls");
						listarsuportenote();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 9:
						system("cls");
						listarimpressora();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 10:
						system("cls");
						listarmicrofone();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 11:
						system("cls");
						listarestabilizador();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}	
						break;	
						
						case 12:
						system("cls");
						listarnobreak();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 13:
						system("cls");
						listarled();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}	
						break;	
						
						case 14:
						system("cls");
						listarcaixadesom();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
							system("cls");
								menu();
										}
						break;	
						
						case 15:
						system("cls");
						listarcabos();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}	
						break;	
						
						case 16:
						system("cls");
						listarcontrole();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
						if (qe==0){
								system("cls");
								menu();
										}
						break;	
						
						case 17:
						system("cls");
						listarpendrive();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
					if (qe==0){
						system("cls");
							menu();
										}
						break;	
						
						case 18:
						system("cls");
						listarwebcam();
						cout << "\n\n";
						cout << "[0] VOLTAR ";
						cin >> qe;
						system("cls");
							if (qe==0){
								system("cls");
								menu();
										}	
						break;	
					case 0:
						system("cls");
						menu();
						break;
					
					}
					
					break;
					
					case 3:
						
						system("cls");
						cout << "[1] LISTAR VENDAS";
						cout << "[2] CADASTRAR VENDAS";
						cout << "[3] ATUALIZAR VENDAS";
						cout << "[4] EXCLUIR VENDAS";
						cout << "[0] VOLTAR";
						cin >> qi;
						
						switch(qi){
							
							
							case 1:
								system("cls");
								listarvenda();
								cout << "\n\n";
								cout << "[0] VOLTAR \n";
								cin >> qa;
								if (qa==0){
								system("cls");
								menu();
										}
								break;
							case 2:
								system("cls");
								adicionarvenda();
								cout << "\n\n";
								cout << "[0] VOLTAR \n";
								cin >> qa;
									if (qa==0){
								system("cls");
								menu();
										}
								break;	
							case 3:
								system("cls");
								atualizarvenda();
								cout << "\n\n";
								cout << "[0] VOLTAR \n";
								cin >> qa;
									if (qa==0){
								system("cls");
								menu();
										}
								break;	
							case 4:
								system("cls");
								excluirvenda();
								cout << "\n\n";
								cout << "[0] VOLTAR \n";
								cin >> qa;
									if (qa==0){
								system("cls");
								menu();
										}
								break;	
							case 0:
								system("cls");
								cout << "\n\n";
								cout << "[0] VOLTAR \n";
								cin >> qa;
								if (qa==0){
								system("cls");
								menu();
										}
								break;	
								
								
						}
						
						case 0:
							system("cls");
							menu();
							break;
}
	
	break;
	

	case 2:
	
	system("cls");
	clientes();
	cin >> c;
	
		switch(c){
			
			case 1:
				
				system("cls");
				criarcliente();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> cc;
				if (cc==0){
				system("cls");
				menu();
			}
				break;
				
			case 2:
			
				system("cls");
				listarclientes();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> cc;
				if (cc==0){
				system("cls");
				menu();
			}
				break;
				
			case 3:
			
				system("cls");
				buscarcliente();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> cc;
				if (cc==0){
				system("cls");
				menu();
			}
				break;
				
			case 4:
			
				system("cls");
				atualizarcliente();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> cc;
				if (cc==0){
				system("cls");
				menu();
			}
				break;
				
			case 5:
			
				system("cls");
				excluircliente();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> cc;
				if (cc==0){
				system("cls");
				menu();
			}
				break;
			case 0:
				system("cls");
				menu();
				break;
		
		}


	break;	
		
	case 3:
	
	system("cls");
	fornecedor();
	cin >> d;
	
	switch(d){
			
		
	
			case 1:
				
				system("cls");
				criarfornecedores();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> dd;
				if (dd==0){
				system("cls");
				menu();
			}
				break;
				
			case 2:
			
				system("cls");
				listarfornecedores();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> dd;
				if (dd==0){
				system("cls");
				menu();
			}
				break;
				
			case 3:
			
				system("cls");
				buscarfornecedores();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> dd;
				if (dd==0){
				system("cls");
				menu();
			}
				break;
				
			case 4:
			
				system("cls");
				atualizarfornecedores();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> dd;
			if (dd==0){
				system("cls");
				menu();
			}
				break;
				
			case 5:
			
				system("cls");
				excluirfornecedores();
				cout << "\n\n";
				cout << "[0] VOLTAR \n\n";
				cin >> dd;
				if (dd==0){
			system("cls");
				menu();
			}
				break;
				
				case 0:
					system("cls");
					menu();
					break;
		}

	
	break;	

	
	case 4:
	
	system("cls");
	cpx();	
	cin >> ab;
	
	switch(ab){
	
	
		case 1:
			
			system("cls");
			hard();
			cin >> yz;
			
			
			switch(yz){
		
				case 1:
					
					system("cls");
					criarprocessador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					criarmemoria();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
				
				case 3:
					
					system("cls");
					criarplacamae();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
					system("cls");	
					menu();
					}
					break;
				
				case 4:
					
					system("cls");
					criarhd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
				
				case 5:
					
					system("cls");
					criarssd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					criarvga();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					criarpastatermica();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					criarcooler();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					criarfonte();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> pp;
					if(pp==0){
					system("cls");	
					menu();
					}
					break;
			
				case 0:
				system("cls");
				menu();
				break;				
			}

						break;
		
		case 2:
		
		system("cls");
		peri();
		cin >> yz;
		
		switch(yz){
				
			case 1:
					
					system("cls");
					criarmouse();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					criarmonitor();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
					system("cls");	
					menu();
					}
					break;
				
				case 3:
					
					system("cls");
					criarteclado();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
					system("cls");	
					menu();
					}
					break;
				
				case 4:
					
					system("cls");
					criarheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
					system("cls");	
					menu();
					}
					break;
				
				case 5:
					
					system("cls");
					criarmousepad();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					criargabinetes();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					criarsuporteheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					criarsuportenote();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					criarimpressora();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 10:
					
					system("cls");
					criarmicrofone();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 11:
					
					system("cls");
					criarestabilizador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
				
				case 12:
					
					system("cls");
					criarnobreak();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
				
				case 13:
					
					system("cls");
					criarled();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
				
				case 14:
					
					system("cls");
					criarcaixadesom();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
					
				case 15:
					
					system("cls");
					criarcabos();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;
				
				case 16:
					
					system("cls");
					criarcontrole();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
					system("cls");	
					menu();
					}
					break;	
					
				case 17:
					
					system("cls");
					criarpendrive();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;	
					
				case 18:
					
					system("cls");
					criarwebcam();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> zy;
					if(zy==0){
						system("cls");
						menu();
					}
					break;	
					
				case 0:
				system("cls");
				menu();
				break;		
			}	
		
		
		break;
		
		case 3:	
		
			system("cls");
			hard();
			cin >> mm;
			
			
			switch(mm){
		
				case 1:
					
					system("cls");
					excluirprocessador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					excluirmemoria();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
				
				case 3:
					
					system("cls");
					excluirplacamae();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
				
				case 4:
					
					system("cls");
					excluirhd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
				
				case 5:
					
					system("cls");
					excluirssd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					excluirvga();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					excluirpastatermica();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					excluircooler();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					excluirfonte();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> nn;
					if(nn==0){
						system("cls");
						menu();
					}
					break;
				
				case 0:
				system("cls");
				menu();
				break;	
			}
		
		break;
		
		case 4:
		system("cls");
		peri();
		cin >> oo;
		
		switch(oo){
				
			case 1:
					
					system("cls");
					excluirmouse();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					excluirmonitor();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 3:
					
					system("cls");
					excluirteclado();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 4:
					
					system("cls");
					excluirheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 5:
					
					system("cls");
					excluirmousepad();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					excluirgabinetes();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					excluirsuporteheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					excluirsuportenote();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					excluirimpressora();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 10:
					
					system("cls");
					excluirmicrofone();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 11:
					
					system("cls");
					excluirestabilizador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 12:
					
					system("cls");
					excluirnobreak();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 13:
					
					system("cls");
					excluirled();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 14:
					
					system("cls");
					excluircaixadesom();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
					
				case 15:
					
					system("cls");
					excluircabos();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;
				
				case 16:
					
					system("cls");
					excluircontrole();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;	
					
				case 17:
					
					system("cls");
					excluirpendrive();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;	
					
				case 18:
					
					system("cls");
					excluirwebcam();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> qq;
					if(qq==0){
						system("cls");
						menu();
					}
					break;		
					
				case 0:
				system("cls");
				menu();
				break;	
			}
		break;
		
		case 5:
			system("cls");
			hard();
			cin >> rr;
			
			
			switch(rr){
		
				case 1:
					
					system("cls");
					buscarprocessador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					buscarmemoria();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
				
				case 3:
					
					system("cls");
					buscarplacamae();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
					system("cls");	
					menu();
					}
					break;
				
				case 4:
					
					system("cls");
					buscarhd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
				
				case 5:
					
					system("cls");
					buscarssd();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					buscarvga();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					buscarpastatermica();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					buscarcooler();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					buscarfonte();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> ss;
					if(ss==0){
						system("cls");
						menu();
					}
					break;
				
				case 0:
				system("cls");
				menu();
				break;
					
			}
		break;
		
		case 6:
				
		system("cls");
		peri();
		cin >> tt;
		
		switch(tt){
				
			case 1:
					
					system("cls");
					buscarmouse();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 2:
					
					system("cls");
					buscarmonitor();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 3:
					
					system("cls");
					buscarteclado();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
					system("cls");	
					menu();
					}
					break;
				
				case 4:
					
					system("cls");
					buscarheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 5:
					
					system("cls");
					buscarmousepad();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 6:
					
					system("cls");
					buscargabinetes();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 7:
					
					system("cls");
					buscarsuporteheadset();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;	
					
				case 8:
					
					system("cls");
					buscarsuportenote();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 9:
					
					system("cls");
					buscarimpressora();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 10:
					
					system("cls");
					buscarmicrofone();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 11:
					
					system("cls");
					buscarestabilizador();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 12:
					
					system("cls");
					buscarnobreak();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 13:
					
					system("cls");
					buscarled();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 14:
					
					system("cls");
					buscarcaixadesom();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
				case 15:
					
					system("cls");
					buscarcabos();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;
				
				case 16:
					
					system("cls");
					buscarcontrole();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;	
					
				case 17:
					
					system("cls");
					buscarpendrive();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					if(uu==0){
						system("cls");
						menu();
					}
					break;	
					
				case 18:
					
					system("cls");
					buscarwebcam();
					cout << "\n\n";
					cout << "[0] VOLTAR \n\n";
					cin >> uu;
					cpx();
					if(uu==0){
						system("cls");
						menu();
					}
					break;
					
					case 0 :
						system("cls");
						menu();
						break;
						
			}
		break;
	
		case 0:
		system("cls");
		menu();
		break;
}

	
	break;
	
	case 5:
	
	system("cls");
	ajuda();
	cin >> f;
	
	switch(f){
		
		case 1:
			
			system("cls");
			cout << "Recomendamos ligar para o suporte que é a 4º opção deste menu para efeturar a mudança com um de nossos técnicos.";
			cout << "\n\n";
			cout << "[0] VOLTAR \n\n";
			cin >> y;
			system("cls");
			if (y==0){
				menu();
			}
			break;
					
		case 2:
			
			system("cls");
			cout << "O programa foi enumerado para facilitar e agilizar as tarefas do dia a dia.";
			cout << "\n\n";
			cout << "[0] VOLTAR \n\n";
			cin >> y;
			system("cls");
			if (y==0){
				menu();
			}
			break;
			
		case 3:
			
			system("cls");
			cout << "Sim. Desenvolvemos o programa para um único usuário, assim, terá mais segurança e um suporte 24horas a sua disposição.";
			cout << "\n\n";
			cout << "[0] VOLTAR \n\n";
			cin >> y;
			system("cls");
			if (y==0){
			menu();
			}
			break;
			
		case 4:
			
			system("cls");
			cout << "nortdesenvolvimentos@gmail.com \n";
			cout << "(31) 9 8299-6238  -  NIKOLAS \n";
			cout << "(31) 9 8916-8854  -  OTÁVIO \n";
			cout << "(31) 9 7171-7844  -  RAQUEL \n";
			cout << "(31) 9 9851-8179  -  THALLES \n";
			cout << "\n\n";
			cout << "[0] VOLTAR \n\n";
			cin >> y;
			system("cls");
			if (y==0){
				menu();
			}
			break;
	case 0:
		system("cls");
		menu();
		break;
}
	
	break;	
	
	
	case 6:
	
	
	system("cls");
	sobre();
	cin >> g;
	if(g==0){
		system("cls");
			menu();
	}

	
	break;
	
	case 0:
	
	system("cls");
	login();
	
	break;	

}
}


int main(int argc, char** argv) {

setlocale(LC_ALL, "Portuguese");

cout<<"       ___________________________   \n";
cout<<"      |[]                        []|\n";
cout<<"      |[] GGHARDWARE             []|\n";
cout<<"      |                            |\n";
cout<<"      |            . .             |\n";
cout<<"      |          `    _`           |\n";
cout<<"      |         `  ()|_|`          |\n";
cout<<"      |         `       `          |\n";
cout<<"      |          ` . . `           |\n";
cout<<"      |      ________________      |\n";
cout<<"      |     |          ____  |     |\n";
cout<<"      |     |         |    | |     |\n";
cout<<"      |     | 235KB   |    | |     |\n";
cout<<"      |     |         |    | |     |\n";
cout<<"      |()   |         |_  _| |   ()|\n";
cout<<"      |)    |           --   |    (|\n";
cout<<"      |_____|[]______________|\___/\n";


cout<< "\n\n\n\n\n";


cout<< "     ########  ######## ##     ##      ##     ##  ####  ##    ## ########   #######  \n";
cout<< "     ##     ## ##       ###   ###      ##     ##   ##   ###   ## ##     ## ##     ## \n";
cout<< "     ##     ## ##       #### ####      ##     ##   ##   ####  ## ##     ## ##     ## \n";
cout<< "     ########  ######   ## ### ##      ##     ##   ##   ## ## ## ##     ## ##     ## \n";
cout<< "     ##     ## ##       ##     ##       ##   ##    ##   ##  #### ##     ## ##     ## \n";
cout<< "     ##     ## ##       ##     ##        ## ##     ##   ##   ### ##     ## ##     ## \n";
cout<< "     ########  ######## ##     ##         ###     ####  ##    ## ########   #######  \n";

cout<< "\n\n\n\n\n";

login();
system("cls");
menu();



//	return 0;
system("pause");


}
