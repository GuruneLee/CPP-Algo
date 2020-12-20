# Tree

## Tree Traversal  
<img width="300" height="400" src="./treetraversal.png">

~~~
void traversal(node){
  if(node){
    //visit(node); preorder
    traversal(node->left);
    //visit(node); inorder
    traversal(node->right);
    //visit(node); postorder
  }
}
~~~