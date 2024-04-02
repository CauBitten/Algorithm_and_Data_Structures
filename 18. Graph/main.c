#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[50];
    char cpf[11];

    struct pessoa *prox;    // arestas
    struct pessoa *baixo;   // vértices
} pessoa;

typedef struct {
    int n;              // Quantidade de vértices
    pessoa *inicio;     // Onde começa o primeiro vértice
} Grafo;

// ===========================CABEÇALHOS========================================
void FuncaoTeste(Grafo *G);
void CriaLD(Grafo *G);
void Free_All(Grafo *G);
void ImprimeGrafoCompleto(Grafo *G);
pessoa *NovoVertAresta(char nome[50], char cpf[11]);
pessoa *RetornaItemAnterior(Grafo *G, char cpf[11]);
char* getNomeByCpf (Grafo *G, char cpf[11]);
int VerificaRemoveVertices(Grafo *G, char nome[50], char cpf[11]);
int VerificaRemoveArestas(Grafo *G, char nome1[50], char cpf1[11], char nome2[50], char cpf2[11]);
int VerificaAresta(Grafo *G, char nome1[50], char cpf1[11], char nome2[50], char cpf2[11]);
void InserirAresta(Grafo *G, pessoa *C, pessoa *V);
int InserirVertice(Grafo *G, char nome[50], char cpf[11]);
void InserirVerticeOrdenado(Grafo *G, pessoa *C);
void InserirPrimeiroVertice(Grafo *G, pessoa *c);
void InserirFimVertice(Grafo *G, pessoa *c);
void RemoveAresta(Grafo *Grafo, pessoa *V, char nome[50]);
// ==========================================================
// =============================================================================

