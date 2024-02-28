//jogo desenvolvido por Rafael Kazuhito / Bruno de Oliveira / Patrick Padilha

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
bool showMenu;
const int width = 40;
const int height = 20;
int x, y, ballX, ballY, dirX, dirY;
int paddle1Y, paddle2Y;

void Setup()
{
    gameOver = false;
    showMenu = true;
    x = width / 2;
    y = height / 2;
    ballX = x;
    ballY = y;
    dirX = -1;
    dirY = -1;
    paddle1Y = height / 2;
    paddle2Y = height / 2;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == ballY && j == ballX)
                cout << "o";
            else if (i == paddle1Y && j == 1)
                cout << "|";
            else if (i == paddle1Y - 1 && j == 1)
                cout << "|";
            else if (i == paddle1Y + 1 && j == 1)
                cout << "|";
            else if (i == paddle2Y && j == width - 2)
                cout << "|";
            else if (i == paddle2Y - 1 && j == width - 2)
                cout << "|";
            else if (i == paddle2Y + 1 && j == width - 2)
                cout << "|";
            else
                cout << " ";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
}

void Input()
{
    if (_kbhit())
    {
        char key = _getch();
        if (key == 'w' && paddle1Y > 2)
            paddle1Y--;
        if (key == 's' && paddle1Y < height - 3)
            paddle1Y++;
        if (key == 'i' && paddle2Y > 2)
            paddle2Y--;
        if (key == 'k' && paddle2Y < height - 3)
            paddle2Y++;
        if (key == 'q')
        {
            showMenu = true;
            gameOver = true;
        }
    }
}

void Logic()
{
    ballX += dirX;
    ballY += dirY;

    // Colisão com as paredes
    if (ballX == width - 1)
        dirX = -dirX; // Bola bate na parede direita
    if (ballY == height - 1 || ballY == 0)
        dirY = -dirY; // Bola bate na parede superior ou inferior

    // Colisão com as raquetes
    if (ballX == 2 && (ballY == paddle1Y || ballY == paddle1Y - 1 || ballY == paddle1Y + 1))
        dirX = -dirX; // Bola bate na raquete esquerda
    if (ballX == width - 3 && (ballY == paddle2Y || ballY == paddle2Y - 1 || ballY == paddle2Y + 1))
        dirX = -dirX; // Bola bate na raquete direita

    // Verificar se a bola sai da tela
    if (ballX <= 0 || ballX >= width - 1)
    {
        showMenu = true;
        gameOver = true;
    }
}

void ShowMenu()
{
    system("cls");
    cout << "------------- PONG -------------" << endl;
    cout << "Pressione 'w' e 's' para mover o Jogador 1" << endl;
    cout << "Pressione 'i' e 'k' para mover o Jogador 2" << endl;
    cout << "Pressione 'q' para sair" << endl;
    cout << "---------------------------------" << endl;
    cout << "Pressione qualquer tecla para iniciar o jogo...";
    _getch();
    showMenu = false;
}

int main()
{
    while (true)
    {
        Setup();
        while (!gameOver)
        {
            if (showMenu)
                ShowMenu();
            Draw();
            Input();
            Logic();
            Sleep(50); // Pequeno atraso para diminuir a velocidade do jogo
        }

        Draw();
        if (ballX <= 0)
            cout << "Jogador 2 venceu!" << endl;
        else if (ballX >= width - 1)
            cout << "Jogador 1 venceu!" << endl;

        cout << "Pressione qualquer tecla para jogar novamente...";
        _getch();
    }
    return 0;
}

