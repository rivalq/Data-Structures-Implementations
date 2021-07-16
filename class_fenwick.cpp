#include<bits/stdc++.h>



// 1-based
template<typename T>
struct Fenwick{
    std::vector<T> tree;
    int n;

    Fenwick(int n):n(n){
        tree.resize(n + 1);
    }

    T query(int i){
        int sum = 0;
        while(i){
           sum += tree[i];
           i -= i&(-i);
       }  
       return sum;
    }
    void update(int i,T val){
       while(i <= n){
          tree[i] += val;
          i += i&(-i);
       }
    }
};

int main(){
	Fenwick<int> tree(10);
}