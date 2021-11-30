#pragma once
#include"BinaryTree.h"

// BinaryTree<T> *pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2);
// BinaryTree<T> *post_in_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2);
// BinaryTree<T> *in_level_BuildBT(T level[], T in[], int in1, int in2, int n);
// BinaryTree<T> *level_in_BuildBT(T level[], T in[], int n);
// int locate(T A[], T x, int n);
// BinaryTree<T> *level_BuildBT(T A[], int n);


// void BinaryTree<T>::PreOrder();
// void BinaryTree<T>::InOrder();
// void BinaryTree<T>::PostOrder();
// void BinaryTree<T>::levelOrder();
// void BinaryTree<T>::PreOrder(T *A);
// void BinaryTree<T>::InOrder(T *A);
// void BinaryTree<T>::PostOrder(T *A);
// void BinaryTree<T>::levelOrder(T *A);


// //给出树的层序遍历及对应节点的度,构造对应的二叉链表树
// BinaryTree<T> *treetoBinarytree(T level[], int grade[], int k);

// //输出树存储的表达式
// void BinaryTree<T>::disp(int deep);

// //带权路径长度
// int BinaryTree<T>::WPL(int k);

// //交换左右子树
// void BinaryTree<T>::swapBinarytree();

// //树高,递归
// int BinaryTree<T>::generation();

// //树高,非递归
// int BinaryTree<T>::hight();

// //是否是完全二叉树
// bool BinaryTree<T>::iscomplete();

// //返回有两个孩子的节点数量
// int BinaryTree<T>::dson();

// //删除值为x的节点
// void BinaryTree<T>::deletevalue(T x);

// //删除树
// void BinaryTree<T>::deleteroot();

// //输出从根节点到x结点的路径
// void BinaryTree<T>::printroute(T x);

// //两个节点的最近公共祖先
// BinaryTree<T> *BinaryTree<T>::ancestor(BinaryTree<T> *p, BinaryTree<T> *q);

// //找值为x的结点
// BinaryTree<T> *BinaryTree<T>::find(T x);

// //求二叉树的最大宽度,其中一层上的节点个数
// int BinaryTree<T>::width();

// //链接所有叶子节点为一个链表,以右孩子指针为next指针
// BinaryTree<T> *BinaryTree<T>::linkLeaf();

// //比较两棵树是否相同
// bool BinaryTree<T>::isSame(BinaryTree<T> *tr);

// //找到结点p在树中的层数
// int BinaryTree<T>::level(BinaryTree<T> *p, int n);

// //是否是平衡二叉树
// bool BinaryTree<T>::isbalance(int &h);

// bool BinaryTree<T>::isBST();

// //给定结点权值,构造哈夫曼树
// HFMtree<T> *buildHFM(T A[], int n);

// //构造二叉搜索树,依次插入结点
// BinarySearchTree *BuildBinarySearchTree(int A[], int n);
// //二叉搜索树插入节点
// void BinarySearchTree::Insert(int x);

// //输出二叉搜索树中所有大于k的结点
// void BinarySearchTree::showk(int k);

// //前序序列转后序序列
// void preTopost(int pre[], int begin, int end);

// //输出最后一层结点
// void BinaryTree<T>::lastgen();

// //输出所有平衡节点,不是平衡二叉树的根节点依然可能是平衡节点
// void BinaryTree<T>::printbalance(int &h, bool &balance);

// ostream &operator<<(ostream &out, BinaryTree<T> *tr);

// //二叉树转换为线索二叉树
// ThreadTree<T>::ThreadTree(BinaryTree<T> *tr);

// //前序线索化
// void ThreadTree<T>::preThread();
// void ThreadTree<T>::preThread(ThreadTree<T> *&pre);

// void ThreadTree<T>::inThread();
// void ThreadTree<T>::inThread(ThreadTree<T> *&pre);

// //添加线索的顺序改为后续
// void ThreadTree<T>::postThread();
// void ThreadTree<T>::postThread(ThreadTree<T> *&pre);

// //以二叉树的形状构造树
// Tree<T>::Tree(BinaryTree<T> *tr);

// void Tree<T>::LevelOrder();
// void Tree<T>::PreOrder();

// //原树的深度,访问左孩子则深度+1
// int Tree<T>::depth();

// Tree<T> *level_grade_build(T level[], int grade[], int n);
// Tree<T> *level_grade_build2(T level[], int grade[], int n);

// bool Tree<T>::isSame(Tree<T> *tr);

