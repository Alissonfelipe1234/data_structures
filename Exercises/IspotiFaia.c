#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct _Comando {
    char valor[136];
    struct _Comando* prox;
} Comando;
typedef struct _List_Comandos {
    struct Comando* primeiro;
    struct Comando* ultimo;
} List_Comandos;
typedef struct _Musica {
    char nome[128];
    struct _Musica* proximo;
    struct _Musica* anterior;
} Musica;
typedef struct _Lista_Playlist {
    struct Musica* primeiro;
    struct Musica* cursor;
} Lista_Playlist;

List_Comandos* novaList_Comandos(){
    return (List_Comandos*) calloc(1, sizeof(List_Comandos));
}
Lista_Playlist* novaList_Playlist(){
    return (Lista_Playlist*) calloc(1, sizeof(Lista_Playlist));
}
Comando* novoComando(char c[136]){
     Comando* novo = (Comando*) calloc(1, sizeof(Comando));
     novo->valor =  c;
     return novo;
}

int AdicionarComando(List_Comandos list, char[136] c){
    if(list == NULL)
        return 0;
    Comando* novo = novoComando(c);
    if(list->primeiro == NULL)
    {
        list->primeiro = novo;
        list->ultimo = novo;
        return 1;
    }
    list->ultimo->prox = novo;
    list->ultimo = novo;
    return 1;
}

const char * RespostaComandos(List_Comandos* lista_c, Lista_Playlist* lista_play){
    char[128] resposta;
    char[138] comando = lista_c->primeiro->valor;
    char[128] nome;
    char[8] primeiraPalavra;
    int x = 0;
    for(int i = 0; i < strlen(comando); i++){
        if(comando[i] == ' ')
        {
            x = i;
            break;
        }
    }
    strncpy(primeiraPalavra, comando, x);
    strncpy(nome, comando+x, strlen(comando)-x);
    switch (primeiraPalavra)
    {
        case "insere":
            resposta = "";
            InserirMusica(lista_play, nome);
            break;
        case "remove"):
            resposta = "";
            RemoverMusica(lista_play, nome);
            break;
        case "toca":
            resposta = lista_play->cursor;
            lista_play->cursor = lista_play->cursor->proximo;
            break;
        case "volta":
            lista_play->cursor = lista_play->cursor->anterior;
            break;
        case "final":
            printarAteAPenultima(lista_play); //andar com o cursor até o ultimo
            resposta = lista_play->primeiro->anterior;
            break;
        case "inverte":
            inverterLista_Play(lista_play);
            break;
    }
    ExcluirComando(lista_c);
    return resposta;
}
int main()
{
    int comands = 0;
    List_Comandos* lista_c = novaList_Comandos();
    Lista_Playlist* lista_play = novaList_Playlist();
    do{
        scanf("%i", &comands);
        char[136] comando;
        for(int i = 0; i < comands; i++)
        {
            gets (comando); //scans
            AdicionarComando(lista_c, comando);
        }
        for(int i = 0; i < comands; i++)
        {
            puts(RespostaComandos(lista_c, lista_play));
        }

    }while(comands != 0);
    puts("");
    return 0;
}
