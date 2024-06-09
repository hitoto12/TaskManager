# Task Manager System

## Objetivo
Aplicar as estruturas de dados Pilha, Fila e Lista em um código existente em C para gerenciar tarefas.

## Descrição
O sistema gerencia tarefas usando três estruturas de dados:
- **Fila de Tarefas Pendentes**: As tarefas criadas pelo usuário vão para esta fila (FIFO).
- **Lista de Tarefas Concluídas**: As tarefas concluídas são movidas para esta lista.
- **Pilha de Tarefas em Rascunho**: Tarefas removidas da lista de concluídas são movidas para esta pilha (LIFO).

## Funcionalidades
1. Criar uma nova tarefa pendente.
2. Visualizar todas as tarefas pendentes.
3. Concluir a primeira tarefa pendente.
4. Visualizar todas as tarefas concluídas.
5. Mover uma tarefa concluída (por ID) para os rascunhos.
6. Visualizar todas as tarefas em rascunho.
7. Mover a última tarefa em rascunho para as pendentes.
8. Sair do sistema.

## Como Executar
1. Compile o código usando GCC:
    ```bash
    gcc main.c -o main
    ```
2. Execute o programa:
    ```bash
    ./main
    ```
3. Siga as instruções do menu para gerenciar suas tarefas.

## Estrutura do Código
- `main.c`: Contém toda a lógica do sistema, incluindo a definição das estruturas e funções para gerenciar as tarefas.

## Autores

- Cesar Wellington Dos Santos Nunes - RA 024058


