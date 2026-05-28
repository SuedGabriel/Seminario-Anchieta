#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    string livros[10] = {
        "Dom Casmurro",
        "O Pequeno Principe",
        "1984",
        "Harry Potter e a Pedra Filosofal",
        "O Senhor dos Aneis",
        "A Revolucao dos Bichos",
        "Cem Anos de Solidao",
        "O Codigo Da Vinci",
        "Orgulho e Preconceito",
        "Crime e Castigo"};

    int estoqueTotal[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int estoqueDisponivel[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    string loginBiblio = "bibliotecario";
    string senhaBiblio = "biblio123";
    string loginUser = "visitante";
    string senhaUser = "visita123";

    bool bibliotecarioLogado = false;
    bool usuarioLogado = false;

    int opcao;

    do
    {
        cout << "\n=====================================\n";
        cout << "======= SISTEMA DE BIBLIOTECA =======\n";
        cout << "=====================================\n";

        if (!usuarioLogado)
        {
            cout << "1 - Logar\n";
        }
        else
        {
            cout << "Usuario logado com sucesso!\n";

            if (bibliotecarioLogado)
            {
                cout << "2 - Cadastrar livros\n";
            }

            cout << "3 - Exibir livros\n";
            cout << "4 - Emprestar livro\n";
            cout << "5 - Devolver livro\n";
            cout << "6 - Logout\n";
        }

        cout << "99 - Sair\n";
        cout << "Digite a opcao: ";
        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntrada invalida. Digite apenas numeros.\n";
            continue;
        }

        if (opcao == 1)
        {
            string login, senha;

            cout << "\n===== LOGIN =====\n";
            cout << "Insira seu login: ";
            cin >> login;

            cout << "Insira sua senha: ";
            cin >> senha;

            if (login == loginBiblio && senha == senhaBiblio)
            {
                cout << "\nSucesso! Voce logou como bibliotecario!\n";
                bibliotecarioLogado = true;
                usuarioLogado = true;
            }
            else if (login == loginUser && senha == senhaUser)
            {
                cout << "\nSucesso! Voce logou como visitante!\n";
                bibliotecarioLogado = false;
                usuarioLogado = true;
            }
            else
            {
                cout << "\nFalha no login! Usuario ou senha incorretos.\n";
                bibliotecarioLogado = false;
                usuarioLogado = false;
            }
        }

        else if (opcao == 2)
        {
            if (bibliotecarioLogado)
            {
                int espacoLivro;

                cout << "\n===== LISTA DE LIVROS CADASTRADOS =====\n";
                for (int i = 0; i < 10; i++)
                {
                    cout << i + 1 << " - " << livros[i] << "\n";
                }

                cout << "\nInsira o espaco que deseja cadastrar: ";
                cin >> espacoLivro;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nEntrada invalida. Digite apenas numeros.\n";
                    continue;
                }

                if (espacoLivro >= 1 && espacoLivro <= 10)
                {
                    if (estoqueDisponivel[espacoLivro - 1] == estoqueTotal[espacoLivro - 1])
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Informe o nome do livro: ";
                        getline(cin, livros[espacoLivro - 1]);

                        estoqueTotal[espacoLivro - 1] = 1;
                        estoqueDisponivel[espacoLivro - 1] = 1;

                        cout << "\nLivro cadastrado com sucesso!\n";
                    }
                    else
                    {
                        cout << "\nNao e possivel trocar um livro que esta emprestado.\n";
                    }
                }
                else
                {
                    cout << "\nPosicao invalida.\n";
                }
            }
            else
            {
                cout << "\nApenas bibliotecarios podem usar essa funcao.\n";
            }
        }

        else if (opcao == 3)
        {
            if (usuarioLogado)
            {
                cout << "\n===== LISTA DE LIVROS =====\n";
                for (int i = 0; i < 10; i++)
                {
                    cout << i + 1 << " - " << livros[i]
                         << ". Estoque disponivel: "
                         << estoqueDisponivel[i] << "\n";
                }
            }
            else
            {
                cout << "\nVoce precisa estar logado para exibir livros.\n";
            }
        }

        else if (opcao == 4)
        {
            if (usuarioLogado)
            {
                int espacoLivro;

                cout << "\n===== LISTA DE LIVROS =====\n";
                for (int i = 0; i < 10; i++)
                {
                    cout << i + 1 << " - " << livros[i]
                         << ". Estoque disponivel: "
                         << estoqueDisponivel[i] << "\n";
                }

                cout << "\nInsira o espaco do livro que deseja emprestar: ";
                cin >> espacoLivro;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nEntrada invalida. Digite apenas numeros.\n";
                    continue;
                }

                if (espacoLivro >= 1 && espacoLivro <= 10)
                {
                    if (estoqueDisponivel[espacoLivro - 1] > 0)
                    {
                        estoqueDisponivel[espacoLivro - 1]--;
                        cout << "\nAproveite! Voce emprestou o: "
                             << livros[espacoLivro - 1] << "\n";
                    }
                    else
                    {
                        cout << "\nNao foi possivel fazer o emprestimo! Estamos sem estoque.\n";
                    }
                }
                else
                {
                    cout << "\nPosicao invalida.\n";
                }
            }
            else
            {
                cout << "\nVoce precisa estar logado para emprestar livros.\n";
            }
        }

        else if (opcao == 5)
        {
            if (usuarioLogado)
            {
                int espacoLivro;

                cout << "\n===== LISTA DE LIVROS =====\n";
                for (int i = 0; i < 10; i++)
                {
                    cout << i + 1 << " - " << livros[i]
                         << ". Estoque disponivel: "
                         << estoqueDisponivel[i] << "\n";
                }

                cout << "\nInsira o espaco do livro que deseja devolver: ";
                cin >> espacoLivro;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nEntrada invalida. Digite apenas numeros.\n";
                    continue;
                }

                if (espacoLivro >= 1 && espacoLivro <= 10)
                {
                    if (estoqueDisponivel[espacoLivro - 1] < estoqueTotal[espacoLivro - 1])
                    {
                        estoqueDisponivel[espacoLivro - 1]++;
                        cout << "\nObrigado! Voce devolveu o: "
                             << livros[espacoLivro - 1] << "\n";
                    }
                    else
                    {
                        cout << "\nHouve um erro! Esse livro nao foi emprestado.\n";
                    }
                }
                else
                {
                    cout << "\nPosicao invalida.\n";
                }
            }
            else
            {
                cout << "\nVoce precisa estar logado para devolver livros.\n";
            }
        }

        else if (opcao == 6)
        {
            if (usuarioLogado)
            {
                usuarioLogado = false;
                bibliotecarioLogado = false;
                cout << "\nLogout realizado com sucesso.\n";
            }
            else
            {
                cout << "\nNenhum usuario esta logado.\n";
            }
        }

        else if (opcao != 99)
        {
            cout << "\nOpcao invalida.\n";
        }

    } while (opcao != 99);

    cout << "\nSistema encerrado.\n";
    return 0;
}
