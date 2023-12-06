#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar os dados de endereço
struct Endereco {
    char logradouro[100];
    int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    char cep[15];
    char estado[3];
    // Adicione mais campos conforme necessário
};

// Estrutura para armazenar os dados da criança e vacinas
struct Crianca {
    int id;
    char nome[50];
    char dataNascimento[15];
    char municipioNascimento[50];
    char nomeMae[50];
    char nomePai[50];
    struct Endereco endereco; // Estrutura de endereço
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
    // Adicione mais campos conforme necessário
};

int proximoId = 1; // Variável global para rastrear o próximo ID disponível

// Função para incluir os dados de identificação da criança
void incluirDadosIdentificacao(struct Crianca *crianca) {
    crianca->id = proximoId++;
    printf("Nome da criança: ");
    scanf("%s", crianca->nome);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", crianca->dataNascimento);
    printf("Município de nascimento: ");
    scanf("%s", crianca->municipioNascimento);
    printf("Nome da mãe: ");
    scanf("%s", crianca->nomeMae);
    printf("Nome do pai: ");
    scanf("%s", crianca->nomePai);
    printf("Telefone do responsável: ");
    scanf("%s", crianca->telefoneResponsavel);
    printf("Etnia (Branca, Negra, Amarela, Parda, Indígena): ");
    scanf("%s", crianca->etnia);
    printf("Meses de vida da criança: ");
    scanf("%d", &crianca->mesesDeVida);
}