// ostream &operator<<(ostream &os, node<T> p);

// void node<T>::print();

// //层序遍历构造静态链表
// ListBTree<T>::ListBTree(BinaryTree<T> *p);

// ostream &operator<<(ostream &os, ListBTree<T> &p);

// void ListBTree<T>::print();

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

//以中序为基准,递归构造
template<class T>
BinaryTree<T> *in_level_BuildBT(T level[], T in[], int in1, int in2, int n){
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
int locate(T A[], T x, int n){
    for (int i = 0; i < n; i++)
     if(A[i]==x)
         return i;
    return -1;
}

//以层序为基准,用队列构造
template<class T>
BinaryTree<T> *level_in_BuildBT(T level[], T in[], int n){
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *root, *p;
    bool *tag = new bool[n];
    for (int i = 0; i < n; i++)
        tag[i] = false;
    int pos = 0, x;
    root = new BinaryTree<T>(level[pos++]);
    x = locate(in, root->data, n);
    tag[x] = true;
    Q.push(root);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        x = locate(in, p->data, n);
        if(x>0&&x<n&&!tag[x-1]){
            p->lchild = new BinaryTree<T>(level[pos++]);
            Q.push(p->lchild);
            tag[locate(in, p->lchild->data, n)] = true;
        }
        else
            p->lchild = NULL;
        if(x>=0&&x<n-1&&!tag[x+1]){
            p->rchild = new BinaryTree<T>(level[pos++]);
            Q.push(p->rchild);
            tag[locate(in, p->rchild->data, n)] = true;
        }
        else
            p->rchild = NULL;
    }
    delete[] tag;
    return root;
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

//给出树的层序遍历及对应节点的度,构造对应的二叉链表树
template<class T>
BinaryTree<T>* treetoBinarytree(T level[], int grade[], int k){
    int x = 0, y = 0;//标记数组中已插入的结点序号
    BinaryTree<T> *root = new BinaryTree<T>(level[x++]);
    BinaryTree<T> *p;
    queue<BinaryTree<T> *> Q;
    queue<int> g;
    Q.push(root);//结点队列
    g.push(grade[y++]);//度队列
    while(x<k){
        p = Q.front();
        Q.pop();
        int n = g.front();
        g.pop();
        BinaryTree<T> *child = new BinaryTree<T>(level[x++]);
        g.push(grade[y++]);
        p->lchild = child;
        p = p->lchild;
        for (int i = 1; i < n; i++){//根据度,循环添加nextsibling
            BinaryTree<T> child = new BinaryTree<T>(level[x++]);
            p->rchild = child;
            p = p->rchild;
            Q.push(p);
            g.push(grade[y++]);
        }
    }
    return root;
}

//输出树存储的表达式
template<class T>
void BinaryTree<T>::disp(int deep){
    if(this==NULL)
        return;
    if(this->lchild==NULL&&this->rchild==NULL)
        cout << this->data;
    else{
        if(deep>1)//层数大于1则加括号
            cout << '(';
        this->disp(deep + 1);
        cout << this->data;
        this->disp(deep + 1);
        if(deep>1)
            cout << ')';
    }
}

//带权路径长度
template<class T>
int BinaryTree<T>::WPL(int k){
    if(this==NULL)
        return 0;
    else
        return (this->data) * k + this->lchild->WPL(k + 1) + this->rchild->WPL(k + 1);
}

//交换左右子树
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

//树高,递归
template<class T>
int BinaryTree<T>::generation(){
    if(this->lchild==NULL&&this->rchild==NULL)
        return 1;
    else{
        int l=0, r=0;//左右子树高度
        if(this->lchild!=NULL)
            l = this->lchild->generation() + 1;
        if(this->rchild!=NULL)
            r = this->rchild->generation() + 1;
        return l > r ? l : r;
    }
}

//树高,非递归
//层序遍历,last标记每一层最后一个节点,每当遍历到last,层数++
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

//是否是完全二叉树
template<class T>
bool BinaryTree<T>::iscomplete(){
    BinaryTree<T> *tr = this;
    queue<BinaryTree<T> *> q;
    q.push(tr);
    while(!q.empty()){//层序遍历,遍历到某个结点的孩子节点有NULL时,break
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
    while(!q.empty()){//判断队列内后续的结点的孩子是否都为NULL,不然则不是完全二叉树
        tr = q.front();
        q.pop();
        if(tr->lchild!=NULL||tr->rchild!=NULL)
            return false;
    }
    return true;
}

//返回有两个孩子的节点数量
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

//删除值为x的节点
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


//删除树
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


//输出从根节点到x结点的路径
//后序遍历栈中所保存的即路径
template<class T>
void BinaryTree<T>::printroute(T x){
    stack<BinaryTree<T> *> s;
    BinaryTree<T> *tr = this, *r = NULL;
    while(tr!=NULL||!s.empty()){//后序遍历找x结点
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
                    break;//找到后break
                s.pop();
                r = tr;
                tr = NULL;
            }
        }
    }
    while(!s.empty()){//输出栈中元素
        cout << s.top()->data << "<-";
        s.pop();
    }
    cout << endl;
}

