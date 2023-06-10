#include <bits/stdc++.h> 
using namespace std;

struct node{
    int val;
    node* parent;
    vector<pair<int, node*>> next;
};

struct node* newNode(int val, node* parent, int version)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->parent = parent;
    node->next.push_back({version, NULL});
    return (node);
}

bool myComp(const int& e1, const int& val) {
    return e1<val;
};

class Stack{
    public:
    node *root, *top, *temp;
    int version;
    Stack(){
        version = 0;
        root = newNode(-1, NULL, version);
        top = root;
    }
    void push(int val){
        version+=1;
        temp = newNode(val, top, version);
        top->next.push_back({version, temp});
        top = temp;
    }
    void pop(){
        version+=1;
        temp = top->parent;
        temp->next.push_back({version, NULL});
        top=temp;
    }
    void printStack(int version){
        temp = root;
        while(1){
            auto t = lower_bound(temp->next.begin(), temp->next.end(), version, 
                    [](const pair<int, node*>& p, const int val)
                    {
                        return p.first < val;
                        
                    });
            if(t==temp->next.end() || (*t).first > version ){
                t--;
            }
            temp = (*t).second;
            if(temp==NULL) break;
            cout<<temp->val;
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.printStack(3);
    s.printStack(2);
    s.pop();
    s.pop();
    s.printStack(5);
    s.printStack(4);
	return 0;
}
