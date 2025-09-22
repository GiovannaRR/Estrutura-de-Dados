#include<iostream>
#define MAX 255

    class Pilha{ //criando uma classe
    private:
        int array[MAX];
        int topo;
    
    public:
        Pilha(){ //um construtor para iniciar a pilha vazia (-1)
            topo = -1;
        }

        void push(int valor){ //empilhar
            if(topo < MAX -1){ //esta verificando se ainda tem espaço na pilha
                array[++topo] = valor;
            }
            else{
                std::cout << "\nPilha cheia!\n";
            }
        }

        int pop(){ //desempilhar
            if(topo >= 0){ //verifica se tem elementos na pilha
                return array[topo--];
            }
            else{
                std::cout << "\nPilha vazia!\n";
                return -1;
            }
        }

        int top(){
            if(topo >= 0){
                return array[topo];
            }
            else{
                std::cout << "\nPilha vazia!\n";
                return -1;
            }
        }

        int calcular(const char expressao[], int tam){
            Pilha pilha;
            int i = 0;

            for(i = 0; i< tam; i++){
                if(expressao[i] >= '0' && expressao[i] <= '9'){ //esta verificando se char é um numero > 0 < 9
                    pilha.push(expressao[i] - '0'); //aqui tranformamos o char em int, tipo '2' em 2 
                }
    
                else{
                    int b = pilha.pop();  // da um pop no ultimo num da pilha
                    int a = pilha.pop();  // da um pop no penultimo
                        
                    if(expressao[i] == '+'){
                            pilha.push(a + b);
                    }
                    if(expressao[i] == '-'){
                        pilha.push(a - b);
                    }
                    if(expressao[i] == '*'){
                        pilha.push(a * b);
                    }
                    if(expressao[i] == '/'){
                        pilha.push(a / b);
                    }
                }
            }
            return pilha.pop();
        } 
    };

int main(){
    Pilha pil;
    char expressao[MAX];
    int tam = 0;

    std::cout << "Qual o tamanho da sua expressao? \n";
    std::cin >> tam;

    std::cout << "Digite a expressao: \n";
    for(int i = 0; i < tam; i++){
        std::cin >> expressao[i];
    }

    int resultado = pil.calcular(expressao, tam);

    std::cout << "\nO resultado eh: " << resultado;

    return 0;
}