#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar os dados de endere�o
struct Endereco {
    char logradouro[100];
    int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    char cep[15];
    char estado[3];
    // Adicione mais campos conforme necess�rio
};

// Estrutura para armazenar os dados da crian�a e vacinas
struct Crianca {
    int id;
    char nome[50];
    char dataNascimento[15];
    char municipioNascimento[50];
    char nomeMae[50];
    char nomePai[50];
    struct Endereco endereco; // Estrutura de endere�o
    char telefoneResponsavel[15];
    char etnia[20];
    int mesesDeVida;  // Adicionado campo para meses de vida
    int vacinaBCG;
    int vacinaHepatiteB1;
    int vacinaHepatiteB2;
    int vacinaDTPHib1;
    int vacinaVOP1;
    int vacinaVORH1;
    int vacinaDTPHib2;
    int vacinaVOP2;
    int vacinaVORH2;
    // Adicione mais campos conforme necess�rio
};

int proximoId = 1; // Vari�vel global para rastrear o pr�ximo ID dispon�vel

// Fun��o para incluir os dados de identifica��o da crian�a
void incluirDadosIdentificacao(struct Crianca *crianca) {
    crianca->id = proximoId++;
    printf("Nome da crian�a: ");
    scanf("%s", crianca->nome);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", crianca->dataNascimento);
    printf("Munic�pio de nascimento: ");
    scanf("%s", crianca->municipioNascimento);
    printf("Nome da m�e: ");
    scanf("%s", crianca->nomeMae);
    printf("Nome do pai: ");
    scanf("%s", crianca->nomePai);
    printf("Telefone do respons�vel: ");
    scanf("%s", crianca->telefoneResponsavel);
    printf("Etnia (Branca, Negra, Amarela, Parda, Ind�gena): ");
    scanf("%s", crianca->etnia);
    printf("Meses de vida da crian�a: ");
    scanf("%d", &crianca->mesesDeVida);
}

// Fun��o para incluir o endere�o da crian�a
void incluirEndereco(struct Crianca *crianca) {
    printf("Logradouro: ");
    scanf("%s", crianca->endereco.logradouro);
    printf("N�mero: ");
    scanf("%d", &crianca->endereco.numero);
    printf("Complemento: ");
    scanf("%s", crianca->endereco.complemento);
    printf("Bairro: ");
    scanf("%s", crianca->endereco.bairro);
    printf("Cidade: ");
    scanf("%s", crianca->endereco.cidade);
    printf("CEP: ");
    scanf("%s", crianca->endereco.cep);
    printf("Estado: ");
    scanf("%s", crianca->endereco.estado);
}

