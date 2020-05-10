 #include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>

using namespace std;

class node{
public:
    int data;
    node* next;
    
    node(int d){
        data=d;
        next=NULL;
    }
};
/*
class linkedlist{
    node* head;
    node* tail;
public:
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
}
*/
void insertAthead(node*&head,int data){
    node*n=new node(data);
    n->next=head;
    head=n;
}
void deleteAtmiddle(node*&head,int p){
    node*temp=head;
    node*prev=head;
    int jump=1;
    while(jump<=p-1){
        prev=prev->next;
        temp=temp->next;
        jump++;
    }
    temp=temp->next;
    prev->next=temp->next;
    delete temp;
    
}
void deleteAthead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
    return;
}



void insertAttail(node*&head,int data){
    node*n=new node(data);

    if(head==NULL){
        head=n;
        return;
    }
        node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}
void deleteAttail(node*&head){
    node*temp=head;
    node*prev=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    while(prev->next->next!=NULL){
        prev=prev->next;
    }
    prev->next=NULL;
    delete temp;
}

int length(node*head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

void insertAtmiddle(node*&head,int data,int p){
    if(head==NULL || p==0){
        insertAthead(head,data);
    }
    if(p>length(head)){
        insertAttail(head, data);
    }
    else{
    node*n=new node(data);
    node*prev=head;
    int jump=1;
    while(jump<=p-1){
        prev=prev->next;
        jump++;
    }
        n->next=prev->next;
        prev->next= n;

    }

}
void buildlist(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAttail(head, data);
        cin>>data;
    }
}

