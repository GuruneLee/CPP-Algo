# Validate Binary Search Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/

## Solution
### Inorder Traversal
- Inorder Traversal시행시, 방문한 node의 크기가 오름차순이어야 함  
~~~
// array에 순서대로 저장하기
bool isValidBST(TreeNode* root) {
    traversal(node);
    {
        //val이 오름차순으로 정렬되어 있는가?
    }
}

int val[]
void traversal(node){
  if(node){
    traversal(node->left);
    val.append(node->val)
    traversal(node->right);
  }
}
~~~

- 꼭 배열을 사용해야 하는가? -> NO!! (근데 방법을 모르겠음...)  

### lower limit, upper limmit
- 모든 노드마다 left-subtree의 upper limmit, right-subtree의 lower limmit과 노드의 val을 비교해보자! (지금말고)


## Trouble Shooting
- 모든 노드를 돌면서 각 노드마다 왼쪽과 오른쪽이 조건을 만족하는지 파악하기  
: 5  
4   6  
n n 3 7  
이런 경우를 잡아내지 못함