// Fun��o para incluir o registro das vacinas da crian�a
void incluirRegistroVacina(struct Crianca *crianca) {
    printf("\nIncluir Registro de Vacina para a Crian�a %s (ID: %d)\n", crianca->nome, crianca->id);

    printf("A crian�a tomou a vacina BCG? (Digite 'sim' ou 'nao'): ");
    char resposta[10];
    scanf("%s", resposta);
    crianca->vacinaBCG = (strcmp(resposta, "sim") == 0) ? 1 : 0;

    printf("A crian�a tomou a 1� dose da vacina Hepatite B? (Digite 'sim' ou 'nao'): ");
    scanf("%s", resposta);
    crianca->vacinaHepatiteB1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

    // L�gica para as demais vacinas de acordo com os meses de vida
    if (crianca->mesesDeVida >= 1) {
        printf("A crian�a tomou a 2� dose da vacina Hepatite B? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaHepatiteB2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    if (crianca->mesesDeVida >= 2) {
        printf("A crian�a tomou a 1� dose da vacina DTPHib? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaDTPHib1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A crian�a tomou a 1� dose da vacina VOP? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVOP1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A crian�a tomou a 1� dose da vacina VORH? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVORH1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    if (crianca->mesesDeVida >= 4) {
        printf("A crian�a tomou a 2� dose da vacina DTPHib? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaDTPHib2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A crian�a tomou a 2� dose da vacina VOP? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVOP2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A crian�a tomou a 2� dose da vacina VORH? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVORH2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    // Adicione l�gica para outras vacinas de acordo com a idade
}

// Fun��o para encontrar uma crian�a pelo ID
struct Crianca *buscarCriancaPorId(struct Crianca *criancas, int numCriancas, int id) {
    int i;
    for (i = 0; i < numCriancas; i++) {
        if (criancas[i].id == id) {
            return &criancas[i];
        }
    }
    return NULL; // Retorna NULL se n�o encontrar a crian�a
}

// Fun��o para listar todos os dados da crian�a e verificar vacina��o
// Fun��o para listar todos os dados da crian�a e verificar vacina��o
// Fun��o para listar todos os dados da crian�a, verificar vacina��o e mostrar vacinas que precisam ser tomadas
void listarDados(struct Crianca crianca) {
    printf("\nDados de Identifica��o:\n");
    printf("ID: %d\n", crianca.id);
    printf("Nome: %s\n", crianca.nome);
    printf("Data de nascimento: %s\n", crianca.dataNascimento);
    printf("Munic�pio de nascimento: %s\n", crianca.municipioNascimento);
    printf("Nome da m�e: %s\n", crianca.nomeMae);
    printf("Nome do pai: %s\n", crianca.nomePai);
    printf("Telefone do respons�vel: %s\n", crianca.telefoneResponsavel);
    printf("Etnia: %s\n", crianca.etnia);

    printf("\nEndere�o:\n");
    printf("Logradouro: %s\n", crianca.endereco.logradouro);
    printf("N�mero: %d\n", crianca.endereco.numero);
    printf("Complemento: %s\n", crianca.endereco.complemento);
    printf("Bairro: %s\n", crianca.endereco.bairro);
    printf("Cidade: %s\n", crianca.endereco.cidade);
    printf("CEP: %s\n", crianca.endereco.cep);
    printf("Estado: %s\n", crianca.endereco.estado);

    printf("\nVacinas Tomadas:\n");

    // L�gica para exibir vacinas tomadas
    if (crianca.vacinaBCG) {
        printf("BCG - ID dose �nica: Formas graves de tuberculose\n");
    }
    if (crianca.vacinaHepatiteB1) {
        printf("Vacina contra hepatite B (1) - 1� dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 1 && crianca.vacinaHepatiteB2) {
        printf("Vacina contra hepatite B (2) - 2� dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaDTPHib1) {
        printf("Vacina tetravalente (DTP + Hib) (1) - 1� dose: Difteria, t�tano, coqueluche, meningite e outras infec��es\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaVOP1) {
        printf("VOP (vacina oral contra p�lio) (1) - 1� dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaVORH1) {
        printf("VORH (Vacina Oral de Rotav�rus Humano) (1) - 1� dose: Diarr�ia por Rotav�rus\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaDTPHib2) {
        printf("Vacina tetravalente (DTP + Hib) (2) - 2� dose: Difteria, t�tano, coqueluche, meningite e outras infec��es\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaVOP2) {
        printf("VOP (vacina oral contra p�lio) (2) - 2� dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaVORH2) {
        printf("VORH (Vacina Oral de Rotav�rus Humano) (2) - 2� dose: Diarr�ia por Rotav�rus\n");
    }

    printf("\nVacinas que Precisam ser Tomadas:\n");

    // L�gica para exibir vacinas que precisam ser tomadas
    if (!crianca.vacinaBCG) {
        printf("BCG - ID dose �nica: Formas graves de tuberculose\n");
    }
    if (!crianca.vacinaHepatiteB1) {
        printf("Vacina contra hepatite B (1) - 1� dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 1 && !crianca.vacinaHepatiteB2) {
        printf("Vacina contra hepatite B (2) - 2� dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaDTPHib1) {
        printf("Vacina tetravalente (DTP + Hib) (1) - 1� dose: Difteria, t�tano, coqueluche, meningite e outras infec��es\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaVOP1) {
        printf("VOP (vacina oral contra p�lio) (1) - 1� dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaVORH1) {
        printf("VORH (Vacina Oral de Rotav�rus Humano) (1) - 1� dose: Diarr�ia por Rotav�rus\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaDTPHib2) {
        printf("Vacina tetravalente (DTP + Hib) (2) - 2� dose: Difteria, t�tano, coqueluche, meningite e outras infec��es\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaVOP2) {
        printf("VOP (vacina oral contra p�lio) (2) - 2� dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaVORH2) {
        printf("VORH (Vacina Oral de Rotav�rus Humano) (2) - 2� dose: Diarr�ia por Rotav�rus\n");
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configura a localiza��o para a padr�o do sistema

    struct Crianca *criancas = NULL;
    int numCriancas = 0;
    char opcao;

    do {
        // Exibir menu
        printf("\nMenu:\n");
        printf("a. Incluir dados de identifica��o da crian�a\n");
        printf("b. Incluir endere�o da crian�a\n");
        printf("c. Incluir registro de vacina\n");
        printf("d. Listar todos os dados da crian�a e verificar vacina��o\n");
        printf("e. Sair do programa\n");
        printf("Escolha a op��o (a, b, c, d, ou e): ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a': {
                // Adiciona uma nova crian�a ao array
                numCriancas++;
                criancas = realloc(criancas, numCriancas * sizeof(struct Crianca));
                if (criancas == NULL) {
                    printf("Erro ao alocar mem�ria.\n");
                    return 1;
                }
                incluirDadosIdentificacao(&criancas[numCriancas - 1]);
                break;
            }
            case 'b':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da crian�a para incluir/endere�o: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        incluirEndereco(criancaSelecionada);
                    } else {
                        printf("ID de crian�a inv�lido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma crian�a cadastrada. Cadastre uma crian�a primeiro.\n");
                }
                break;
            case 'c':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da crian�a para incluir registro de vacina: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        incluirRegistroVacina(criancaSelecionada);
                    } else {
                        printf("ID de crian�a inv�lido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma crian�a cadastrada. Cadastre uma crian�a primeiro.\n");
                }
                break;
            case 'd':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da crian�a para listar os dados e verificar vacina��o: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        listarDados(*criancaSelecionada);
                    } else {
                        printf("ID de crian�a inv�lido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma crian�a cadastrada. Cadastre uma crian�a primeiro.\n");
                }
                break;
            case 'e':
                // Liberar a mem�ria alocada para o array de crian�as
                free(criancas);
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

        // Limpar o buffer do teclado
        while (getchar() != '\n');

    } while (opcao != 'e');

    return 0;
}
