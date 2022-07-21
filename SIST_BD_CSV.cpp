#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void criar() {
	
	system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout << "===================> Cadastrar Novos Clientes <================== \n\n";
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("clientes.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos clientes? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Clientes:" << "\n\n";
  
    int codigo, idade;
    string nome, telefone, email, cpf;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "===========> Adicionar Cliente " << codigo << " <============== \n\n";
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
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << telefone << ", "
             << email << ", "
             << idade << ", "
             << cpf
             << "\n";
    }
	cout << "Dados Gravados com Sucesso! \n";
}

void buscar_dados() {
	
	system("cls");  // Limpar tela anterior e exibir parte buscar clientes.
	
	cout << "===================> Pesquisar Clientes <================== \n\n";

    fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    cout << "Digite o codigo do cliente para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
        
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, mostre o cliente correspondente a ela.
  
            cont = 1; // caso seja verdadeira a condição
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
    if (cont == 0) { // condição explicado acima.
        cout << "Dados nao encontrados... \n";
        buscar_dados(); // retorna ao inicio da busca.
	}
	int op; // Opções de pesquisar novamente ou sair desta ação de busca.
	cout << "Deseja buscar outro cliente? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> op;	
    
    switch(op) {
    	case 1:
			buscar_dados();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			buscar_dados();
			break;
	} 
} 

void listar_todos() {
	
	system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	
	cout << "===================> Listar todos os Clientes <================== \n\n";
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
    
    cout << "==============> Lista de Clientes Cadastrados <================ \n\n";
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "==============> Cliente " << linhas[0] << " <================ \n\n";
		
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            
        cout << "======================================================== \n\n";

    }
	
}
  
void atualizar() {
	
	system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	
	cout << "===================> Atualizar dados dos Clientes <================== \n\n";
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attclientes.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o codigo do cliente que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "==========> Alterar dados do cliente " << linhan1 << " <=========== \n\n";
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o telefone, Digite 2. \n";
    cout << "Para alterar o e-mail, Digite 3. \n";
    cout << "Para alterar a idade, Digite 4. \n";
    cout << "Para alterar o cpf, Digite 5. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
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
	        atualizar();
			break;  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { // Caso condição falsa
    	cout << "Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizar(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("clientes.csv"); // Remove o arquivo
    rename("attclientes.csv", "clientes.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
} 

void excluir() {
	
	system("cls"); // Limpar tela anterior e exibir parte de excluir dados dos clientes.
	
	cout << "===================> Excluir dados de Clientes <================== \n\n";

    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attclientes.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

	cout << "Digite o codigo do cliente que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("clientes.csv"); // Remove o arquivo
    rename("attclientes.csv", "clientes.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    int opex; // Opções de excluir novamente ou sair desta ação de deletar dados.
	cout << "Deseja excluir outro cliente? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluir();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}

int main(int argc, char** argv) { // Inicialização do programa
	
	int fim = 1;
	
	while(fim != 0) {
	
		int opcao;
	
		cout << "===================> MENU PRINCIPAL <================== \n\n";
		cout << "Digite uma opcao: 1- Gravar dados, 2- Buscar Dados, 3- Listar dados, 4- Atualizar, 5- Excluir, 0- Sair \n";
		cout << "=> ";
		cin >> opcao;
		
		switch(opcao) {
			
			case 1:
				criar();
				break;
			
			case 2:
				buscar_dados();
				break;
			
			case 3:
				listar_todos();
				break;
				
			case 4:
				atualizar();
				break;
			
			case 5:
				excluir();
				break;
				
			case 0:
				fim = 0;
				break;
				
			default:
				cout << "Opçao invalida! ";
				break;	
		}
		
		if(fim == 1) {
			cout << "Digite: 1- Voltar ao menu, 0- Sair. \n";
			cout << "=>";
			cin >> fim;
			system("cls");
			
		} else {
			continue;
		}
	}
	return 0;
}
