// 에디터
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    char val;
    Node *pre;
    Node *nxt;
};

void printNode(Node *head) {
    Node *trav = head;
    while (trav)
    {
        cout << trav->val;
        trav = trav->nxt;
    }
}

void command(string cmd, Node *&cur)
{
    if (cmd[0] == 'L')
    {
        if (cur->pre)
            cur = cur->pre;
    }
    else if (cmd[0] == 'D')
    {
        if (cur->nxt)
            cur = cur->nxt;
    }
    else if (cmd[0] == 'B')
    {
        if (cur->pre) {
            cur->pre->nxt = cur->nxt;
            if (cur->nxt) cur->nxt->pre = cur->pre;
            cur = cur->pre;
        }
    }
    else if (cmd[0] == 'P')
    {
        Node *n = new Node{cmd[2], cur, cur->nxt};
        if (cur->nxt) cur->nxt->pre = n;
        cur->nxt = n;
        cur = cur->nxt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node *head = new Node{' ', nullptr, nullptr};
    Node *trav = head;

    string s;
    int m;
    getline(cin, s);
    cin >> m;
    for(char c: s) {
        Node *nxt = new Node{c, trav, nullptr};
        trav->nxt = nxt;
        trav = trav->nxt;
    }

    string cmd;
    cin.ignore();   
    for (int i = 0; i < m; i++)
    {
        getline(cin, cmd);
        command(cmd, trav);
    }

    printNode(head->nxt);
    cout << '\n';
}