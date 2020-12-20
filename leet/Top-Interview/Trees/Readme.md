# Tree

## Tree Traversal  
![Tree Traversal](./treetraversal.png){: width="300" height="400"}

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