// Função para incluir o endereço da criança
void incluirEndereco(struct Crianca *crianca) {
    printf("Logradouro: ");
    scanf("%s", crianca->endereco.logradouro);
    printf("Número: ");
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

// Função para incluir o registro das vacinas da criança
void incluirRegistroVacina(struct Crianca *crianca) {
    printf("\nIncluir Registro de Vacina para a Criança %s (ID: %d)\n", crianca->nome, crianca->id);

    printf("A criança tomou a vacina BCG? (Digite 'sim' ou 'nao'): ");
    char resposta[10];
    scanf("%s", resposta);
    crianca->vacinaBCG = (strcmp(resposta, "sim") == 0) ? 1 : 0;

    printf("A criança tomou a 1ª dose da vacina Hepatite B? (Digite 'sim' ou 'nao'): ");
    scanf("%s", resposta);
    crianca->vacinaHepatiteB1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

    // Lógica para as demais vacinas de acordo com os meses de vida
    if (crianca->mesesDeVida >= 1) {
        printf("A criança tomou a 2ª dose da vacina Hepatite B? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaHepatiteB2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    if (crianca->mesesDeVida >= 2) {
        printf("A criança tomou a 1ª dose da vacina DTPHib? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaDTPHib1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A criança tomou a 1ª dose da vacina VOP? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVOP1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A criança tomou a 1ª dose da vacina VORH? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVORH1 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    if (crianca->mesesDeVida >= 4) {
        printf("A criança tomou a 2ª dose da vacina DTPHib? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaDTPHib2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A criança tomou a 2ª dose da vacina VOP? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVOP2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;

        printf("A criança tomou a 2ª dose da vacina VORH? (Digite 'sim' ou 'nao'): ");
        scanf("%s", resposta);
        crianca->vacinaVORH2 = (strcmp(resposta, "sim") == 0) ? 1 : 0;
    }

    // Adicione lógica para outras vacinas de acordo com a idade
}

// Função para encontrar uma criança pelo ID
struct Crianca *buscarCriancaPorId(struct Crianca *criancas, int numCriancas, int id) {
    int i;
    for (i = 0; i < numCriancas; i++) {
        if (criancas[i].id == id) {
            return &criancas[i];
        }
    }
    return NULL; // Retorna NULL se não encontrar a criança
}

// Função para listar todos os dados da criança e verificar vacinação
// Função para listar todos os dados da criança e verificar vacinação
// Função para listar todos os dados da criança, verificar vacinação e mostrar vacinas que precisam ser tomadas
void listarDados(struct Crianca crianca) {
    printf("\nDados de Identificação:\n");
    printf("ID: %d\n", crianca.id);
    printf("Nome: %s\n", crianca.nome);
    printf("Data de nascimento: %s\n", crianca.dataNascimento);
    printf("Município de nascimento: %s\n", crianca.municipioNascimento);
    printf("Nome da mãe: %s\n", crianca.nomeMae);
    printf("Nome do pai: %s\n", crianca.nomePai);
    printf("Telefone do responsável: %s\n", crianca.telefoneResponsavel);
    printf("Etnia: %s\n", crianca.etnia);

    printf("\nEndereço:\n");
    printf("Logradouro: %s\n", crianca.endereco.logradouro);
    printf("Número: %d\n", crianca.endereco.numero);
    printf("Complemento: %s\n", crianca.endereco.complemento);
    printf("Bairro: %s\n", crianca.endereco.bairro);
    printf("Cidade: %s\n", crianca.endereco.cidade);
    printf("CEP: %s\n", crianca.endereco.cep);
    printf("Estado: %s\n", crianca.endereco.estado);

    printf("\nVacinas Tomadas:\n");

    // Lógica para exibir vacinas tomadas
    if (crianca.vacinaBCG) {
        printf("BCG - ID dose única: Formas graves de tuberculose\n");
    }
    if (crianca.vacinaHepatiteB1) {
        printf("Vacina contra hepatite B (1) - 1ª dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 1 && crianca.vacinaHepatiteB2) {
        printf("Vacina contra hepatite B (2) - 2ª dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaDTPHib1) {
        printf("Vacina tetravalente (DTP + Hib) (1) - 1ª dose: Difteria, tétano, coqueluche, meningite e outras infecções\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaVOP1) {
        printf("VOP (vacina oral contra pólio) (1) - 1ª dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 2 && crianca.vacinaVORH1) {
        printf("VORH (Vacina Oral de Rotavírus Humano) (1) - 1ª dose: Diarréia por Rotavírus\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaDTPHib2) {
        printf("Vacina tetravalente (DTP + Hib) (2) - 2ª dose: Difteria, tétano, coqueluche, meningite e outras infecções\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaVOP2) {
        printf("VOP (vacina oral contra pólio) (2) - 2ª dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 4 && crianca.vacinaVORH2) {
        printf("VORH (Vacina Oral de Rotavírus Humano) (2) - 2ª dose: Diarréia por Rotavírus\n");
    }

    printf("\nVacinas que Precisam ser Tomadas:\n");

    // Lógica para exibir vacinas que precisam ser tomadas
    if (!crianca.vacinaBCG) {
        printf("BCG - ID dose única: Formas graves de tuberculose\n");
    }
    if (!crianca.vacinaHepatiteB1) {
        printf("Vacina contra hepatite B (1) - 1ª dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 1 && !crianca.vacinaHepatiteB2) {
        printf("Vacina contra hepatite B (2) - 2ª dose: Hepatite B\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaDTPHib1) {
        printf("Vacina tetravalente (DTP + Hib) (1) - 1ª dose: Difteria, tétano, coqueluche, meningite e outras infecções\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaVOP1) {
        printf("VOP (vacina oral contra pólio) (1) - 1ª dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 2 && !crianca.vacinaVORH1) {
        printf("VORH (Vacina Oral de Rotavírus Humano) (1) - 1ª dose: Diarréia por Rotavírus\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaDTPHib2) {
        printf("Vacina tetravalente (DTP + Hib) (2) - 2ª dose: Difteria, tétano, coqueluche, meningite e outras infecções\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaVOP2) {
        printf("VOP (vacina oral contra pólio) (2) - 2ª dose: Poliomielite (paralisia infantil)\n");
    }
    if (crianca.mesesDeVida >= 4 && !crianca.vacinaVORH2) {
        printf("VORH (Vacina Oral de Rotavírus Humano) (2) - 2ª dose: Diarréia por Rotavírus\n");
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configura a localização para a padrão do sistema

    struct Crianca *criancas = NULL;
    int numCriancas = 0;
    char opcao;

    do {
        // Exibir menu
        printf("\nMenu:\n");
        printf("a. Incluir dados de identificação da criança\n");
        printf("b. Incluir endereço da criança\n");
        printf("c. Incluir registro de vacina\n");
        printf("d. Listar todos os dados da criança e verificar vacinação\n");
        printf("e. Sair do programa\n");
        printf("Escolha a opção (a, b, c, d, ou e): ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a': {
                // Adiciona uma nova criança ao array
                numCriancas++;
                criancas = realloc(criancas, numCriancas * sizeof(struct Crianca));
                if (criancas == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return 1;
                }
                incluirDadosIdentificacao(&criancas[numCriancas - 1]);
                break;
            }
            case 'b':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da criança para incluir/endereço: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        incluirEndereco(criancaSelecionada);
                    } else {
                        printf("ID de criança inválido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma criança cadastrada. Cadastre uma criança primeiro.\n");
                }
                break;
            case 'c':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da criança para incluir registro de vacina: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        incluirRegistroVacina(criancaSelecionada);
                    } else {
                        printf("ID de criança inválido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma criança cadastrada. Cadastre uma criança primeiro.\n");
                }
                break;
            case 'd':
                if (numCriancas > 0) {
                    int escolhaId;
                    printf("Escolha o ID da criança para listar os dados e verificar vacinação: ");
                    scanf("%d", &escolhaId);
                    struct Crianca *criancaSelecionada = buscarCriancaPorId(criancas, numCriancas, escolhaId);
                    if (criancaSelecionada != NULL) {
                        listarDados(*criancaSelecionada);
                    } else {
                        printf("ID de criança inválido. Tente novamente.\n");
                    }
                } else {
                    printf("Nenhuma criança cadastrada. Cadastre uma criança primeiro.\n");
                }
                break;
            case 'e':
                // Liberar a memória alocada para o array de crianças
                free(criancas);
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        // Limpar o buffer do teclado
        while (getchar() != '\n');

    } while (opcao != 'e');

    return 0;
}
