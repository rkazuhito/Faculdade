#include <iostream> // Inclui a biblioteca de entrada e sa�da padr�o
#include <conio.h> // Inclui a biblioteca para lidar com entrada do teclado
#include <windows.h> // Inclui a biblioteca para algumas fun��es de controle do sistema Windows

using namespace std; // Permite o uso de identificadores da biblioteca padr�o sem precisar qualific�-los

bool gameOver; // Vari�vel que indica se o jogo terminou
bool showMenu; // Vari�vel que indica se o menu deve ser exibido
const int width = 40; // Largura da tela do jogo
const int height = 20; // Altura da tela do jogo
int x, y, ballX, ballY, dirX, dirY; // Vari�veis para a posi��o e dire��o da bola e dos jogadores
int paddle1Y, paddle2Y; // Posi��es verticais das raquetes dos jogadores

// Fun��o para configurar as vari�veis do jogo
void Setup()
{
    gameOver = false; // Inicializa o estado do jogo como n�o terminado
    showMenu = true; // Inicialmente, mostra o menu
    x = width / 2; // Define a posi��o inicial do jogador 1
    y = height / 2; // Define a posi��o inicial do jogador 1
    ballX = x; // Define a posi��o inicial da bola
    ballY = y; // Define a posi��o inicial da bola
    dirX = -1; // Define a dire��o inicial da bola na horizontal
    dirY = -1; // Define a dire��o inicial da bola na vertical
    paddle1Y = height / 2; // Define a posi��o vertical inicial da raquete do jogador 1
    paddle2Y = height / 2; // Define a posi��o vertical inicial da raquete do jogador 2
}

// Fun��o para desenhar a tela do jogo
void Draw()
{
    system("cls"); // Limpa a tela do console
    for (int i = 0; i < width + 2; i++) // Loop para desenhar a borda superior
        cout << "#"; // Desenha um caractere de borda
    cout << endl;

    for (int i = 0; i < height; i++) // Loop para desenhar o conte�do da tela
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) // Se estiver na primeira coluna, desenha a borda esquerda
                cout << "#";
            if (i == y && j == x) // Se a posi��o atual corresponder � do jogador 1, desenha o jogador 1
                cout << "O";
            else if (i == ballY && j == ballX) // Se a posi��o atual corresponder � da bola, desenha a bola
                cout << "o";
            else if (i == paddle1Y && j == 1) // Se a posi��o atual corresponder � da raquete do jogador 1, desenha a raquete do jogador 1
                cout << "|";
            else if (i == paddle1Y - 1 && j == 1) // Desenha a parte superior da raquete do jogador 1
                cout << "|";
            else if (i == paddle1Y + 1 && j == 1) // Desenha a parte inferior da raquete do jogador 1
                cout << "|";
            else if (i == paddle2Y && j == width - 2) // Se a posi��o atual corresponder � da raquete do jogador 2, desenha a raquete do jogador 2
                cout << "|";
            else if (i == paddle2Y - 1 && j == width - 2) // Desenha a parte superior da raquete do jogador 2
                cout << "|";
            else if (i == paddle2Y + 1 && j == width - 2) // Desenha a parte inferior da raquete do jogador 2
                cout << "|";
            else // Se n�o estiver em nenhuma das posi��es acima, desenha um espa�o em branco
                cout << " ";
            if (j == width - 1) // Se estiver na �ltima coluna, desenha a borda direita
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) // Loop para desenhar a borda inferior
        cout << "#";
    cout << endl;
}

