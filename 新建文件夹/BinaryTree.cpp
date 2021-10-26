#pragma once
#include"BinaryTree.h"



template<class T>
BinaryTree<T>* pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2){
    BinaryTree<T> *root = new BinaryTree<T>(pre[pre1]);
    int i;
    for (i = in1; in[i] != root->data; i++);
    int llen = i - in1;
    int rlen = in2 - i;
    if(llen)
        root->lchild = pre_in_BuildBT(pre, in, pre1 + 1, pre1 + llen, in1, in1 + llen - 1);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = pre_in_BuildBT(pre, in, pre2 - rlen + 1, pre2, in2 - rlen + 1, in2);
    else
        root->rchild = NULL;
    return root;
}

template<class T>
BinaryTree<T>* post_in_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2){
    BinaryTree<T> *root = new BinaryTree<T>(post[post2]);
    int i;
    for (i = in1; in[i] != root->data; i++);
    int llen = i - in1;
    int rlen = in2 - i;
    if(llen)
        root->lchild = post_in_BuildBT(post, in, post1, post1 + llen - 1, in1, in1 + llen - 1);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = post_in_BuildBT(post, in, post2 - rlen, post2 - 1, in2 - rlen + 1, in2);
    else
        root->rchild = NULL;
    return root;
}

template<class T>
BinaryTree<T> *level_in_BuildBT(T level[], T in[], int in1, int in2, int n){
    if(in1>in2)
        return NULL;
    int i, j;
    bool find;
    for (i = 0; i < n; i++){
        find = false;
        for (j = in1; j <=in2; j++){
            if(level[i]==in[j]){
                find = true;
                break;
            }
        }
        if(find)
            break;
    }
    BinaryTree<T> *P = new BinaryTree<T>(level[i]);
    P->lchild = level_in_BuildBT(level, in, in1, j - 1, n);
    P->rchild = level_in_BuildBT(level, in, j + 1, in2, n);
    return P;
}

template<class T>
BinaryTree<T> *level_BuildBT(T A[], int n){
    BinaryTree<T> *root = new BinaryTree<T>(A[0]);
    BinaryTree<T> *tr = root;
    queue<BinaryTree<T> *> Q;
    Q.push(tr);
    int i = 1;
    while (i < n){
        tr = Q.front();
        Q.pop();
        if(i<n){
            tr->lchild = new BinaryTree<T>(A[i++]);
            Q.push(tr->lchild);
        }
        if(i<n){
            tr->rchild = new BinaryTree<T>(A[i++]);
            Q.push(tr->rchild);
        }
    }
    return root;
}

