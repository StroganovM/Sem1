#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Определяем класс фигур
class Piece {
public:
    Piece(string color) {
        this->color = color;
    }
    virtual string getSymbol() {
        return "  ";
    }
    string getColor() {
        return color;
    }
protected:
    string color;
};

// Определяем класс пустой клетки
class EmptyCell : public Piece {
public:
    EmptyCell() : Piece("none") {
    }
    string getSymbol() {
        return "- ";
    }
};

// Определяем класс пешки
class Pawn : public Piece {
public:
    Pawn(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♙ " : "♟ ";
    }
};

// Определяем класс коня
class Knight : public Piece {
public:
    Knight(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♘ " : "♞ ";
    }
};

// Определяем класс слона
class Bishop : public Piece {
public:
    Bishop(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♗ " : "♝ ";
    }
};

// Определяем класс ладьи
class Rook : public Piece {
public:
    Rook(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♖ " : "♜ ";
    }
};

// Определяем класс ферзя
class Queen : public Piece {
public:
    Queen(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♕ " : "♛ ";
    }
};

// Определяем класс короля
class King : public Piece {
public:
    King(string color) : Piece(color) {
    }
    string getSymbol() {
        return color == "white" ? "♔ " : "♚ ";
    }
};

// Определяем класс игрока
class Player {
public:
    Player(string name, string color) {
        this->name = name;
        this->color = color;
    }
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
    void addPiece(Piece* piece) {
        pieces.push_back(piece);
    }
    vector<Piece*> getPieces() {
        return pieces;
    }
public:
    string name;
    string color;
    vector <Piece*> pieces;
};

// Определяем класс доски
class Board {
public:
    Board() {
        // Создаем пустые клетки на доске
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                pieces[i][j] = new EmptyCell();
            }
        }
        // Создаем фигуры на доске
        for (int i = 0;
            // Создаем фигуры на доске
            for (int i = 0; i < 8; i++) {
                pieces[1][i] = new Pawn("white");
                    pieces[6][i] = new Pawn("black");
            }
        pieces[0][0] = new Rook("white");
            pieces[0][7] = new Rook("white");
            pieces[7][0] = new Rook("black");
            pieces[7][7] = new Rook("black");
            pieces[0][1] = new Knight("white");
            pieces[0][6] = new Knight("white");
        pieces[7][1] = new Knight("black");
        pieces[7][6] = new Knight("black");
        pieces[0][2] = new Bishop("white");
        pieces[0][5] = new Bishop("white");
        pieces[7][2] = new Bishop("black");
        pieces[7][5] = new Bishop("black");
        pieces[0][3] = new Queen("white");
        pieces[7][3] = new Queen("black");
        pieces[0][4] = new King("white");
        pieces[7][4] = new King("black");
    }
    void print() {
        // Выводим доску на экран
        cout << "  a b c d e f g h\n";
        for (int i = 0; i < 8; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < 8; j++) {
                cout << pieces[i][j]->getSymbol();
            }
            cout << i + 1 << endl;
        }
        cout << "  a b c d e f g h\n";
    }
    void move(string from, string to) {
        // Парсим координаты хода
        int fromRow = from[1] - '1';
        int fromCol = from[0] - 'a';
        int toRow = to[1] - '1';
        int toCol = to[0] - 'a';
        // Проверяем, что клетки существуют
        if (fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 ||
            toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
            cout << "Invalid move: out of board range\n";
            return;
        }
        // Получаем фигуру, которую нужно переместить
        Piece* piece = pieces[fromRow][fromCol];
        if (piece->getColor() != currentPlayer->getColor()) {
            cout << "Invalid move: you cannot move the opponent's piece\n";
            return;
        }
        // Проверяем, что это действительно ход этой фигуры
        if (!isValidMove(fromRow, fromCol, toRow, toCol)) {
            cout << "Invalid move: this piece cannot move there\n";
            return;
        }
        // Перемещаем фигуру
        pieces[fromRow][fromCol] = new EmptyCell();
        pieces[toRow][toCol] = piece;
        // Передаем ход следующему игроку
        currentPlayer = currentPlayer == player1 ? player2 : player1;
    }
    void play() {
        // Создаем двух игроков
        player1 = new Player("Player 1", "white");
        player2 = new Player("Player 2", "black");
        currentPlayer = player1;

        // Печатаем начальное состояние доски
        print();

        // Цикл игры
        while (true) {
            // Получаем ход от игрока
            string from, to;
            cout << currentPlayer->getName() << ", make your move (e.g. e2 e4): ";
            cin >> from >> to;

            // Выполняем ход
            move(from, to);

            // Печатаем текущее состояние доски
            print();

            // Проверяем, не наступил ли конец игры
            if (isGameOver()) {
                break;
            }
        }

        // Печатаем результат игры
        if (isCheckmate()) {
            cout << "Checkmate! " << currentPlayer->getName() << " wins!\n";
        }
        else {
            cout << "Stalemate! The game is a draw.\n";
        }

        // Очищаем память
        delete player1;
        delete player2;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                delete pieces[i][j];
            }
        }
    }
};

int main() {
    ChessGame game;
    game.play();
    return 0;
}