int main (void) {
    int opcao;   // Variavel para escolher opcoes do MENU
    int retorno; // Variavel usada para receber retorno das funcoes

    Grafo Grafo; // Criando uma Lista Dinamica com o Nome GRAFO
    CriaLD(&Grafo);      // Setando Quantidade e ponteiros para NULL

    // ====================================== TEST ===========================================
    //           ESPAÇO DESTINADO A FUNÇÕES TESTE E PRE-CODIGOS PARA AGILIZAR OS TESTES
    FuncaoTeste(&Grafo);

    do // Responsavel por deixar o MENU em LOOP até o usuario informar "SAIR"
    {
        printf("\n1. Inserir Vertices\n2. Inserir Arestas\n3. Visualizar Grafo\n"); // Opcoes MENU
        printf("4. Remover Vertices\n5. Remover Arestas\n6. Sair\n");               // Opcoes MENU
        printf("\nOpcao: ");
        scanf("%d", &opcao); // Vai ler a opcao que usuario informou

        switch (opcao)
        {
            case 1: // Inserir Vertices
            {
                // * PARA VERTICE ... NÃO PODE TER VALOR DE VERTICE REPETIDO ...

                char nome[50]; // vai ser usada para pegar o nome do vertice
                printf("Insira um nome para o Vertice: ");
                scanf("%s", nome);
                getchar();

                char cpf[11]; // vai ser usada para pegar o cpf do vertice
                printf("Insira um cpf para o Vertice: ");
                scanf("%s", cpf);
                getchar();

                retorno = InserirVertice(&Grafo, nome, cpf);
                if (retorno == (-1)) // Validando return ... (-1) para Vertice ja existente (repetido)
                {
                    printf("Vertice Repetido !!!\n");
                }
                else // Validando return ... se != (-1) vertice adicionado com sucesso
                {
                    printf("Vertice Criado com sucesso !!!\n");
                }
                break;
            }

            case 2: // Inserir Arestas
            {
                // * PARA ARESTAS ... NÃO PODE TER MULTIPLAS ARESTAS ... VERIFICAR SE OS PONTOS INFORMADOS TEM NO GRAFO

                char cpf1[11], cpf2[11]; // vai ser usada para pegar o vertice 1 e 2 informada pelo usuario
                printf("Informe o Vertice de Origem (cpf): ");
                scanf("%s", cpf1);
                printf("Informe o Vertice de Destino (cpf): ");
                scanf("%s", cpf2);

                char nome1[50];
                char nome2[50];

                strcpy(nome1, getNomeByCpf(&Grafo, cpf1));
                strcpy(nome2, getNomeByCpf(&Grafo, cpf2));

                retorno = VerificaAresta(&Grafo, nome1, cpf1, nome2, cpf2); // chamando função responsavel por Inserir e Verificar Arestas
                if (retorno == -1)
                {
                    printf("ERRO! Já existe Aresta ligando os pontos %s e %s.\n", nome1, nome2);
                }
                else if (retorno == -2)
                {
                    printf("ERRO! Nao existe os vertices %s ou %s ou ambos.\n", nome1, nome2);
                }
                else if (retorno == -3)
                {
                    printf("ERRO! No Grafo nao pode ter laco (V1 = V2).\n");
                }
                else if (retorno == -4)
                {
                    printf("ERRO! Quantidade de vertices insuficientes para criar aresta.\n");
                }
                else
                {
                    printf("Aresta Criada com sucesso !!!\n");
                }
                break;
            }

            case 3: // Visualizar Grafo
            {
                if (Grafo.n == 0)
                {
                    printf("Grafo Vazio !!!\n");
                }
                else
                {
                    // TIRAR ESSE PRINT DEPOIS
                    //printf("L->inicio: %d\nQuantV: %d\n", Grafo.inicio->numero, Grafo.quantV);
                    ImprimeGrafoCompleto(&Grafo);
                }
                break;
            }

            case 4: // Remover Vertices
            {
                char cpf[11];
                printf("Informe o Vertice que deseja tirar (cpf): ");
                scanf("%s", cpf);

                char nome[50];

                strcpy(nome, getNomeByCpf(&Grafo, cpf));

                retorno = VerificaRemoveVertices(&Grafo, nome, cpf);
                if (retorno == (-1))
                {
                    printf("ERRO! O Vertice informado nao existe no Grafo !!!\n");
                }

                else
                {
                    printf("Vertice Removido com sucesso !!!\n");
                }
                break;
            }

            case 5: // Remover Arestas
            {
                char cpf1[11], cpf2[11]; // vai ser usada para pegar o vertice 1 e 2 informada pelo usuario
                printf("Informe o Vertice de Origem da Aresta a ser removida (cpf): ");
                scanf("%s", cpf1);
                printf("Informe o Vertice de Destino da Aresta a ser removida (cpf): ");
                scanf("%s", cpf2);

                char nome1[50], nome2[50];

                strcpy(nome1, getNomeByCpf(&Grafo, cpf1));
                strcpy(nome2, getNomeByCpf(&Grafo, cpf2));

                retorno = VerificaRemoveArestas(&Grafo, nome1, cpf1, nome2, cpf2); // chamando função que verifica e Remove Aresta
                if (retorno == -3)
                {
                    printf("ERRO! V1 e V2 são iguais !!!\n");
                }

                else if (retorno == -2)
                {
                    printf("ERRO! Nao existe os vertices %s ou %s ou ambos.\n", nome1, nome2);
                }

                else if (retorno == -1)
                {
                    printf("ERRO! Nao existe aresta entre os vertices %s e %s.\n", nome1, nome2);
                }

                else
                {
                    printf("Aresta removida com sucesso !!!\n");
                }
                break;
            }

            case 6: // Sair
            {
                Free_All(&Grafo); // Antes de sair ele vai dar free no Grafo inteiro (Vertices e Arestas)
                break;
            }

            default: // Se Usuario informou numero != de [1-6] ~~ Opção Invalida
            {
                printf("Opcao Invalida !!!\n");
                break;
            }
        }
    } while (opcao != 6); // Se Opção for 6 ele sai do laço e "fecha" o programa
    return 0;
}