//辅助栈
template<class T>
struct stac{
    BinaryTree<T> *tree;
    bool tag;//标记是否为第一个节点的路径
};
//两个节点的最近公共祖先
//求两个结点的路径,再找公共的部分
template<class T>
BinaryTree<T> *BinaryTree<T>::ancestor(BinaryTree<T> *p, BinaryTree<T> *q){
    stac<T> s[100];
    int top = -1;//顺序栈初始化
    bool find = false;//有没有找到第一个节点
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
                s[top].tag = false;//false表示不是第一个节点的路径
                tr = tr->lchild;
            }
            else{
                top--;
                if(!find&&(tr==p||tr==q)){//找到第一个节点
                    for (int i = 0; i <= top; i++)
                        s[i].tag = true;//标记栈中所有元素为true,表示是第一个节点的路径
                    find = true;//找到第一个节点
                }
                if(find&&(tr==p||tr==q)){//找到第二个节点,break
                    break;
                }
                r = tr;
                tr = NULL;
            }
        }    
    }
    for (; top != -1 && !s[top].tag; top--);//检查栈中的元素,依次弹出至标记为true的结点,该节点为第一个找到的结点上的路径结点
    return s[top].tree;
}


//找值为x的结点
template<class T>
BinaryTree<T> *BinaryTree<T>::find(T x){
    if(this==NULL||this->data==x)
        return this;
    BinaryTree<T> *l, *r;
    l = this->lchild->find(x);
    r = this->rchild->find(x);
    return l == NULL ? r : l;
}

//求二叉树的最大宽度,其中一层上的节点个数
//标记每层上最后一个节点last,每当遍历到last,比较wide和i
template<class T>
int BinaryTree<T>::width(){
    BinaryTree<T> *q[100];
    int front = -1, rear = -1, last, wide = 0, i = 0;//初始化辅助队列,last为该层最后一个节点,i记录该层宽度
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

//链接所有叶子节点为一个链表,以右孩子指针为next指针
//中序遍历+链表头插法,需要p指针标记前一个链表节点
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
            if(tr->lchild==NULL&&tr->rchild==NULL){//如果是叶子节点
                p->rchild = tr;
                p = tr;
            }
            tr = tr->rchild;
        }
    }
    return head;
}

//比较两棵树是否相同
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


//找到结点p在树中的层数
//递归遍历,没找到返回0,找到返回n,n用来标记层数,每进入下一层+1
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

//是否是平衡二叉树
//lh rh左右子树高度,lb rb左右子树是否平衡
//递归遍历,h存储树高即lh和rh中大者
template<class T>
bool BinaryTree<T>::isbalance(int &h){
    bool lb = true, rb = true;
    int lh = 0, rh = 0;
    if(this==NULL){//空返回true
        h = 0;
        return true;
    }
    else if(this->lchild==NULL&&this->rchild==NULL){//左右都空,返回true
        h = 1;
        return true;
    }
    if(this->lchild!=NULL)
        lb = this->lchild->isbalance(lh);
    if(this->rchild!=NULL)
        rb = this->rchild->isbalance(rh);
    if (!lb || !rb) //左右一个不平衡就返回false
        return false;
    else{//左右都平衡记录树高,检查平衡性
        h = (lh > rh ? lh : rh) + 1;
        return abs(lh - rh) > 1 ? false : true;
    }
}

template<class T>
bool BinaryTree<T>::isBST(){
    if(this==NULL)
        return true;
    bool l = true, r = true;
    if(this->lchild!=NULL){
        if(this->lchild->data>this->data)
            l = false;
        else
            l = this->lchild->isBST();
    }
    if(this->rchild!=NULL){
        if(this->rchild->data<this->data)
            r = false;
        else
            r = this->rchild->isBST();
    }
    return l && r;
}

