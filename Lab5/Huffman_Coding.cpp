#include<bits/stdc++.h>
using namespace std;

struct Node {
    char value;
    int freq;
    struct Node *left, *right;
};
struct compare_to{
    bool operator()(Node* c1, Node* c2){
        return c1->freq > c2->freq;
    }
};

Node* Huffman_Coding(char values[], int freq[], int n){
    vector<Node> nodes;
    priority_queue<Node*,vector<Node*>,compare_to>Q;
    for(int i=0; i<n; i++){
        Node n = {values[i],freq[i]};
        nodes.push_back(n);
        Node* tempNode = new Node;
        tempNode->left = NULL;
        tempNode->right = NULL;
        tempNode->value=values[i];
        tempNode->freq=freq[i];
        Q.push(tempNode);
    }
    while (Q.size()>1){
        Node* x = Q.top();
        Q.pop();
        Node* y = Q.top();
        Q.pop();
        Node* z = (Node*) malloc(sizeof(Node));
        z->left = x;
        z->right = y;
        z->value = NULL;
        z->freq = x->freq+y->freq;
        Q.push(z);
    }
    return Q.top();
}
void print(Node* node, string str) {
    if (!node)
        return;
    if (node->value != NULL)
        cout<<node->value<<": "<<str<<"\n";
    print(node->left, str + "0");
    print(node->right, str + "1");
}
int main(){
    char values[] = {'a','b','c','d','e','f'};
    int freq[]={5, 9, 12, 13, 16, 11};
    int n=sizeof(freq)/sizeof(freq[0]);
    Node* root=Huffman_Coding(values, freq, n);
    print(root,"");
    return 0;
}
