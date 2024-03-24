#include <iostream>
#include <cstring>
#include <fstream>

constexpr short TITLE_LEN = 21;
constexpr short MAX_GAMES_COUNT = 20;


class Game {
private:
    char title[TITLE_LEN];
    double price;
    bool isAvailable;

public:
    Game() : price(0), isAvailable(false) {
        title[0] = '\0';
    }

    Game(const char *title, double price, bool isAvailable) : isAvailable(isAvailable) {
        setPrice(price);
        setTitle(title);
    }

    const char *getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    void setTitle(const char *title) {
        if (!title) {
            return;
        }

        strncpy(this->title, title, TITLE_LEN);
    }

    void setPrice(double price) {
        if (price < 0) {
            price = 0;
        }

        this->price = price;
    }

    void setIsAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    bool isFree() const {
        return price == 0;
    }

    void print() const {
        std::cout << "Title: " << title << std::endl
                  << "Price: " << price << std::endl
                  << "Is available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

using BiPredicate = bool (*)(const Game &lhs, const Game &rhs);

class GamePlatform {
private:
    Game games[MAX_GAMES_COUNT]{};
    size_t gamesCount = 0;

public:
    GamePlatform() = default;

    const Game *getGames() const {
        return games;
    }

    size_t getGamesCount() const {
        return gamesCount;
    }


    bool addGame(const Game &game) {
        if (gamesCount >= MAX_GAMES_COUNT) {
            return false;
        }

        games[gamesCount++] = game;
        return true;
    }

    Game findByTitle(const char *title) const {
        if (!title) {
            return {};

        }

        for (int i = 0; i < gamesCount; i++) {
            if (strcmp(games[i].getTitle(), title) == 0) {
                return games[i];
            }
        }

        return {};
    }

    Game find(const BiPredicate &biPredicate) const {
        Game result = games[0];
        for (int i = 1; i < gamesCount; i++) {
            if (biPredicate(games[i], result)) {
                result = games[i];
            }
        }

        return result;
    }

    Game findCheapest() const {
        return find([](const Game &lhs, const Game &rhs) {
            return lhs.getPrice() < rhs.getPrice();
        });
    }

    Game findMostExpensive() const {
        return find([](const Game &lhs, const Game &rhs) {
            return lhs.getPrice() > rhs.getPrice();
        });
    }

    bool removeGame(const char *title) {
        if (!title) {
            return false;
        }

        for (int i = 0; i < gamesCount; i++) {
            if (strcmp(games[i].getTitle(), title) == 0) {
                std::swap(games[i], games[gamesCount--]);
                return true;
            }
        }

        return false;
    }

    void printAvailable() const {
        for (int i = 0; i < gamesCount; i++) {
            if (games[i].getIsAvailable()) {
                games[i].print();
            }
        }
    }

    void printAll() const {
        for (int i = 0; i < gamesCount; i++) {
            games[i].print();
        }
    }

    void saveToFile(const char *filePath) const {
        if (!filePath) {
            return;
        }

        std::ofstream file(filePath);
        if (!file.is_open()) {
            return;
        }

        file << gamesCount << std::endl;
        for (int i = 0; i < gamesCount; i++) {
            file << games[i].getTitle() << ' '
                 << games[i].getPrice() << ' '
                 << games[i].getIsAvailable() << std::endl;
        }

        file.close();
    }

    void readFromFile(const char *filePath) {
        if (!filePath) {
            return;
        }

        std::ifstream file(filePath);
        if (!file.is_open()) {
            return;
        }

        file >> gamesCount;
        char title[TITLE_LEN];
        double price;
        bool isAvailable;

        for (int i = 0; i < gamesCount; i++) {
            file >> title >> price >> isAvailable;
            games[i] = Game(title, price, isAvailable);
        }

        file.close();
    }

    void sort(const BiPredicate &biPredicate) {
        for (int i = 0; i < gamesCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < gamesCount; j++) {
                if (biPredicate(games[j], games[minIndex])) {
                    minIndex = j;
                }
            }

            if (i != minIndex) {
                std::swap(games[i], games[minIndex]);
            }
        }
    }

    void sortByPrice() {
        sort([](const Game &lhs, const Game &rhs) {
            return lhs.getPrice() < rhs.getPrice();
        });
    }

    void sortByTitle() {
        sort([](const Game &lhs, const Game &rhs) {
            return strcmp(lhs.getTitle(), rhs.getTitle()) < 0;
        });
    }
};