//bibliotecas
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// maximo de pessoas definidas
#define MAX 9

// typedef define um nome e voto para cada candidato
typedef struct
{
    string nome;
    int votos;
}
candidato;

// número de pessoas que chamo na função, array de no maximo 9 pessoas
candidato candidatos[MAX];

// números do candidato
int candidato_count;

// chamado da função/prototipo
bool voto(string nome);
void print_vencedor(void);

int main(int argc, string argv[])
{
    //checar o envio dos nomes do candidato junto com ./voto ...
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // indica o máximo de candidatos que tivemos
    candidato_count = argc - 1;
    if (candidato_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidato_count; i++)
    {
        candidatos[i].nome = argv[i + 1];
        candidatos[i].votos = 0;
    }

    int voto_count = get_int("Number of voters: ");

    // loop/for dos nossos votos 
    for (int i = 0; i < voto_count; i++)
    {
        string nome = get_string("Vote: ");

        //checando os votos 
        if (!voto(nome))
        {
            printf("Invalid vote.\n");
        }
    }

    // mostrando o ganhador 
    print_vencedor();
    
}

// Update vote totals given a new vote
bool voto(string nome)
{
    // TODO
    //Linear search for mathing canditate name 
    for (int i = 0; i < candidato_count; i++){
        if(strcmp(candidatos[i].nome, nome) == 0){
            candidatos[i].votos += 1;
            return true;
        }
    }
    
    return false;
}

// Print the winner (or winners) of the election
void print_vencedor(void)
{
    // TODO
    int maxvotos = 0;

//ajuda by CC50 made easy 

    for (int i = 0; i < candidato_count; i++)
    {
        if (candidatos[i].votos > maxvotos)
        {
            maxvotos = candidatos[i].votos;
        }
    }
    // print winners
    for (int i = 0; i < candidato_count; i++)
    {
        if (candidatos[i].votos == maxvotos)
        {
            printf("%s\n", candidatos[i].nome);
        }
    }
    
   return; 
   
}