// ============================================ FUNÇOES DIVERSAS ===========================================
void FuncaoTeste(Grafo *G) // Função usada na "main"
{
    InserirVertice(G, "Caua", "10134223487");
    InserirVertice(G, "Lucas", "73892883764");
    InserirVertice(G, "Higor", "72910349290");
    InserirVertice(G, "Peter", "19203994032");
    InserirVertice(G, "Joao", "19304030203");

    VerificaAresta(G, "Caua", "10134223487", "Higor", "72910349290"); // Cauã -- Higor
    VerificaAresta(G, "Caua", "10134223487", "Lucas", "73892883764"); // Cauã -- Lucas

    VerificaAresta(G, "Lucas", "73892883764", "Higor", "72910349290"); // Lucas -- Higor
    VerificaAresta(G, "Lucas", "73892883764", "Peter", "19203994032"); // Lucas -- Peter
    VerificaAresta(G, "Lucas", "73892883764", "Joao", "19304030203"); // Lucas -- João

    VerificaAresta(G, "Joao", "19304030203", "Caua", "10134223487"); // João -- Cauã
    VerificaAresta(G, "Joao", "19304030203", "Peter", "19203994032"); // João -- Peter
}

void CriaLD(Grafo *G) // Função usada na "main"
{
    G->n = 0;           // Setando Quantidade de Vertices do Grafo em zero
    G->inicio = NULL;   // atualizando ponteiro Inicio para NULL
}

void Free_All(Grafo *G) // Função usada na "main"
{
    pessoa *AuxV, *AuxA, *InicioA; // Ponteiro inicioA é para criar um Inicio para Arestas
    while (G->inicio != NULL)    // Loop responsavel por dar free em todos os vertices do grafo
    {
        AuxV = G->inicio;       // Enquanto L->inicio é != de NULL então tem item para dar free
        InicioA = AuxV->prox;   // Inicio de Aresta sempre começa no AuxV->prox;
        while (InicioA != NULL) // começa aqui para dar free nas arestas
        {
            AuxA = InicioA;
            InicioA = AuxA->prox;
            free(AuxA); // free na aresta
            AuxA = NULL;
        }
        G->inicio = AuxV->baixo;
        free(AuxV); // free no vertice
        AuxV = NULL;
    }
    // \/ NÂO PRECISA FAZER ISSO PORQUE MEU GRAFO NÃO É CRIADO COM MALLOC E SIM POR TIPO
    //free(L); // dando free na estrutura grafo
    //L = NULL;
}

void ImprimeGrafoCompleto(Grafo *G) // Função usada na "main" case 3
{
    pessoa *auxV = G->inicio; // Criando tipo item V para vertice e itemA para aresta.
    pessoa *auxA;
    printf("Vertices      Arestas\n");
    while (auxV != NULL) // Vai terminar de printar o grafo quando chegar no ultimo vertice
    {
        auxA = auxV;                            // auxA precisa receber auxV para o auxA sempre printar os itens da sua linha
        printf("   %s  ------>", auxV->nome); // Printando o Vertice
        if (auxA->prox == NULL)                 // Se o proximo item de Vertice for NULL ele vai printar um NULL
        {
            printf("   NULL\n");
        }
        else // Se não for NULL quer dizer que tem itens para proximo de Vertice ...
        {
            auxA = auxV->prox;   // Precisa fazer isso porque senão ele vai printar o Vertice de novo ... A aresta sempre começa do V->prox; e não de V.
            while (auxA != NULL) // Imprimir todos da Lista (Aresta)
            {
                printf(" %s ->", auxA->nome);
                auxA = auxA->prox; // Percorrendo Lista na Horizontal (Printando todas as Arestas) do vertice V
            }
            printf(" NULL\n");
        }
        auxV = auxV->baixo; // Para Percorrer até o ultimo Vertice da lista
    }
}

pessoa *NovoVertAresta(char nome[50], char cpf[11]) // Usada na função "Inserir Vertice"
{
    pessoa *aux;
    aux = malloc(sizeof(pessoa));

    strcpy(aux->nome, nome);
    strcpy(aux->cpf, cpf);

    aux->prox = NULL;
    aux->baixo = NULL;
    return aux;                     // Retornando o ponteiro para o aux criado
}

pessoa *RetornaItemAnterior(Grafo *G, char cpf[11]) // Funcao usada em "VerificaRemoveVertices"
{
    pessoa *C = G->inicio;
    while ( (strcpy(C->baixo->cpf, cpf)) != 0 )
    {
        C = C->baixo;
    }
    return C;
}

