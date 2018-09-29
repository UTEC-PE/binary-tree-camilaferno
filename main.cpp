#include <iostream>
#include "BT.h"
using namespace std;

/*
1. Insertar
2. Eliminar
3. Peso
4. Iterador in-order
5. print inorder, postorder, preorder
*/

int main(int argc, char const *argv[]) {

  BT bT;

  bT.constructTree(10);
  bT.constructTree(20);
  bT.constructTree(11);
  bT.constructTree(5);
  bT.constructTree(6);
  bT.constructTree(4);
  bT.constructTree(1);

  bT.remove(5);
  bT.PrintTreeInternet();



  return 0;
}