template<class T>
void BinaryTree<T>::PreOrder(){
    cout << "前序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    S.push(NULL);
    while(p!=NULL){
        visit(p);
        if(p->rchild!=NULL)
            S.push(p->rchild);

        if(p->lchild!=NULL)
            p = p->lchild;
        else{
            p=S.top();
            S.pop();
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::InOrder(){
    cout << "中序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            S.pop();
            visit(p);
            p = p->rchild;
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrder(){
    cout << "后序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this, *r = NULL;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild!=NULL&&p->rchild!=r){
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            }
            else{
                S.pop();
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(){
    cout << "层序遍历:";
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *p;
    Q.push(this);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        visit(p);
        if(p->lchild!=NULL)
            Q.push(p->lchild);
        if(p->rchild!=NULL)
            Q.push(p->rchild);
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PreOrder(T *A){
    stack<BinaryTree<T> *> S;
    int i = 0;
    BinaryTree<T> *p = this;
    S.push(NULL);
    while(p!=NULL){
        A[i++] = p->data;
        if(p->rchild!=NULL)
            S.push(p->rchild);

        if(p->lchild!=NULL)
            p = p->lchild;
        else{
            p=S.top();
            S.pop();
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::InOrder(T *A){
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    int i = 0;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            S.pop();
            A[i++] = p->data;
            p = p->rchild;
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrder(T *A){
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this, *r = NULL;
    int i = 0;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild!=NULL&&p->rchild!=r){
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            }
            else{
                S.pop();
                A[i++] = p->data;
                r = p;
                p = NULL;
            }
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(T *A){
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *p;
    int i = 0;
    Q.push(this);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        A[i++] = p->data;
        if(p->lchild!=NULL)
            Q.push(p->lchild);
        if(p->rchild!=NULL)
            Q.push(p->rchild);
    }
    cout << endl;
}

template<class T>
BinaryTree<T>* treetoBinarytree(T level[], int grade[], int k){
    int x = 0, y = 0;
    BinaryTree<T> *root = new BinaryTree<T>(level[x++]);
    BinaryTree<T> *p;
    queue<BinaryTree<T> *> Q;
    queue<int> g;
    Q.push(root);
    g.push(grade[y++]);
    while(x<k){
        p = Q.front();
        Q.pop();
        int n = g.front();
        g.pop();
        BinaryTree<T> *child = new BinaryTree<T>(level[x++]);
        g.push(grade[y++]);
        p->lchild = child;
        p = p->lchild;
        for (int i = 1; i < n; i++){
            BinaryTree<T> child = new BinaryTree<T>(level[x++]);
            p->rchild = child;
            p = p->rchild;
            Q.push(p);
            g.push(grade[y++]);
        }
    }
    return root;
}

template<class T>
void BinaryTree<T>::disp(int deep){
    if(this==NULL)
        return;
    if(this->lchild==NULL&&this->rchild==NULL)
        cout << this->data;
    else{
        if(deep>1)
            cout << '(';
        this->disp(deep + 1);
        cout << this->data;
        this->disp(deep + 1);
        if(deep>1)
            cout << ')';
    }
}

template<class T>
int BinaryTree<T>::WPL(int k){
    if(this==NULL)
        return 0;
    else
        return (this->data) * k + this->lchild->WPL(k + 1) + this->rchild->WPL(k + 1);
}

template<class T>
void BinaryTree<T>::swapBinarytree(){
    if(this==NULL)
        return;
    BinaryTree<T>* temp = this->lchild;
    this->lchild = this->rchild;
    this->rchild = temp;
    this->lchild->swapBinarytree();
    this->rchild->swapBinarytree();
}

template<class T>
int BinaryTree<T>::generation(){
    if(this->lchild==NULL&&this->rchild==NULL)
        return 1;
    else{
        int l=0, r=0;
        if(this->lchild!=NULL)
            l = this->lchild->generation() + 1;
        if(this->rchild!=NULL)
            r = this->rchild->generation() + 1;
        return l > r ? l : r;
    }
}

template<class T>
int BinaryTree<T>::hight(){
    BinaryTree<T> *que[100];
    int front = -1, rear = -1;
    que[++rear] = this;
    int last = 0;
    int high = 0;
    BinaryTree<T> *tr;
    while(front<rear){
        tr = que[++front];
        if(tr->lchild!=NULL)
            que[++rear] = tr->lchild;
        if(tr->rchild!=NULL)
            que[++rear] = tr->rchild;
        if(last==front){
            high++;
            last = rear;
        }
    }
    return high;
}

template<class T>
bool BinaryTree<T>::iscomplete(){
    BinaryTree<T> *tr = this;
    queue<BinaryTree<T> *> q;
    q.push(tr);
    while(!q.empty()){
        tr = q.front();
        q.pop();
        if(tr->lchild!=NULL)
            q.push(tr->lchild);
        else
            break;
        if(tr->rchild!=NULL)
            q.push(tr->rchild);
        else
            break;
    }
    while(!q.empty()){
        tr = q.front();
        q.pop();
        if(tr->lchild!=NULL||tr->rchild!=NULL)
            return false;
    }
    return true;
}

template<class T>
int BinaryTree<T>::dson(){
    int l = 0;
    int r = 0;
    if(this->lchild!=NULL&&this->rchild!=NULL)
        return 1 + this->lchild->dson() + this->rchild->dson();
    else if(this->lchild!=NULL)
        return this->lchild->dson();
    else if(this->rchild!=NULL)
        return this->rchild->dson();
    else
        return 0;
}

template<class T>
void BinaryTree<T>::deletevalue(T x){
    if(this->data==x){
        this->deleteroot();
    }
    else if(this->lchild!=NULL)
        this->lchild->deletevalue(x);
    else if(this->rchild!=NULL)
        this->rchild->deletevalue(x);
}

template<class T>
void BinaryTree<T>::deleteroot(){
    if(this->lchild!=NULL){
        this->lchild->deleteroot();
        this->lchild = NULL;
    }
    if(this->rchild!=NULL){
        this->rchild->deleteroot();
        this->rchild = NULL;
    }
    delete this;
}

template<class T>
void BinaryTree<T>::printroute(T x){
    stack<BinaryTree<T> *> s;
    BinaryTree<T> *tr = this, *r = NULL;
    while(tr!=NULL||!s.empty()){
        if(tr!=NULL){
            s.push(tr);
            tr = tr->lchild;
        }
        else{
            tr = s.top();
            if(tr->rchild!=NULL&&tr->rchild!=r){
                tr = tr->rchild;
                s.push(tr);
                tr = tr->lchild;
            }
            else{
                if(tr->data==x)
                    break;
                s.pop();
                r = tr;
                tr = NULL;
            }
        }
    }
    while(!s.empty()){
        cout << s.top()->data << "<-";
        s.pop();
    }
    cout << endl;
}

template<class T>
struct stac{
    BinaryTree<T> *tree;
    bool tag;
};

template<class T>
BinaryTree<T> *BinaryTree<T>::ancestor(BinaryTree<T> *p, BinaryTree<T> *q){
    stac<T> s[100];
    int top = -1;
    bool find = false;
    BinaryTree<T> *tr1 = p, *tr2 = q, *tr = this, *r = NULL;
    while(tr!=NULL||top!=-1){
        if(tr!=NULL){
            s[++top].tree = tr;
            s[top].tag = false;
            tr = tr->lchild;
        }
        else{
            tr = s[top].tree;
            if(tr->rchild!=NULL&&tr->rchild!=r){
                tr = tr->rchild;
                s[++top].tree = tr;
                s[top].tag = false;
                tr = tr->lchild;
            }
            else{
                top--;
                if(!find&&(tr==p||tr==q)){
                    for (int i = 0; i <= top; i++)
                        s[i].tag = true;
                    find = true;
                }
                if(find&&(tr==p||tr==q)){
                    break;
                }
                r = tr;
                tr = NULL;
            }
        }    
    }
    for (; top != -1 && !s[top].tag; top--);
    return s[top].tree;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::find(T x){
    if(this==NULL||this->data==x)
        return this;
    BinaryTree<T> *l, *r;
    l = this->lchild->find(x);
    r = this->rchild->find(x);
    return l == NULL ? r : l;
}

template<class T>
int BinaryTree<T>::width(){
    BinaryTree<T> *q[100];
    int front = -1, rear = -1, last, wide = 0, i = 0;
    BinaryTree<T> *tr = this;
    q[++rear]=tr;
    last = rear;
    while(rear!=front){
        tr = q[++front];
        i++;
        if(tr->lchild!=NULL)
            q[++rear] = tr->lchild;
        if(tr->rchild!=NULL)
            q[++rear] = tr->rchild;
        if(front==last){
            if(i>wide)
                wide = i;
            i = 0;
            last = rear;
        }   
    }
    return wide;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::linkLeaf(){
    BinaryTree<T> *head = new BinaryTree<int>;
    BinaryTree<T> *p = head, *tr = this;
    stack<BinaryTree<T> *> s;
    while(tr!=NULL||!s.empty()){
        if(tr!=NULL){
            s.push(tr);
            tr = tr->lchild;
        }
        else{
            tr = s.top();
            s.pop();
            if(tr->lchild==NULL&&tr->rchild==NULL){
                p->rchild = tr;
                p = tr;
            }
            tr = tr->rchild;
        }
    }
    return head;
}

template<class T>
bool BinaryTree<T>::isSame(BinaryTree<T> *tr){
    if(this==NULL&&tr==NULL)
        return true;
    else if((this==NULL&&tr!=NULL)||(this!=NULL&&tr==NULL))
        return false;
    else if(this->data==tr->data)
        return this->lchild->isSame(tr->lchild) && this->rchild->isSame(tr->rchild);
    else
        return false;
}

template<class T>
int BinaryTree<T>::level(BinaryTree<T> *p, int n){
    if(this==NULL)
        return 0;
    if(this==p)
        return n;
    int l = this->lchild->level(p, n + 1);
    int r = this->rchild->level(p, n + 1);
    if(l)
        return l;
    else if(r)
        return r;
    else
        return 0;
}

template<class T>
bool BinaryTree<T>::isbalance(int &h, bool &balance){
    bool lb = true, rb = true;
    int lh = 0, rh = 0;
    if(this==NULL){
        h = 0;
        return true;
    }
    else if(this->lchild==NULL&&this->rchild==NULL){
        h = 1;
        return true;
    }
    if(this->lchild!=NULL)
        this->lchild->isbalance(lh, lb);
    if(this->rchild!=NULL)
        this->rchild->isbalance(rh, rb);
    if(!lb||!rb)
        balance = false;
    else{
        h = (lh > rh ? lh : rh) + 1;
        balance = abs(lh - rh) > 1 ? false : true;
    }
    return balance;
}

template<class T>
void BinaryTree<T>::Insert(int x){
    return;
}

template<class T>
HFMtree<T>* buildHFM(T A[], int n){
    HFMtree<T> *Node[n];
    for (int i = 0; i < n; i++){
        HFMtree<T> *p = new HFMtree<T>(A[i]);
        p->lchild = NULL;
        p->rchild = NULL;
        Node[i] = p;
    }
    int k1 = -1, k2 = -1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(Node[j]==NULL)
                continue;
            if(k1==-1||Node[k1]==NULL||Node[k1]->data>Node[j]->data)
                k1 = j;
        }
        for (int j = 0; j < n;j++){
            if(Node[j]==NULL||k1==j)
                continue;
            if(k2==-1||Node[k2]==NULL||Node[k2]->data>Node[j]->data)
                k2 = j;
        }
        if(Node[k2]==NULL){
            HFMtree<T> *r;
            r = Node[k1];
            return r;
        }
        HFMtree<T> *t = new HFMtree<T>(Node[k1]->data + Node[k2]->data);
        t->lchild = Node[k1];
        t->rchild = Node[k2];
        Node[k1] = t;
        Node[k2] = NULL;
    }
}

BinarySearchTree *BuildBinarySearchTree(int A[], int n){
    BinarySearchTree *root = new BinarySearchTree(A[0]);
    for (int i = 1; i < n; i++)
        root->Insert(A[i]);
    return root;
}

void BinarySearchTree::Insert(int x){
    if(this->data==x){
        cout << "结点已存在" << endl;
        return;
    }
    else if(x>this->data){
        if(this->rchild==NULL){
            BinarySearchTree *T = new BinarySearchTree(x);
            this->rchild = T;
        }
        else
            dynamic_cast<BinarySearchTree *>(this->rchild)->Insert(x);
    }
    else{
        if(this->lchild==NULL){
            BinarySearchTree *T = new BinarySearchTree(x);
            this->lchild = T;
        }
        else
            dynamic_cast<BinarySearchTree *>(this->lchild)->Insert(x);
    }
}

void BinarySearchTree::showk(int k){
    stack<BinaryTree *> S;
    BinaryTree *p = this;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->rchild;
        }
        else{
            p = S.top();
            S.pop();
            if(p->data>=k)
                visit(p);
            else
                return;
            p = p->lchild;
        }
    }
}

void preTopost(int pre[], int begin, int end){
    if(begin<end-1){
        int temp = pre[end];
        pre[end] = pre[begin];
        for (int i = begin; i < end-1; i++)
            pre[i] = pre[i + 1];
        pre[end-1] = temp;
    }
    else
        return;
    for (int i = 0; i < 15;i++){
        cout << pre[i] << ',';
    }
    cout << endl;
    preTopost(pre, begin, begin+(end-begin) / 2 - 1);
    preTopost(pre, begin+(end-begin) / 2, begin+(end-begin) - 1);
}

template<class T>
void BinaryTree<T>::lastgen(){
    BinaryTree<T> *Q[maxsize];
    int front = 0, rear = 0, first, last, gen = 1;
    bool r = false;
    Q[rear++] = this;
    first = front;
    last = front+1;
    while(front!=rear){
        if(front==last){
            last = rear;
            first = front;
            gen++;
        }
        BinaryTree<T> *p = Q[front++];
        p = p->lchild;
        while(p!=NULL){
            Q[rear++] = p;
            p = p->rchild;
        }
    }
    cout << "gen:" << gen << endl;
    for (int i = first; i < last; i++)
        visit(Q[i]);
}

template<class T>
ThreadTree<T>::ThreadTree(BinaryTree<T> *tr){
    data = tr->data;
    lchild = tr->lchild != NULL ? new ThreadTree(tr->lchild) : NULL;
    rchild = tr->rchild != NULL ? new ThreadTree(tr->rchild) : NULL;
    ltag = false;
    rtag = false;
}

template<class T>
void ThreadTree<T>::preThread(){
    ThreadTree *pre = NULL;
    if(this){
        this->preThread(pre);
        pre->rchild = NULL;
        pre->rtag = true;
    }
}

template<class T>
void ThreadTree<T>::preThread(ThreadTree<T> *&pre){
    if(this!=NULL){
        if(this->lchild==NULL){
            this->lchild = pre;
            this->ltag = true;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild = this;
            pre->rtag = true;
        }
        pre = this;
        if(!this->ltag)
            this->lchild->preThread(pre);
        if(!this->rtag)
            this->rchild->preThread(pre);
    }
}

template<class T>
void ThreadTree<T>::inThread(){
    ThreadTree *pre = NULL;
    if(this!=NULL){
        this->inThread(pre);
        pre->rchild = NULL;
        pre->rtag = true;
    }
}

template<class T>
void ThreadTree<T>::inThread(ThreadTree<T> *&pre){
    if(this!=NULL){
        this->lchild->inThread(pre);
        if(this->lchild==NULL){
            this->lchild = pre;
            this->ltag = true;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild = this;
            pre->rtag = true;
        }
        pre = this;
        this->rchild->inThread(pre);
    }
}

template<class T>
void ThreadTree<T>::postThread(){
    ThreadTree *pre = NULL;
    if(this!=NULL){
        postThread(pre);
        pre->rchild = NULL;
        pre->rtag = true;
    }
}

template<class T>
void ThreadTree<T>::postThread(ThreadTree<T> *&pre){
    if(this!=NULL){
        if(!this->ltag)
            this->lchild->postThread(pre);
        if(!this->rtag)
            this->rchild->postThread(pre);
        if(this->lchild==NULL){
            this->lchild = pre;
            this->ltag = true;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild = this;
            pre->rtag = true;
        }
        pre = this;
    }
}
