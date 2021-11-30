#include<bits/stdc++.h>
using namespace std;

struct Node {
    char s;//
    int f;
    struct Node *l, *r;
};

struct comp{
    bool operator()(Node* n1, Node* n2){
        return n1->f > n2->f;
    }
};

Node* create_node(Node n){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->l = NULL;
    temp->r = NULL;
    temp->s = n.s;
    temp->f = n.f;
    return temp; 
    
}
void huffman(vector<Node> nodes){
    priority_queue<Node*,vector<Node*>,comp>Q;
    for(Node n: nodes){
        Node* new_node = create_node(n);
        Q.push(new_node);
        cout<< n.f<<endl;
    }
    while (Q.size()>1){
        Node* x = Q.top();
        Q.pop();
        Node* y = Q.top();
        Q.pop();
        cout<<x->s <<" "<<y->s << endl;
    }
    
}
int main(){
    char chars[] = {'a','b','c','d','e','f'};
    int freq[]={ 8,1,2,4,12,2};
    int n=sizeof(freq)/sizeof(freq[0]);

    vector<Node> nodes;
    for(int i=0; i<n; i++){
        Node n;
        n.s =chars[i]; //
        n.f = freq[i];
        nodes.push_back(n);


    }
    huffman(nodes);
}