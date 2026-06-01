#include "../src/crypto/vigenere_cipher.h"
#include "../src/crypto/sha512.h"
#include "../src/algorithms/binary_search.h"
#include "../src/algorithms/dijkstra.h"
#include <iostream>
#include <vector>
#include <cassert>

void test_Vigenere() {
    std::cout << "Testing Vigenere Cipher...\n";

    std::string original = "Hello World";
    std::string key = "TEST";

    std::string encrypted = VigenereCipher::encrypt(original, key);
    std::string decrypted = VigenereCipher::decrypt(encrypted, key);

    assert(decrypted == original);
    std::cout << "  Vigenere: OK\n";
}

void test_SHA512() {
    std::cout << "Testing SHA-512...\n";

    std::string hash1 = SHA512::hash("test");
    std::string hash2 = SHA512::hash("test");

    assert(hash1 == hash2 && !hash1.empty());
    assert(hash1.length() == 128);  // SHA-512 hex = 128 символов

    std::cout << "  SHA512: OK\n";
}

void test_BinarySearch() {
    std::cout << "Testing Binary Search...\n";

    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    assert(BinarySearch::search(arr, 7) == 3);
    assert(BinarySearch::search(arr, 1) == 0);
    assert(BinarySearch::search(arr, 13) == 6);
    assert(BinarySearch::search(arr, 100) == -1);

    std::cout << "  Binary Search: OK\n";
}

void test_Dijkstra() {
    std::cout << "Testing Dijkstra...\n";

    Graph g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 1);

    auto dist = g.shortestPath(0);

    assert(dist[0] == 0);
    assert(dist[1] == 3);  // 0->2->1
    assert(dist[3] == 4);  // 0->2->4->3
    assert(dist[4] == 4);

    std::cout << "  Dijkstra: OK\n";
}

int main() {
    std::cout << "=== Запуск Unit-тестов ===\n\n";

    test_Vigenere();
    test_SHA512();
    test_BinarySearch();
    test_Dijkstra();

    std::cout << "\n✅ Все тесты прошли успешно!\n";
    return 0;
}
