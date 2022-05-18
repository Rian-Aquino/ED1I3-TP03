#include <iostream>
#include <string>
using  namespace std;

struct Lista
{
	int prontuario;
	string nome;
	double salario;
	Lista* ant;
};

Lista* init()
{
	return NULL;
}

Lista* insert(Lista* lista, int prontuario, string nome, double salario )
{
	Lista* novo = new Lista();
	
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
	    if(prontuario != aux->prontuario) {
		    aux = aux->ant;
	    } else {
	        throw invalid_argument( " X Prontuário já existente, tente novamente." );
	    }
	}
	
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->ant = lista;
	
	return novo;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	
	cout << "--------------------------------" << endl << endl;
	
	double totalSalarios = 0;
	
	while (aux != NULL)
	{
        totalSalarios += aux->salario;
        
    	cout << " - Prontuário: " << aux->prontuario << endl;
    	cout << " - Nome: " << aux->nome << endl;
    	cout << " - Salário: R$" << aux->salario << endl << endl;
    	
		aux = aux->ant;
	}
	
	cout << " - Salário Total: R$" << totalSalarios << endl << endl;
	
	cout << "--------------------------------" << endl;
}

Lista* find(Lista* lista, int prontuario)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario)
	{
		aux = aux->ant;
	}
	
	cout << "--------------------------------" << endl;
	cout << " - Prontuário: " << aux->prontuario << endl;
	cout << " - Nome: " << aux->nome << endl;
	cout << " - Salário: R$" << aux->salario << endl;
	cout << "--------------------------------" << endl << endl;
	
	return aux;
}

Lista* remove(Lista* lista, int prontuario)
{
	Lista *aux;
	
	Lista *anterior = NULL;

	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario)
	{
		anterior = aux;
		aux = aux->ant;
	}
	
	if (aux == NULL)
	{
		return lista;
	}
	
	if (anterior == NULL)
	{
		lista = aux->ant; 
	}
	
	else
	{
   	    anterior->ant = aux->ant;
	}
	
	free(aux);
	return lista;
}

int main(int argc, char** argv)
{
    int seletor;
    Lista* minhaLista;
    minhaLista = init();
    
    do{
        
        cout << "Escolha uma das opções: " << endl
             << " 0. Sair " << endl
             << " 1. Incluir" << endl
             << " 2. Excluir" << endl
             << " 3. Pesquisar" << endl
             << " 4. Listar" << endl;
             
        cout << " -> ";
        cin >> seletor;
        cout << endl;
        
        int prontuario;
        string nome;
        double salario;
        
        switch(seletor) {
            case 0:
                cout << " - Fim do programa.";
                break;
                
            case 1:
                cout << "Cadastro de Funcionário: " << endl;
                
                cout << " > Prontuário: ";
                cin >> prontuario;
                
                cout << " > Nome: ";
                cin >> nome;
                
                cout << " > Salário: ";
                cin >> salario;
                
                try {
                    minhaLista = insert(minhaLista, prontuario, nome, salario);
                    cout << endl << " - Usuário cadastrado com sucesso." << endl << endl;
                }
                    catch (invalid_argument& e) {
                        cout << endl;
                        cerr << e.what() << endl; 
                        cout << endl;
                    }
                break;
            
            case 2:
                cout << "Digite o prontuário do Funcionário desejado: ";
                cin >> prontuario;
                
                minhaLista = remove(minhaLista, prontuario);
                cout << endl << " - Funcionário excluído com sucesso." << endl << endl;
                break;
                
            case 3:
                cout << "Digite o prontuário do Funcionário desejado: ";
                cin >> prontuario;
                
                find(minhaLista, prontuario);
                break;
                
            case 4:
                print(minhaLista);
                break;
                
            default:
                cout << " - Digite um seletor válido! " << endl << endl;
                break;
        }
        
    } while(seletor != 0);

    return 0;
}    