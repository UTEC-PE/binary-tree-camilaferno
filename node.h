#include <iostream>
#include <string.h>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
};

node* GetnewNode(int idata){
  node* newNode = new node();
  newNode -> data = idata;
  newNode -> left = nullptr;
  newNode -> right = nullptr;

  return newNode;
}
