#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MaxSegmentTree {
  private:
  vector<int> tree;
  public:
  MaxSegmentTree(vector<int>& v) {
    tree.resize(4*v.size());
  }
//////////////// building max segment tree ////////////////////////

  void buildTree(vector<int>& arr,int s , int e , int node) {
    if(s > e) return;
    if(s==e) {
      tree[node]=arr[s];
      return;
    }
    int m = s + (e-s)/2;
    buildTree(arr, s, m, node*2+1);
    buildTree(arr, m+1, e, node*2+2);
    tree[node] = max(tree[node*2+1], tree[node*2+2]);
  }
////////////////////////// printing max segment tree ///////////////////////////

  void print_tree(void) {
    for(int i=0 ; i<tree.size() ; i++) {
      cout<<tree[i]<<" ";
    }
    cout<<endl;
  }

////////////////////////// Query in max segment tree /////////////////////////

  int rangeQuery ( int q1 , int q2 , int s1 , int s2 , int node ) {
    /////// talking about three cases here //////////
    /*
    1. No overlapping => just return;
    2. Completely overlapping => calculate max 
    3. partial overlapping => search in childrens 
    */

     ////////// no overlapping /////////
     if(s2 < q1 || s1 > q2) return INT_MIN;

     ///////// complete overlapping /////////
     if(s1 >=q1 && s2 <=q2) {
      return tree[node];
     }
     int m = s1 + (s2-s1)/2;
     ///////// partial overlapping ///// ( imp )
     int left = rangeQuery(q1 , q2 , s1 , m , node*2+1);
     int right = rangeQuery(q1 , q2 , m+1 , s2 , node*2+2);
     return max(left , right);
    }

    ////////////////////// Update in max segment tree /////////////////////////////////

    void updateQuery (int idx , int value , int s1 , int s2 , int node) {

      if(idx < s1 || idx >s2) return;

      if(idx ==s1 && idx == s2) {
        tree[node]=value;
        return;
      }

        int m = s1 + (s2-s1)/2;
        updateQuery(idx , value , s1 , m , node*2+1);
        updateQuery(idx , value , m+1 , s2 , node*2+2);

        tree[node] = max(tree[node*2+1], tree[node*2+2]);
    }
};

int main() {
  vector<int>arr = {6,8,-1,2,17,1,3,2,4};
  MaxSegmentTree Tree(arr);
  Tree.buildTree(arr , 0, arr.size()-1 , 0);
  Tree.print_tree();
  cout<<Tree.rangeQuery(6,8,0,arr.size()-1, 0)<<endl;
  Tree.updateQuery(4,18,0,arr.size()-1,0);
  Tree.print_tree();
  return 0;
}