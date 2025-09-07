#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* raiz) {
        vector<vector<int>> niveis;
        if (raiz == nullptr) return niveis;

        queue<TreeNode*> espera;
        espera.push(raiz);

        while (!espera.empty()) {
            auto qtd = espera.size();
            vector<int> atual;
            atual.reserve(qtd);

            while (qtd--) {
                auto no = espera.front();
                espera.pop();
                atual.push_back(no->val);

                if (no->left) espera.push(no->left);
                if (no->right) espera.push(no->right);
            }
            niveis.push_back(move(atual));
        }
        return niveis;
    }
};