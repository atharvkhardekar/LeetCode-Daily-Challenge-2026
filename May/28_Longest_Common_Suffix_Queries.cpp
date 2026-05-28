// 3093. Longest Common Suffix Queries
// Daily Challenge - 28/05/2026

class Solution {
public:

    struct TrieNode {
        int next[26];
        int bestIndex;

        TrieNode() {
            memset(next, -1, sizeof(next));
            bestIndex = -1;
        }
    };

    vector<TrieNode> trie;

    void chooseBetterIndex(int &currentIdx, int candidateIdx,
                           vector<string>& wordsContainer) {

        if (currentIdx == -1) {
            currentIdx = candidateIdx;
            return;
        }

        int currentLength = wordsContainer[currentIdx].size();
        int candidateLength = wordsContainer[candidateIdx].size();

        if (candidateLength < currentLength) {
            currentIdx = candidateIdx;
        }
        else if (candidateLength == currentLength &&
                 candidateIdx < currentIdx) {
            currentIdx = candidateIdx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        for (int i = 0; i < wordsContainer.size(); i++) {

            string str = wordsContainer[i];
            reverse(str.begin(), str.end());

            int currentNode = 0;

            chooseBetterIndex(trie[currentNode].bestIndex,
                              i,
                              wordsContainer);

            for (char ch : str) {

                int pos = ch - 'a';

                if (trie[currentNode].next[pos] == -1) {
                    trie[currentNode].next[pos] = trie.size();
                    trie.push_back(TrieNode());
                }

                currentNode = trie[currentNode].next[pos];

                chooseBetterIndex(trie[currentNode].bestIndex,
                                  i,
                                  wordsContainer);
            }
        }

        vector<int> result;

        for (string query : wordsQuery) {

            reverse(query.begin(), query.end());

            int currentNode = 0;

            for (char ch : query) {

                int pos = ch - 'a';

                if (trie[currentNode].next[pos] == -1) {
                    break;
                }

                currentNode = trie[currentNode].next[pos];
            }

            result.push_back(trie[currentNode].bestIndex);
        }

        return result;
    }
};
