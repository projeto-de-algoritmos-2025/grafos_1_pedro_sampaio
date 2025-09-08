#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string palavraInicio, string palavraFim, vector<string>& listaPalavras) {
        unordered_set<string> dicionario(listaPalavras.begin(), listaPalavras.end());
        if (!dicionario.count(palavraFim)) return 0;

        queue<string> fila;
        fila.push(palavraInicio);
        int qtdPassos = 1;

        while (!fila.empty()) {
            for (int tamNivel = fila.size(); tamNivel > 0; --tamNivel) {
                string palavraAtual = fila.front(); 
                fila.pop();

                if (palavraAtual == palavraFim) return qtdPassos;

                for (int i = 0; i < palavraAtual.size(); i++) {
                    char letraOriginal = palavraAtual[i];
                    for (char letra = 'a'; letra <= 'z'; letra++) {
                        if (letra == letraOriginal) continue;
                        palavraAtual[i] = letra;
                        if (dicionario.erase(palavraAtual)) fila.push(palavraAtual);
                    }
                    palavraAtual[i] = letraOriginal;
                }
            }
            qtdPassos++;
        }
        return 0;
    }
};