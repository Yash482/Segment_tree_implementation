#include<bits/stdc++.h>

using namespace std;

const int N = 100000;
vector<int> tree(2*N, -1);
vector<int> a;
void build_tree(vector<int> a, int n){
	for(int i=n-1; i>=0; i--){
		tree[n+i-1] = a[i];
	}
	
	//for parents
	for(int i=n-2; i>=0; i--){
		int left = 2*i +1;
		int right= 2*i +2;
		if(tree[left]>0 && tree[right]>0)
			tree[i] = tree[left] + tree[right];
	}
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node+1, start, mid, l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}

void update(int index, int value){
	tree[a.size()+index-1] = value;
	int current_index = (a.size()+index-2);
	while(current_index>=0){
		current_index /= 2;
		int left = 2*current_index +1;
		int right= 2*current_index +2;
		if(tree[left]>0 && tree[right]>0)
			tree[current_index] = tree[left] + tree[right];
		current_index = (current_index-1);
	}
}

int main(){

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	build_tree(a, 4);
	update(1,5);
	for(int i=0; i<=6; i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	cout<<query(0, 0, 3, 0, 2);
}
