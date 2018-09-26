#include <iostream>
#include "BT.h"
using namespace std;


// bool Search(node* root, int data){
//   if(root == nullptr) return false;
//   else if(root->data==data) return true;
//   else if(data <= root->data) return Search(root->left,data);
//   else return Search(root->right, data);
// }


int main(int argc, char const *argv[]) {

  BT BT;

  BT.constructTree(10);
  BT.constructTree(20);
  BT.constructTree(11);
  BT.constructTree(5);
  BT.constructTree(6);

  // if(Search(root, 2)) cout << "found";
  // else cout << "Not";

  BT.printTree();


  return 0;
}
