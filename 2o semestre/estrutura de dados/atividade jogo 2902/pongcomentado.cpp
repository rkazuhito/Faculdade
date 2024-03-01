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
void ShowMenu()
{
    system("cls"); // Limpa a tela do console
    cout << "------------- PONG -------------" << endl; // Imprime o título do jogo
    cout << "Pressione 'w' e 's' para mover o Jogador 1" << endl; // Instruções para mover o Jogador 1
    cout << "Pressione 'i' e 'k' para mover o Jogador 2" << endl; // Instruções para mover o Jogador 2
    cout << "Pressione 'q' para sair" << endl; // Instrução para sair do jogo
    cout << "---------------------------------" << endl; // Linha separadora
    cout << "Pressione qualquer tecla para iniciar o jogo..."; // Instrução para iniciar o jogo
    _getch(); // Aguarda até que o usuário pressione uma tecla
    showMenu = false; // Oculta o menu após o usuário pressionar uma tecla
}

int main()
{
    while (true) // Loop principal do jogo
    {
        Setup(); // Configura o estado inicial do jogo
        while (!gameOver) // Loop enquanto o jogo não acabar
        {
            if (showMenu) // Se showMenu for verdadeiro, exibe o menu
                ShowMenu(); // Exibe o menu na tela
            Draw(); // Desenha a tela do jogo
            Input(); // Captura a entrada do jogador
            Logic(); // Atualiza a lógica do jogo
            Sleep(50); // Pequeno atraso para diminuir a velocidade do jogo
        }

        Draw(); // Desenha a tela do jogo após o jogo terminar
        if (ballX <= 0) // Se a bola sair pelo lado esquerdo da tela
            cout << "Jogador 2 venceu!" << endl; // Mensagem indicando que o Jogador 2 venceu
        else if (ballX >= width - 1) // Se a bola sair pelo lado direito da tela
            cout << "Jogador 1 venceu!" << endl; // Mensagem indicando que o Jogador 1 venceu

        cout << "Pressione qualquer tecla para jogar novamente..."; // Instrução para jogar novamente
        _getch(); // Aguarda até que o usuário pressione uma tecla para jogar novamente
    }
    return 0; // Retorna 0 para indicar o término bem-sucedido do programa
}

// Bibliotecas: Incluímos as bibliotecas necessárias para entrada/saída no console (iostream),
// para detecção de teclas pressionadas (conio.h) e para usar a função Sleep para criar um pequeno atraso (windows.h).

// Variáveis globais: Definimos várias variáveis globais que serão usadas ao longo do código, como gameOver para controlar o estado do jogo,
// showMenu para controlar a exibição do menu, dimensões do jogo (width e height), posições da bola e das raquetes, e direções da bola.

// Função Setup(): Esta função é chamada no início do jogo para inicializar as variáveis. Ela define o estado inicial do jogo,
// incluindo a posição inicial da bola e das raquetes, e as direções da bola.

// Função Draw(): Esta função desenha o estado atual do jogo na tela. Percorremos uma matriz representando a tela do jogo e desenhamos os elementos,
// como a bola, as raquetes e as paredes.

// Função Input(): Esta função detecta as teclas pressionadas pelo jogador e atualiza as posições das raquetes de acordo.
// Além disso, se o jogador pressionar 'q', o jogo termina e o menu é mostrado novamente.

// Função Logic(): Aqui é onde a lógica do jogo acontece. A posição da bola é atualizada de acordo com sua direção.
// Verificamos colisões da bola com as paredes e as raquetes, e se a bola sai da tela. Se a bola sair da tela, o jogo termina.

// Função ShowMenu(): Esta função mostra o menu na tela. Ele fornece instruções sobre como jogar e aguarda o jogador pressionar qualquer tecla para iniciar o jogo.

// Função main(): Aqui é onde o jogo é executado. O loop principal do jogo executa até o jogo acabar.
// Se o jogo acabar, o vencedor é mostrado na tela e o jogador é solicitado a pressionar uma tecla para jogar novamente.



