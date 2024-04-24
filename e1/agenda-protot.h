typedef struct {
  char nome[40];
  char email[40];
  int telefone;
} Contato;

typedef struct {
  Contato *contatos;
  int capacidade;
  int tamanho;
} Agenda;

// Protótipos das funções relacionadas à Agenda
Agenda *criarAgenda(int capacidade);
void liberarAgenda(Agenda *agenda);
void inserirContato(Agenda *agenda, const char *nome, const char *email,
                    int telefone);
void excluirContato(Agenda *agenda, const char *nome);
void alterarContato(Agenda *agenda, const char *nome);
void consultarAgenda(const Agenda *agenda);
void pesquisarContato(const Agenda *agenda, const char *nome);
void ordenarAgenda(Agenda *agenda);
void quicksort(Contato *contatos, int esq, int dir);
