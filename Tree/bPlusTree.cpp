#include <bits/stdc++.h>
#define ORDER 5

using namespace std;

class Node {
    public:
        bool is_leaf;
        int cur_num_keys;
        vector<string> keys;
        vector<Node*> children;
        Node* parent;

        Node(bool is_leaf = false) {
            this->is_leaf = is_leaf;
            cur_num_keys = 0;
            keys.resize(ORDER);
            children.resize(ORDER+1);
            this->parent = nullptr;
        }
};

class BPlusTree {
    private:
        Node* root;

    public:     
        BPlusTree() {
            root = nullptr;
        }

        void insert(string word) {
            if(root == nullptr) {
                root = new Node(true);
                root->keys[0] = word;
                root->cur_num_keys = root->cur_num_keys++;
            } else {
                Node * temp = root;
                if(temp->cur_num_keys == ORDER) {
                    Node* newNode = new Node();
                    root = newNode;
                    newNode->children[0] = temp;
                    split_node(newNode, 0);
                    check_and_insert(newNode, word);
                } else {
                    check_and_insert(temp, word);
                }
            }
        }

        void split_node(Node* node, int start) {
            Node* copyChild = node->children[start];
            Node* newNode = new Node(copyChild->is_leaf);
            newNode->parent = node;
            node->children.insert(node->children.begin() + start + 1, newNode);
            node->keys.insert(node->keys.begin() + start, copyChild->keys[ORDER / 2]);
            node->cur_num_keys++;
            node->children[start + 1] = newNode;

            for (int i = ORDER / 2 + 1; i < ORDER; i++) {
            newNode->keys[i - (ORDER / 2 + 1)] = copyChild->keys[i];
            newNode->children[i - (ORDER / 2 + 1)] = copyChild->children[i];
            newNode->cur_num_keys++;
            copyChild->cur_num_keys--;
            }

            if (!copyChild->is_leaf)
                newNode->children[newNode->cur_num_keys] = copyChild->children[ORDER];
            copyChild->cur_num_keys--;
        }

        void check_and_insert(Node* node, string word) {
            int index_to_put = node->cur_num_keys - 1;
            if(node->is_leaf) {
                while(index_to_put >= 0 && word < node->keys[index_to_put]) {
                    node->keys[index_to_put + 1] = node->keys[index_to_put];
                    index_to_put--;
                }
                node->keys[index_to_put+1] = word;
                node->cur_num_keys++;
            } else {
                while(index_to_put >= 0 && word < node->keys[index_to_put]) {
                    index_to_put--;
                }
                index_to_put++;
                if(node->children[index_to_put]->cur_num_keys == ORDER) {
                    split_node(node, index_to_put);
                    if(word > node->keys[index_to_put]) {
                        index_to_put++;
                    }
                    check_and_insert(node->children[index_to_put], word);
                }
            }
        }

        bool search(string word) {
            if (root == nullptr)
                return false;

            Node* curr = root;
            while (curr != nullptr) {
                int i = 0;
                while (i < curr->cur_num_keys && word > curr->keys[i])
                    i++;

                if (i < curr->cur_num_keys && word == curr->keys[i])
                    return true;

                if (curr->is_leaf)
                    return false;

                curr = curr->children[i];
            }

            return false;
        }
};
int main() {
    BPlusTree dictionary;

    dictionary.insert("apple");
    dictionary.insert("banana");
    dictionary.insert("cherry");
    dictionary.insert("date");

    std::cout << "Searching for 'apple': " << (dictionary.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'banana': " << (dictionary.search("banana") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'cherry': " << (dictionary.search("cherry") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'date': " << (dictionary.search("date") ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 'grape': " << (dictionary.search("grape") ? "Found" : "Not found") << std::endl;

    return 0;
}

