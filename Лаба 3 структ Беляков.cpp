#include <iostream>
#include <deque>
#include <vector>

enum Color { WHITE, BLACK };

std::vector<Color> arrange_cards(int n) {
    std::deque<Color> deque;
    for (int i = n; i > 0; --i) {
        if (i % 2 == 1) {
            deque.push_front(WHITE);
        }
        else {
            deque.push_front(BLACK);
        }
        if (i > 1) {
            deque.push_front(deque.back());
            deque.pop_back();
        }
    }
    return std::vector<Color>(deque.begin(), deque.end());
}

void print_deck(const std::vector<Color>& deck) {
    for (Color card : deck) {
        if (card == WHITE) {
            std::cout << "WHITE ";
        }
        else {
            std::cout << "BLACK ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Беляков Никита Юрьевич "; << std::endl;
    std::cout << "090301-ПОВа-о23 "; << std::endl;
    
    std::cout << "Введите количество карточек: ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Невозможно чередовать карточки по цвету с нечетным количеством." << std::endl;
        return 1;
    }

    std::vector<Color> initial_deck = arrange_cards(n);
    std::cout << "Начальное расположение карточек в стопке: ";
    print_deck(initial_deck);

    return 0;
}