// Fun��o para lidar com a entrada do jogador
void Input()
{
    if (_kbhit()) // Verifica se uma tecla foi pressionada
    {
        char key = _getch(); // Obt�m a tecla pressionada
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

// Fun��o para atualizar a l�gica do jogo

    void Logic()
{
    ballX += dirX; // Atualiza a posi��o horizontal da bola de acordo com sua dire��o
    ballY += dirY; // Atualiza a posi��o vertical da bola de acordo com sua dire��o

    // Colis�o com as paredes
    if (ballX == width - 1) // Verifica se a bola atingiu a parede direita
        dirX = -dirX; // Inverte a dire��o horizontal da bola para simular o rebatimento

    if (ballY == height - 1 || ballY == 0) // Verifica se a bola atingiu a parede superior ou inferior
        dirY = -dirY; // Inverte a dire��o vertical da bola para simular o rebatimento

    // Colis�o com as raquetes
    if (ballX == 2 && (ballY == paddle1Y || ballY == paddle1Y - 1 || ballY == paddle1Y + 1)) // Verifica se a bola atingiu a raquete esquerda
        dirX = -dirX; // Inverte a dire��o horizontal da bola para simular o rebatimento

    if (ballX == width - 3 && (ballY == paddle2Y || ballY == paddle2Y - 1 || ballY == paddle2Y + 1)) // Verifica se a bola atingiu a raquete direita
        dirX = -dirX; // Inverte a dire��o horizontal da bola para simular o rebatimento

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
    cout << "------------- PONG -------------" << endl; // Imprime o t�tulo do jogo
    cout << "Pressione 'w' e 's' para mover o Jogador 1" << endl; // Instru��es para mover o Jogador 1
    cout << "Pressione 'i' e 'k' para mover o Jogador 2" << endl; // Instru��es para mover o Jogador 2
    cout << "Pressione 'q' para sair" << endl; // Instru��o para sair do jogo
    cout << "---------------------------------" << endl; // Linha separadora
    cout << "Pressione qualquer tecla para iniciar o jogo..."; // Instru��o para iniciar o jogo
    _getch(); // Aguarda at� que o usu�rio pressione uma tecla
    showMenu = false; // Oculta o menu ap�s o usu�rio pressionar uma tecla
}

int main()
{
    while (true) // Loop principal do jogo
    {
        Setup(); // Configura o estado inicial do jogo
        while (!gameOver) // Loop enquanto o jogo n�o acabar
        {
            if (showMenu) // Se showMenu for verdadeiro, exibe o menu
                ShowMenu(); // Exibe o menu na tela
            Draw(); // Desenha a tela do jogo
            Input(); // Captura a entrada do jogador
            Logic(); // Atualiza a l�gica do jogo
            Sleep(50); // Pequeno atraso para diminuir a velocidade do jogo
        }

        Draw(); // Desenha a tela do jogo ap�s o jogo terminar
        if (ballX <= 0) // Se a bola sair pelo lado esquerdo da tela
            cout << "Jogador 2 venceu!" << endl; // Mensagem indicando que o Jogador 2 venceu
        else if (ballX >= width - 1) // Se a bola sair pelo lado direito da tela
            cout << "Jogador 1 venceu!" << endl; // Mensagem indicando que o Jogador 1 venceu

        cout << "Pressione qualquer tecla para jogar novamente..."; // Instru��o para jogar novamente
        _getch(); // Aguarda at� que o usu�rio pressione uma tecla para jogar novamente
    }
    return 0; // Retorna 0 para indicar o t�rmino bem-sucedido do programa
}

// Bibliotecas: Inclu�mos as bibliotecas necess�rias para entrada/sa�da no console (iostream),
// para detec��o de teclas pressionadas (conio.h) e para usar a fun��o Sleep para criar um pequeno atraso (windows.h).

// Vari�veis globais: Definimos v�rias vari�veis globais que ser�o usadas ao longo do c�digo, como gameOver para controlar o estado do jogo,
// showMenu para controlar a exibi��o do menu, dimens�es do jogo (width e height), posi��es da bola e das raquetes, e dire��es da bola.

// Fun��o Setup(): Esta fun��o � chamada no in�cio do jogo para inicializar as vari�veis. Ela define o estado inicial do jogo,
// incluindo a posi��o inicial da bola e das raquetes, e as dire��es da bola.

// Fun��o Draw(): Esta fun��o desenha o estado atual do jogo na tela. Percorremos uma matriz representando a tela do jogo e desenhamos os elementos,
// como a bola, as raquetes e as paredes.

// Fun��o Input(): Esta fun��o detecta as teclas pressionadas pelo jogador e atualiza as posi��es das raquetes de acordo.
// Al�m disso, se o jogador pressionar 'q', o jogo termina e o menu � mostrado novamente.

// Fun��o Logic(): Aqui � onde a l�gica do jogo acontece. A posi��o da bola � atualizada de acordo com sua dire��o.
// Verificamos colis�es da bola com as paredes e as raquetes, e se a bola sai da tela. Se a bola sair da tela, o jogo termina.

// Fun��o ShowMenu(): Esta fun��o mostra o menu na tela. Ele fornece instru��es sobre como jogar e aguarda o jogador pressionar qualquer tecla para iniciar o jogo.

// Fun��o main(): Aqui � onde o jogo � executado. O loop principal do jogo executa at� o jogo acabar.
// Se o jogo acabar, o vencedor � mostrado na tela e o jogador � solicitado a pressionar uma tecla para jogar novamente.



