#include <iostream> // Inclui a biblioteca de entrada e saída padrão
#include <conio.h> // Inclui a biblioteca para lidar com entrada do teclado
#include <windows.h> // Inclui a biblioteca para algumas funções de controle do sistema Windows

using namespace std; // Permite o uso de identificadores da biblioteca padrão sem precisar qualificá-los

bool gameOver; // Variável que indica se o jogo terminou
bool showMenu; // Variável que indica se o menu deve ser exibido
const int width = 40; // Largura da tela do jogo
const int height = 20; // Altura da tela do jogo
int x, y, ballX, ballY, dirX, dirY; // Variáveis para a posição e direção da bola e dos jogadores
int paddle1Y, paddle2Y; // Posições verticais das raquetes dos jogadores

// Função para configurar as variáveis do jogo
void Setup()
{
    gameOver = false; // Inicializa o estado do jogo como não terminado
    showMenu = true; // Inicialmente, mostra o menu
    x = width / 2; // Define a posição inicial do jogador 1
    y = height / 2; // Define a posição inicial do jogador 1
    ballX = x; // Define a posição inicial da bola
    ballY = y; // Define a posição inicial da bola
    dirX = -1; // Define a direção inicial da bola na horizontal
    dirY = -1; // Define a direção inicial da bola na vertical
    paddle1Y = height / 2; // Define a posição vertical inicial da raquete do jogador 1
    paddle2Y = height / 2; // Define a posição vertical inicial da raquete do jogador 2
}

// Função para desenhar a tela do jogo
void Draw()
{
    system("cls"); // Limpa a tela do console
    for (int i = 0; i < width + 2; i++) // Loop para desenhar a borda superior
        cout << "#"; // Desenha um caractere de borda
    cout << endl;

    for (int i = 0; i < height; i++) // Loop para desenhar o conteúdo da tela
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) // Se estiver na primeira coluna, desenha a borda esquerda
                cout << "#";
            if (i == y && j == x) // Se a posição atual corresponder à do jogador 1, desenha o jogador 1
                cout << "O";
            else if (i == ballY && j == ballX) // Se a posição atual corresponder à da bola, desenha a bola
                cout << "o";
            else if (i == paddle1Y && j == 1) // Se a posição atual corresponder à da raquete do jogador 1, desenha a raquete do jogador 1
                cout << "|";
            else if (i == paddle1Y - 1 && j == 1) // Desenha a parte superior da raquete do jogador 1
                cout << "|";
            else if (i == paddle1Y + 1 && j == 1) // Desenha a parte inferior da raquete do jogador 1
                cout << "|";
            else if (i == paddle2Y && j == width - 2) // Se a posição atual corresponder à da raquete do jogador 2, desenha a raquete do jogador 2
                cout << "|";
            else if (i == paddle2Y - 1 && j == width - 2) // Desenha a parte superior da raquete do jogador 2
                cout << "|";
            else if (i == paddle2Y + 1 && j == width - 2) // Desenha a parte inferior da raquete do jogador 2
                cout << "|";
            else // Se não estiver em nenhuma das posições acima, desenha um espaço em branco
                cout << " ";
            if (j == width - 1) // Se estiver na última coluna, desenha a borda direita
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) // Loop para desenhar a borda inferior
        cout << "#";
    cout << endl;
}

// Função para lidar com a entrada do jogador
void Input()
{
    if (_kbhit()) // Verifica se uma tecla foi pressionada
    {
        char key = _getch(); // Obtém a tecla pressionada
        if (key == 'w' && paddle1Y > 2) // Se o jogador 1 pressionar 'w', move a raquete para cima
            paddle1Y--;
        if (key == 's' && paddle1Y < height - 3) // Se o jogador 1 pressionar 's', move a raquete para baixo
            paddle1Y++;
        if (key == 'i' && paddle2Y > 2) // Se o jogador 2 pressionar 'i', move a raquete para cima
            paddle2Y--;
        if (key == 'k' && paddle2Y < height - 3) // Se o jogador 2 pressionar 'k', move a raquete para baixo
            paddle2Y++;
        if (key == 'q') // Se pressionar 'q', mostra o menu e define o jogo como terminado
        {
            showMenu = true;
            gameOver = true;
        }
    }
}

// Função para atualizar a lógica do jogo

    void Logic()
{
    ballX += dirX; // Atualiza a posição horizontal da bola de acordo com sua direção
    ballY += dirY; // Atualiza a posição vertical da bola de acordo com sua direção

    // Colisão com as paredes
    if (ballX == width - 1) // Verifica se a bola atingiu a parede direita
        dirX = -dirX; // Inverte a direção horizontal da bola para simular o rebatimento

    if (ballY == height - 1 || ballY == 0) // Verifica se a bola atingiu a parede superior ou inferior
        dirY = -dirY; // Inverte a direção vertical da bola para simular o rebatimento

    // Colisão com as raquetes
    if (ballX == 2 && (ballY == paddle1Y || ballY == paddle1Y - 1 || ballY == paddle1Y + 1)) // Verifica se a bola atingiu a raquete esquerda
        dirX = -dirX; // Inverte a direção horizontal da bola para simular o rebatimento

    if (ballX == width - 3 && (ballY == paddle2Y || ballY == paddle2Y - 1 || ballY == paddle2Y + 1)) // Verifica se a bola atingiu a raquete direita
        dirX = -dirX; // Inverte a direção horizontal da bola para simular o rebatimento

    // Verificar se a bola sai da tela
    if (ballX <= 0 || ballX >= width - 1) // Verifica se a bola ultrapassou os limites laterais da tela
    {
        showMenu = true; // Mostra o menu
        gameOver = true; // Define o jogo como terminado
    }
}


