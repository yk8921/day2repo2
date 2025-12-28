#include<iostream>
using namespace std;

class node{
	public:
		int val;
		node *next;
		
	public:
		node(int v){
			val=v;
			next=nullptr;
		}
};


class linklist{
	private:
		node* head;
		int len;
	
	public:
		linklist(){
			len=0;
			head=nullptr;
		}
		
	void insert(int val, int pos){
		if(pos<1 || pos>len+1){
			cout<<"Invalid Position!";
			return;
		}
		
		node* n=new node(val);
		
		if(pos==1){
			n->next=head;
			head=n;
		}
		
		else{
			node* curr=head;
			
			for(int i=1; i<pos-1; i++){
				curr=curr->next;
			}
			
			n->next=curr->next;
			curr->next=n;
		}
		len++;
		
	} //END OF INSERT
	
	void remove(int pos){
		if(len==0){
			return;
		}
		
		if(pos<1 || pos>len){
			cout<<"Invalid Position!";
			return;
		}
		
		node* curr=head;
		
		if(pos==1){
			head=head->next;
			delete curr;
			return;
		}
		
		else{
			for(int i=1; i<pos-1; i++){
				curr=curr->next;
			}
			
			node* temp=curr->next;
			curr->next=temp->next;
			delete temp;
		}
		
		len--;
	
	}
	
	int get(int pos){
		if(len==0){
			return -1;
		}
		
		if(pos<1 || pos>len){
			cout<<"Invalid Position!";
			return -1;
		}
		
		node* curr=head;
		for(int i=1; i<pos; i++){
			curr=curr->next;
		}
		int value=curr->val;
		return value;
	}
	
	void update(int pos, int value){
		if(len==0){
			return;
		}
		
		if(pos<1 || pos>len){
			cout<<"Invalid Position!";
			return;
		}
		
		node* curr=head;
		for(int i=1; i<pos; i++){
			curr=curr->next;
		}
		
		curr->val=value;
	}
	
	void clear(){
		while(head!=nullptr){
			remove(1);
		}
	}
	
	void print(){
		node* curr=head;
		
		for(int i=1; i<=len; i++){
			cout<<curr->val<<"->";
			curr=curr->next;
		}
	}
		
		
		
};


int main(){
	linklist l1;
	l1.insert(1,1);
	l1.insert(2,2);
	l1.insert(3,3);
	l1.remove(2);
	l1.insert(4,2);
	
	l1.print();
	
	
	
	return 0;
}