bool searchRecursive(node*&head,int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }
    else{
     return searchRecursive(head->next, key);
        }
}
    bool searchIterative(node*&head,int key){
        node*temp=head;
        while(temp!=NULL){
                        if(temp->data==key){
                return true;
            }
            temp=temp->next;

        }
        return false;
    }

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"--";
        temp=temp->next;
    }
}
void reverse(node*&head){
    node*prev=NULL;
    node*curr=head;
    node*n;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
    
}
node* recursiveReverse(node*&head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    node*smallhead=recursiveReverse(head->next);
    node*curr=head;
    curr->next->next=curr;
    curr->next=NULL;
    return smallhead;
}
node* midpoint(node*&head){
    if(head!=NULL || head->next!=NULL){
        return head;
    }
    node*slow=head;
    node*fast=head;
    while(fast->next==NULL && fast->next->next==NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge(node*a,node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node*c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c=b;
        c->next = merge(a,b->next);
    }
    return c;

}
node* mergeSort(node*l){
    if(l==NULL or l->next==NULL){
        return l;
    }

    node*mid =  midpoint(l);
    node*a = l;
    node*b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);


}
//floyd's cycle
bool cycleDetection(node*head){
    node*slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main(){
    node* head=NULL;
    int x,key;
    cin>>x;
    insertAthead(head, x);
      insertAthead(head, 4);
      insertAthead(head, 3);
    insertAthead(head, 7);
    insertAthead(head, 9);
        deleteAtmiddle(head,2);
    insertAtmiddle(head, 3, 2);
    insertAtmiddle(head, 66, 2);
    cin>>key;
    if(searchRecursive(head, key)){
        cout<<"key present";
    }
    else{
        cout<<"key not present";
    }
    if(searchIterative(head, key)){
        cout<<"key present";
    }
    else{
        cout<<"key not present";
    }

    print(head);
}





/*
#include<iostream>
   #include<vector>
   #include<string>
   #include<algorithm>

   using namespace std;

void strTOnum(string n,int i){
    
    int len=n.size();
    if(i==len){
        return ;
    }
    cout<<n[i-1];

        if(n[i-1]==n[i]){
        cout<<"*";
    }
    
    strTOnum(n,i+1);

}

int main(){
       string n;
       cin>>n;
       strTOnum(n,1);
    int len=n.size();

    for(int i=0;i<len;i++){
        if(i=(len-1)){
            cout<<n[i];
        }
    }
    
   }
*/
/*
 int Solution::repeatedNumber(const vector<int> &A) {
     sort(A.begin(),A.end());
     
     int x=A.size();
     int b[x]={0};
     for(int i=0;i<x;i++){
         
     }
 }
 
 
 */
 
 

/*
 #include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare( pair<string,int> p1, pair<string, int> p2){
    return p1.first < p2.first;
    
}
    

int main(){
    int x,i;
    cin>>x;
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    
    for(i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    
      sort(v.begin(),v.end(),compare);
    int mdx=v[1].first-v[0].first;
    int mdy=v[1].second-v[0].second;
    int dx,dy;
    for(int i=1;i<n-1;i++){
        dx=v[i+1].first-v[i].first;
        dy=v[i+1].second-v[i].second;
int area=(dx-1)*(dy-1)
        
    }
               
    return 0;
}
*/


/*
 #include<iostream>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=(fact(n))/(2*fact(n-2));
        int fans=ans-n;
        cout<<fans<<endl;
            }
    return 0;
}
*/


/*
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
   
}
int length(node*head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}



void insertAttail(node*&head,int data){
    node*n=new node(data);

    if(head==NULL){
        head=n;
        return;
    }
        node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}

void insertAtHead(node*&head,int data){

    if(head==NULL){
        head = new node(data);
        return;
    }
    node*n = new node(data);
    n->next = head;
    head = n;
}
void buildlist(node*&head,int t){
    int data;
    while(t--){
        cin>>data;

        insertAttail(head, data);
          }
}
void buildlist_method2(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAttail(head, data);
        cin>>data;
    }
}



ostream&operator<<(ostream&a,node*head){
    print(head);
    return a;
}
istream&operator>>(istream&a,node*&head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return a;
}
node* reverse(node*&head){
    node*prev=NULL;
    node*n;
    node*curr=head;
    while (curr!=NULL) {
        n=curr->next;
        curr->next = prev;
        //move c and p one step ahead
        prev = curr;
        curr = n;

    }
   
    return prev;
}
node* merge(node*a,node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node*c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c=b;
        c->next = merge(a,b->next);
    }
    return c;

}

node* append_k(node *head, int k) {
    node *cur = head, *prev = NULL;
    while (k--) {
        cur = cur->next;
    }
    prev = head;
    while (cur->next != NULL) {
        cur = cur->next;
        prev = prev->next;
    }
    node *temp = prev->next;
    prev->next = NULL;
    cur->next = head;
    return temp;
}
int k_element(node *head, int k){
    node *cur = head, *prev = NULL;
    while (k--) {
        cur = cur->next;
    }
    prev = head;
    while (cur->next != NULL) {
        cur = cur->next;
        prev = prev->next;
    }
    node *temp = prev->next;
    return temp->data;
}

void evenAfterOdd(node*&head){
        node*temp=head;
    node*even=NULL;
    node*odd=NULL;


    while(temp!=NULL){
        if(((temp->data)%2)==0){
            insertAttail(even, temp->data);
            
        }
        else{
            insertAttail(odd, temp->data);

        }
        temp=temp->next;
    }
    print(odd);

     print(even);
    
   
}
int intersection_ll(node*head1,node*head2){
    int l1=length(head1);
    int l2=length(head2);
    if(l1>=l2){
    int diff=l1-l2;
        while(diff--){
            head1=head1->next;
        }
        while(head1!=NULL){
            if((head1->data)==(head2->data)){

                return head1->data;
            }
            head1=head1->next;
            head2=head2->next;

        }

    }
    else{
          int diff=l2-l1;
        while(diff--){
            head2=head2->next;

        }
        while(head2!=NULL){
            if((head1->data)==(head2->data)){
                return head1->data;

            }

            head1=head1->next;
            head2=head2->next;

        }


    }
    return -1;
}
bool palindrome(node*head){
    node*head2=reverse(head);
    node*temp1=head;
    node*temp2=head2;

    while(temp1!=NULL){
        if((temp1->data)!=(temp2->data)){
            return false;
        }
        temp1=temp1->next;
          temp2=temp2->next;
    }
    return true;
}

int main(){
    
    node* head1=NULL;

  
    int t;
    cin>>t;
    buildlist(head1, t);
    if(palindrome(head1)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
        return 0;
}


*/
