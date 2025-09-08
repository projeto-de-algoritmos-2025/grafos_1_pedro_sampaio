#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& tabuleiro) {
        string estadoInicial;
        for (auto& linha : tabuleiro)
            for (auto v : linha) estadoInicial.push_back(char('0' + v));

        const string alvo = "123450";
        if (estadoInicial == alvo) return 0;

        const vector<vector<int>> vizinhos = {
            {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}
        };

        queue<pair<string,int>> fila;
        unordered_set<string> visitado;
        fila.push({estadoInicial, 0});
        visitado.insert(estadoInicial);

        while (!fila.empty()) {
            auto [estado, passos] = fila.front(); fila.pop();
            if (estado == alvo) return passos;

            auto posZero = estado.find('0');
            for (auto proxPos : vizinhos[posZero]) {
                auto prox = estado;
                swap(prox[posZero], prox[proxPos]);
                if (visitado.insert(prox).second)
                    fila.push({prox, passos + 1});
            }
        }
        return -1;
    }
};