char* getNomeByCpf (Grafo *G, char cpf[11]) {
    pessoa *C = G->inicio;

    while ( (strcpy(C->baixo->cpf, cpf)) != 0 )
    {
        C = C->baixo;
    }

    return C->nome;
}

// ===================================== FUNÇOES PARA VERTICE ===============================================
int InserirVertice(Grafo *G, char nome[50], char cpf[11]) // Função usada na "main"
{                                           // CHECKLIST DE VERIFICAÇÃO DE VERTICES                                       STATUS     RETURN
    //      * NÃO PODE TER VERTICES IGUAIS                                         OK!        (-1)
    //      * PODE TER VERTICE NEGATIVO || Resp: Sim mas n precisa validar         OK!        (--)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    pessoa *aux;          // Criando variavel aux para percorrer o Grafo
    if (G->n != 0) // Se QuantV for 0 ... certamente o numero que o usuario informou não tem no grafo então não precisa validar e pode adicionar ele direto.
    {                   // Se QuantV != 0 ... então precisa validar se n tem no grafo ou não.
        int i;
        aux = G->inicio;                // Setando aux para o Ponteiro inicio do Vertice
        for (i = 0; i < G->n; i++) // Vai percorrer a Lista inteira para ver se acha um vertice igual o informado
        {
            if (strcmp(aux->cpf, cpf) == 0) // Se ele achar um cpf ja existente no grafo vai retornar -1 (ERRO)
            {
                return -1; // Retornando -1 ... validar Resposta para esse (ERRO)
            }
            aux = aux->baixo; // Atualizando o aux para baixo (vertice) para ele conseguir percorrer o grafo
        }
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    aux = NovoVertAresta(nome, cpf);        // chamando função que cria um item e seta valor e atualiza ponteiros para NULL
    InserirVerticeOrdenado(G, aux); // Chamando função que insere Vertice
    return 1;                       // Se chegou até aqui é porque deu tudo CERTO !!!
}

void InserirPrimeiroVertice(Grafo *G, pessoa *c) // Usada na função "InserirVerticeOrdenado"
{
    G->n++; // Acrescentando quantidade relativo aos Vertices
    c->baixo = G->inicio;
    G->inicio = c; // Atualizando ponteiro L->inicio para o Vertice C
}

void InserirFimVertice(Grafo *G, pessoa *c) // Usada na função "InserirVerticeOrdenado"
{
    //OBS: NÃO VALIDEI POS=0 POIS O CODIGO INTEIRO JA ESTA FAZENDO ESSA VALIDACAO ... MAS SE FOR USAR ESSA FUNCAO COLOQUE
    int pos = G->n; // Como vai adicionar no fim da lista ... Só pegar a ultima posição da lista pelo QuantV
    int cont = 0;
    pessoa *aux = G->inicio;   // atualizando aux para inicio da lista
    while (cont < (pos - 1)) // percorrendo a lista até o ultimo item
    {
        aux = aux->baixo;
        cont++;
    }
    c->baixo = aux->baixo;
    aux->baixo = c;
    G->n++;
}

void InserirVerticeOrdenado(Grafo *G, pessoa *C) // Usada na função "Inserir Vertice"
{
    pessoa *aux = G->inicio; // criando o aux pois ele vai fazer o papel de um L->fim

    if (G->n != 0)    // se a lista esta vazia não precisa percorrer ela
    {
        while (aux->baixo != NULL) // loop responsavel por pegar o ultimo item da lista vertice
        {
            aux = aux->baixo;
        }
    }

    if (G->inicio == NULL) // Se tiver vazia a lista
    {
        InserirPrimeiroVertice(G, C);
    }

    else {
        InserirFimVertice(G, C);
    }
}

// ===================================== FUNÇOES PARA ARESTAS ===============================================
int VerificaAresta(Grafo *G, char nome1[50], char cpf1[11], char nome2[50], char cpf2[11]) // Função usada na "main"
{                                                    // CHECKLIST DE VERIFICAÇÃO DE ARESTAS                                          STATUS     RETURN
    //      * V1 E V2 PRECISA SER DIFERENTE --> NÃO PODE TER LAÇO                    OK!        (-3)
    //      * PRECISA TER NO MINIMO 2 VERTICES NO GRAFO --> NÃO PODE TER LAÇO        OK!        (-4)
    //      * VERIFICAR SE V1 E V2 PERTENCEM AO GRAFO                                OK!        (-2)
    //      * VERIFICAR SE JA EXISTE ARESTA LIGANDO V1 E V2                          OK!        (-1)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    if (G->n == 0 || G->n == 1)
    {              // Não tem como juntar 2 pontos sem ter dois pontos (trabalho não aceita laço)
        return -4; // Saida (-4) quer dizer que tem vertices insuficientes para criar aresta
    }

    if (strcmp(cpf1, cpf2) == 0) // Não pode ter laço
    {
        return -3; // Saida (-3) quer dizer que V1 é igual a V2.
    }

    // Verificar se existe no Grafo os Vertices V1 e V2 ...
    pessoa *aux = G->inicio; // Criando tipo item e setando para começo do Grafo
    int cont = 0;          // Inicializando uma variavel contadora = 0 ... vai ser responsavel por contar se tem os V1 e V2
    while (aux != NULL)
    {
        if (strcmp(aux->cpf, cpf1) == 0 || strcmp(aux->cpf, cpf2) == 0)
        {
            cont++; // Se cair aqui 2x é porque o V1 e V2 existe na lista se cair 1 ou nenhuma vez é pq n tem
        }
        aux = aux->baixo; // Percorrendo grafo na vertical até Aux ser NULL
    }
    if (cont != 2) // Se for igual a 2 é porque o V1^V2 existe no Grafo, se for diferente não existe.
    {
        return -2; // Saida (-2) quer dizer que não tem V1 ou V2 no Grafo ou nenhum deles.
    }

    // Verificar Se já existe essa aresta no Grafo
    aux = G->inicio;          // Setando novamente Aux para inicio do Grafo
    cont = 0;                 // Setando novamente contador = 0 para validar return
    while (strcmp(aux->cpf, cpf1) != 0) // ele vai percorrer o gravo na Vertical(vertice) até achar o v1
    {                         // Ele vai achar o v1 pois ja foi verificado que v1 e v2 pertencem ao grafo
        aux = aux->baixo;
    }
    while (aux != NULL) // Agora o aux vai percorrer o gravo na Horizontal (Arestas).
    {
        if (strcmp(aux->cpf, cpf2) == 0) // Se ele achar o v2 é porque ja tem aresta ligando os pontos v1 e v2
        {
            cont++; // Se cair aqui é porque ja tem arestas ligando, então para validar uma saida o cont recebe 1;
        }           // Se cont=0 --> Não existe aresta ligando v1 e v2 | Se cont != 0 é porque existe aresta ligando V1 e V2
        aux = aux->prox;
    }
    if (cont != 0)
    {
        return -1; // Saida (-1) quer dizer que já existe aresta ligando os pontos V1 e V2
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI ADICIONAR ARESTAS    &*&*         ~~~~~~~~~~~~~
    aux = G->inicio;          // setando novamente aux para inicio do Grafo
    while (strcmp(aux->cpf, cpf1) != 0) // Vai percorrer a lista até achar o Vertice V1
    {
        aux = aux->baixo;
    }
    pessoa *novo;                // declarando tipo item para inserir no v1 a aresta v2
    novo = NovoVertAresta(nome2, cpf2); // Chamando função para criar nova aresta
    InserirAresta(G, novo, aux);

    // Precisamos fazer isso 2x ... um para inserir no v1 a aresta v2 e no outro inserir no v2 a aresta v1.
    aux = G->inicio;
    while (strcmp(aux->cpf, cpf2) != 0)
    {
        aux = aux->baixo;
    }
    novo = NovoVertAresta(nome1, cpf1);
    InserirAresta(G, novo, aux);
    // Chamando função para inserir ... onde novo é o elemento a ser inserido e aux é onde a lista começa
    // horizontalmente (aresta) em v1

    return 1; // Se chegou aqui porque não parou em nenhum return e conseguiu analisar e inserir com sucesso !!!
}

void InserirAresta(Grafo *G, pessoa *C, pessoa *V) // Função usada em "VerificaAresta"
{                                                              // Pessoa C --> pessoa que vc quer inserir || Pessoa V é o Vertice Atual, isto é, o vertice que tu quer inserir a aresta
    if (V->prox == NULL)                                       // Se não tem arestas ... Basta atualizar ponteiro prox para a pessoa nova
    {
        V->prox = C;
    }

    C->prox = V->prox;
    V->prox = C;
}

// =================================== FUNÇOES PARA TIRAR VERTICES =========================================
int VerificaRemoveVertices(Grafo *G, char nome[50], char cpf[11]) // Funcao usada na "main"
{                                                    // CHECKLIST DE VERIFICAÇÃO DE REMOÇÃO DE VERTICES                                 STATUS    RETURN
    //      * VERIFICAR SE V1 EXISTE NO GRAFO                                         OK!       (-1)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    pessoa *aux = G->inicio;
    int cont = 0, i;

    for (i = 0; i < G->n; i++) // percorrer o grafo inteiro para achar um vertice
    {
        if (strcmp(aux->cpf, cpf) == 0)
        {
            cont++; // se caiu aqui pq tem cpf no grafo
            break;  // para não fazer o for ir até o fim ... se achou um não precisa percorrer o resto.
        }
        aux = aux->baixo;
    }
    if (cont == 0)
    {
        return -1; // se cont for 0 não tem vertice para remover ... então retorna (-1)
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÃO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI REMOVER VERTICE    &*&*         ~~~~~~~~~~~~~
    if (aux->prox != NULL) // Se não for NULL é porque tem arestas ... precisa tirar uma por uma e depois exclui o V
    {
        while (aux->prox != NULL)
        {
            VerificaRemoveArestas(G, nome, cpf, aux->prox->nome, aux->prox->cpf);
        }
    }
    if (aux->prox == NULL) // se não tiver aresta é so ligar os vertices
    {
        if (G->n == 1) // se tiver só 1V é só dar free e criar outro Grafo
        {
            free(aux); // dando free no aux
            aux = NULL;
            CriaLD(G); // Criando outro Grafo, isto é, setando quantV=0 | Inicio/Fim == NULL
            return 1;  // não precisa fazer mais nada então return 1
        }

        else if (G->n == 2) // Se tiver 2V ou tira do INICIO ou FIM
        {
            if (strcmp(G->inicio->cpf, cpf) == 0) // Se for tirar do INICIO
            {
                G->inicio = aux->baixo;
                aux->baixo = NULL;
            }
            else // Se v1 é o Ultimo Item
            {
                G->inicio->baixo = NULL;
            }
        }

        else if (strcmp(aux->cpf, G->inicio->cpf) == 0) // Se o Vertice que for tirar é o primeiro da lista
        {
            G->inicio = aux->baixo;
            aux->baixo = NULL;
        }

        else // Se o Vertice tiver Entre outros Vertices ...
        {
            pessoa *aux_Ant = RetornaItemAnterior(G, cpf);
            aux_Ant->baixo = aux->baixo;
            aux->baixo = NULL;
        }

        free(aux);
        aux = NULL;
        G->n--;
        return 1;
    }
    return 1;
}

// =================================== FUNÇOES PARA TIRAR ARESTAS ===========================================
int VerificaRemoveArestas(Grafo *G, char nome1[50], char cpf1[11], char nome2[50], char cpf2[11]) // Função usada na "main"
{                                                           // CHECKLIST DE VERIFICAÇÃO DE REMOCÃO DE ARESTAS                                 STATUS    RETURN
    //      * VERIFICAR SE V1 É IGUAL V2                                              OK!       (-3)
    //      * VERIFICAR SE V1 E V2 EXISTE NO GRAFO                                    OK!       (-2)
    //      * VERIFICAR SE V1 E V2 FAZEM CONEXÃO                                      OK!       (-1)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...

    // verificar se v1 = v2 ... não da para tirar laço pois o grafo não permite laço
    if (strcmp(cpf1, cpf2) == 0)
    {
        return -3; // Saida (-3) quer dizer que V1 == V2 ... não da para tirar laço se não tem laço
    }

    // Verificar se existe no Grafo os Vertices V1 e V2 ...
    pessoa *aux = G->inicio; // Criando tipo item e setando para começo do Grafo
    int cont = 0;          // Inicializando uma variavel contadora = 0 ... vai ser responsavel por contar se tem os V1 e V2
    while (aux != NULL)
    {
        if (strcmp(aux->cpf, cpf1) == 0 || strcmp(aux->cpf, cpf2) == 0)
        {
            cont++; // Se cair aqui 2x é porque o V1 e V2 existe na lista se cair 1 ou nenhuma vez é pq n tem
        }
        aux = aux->baixo; // Percorrendo grafo na vertical até Aux ser NULL
    }
    if (cont != 2) // Se for igual a 2 é porque o V1^V2 existe no Grafo, se for diferente não existe.
    {
        return -2; // Saida (-2) quer dizer que não tem V1 ou V2 no Grafo ou nenhum deles.
    }

    // Verificar Se existe essa aresta no Grafo
    aux = G->inicio;          // Setando novamente Aux para inicio do Grafo
    cont = 0;                 // Setando novamente contador = 0 para validar return
    while (strcmp(aux->cpf, cpf1) != 0) // ele vai percorrer o gravo na Vertical(vertice) até achar o v1
    {                         // Ele vai achar o v1 pois ja foi verificado que v1 e v2 pertencem ao grafo
        aux = aux->baixo;
    }
    while (aux != NULL) // Agora o aux vai percorrer o gravo na Horizontal (Arestas).
    {
        if (strcmp(aux->cpf, cpf2) == 0) // Se ele achar o v2 é porque tem aresta ligando os pontos v1 e v2
        {
            cont++; // Se cair aqui é porque tem arestas ligando, então para validar uma saida o cont recebe 1;
        }           // Se cont=0 --> Não existe aresta ligando v1 e v2 | Se cont != 0 é porque existe aresta ligando V1 e V2
        aux = aux->prox;
    }
    if (cont != 1)
    {
        return -1; // Saida (-1) quer dizer que não existe aresta ligando os pontos V1 e V2
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI REMOVER ARESTAS    &*&*         ~~~~~~~~~~~~~
    aux = G->inicio;          // setando novamente aux para Inicio do Grafo
    while (strcmp(aux->cpf, cpf1) != 0) // loop para achar o vertice 1 e passar como parametro para função RemoverAresta
    {                         // Não precisa validar com NULL pois já verifiquei que existe o vertice 1
        aux = aux->baixo;     // percorrendo para baixo pois quero descobrir o vertice
    }
    RemoveAresta(G, aux, nome2); // Função que vai remover a aresta ... passando Grafo, aux que seria o vertice v1 e o numero v2 para ele tirar de v1

    // Precisamos fazer isso 2x pois voce precisa tirar v1 de v2 e v2 de v1.
    aux = G->inicio;          // setando novamente aux para inicio do grafo
    while (strcmp(aux->cpf, cpf2) != 0) // loop para achar o vertice 2
    {
        aux = aux->baixo; // percorrendo para baixo pois quero descobrir o vertice
    }
    RemoveAresta(G, aux, nome1); // agora ele vai tirar o v1 do vertice 2.

    return 1; // Se chegou até aqui porque não caiu em nenhum return e a verificação/remoção foi um success!!!
}

void RemoveAresta(Grafo *Grafo, pessoa *V, char nome[50]) // Função usada na "VerificaRemoveArestas"
{                                                       // item V corresponde ao Vertice ... e n é o numero que vc quer tirar da aresta
    pessoa *aux, *temp;
    aux = V; // aux recebendo o começo do vertice que foi passada como parametro

    while (strcmp(aux->prox->nome, nome) != 0) // vai percorrer a até achar n (precisa usar && aux != NULL) ???
    {
        aux = aux->prox;
    }
    temp = aux->prox; // para não perder referencia
    aux->prox = temp->prox;
    temp->prox = NULL;
    free(temp); // dando free no item temp que foi adicionado com malloc.
}