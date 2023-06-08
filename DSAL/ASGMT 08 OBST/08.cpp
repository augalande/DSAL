/* PROBLEM STATEMENT ------------------------------------------------------------------

Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search probability pi
for each key ki. Build the Binary search tree that has the least search cost given
the access probability for each key.

------------------------------------------------------------------------------------ */

#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* left;
 Node* right;
public:
 Node(int data){
 this->data = data;
  left = right = NULL;
 }
};
class obst{
    public:
 int *p,*q,*arr;
 Node* root;
 int n;
 int **w,**c,**r;
 obst(int n){
     this->n=n;
  arr=new int[n+1];
  w=new int*[n+1];
  c=new int*[n+1];
  r=new int*[n+1];
  root = NULL;
  for(int i=0 ; i<= n ; i++){
   w[i]=new int[n+1];
   c[i]=new int[n+1];
   r[i]=new int[n+1];
  }
  p=new int[n+1];
  q=new int[n+1];
  cout<<"Enter keys"<<endl;
  for(int i=1 ; i<= n ; i++)
   cin>>arr[i];
cout<<"Enter successful probabilities"<<endl;
  for(int i=1 ; i<= n ; i++)
   cin>>p[i];
  cout<<"Enter the unsuccessful probabilities"<<endl;
  for(int i=0 ; i<= n ; i++)
   cin>>q[i];
 }
 void create(){
  for(int i=0 ; i<= n ; i++){
   for(int j=0 ; j<= n ; j++){
    w[i][j] = r[i][j] = c[i][j] = 0;
   }
  }
  int diff =0;
  while(diff <= n){
   int i=0 , j=i+diff;
   while(j<= n){
    if(i==j)
     w[i][j] = q[i];
     else{
     w[i][j] = w[i][j-1] + p[j] + q[j];
    }
    i++;
    j=i+diff;
   }
   diff++;
  }

  diff =0;
  while(diff <= n){
   int i=0 , j=i+diff;
   while(j<= n){
    if(i==j)
     r[i][j] = c[i][j] = 0;
     else{
     double cost = 99999.9999;
     for(int k = i+1 ; k<=j ; k++){

      if(cost > c[i][k-1]+c[k][j] ){

       c[i][j] = c[i][k-1]+c[k][j];
       r[i][j] = k;
       cost = c[i][k-1]+c[k][j];
      }
     }
     c[i][j] += w[i][j];
    }
    i++;
    j=i+diff;
   }
   diff++;
  }
 this->root = makeTree(0 , n);
}
Node* makeTree(int i , int j ){
 if(i==j)
 return NULL;
 int k = r[i][j];
 Node* p = new Node(k);
 p->left = makeTree(i , k-1);
 p->right = makeTree(k , j);
 return p;
}
void inorder(Node* p){
 if(p == NULL){
  return ;
 }
 inorder(p->left);
 cout<<arr[p->data]<<" , ";
 inorder(p->right);
}
void preorder(Node* p){
 if(p == NULL){
  return ;
 }
 cout<<arr[p->data]<<" , ";
 preorder(p->left);
 preorder(p->right);
}
void postorder(Node* p){
 if(p == NULL){
  return ;
 }
 postorder(p->left);
 postorder(p->right);
 cout<<arr[p->data]<<" , ";
}
void printCost(){
    cout<<"Cost of OBST "<<c[0][n]<<endl;
}
};
int main(){
int n;
cout<<"Enter number of nodes in tree"<<endl;
cin>>n;
 obst t(n);
 t.create();
 while(true)
 {
  int c;
  cout<<"1.Print minimum cost\n2.Print inorder\n3.Print preorder\n4.Print postorder"<<endl;
     cin>>c;
     if(c==1)
     t.printCost();
     else if(c==2)
     {t.inorder(t.root);
     cout<<endl;
     }
     else if(c==3)
    { t.preorder(t.root);
     cout<<endl;
     }
     else if(c==4)
    { t.postorder(t.root);
     cout<<endl;
     }
 }

 return 0;
}
