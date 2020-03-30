#include <set>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node *left; //left 라는 이름의 Node 구조체를 가리키는 포인터 변수 선언
    Node *right; // right 라는 이름의 Node 구조체를 가리키는 포인터 변수 선언
    Node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
};

void remove(Node *root){
    if(root->left){
        remove(root->left);
    }
    if(root->right){
        remove(root->right);
    }
    delete root;
}

string pre_order(Node *root){
    //pre order는 1. 노드 방문, 2. 왼쪽 서브트리 방문, 3. 오른쪽 서브트리 방문임. 재귀를 이용하여 구현한다.
    string ans = "";
    ans += "V";
    if(root->left){
        ans += "L";
        ans += pre_order(root->left);
        ans += "l";
    }
    if(root->right){
        ans += "R";
        ans += pre_order(root->right);
        ans += "r";
    }
    ans += "v";
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    set<string> s;
    while(n--){
        vector<int> a(k,0);
        for(int i = 0; i < k; i++){
            int element; cin>>element;
            a[i] = element;
        }
        //Set Root Node
        Node *root = new Node;
        root->val = a[0];
        
        for(int i = 1; i < k; i++){
            Node *curr = root;
            while(true){
                if(a[i] < curr->val){
                    if(curr->left == NULL){
                        curr->left = new Node;
                        curr->left->val = a[i];
                        break;
                    }
                    else{
                        curr = curr->left;
                    }
                }
                else if(a[i] > curr->val){
                    if(curr->right == NULL){
                        curr->right = new Node;
                        curr->right->val = a[i];
                        break;
                    }
                    else{
                        curr = curr->right;
                    }
                }
                else{
                    break;
                }
            }
        }
        string tmp = pre_order(root);
        s.insert(tmp);
        remove(root);
    }
    cout<<s.size()<<endl;
    return 0;
}