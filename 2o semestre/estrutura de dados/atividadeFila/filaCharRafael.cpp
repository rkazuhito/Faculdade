#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    
    Node(char data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void zerarLista() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Lista zerada." << endl;
    }
    
    void exibirLista() {
        if (head == nullptr) {
            cout << "Lista vazia." << endl;
            return;
        }
        Node* current = head;
        cout << "Lista: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void adicionarInicio(char value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node adicionado no inicio." << endl;
    }
    
    void adicionarFinal(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            cout << "Node adicionado no final." << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << "Node adicionado no final." << endl;
    }
    
    void adicionarPosicao(char value) {
        cout << "Função de adicionar em posição não implementada." << endl;
    }
    
    void retirarInicio() {
        if (head == nullptr) {
            cout << "Lista vazia, nada a retirar." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node retirado do inicio." << endl;
    }
    
    void retirarFinal() {
        if (head == nullptr) {
            cout << "Lista vazia, nada a retirar." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node retirado do final." << endl;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        cout << "Node retirado do final." << endl;
    }
    
    void retirarPosicao() {
        cout << "Função de retirar em posição não implementada." << endl;
    }
    
    void mostrarMenu() {
        char opt;
        do {
            cout << "Escolha a opcao\n";
            cout << "0. Sair\n";
            cout << "1. Zerar lista\n";
            cout << "2. Exibir lista\n";
            cout << "3. Adicionar node no inicio\n";
            cout << "4. Adicionar node no final\n";
            cout << "5. Escolher onde inserir\n";
            cout << "6. Retirar do inicio\n";
            cout << "7. Retirar do fim\n";
            cout << "8. Escolher de onde tirar\n";
            cout << "Opcao: ";
            cin >> opt;
            
            switch(opt) {
                case '0':
                    cout << "Saindo..." << endl;
                    break;
                case '1':
                    zerarLista();
                    break;
                case '2':
                    exibirLista();
                    break;
                case '3': {
                    char value;
                    cout << "Digite o valor a ser adicionado no inicio: ";
                    cin >> value;
                    adicionarInicio(value);
                    break;
                }
                case '4': {
                    char value;
                    cout << "Digite o valor a ser adicionado no final: ";
                    cin >> value;
                    adicionarFinal(value);
                    break;
                }
                case '5': {
                    char value;
                    cout << "Digite o valor a ser adicionado na posicao: ";
                    cin >> value;
                    adicionarPosicao(value);
                    break;
                }
                case '6':
                    retirarInicio();
                    break;
                case '7':
                    retirarFinal();
                    break;
                case '8':
                    retirarPosicao();
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
            }
        } while(opt != '0');
    }
};

int main() {
    LinkedList lista;
    lista.mostrarMenu();
    return 0;
}
