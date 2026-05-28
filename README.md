# Sistema de Biblioteca

O sistema permite fazer login, visualizar livros, emprestar livros, devolver livros e cadastrar novos livros quando o usuario logado for bibliotecario.

## Funcionalidades

- Login como visitante ou bibliotecario
- Listagem de livros cadastrados
- Controle simples de estoque
- Emprestimo de livros
- Devolucao de livros
- Cadastro/substituicao de livros pelo bibliotecario
- Logout
- Tratamento basico para entradas invalidas

## Usuarios de teste

Bibliotecario:

```txt
Login: bibliotecario
Senha: biblio123
```

Visitante:

```txt
Login: visitante
Senha: visita123
```

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```powershell
g++ main.cpp -o biblioteca.exe
```

## Como executar

Depois de compilar, execute:

```powershell
.\biblioteca.exe
```

## Observacoes

Este projeto usa dados fixos no proprio codigo, sem banco de dados ou arquivos externos. Ao fechar o programa, alteracoes feitas durante a execucao nao sao salvas.

O objetivo principal e praticar conceitos iniciais de C++, como variaveis, condicionais, loops, arrays, strings e entrada/saida pelo terminal.