template<class T>
void BinaryTree<T>::Insert(int x){
    return;
}

//给定结点权值,构造哈夫曼树
//建立节点数组(优先队列数组),依次取出最小的两个组合为一个加入节点数组
template<class T>
HFMtree<T>* buildHFM(T A[], int n){
    HFMtree<T> *Node[n];
    for (int i = 0; i < n; i++){//建立节点数组
        HFMtree<T> *p = new HFMtree<T>(A[i]);
        p->lchild = NULL;
        p->rchild = NULL;
        Node[i] = p;
    }
    int k1 = -1, k2 = -1;//标记最小两个节点的序号
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){//手动优先队列,选出第一个最小的
            if(Node[j]==NULL)
                continue;
            if(k1==-1||Node[k1]==NULL||Node[k1]->data>Node[j]->data)
                k1 = j;
        }
        for (int j = 0; j < n;j++){//选出第二个最小的
            if(Node[j]==NULL||k1==j)
                continue;
            if(k2==-1||Node[k2]==NULL||Node[k2]->data>Node[j]->data)
                k2 = j;
        }
        if(Node[k2]==NULL){//如果第二个结点没选,即没有更多节点了,则构造完成
            HFMtree<T> *r;
            r = Node[k1];
            return r;
        }
        HFMtree<T> *t = new HFMtree<T>(Node[k1]->data + Node[k2]->data);//以最小的两个节点为孩子节点构造新结点
        t->lchild = Node[k1];
        t->rchild = Node[k2];
        Node[k1] = t;//新节点加入到节点数组
        Node[k2] = NULL;
    }
}

//构造二叉搜索树,依次插入结点
BinarySearchTree *BuildBinarySearchTree(int A[], int n){
    BinarySearchTree *root = new BinarySearchTree(A[0]);
    for (int i = 1; i < n; i++)
        root->Insert(A[i]);
    return root;
}
//二叉搜索树插入节点
//由于二叉搜索树的孩子节点继承自二叉树,是二叉树指针类型,需要强制转换成二叉搜索树指针类型dynamic_cast<BinarySearchTree *>
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


//输出二叉搜索树中所有大于k的结点
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

//前序序列转后序序列
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

//输出最后一层结点
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

//输出所有平衡节点,不是平衡二叉树的根节点依然可能是平衡节点
template<class T>
void BinaryTree<T>::printbalance(int &h, bool &balance){
    if(this==NULL){
        h = 0;
        balance = true;
        return;
    }
    int lh, rh;
    bool lb, rb;
    this->lchild->printbalance(lh, lb);
    this->rchild->printbalance(rh, rb);
    h = (lh > rh ? lh : rh) + 1;
    balance = abs(lh - rh) > 1 ? false : true;
    if(balance)
        cout << this->data << ',';
}

template<class T>
ostream &operator<<(ostream &out, BinaryTree<T> *tr){//以表的形式输出
        if(tr==NULL)
        return out;
        out << tr->data;
        if(tr->rchild!=NULL||tr->lchild!=NULL)
            out << '(';
        out << tr->lchild;
        if(tr->rchild!=NULL||tr->lchild!=NULL)
            out << ',';
        out << tr->rchild;
        if(tr->rchild!=NULL||tr->lchild!=NULL)
            out << ')';
        out << endl;
        return out;
    }

//二叉树转换为线索二叉树
template<class T>
ThreadTree<T>::ThreadTree(BinaryTree<T> *tr){
    data = tr->data;
    lchild = tr->lchild != NULL ? new ThreadTree(tr->lchild) : NULL;
    rchild = tr->rchild != NULL ? new ThreadTree(tr->rchild) : NULL;
    ltag = false;
    rtag = false;
}

