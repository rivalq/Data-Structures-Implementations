#include<bits/stdc++.h>

using namespace std;

// min_heap -> <
// max_heap -> >
template<
	typename T
>
class binary_heap{
	
	vector<T> tree;
	function<T(const T&, const T&)> compare;


	void up_heapify(int id){
		while(id){
			int parent_id = (id - 1)/2;
			if(compare(tree[id],tree[parent_id])){
				swap(tree[id],tree[parent_id]);
				swap(id,parent_id);
			}else{
				break;
			}
		}
	}


	void down_heapify(int id){
		int left_child = 2*id + 1;
		int right_child = 2*id + 2;
		if(left_child < tree.size() and right_child < tree.size()){
			if(compare(tree[right_child],tree[left_child])){
				if(compare(tree[right_child],tree[id])){
					swap(tree[right_child],tree[id]);
					down_heapify(right_child);
				}
			}else{
				if(compare(tree[left_child],tree[id])){
					swap(tree[left_child],tree[id]);
					down_heapify(left_child);
				}
			}
		}else if(left_child < tree.size()){
			if(compare(tree[left_child],tree[id])){
					swap(tree[left_child],tree[id]);
					down_heapify(left_child);
			}
		}else if(right_child < tree.size()){
			if(compare(tree[right_child],tree[id])){
					swap(tree[right_child],tree[id]);
					down_heapify(right_child);
			}
		}
	}

public:
	void push(T val){
		int id = tree.size();
		tree.push_back(val);
		up_heapify(id);
	}	

	void pop(){
		if(tree.size() == 1){
			tree.clear();
		}else{
			tree[0] = tree.back();
			tree.pop_back();
			down_heapify(0);
		}
	}

	T top(){
		return tree[0];	
	}

	binary_heap(function<T(const T&, const T&)> compare):compare(compare){

	}


};


int main(){
	// min heap
	binary_heap<int> pq([&](int x,int y){
		return x < y;
	});
	
}