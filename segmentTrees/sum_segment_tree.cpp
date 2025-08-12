////// Implementation of segment Trees using array ///////

/// Note : despite it takes only 2n-1 space to build segment tree , we take 4n space .

#include<iostream>
#include<vector>
using namespace std;
class segmentTree {
  private:
  vector<int> tree;

  public:
  segmentTree(vector<int>& v) {
    tree.resize(4*v.size());
  }
  void build_segment_tree(vector<int>& arr , int s , int e , int node) {
    int m = s + (e-s)/2;
    if( s==e) {
      tree[node]=arr[s];
      return;
    }

    build_segment_tree(arr , s , m , node*2+1);
    build_segment_tree(arr , m+1 , e , node*2+2);
    tree[node] = tree[2*node+1] + tree[2*node+2];
  }

  void print_tree(void) {
    for(int i=0 ; i<tree.size() ; i++) {
      cout<<tree[i]<<" ";
    }
  }

  /////  Range Query Operation ////////////// 
// 1 . No overlapping  , just return 
// 2 . Complete overlapping  , add that value to sum and return 
// 3 . Partial overlapping  , travel the childrens until you encounter case 1 or case 2.

int range_query(int q1 , int q2 , int s1 , int s2, int node) {
////////////// 1 . no overlap case ////////////
   if( q1 > s2 || q2 < s1) return 0;

   /////////////// 2 . complete overlap case ///////////////
   if(s1 >=q1 && s2 <=q2) return tree[node];

   //////////////// 3 . partial overlap case /////////////////// ( imp )
   int m = s1+(s2-s1)/2;
   int left = range_query(q1 , q2 , s1 , m , node*2+1);
   int right = range_query(q1 , q2 , m+1 , s2 , node*2+2);
   return left+right;
}


/////////// updating in segment trees //////////////
/// eg : idx = 1 , val = 3;

void update(int idx , int value ,int s1 , int s2, int node) {
     
  ///////////  index doesn't lies within range ////////////
  if( idx < s1 || idx >s2) return;

  //////////// index becomes equal to s1 and s2 //////////////
  if(idx==s1 && idx==s2) {
    tree[node] = value;
    return;
  }

  ////////// index lies between s1 and s2 /////////////
  int m= s1 + ( s2-s1)/2;
  update(idx , value , s1 ,m , node*2+1);
  update(idx , value , m+1 , s2 , node*2+2);
  tree[node] = tree[node*2+1] + tree[node*2+2];
}
};

int main( ) {
  vector<int> arr = {1,2,3,4,5,6,7,8};
  segmentTree Tree(arr);
  Tree.build_segment_tree(arr , 0 , arr.size()-1 , 0);
  Tree.print_tree();
  cout<<endl<<Tree.range_query(2,5,0,arr.size()-1,0)<<endl;
  Tree.update(1,3,0,arr.size()-1 , 0);
  Tree.print_tree();
  return 0;
}