//前序线索化
template<class T>
void ThreadTree<T>::preThread(){
    ThreadTree *pre = NULL;//pre用于标记前序遍历时前一个结点,初始为NULL
    if(this){
        this->preThread(pre);
        pre->rchild = NULL;//最后遍历的节点后继为NULL
        pre->rtag = true;
    }
}
//递归遍历并添加线索
template<class T>
void ThreadTree<T>::preThread(ThreadTree<T> *&pre){
    if(this!=NULL){
        if(this->lchild==NULL){//左孩子为空,需要改左孩子为前驱线索指向pre
            this->lchild = pre;
            this->ltag = true;
        }
        if(pre!=NULL&&pre->rchild==NULL){//pre的右孩子为空,需要改pre的右孩子为后继线索指向当前结点
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
//同上,只是添加线索的顺序改为中序
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

//添加线索的顺序改为后续
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

//以二叉树的形状构造树
template<class T>
Tree<T>::Tree(BinaryTree<T> *tr){
    data = tr->data;
    firstchild = tr->lchild != NULL ? new Tree(tr->lchild) : NULL;
    nextsibling = tr->rchild != NULL ? new Tree(tr->rchild) : NULL;
}

template<class T>
void Tree<T>::LevelOrder(){
    queue<Tree<T> *> Q;
    Tree<T> *p = this;
    Q.push(p);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        p->visit();
        if(p->firstchild!=NULL)
            Q.push(p->firstchild);
        if(p->nextsibling!=NULL)
            Q.push(p->nextsibling);
    }
}

template<class T>
void Tree<T>::PreOrder(){
    if(this!=NULL){
        this->visit();;
        this->firstchild->PreOrder();
        this->nextsibling->PreOrder();
    }
}


//原树的深度,访问左孩子则深度+1
template<class T>
int Tree<T>::depth(){
    if(this==NULL)
        return 0;
    int l = firstchild->depth() + 1;
    int r = nextsibling->depth();
    return l > r ? l : r;
}

template<class T>
struct Queue{
    Tree<T>* tr;
    int degrade;
};
//与之前的做法相同
template<class T>
Tree<T> *level_grade_build(T level[], int grade[], int n){
    Queue<T> Q[maxsize];
    int i = -1, rear = -1, front = -1;
    Tree<T> *root = new Tree<T>(level[++i]);
    Tree<T> *p = root;
    Q[++rear].tr = p;
    Q[rear].degrade = grade[i];
    while(i<n){
        p = Q[++front].tr;
        cout << p->data;
        int d = Q[front].degrade;
        if(d>0){
            Tree<T> *r = new Tree<T>(level[++i]);
            p->firstchild = r;
            p = r;
            Q[++rear].tr = r;
            Q[rear].degrade = grade[i];
            d--;
            for (int j = 1; j <= d; j++){
                r = new Tree<T>(level[++i]);
                p->nextsibling = r;
                p = r;
                Q[++rear].tr = r;
                Q[rear].degrade = grade[i];
            }
        }
    }
    return root;
}

template<class T>
Tree<T> *level_grade_build2(T level[], int grade[], int n){
    Tree<T> *Node[maxsize];
    for (int i = 0; i < n; i++)
        Node[i] = new Tree<T>(level[i]);
    int j = 1;
    for (int i = 0; i < n; i++){
        int k = grade[i];
        if(k!=0){
            Node[i]->firstchild = Node[j];
            k--;
            while(k>0){
                Node[j]->nextsibling = Node[j + 1];
                j++;
                k--;
            }
            j++;
        }
    }
    return Node[0];
}

template <class T>
bool Tree<T>::isSame(Tree<T> *tr){
    if(this==NULL&&tr==NULL)
        return true;
    else if((this==NULL&&tr!=NULL)||(this!=NULL&&tr==NULL))
        return false;
    else if(this->data!=tr->data)
        return false;
    else
        return this->firstchild->isSame(tr->firstchild) && this->nextsibling->isSame(tr->nextsibling);
}

template<class T>
void node<T>::print(){
    cout << data << '\t' << lchild << '\t' << rchild;
}

//层序遍历构造静态链表
template<class T>
ListBTree<T>::ListBTree(BinaryTree<T> *p){
    if(p==NULL){
        size = 0;
        list = NULL;
        return;
    }
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *temp;
    list = new node<T>[20];
    size = 1;
    list[0].data = (p->data);
    Q.push(p);
    int last = 0, t = 0;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp->lchild!=NULL){
            list[++last].data = temp->lchild->data;
            list[t].lchild = list[last].data;
            Q.push(temp->lchild);
            size++;
        }
        if(temp->rchild!=NULL){
            list[++last].data = temp->rchild->data;
            list[t].rchild = list[last].data;
            Q.push(temp->rchild);
            size++;
        }
        t++;
    }
}

template<class T>
ostream &operator<<(ostream &os, ListBTree<T> &p){
    for (int i = 0; i < p.size; i++)
        os << i << ':' << p.list[i] << endl;
    return os;
}

template<class T>
void ListBTree<T>::print(){
    for (int i = 0; i < size; i++){
        list[i].print();
        cout << endl;
    }
}