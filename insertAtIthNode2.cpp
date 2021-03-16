    
    // insert a new node at 2nd position indexing from 0 
    
    #include<bits/stdc++.h>
    using namespace std;
    class Node{
    public :
    int data;
    Node * next;

        Node(int data){
            this->data =data;
            next = NULL;
        }
    };

    // function to print all nodes of a linked list
    void print(Node * head){
    
        while(head!= NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    // function to build a linked list
    Node * takeInput(){
        // -1 as a terminator
        int data;
        cin>>data;
        Node * head = NULL;
        Node * temp = NULL;
        while(data!= -1){
            Node * newNode = new Node(data);
            if(head==NULL){
                head= newNode;
                temp =newNode;
            }else{
                // adding another file
                
                temp->next = newNode;
                temp = temp->next; 
            }
            cin>>data;
        }

        return head;
    }
    // inserting a node to given position
    Node * insertAtI(int data, int pos,Node * head){
            int idx =0;
            Node * newNode = new Node(data);
            Node *temp = head;
            if(pos==0){
                newNode->next =head;
                head = newNode;
                return head;
            }
            while(temp!=NULL&&idx<pos-1){
                idx += 1;
                temp = temp->next;
            }
            if(temp!=NULL){
            newNode->next = temp->next;
            temp->next = newNode;
            }
            return head;
    }

  // deleting a node from linked list
Node *deleteNode(Node *head, int pos)
{
    	int idx =0;
        Node * temp = head;
    	if(pos==0){
            head = head->next;
            return head;
        }
    	
    	while((temp!=NULL)&&(idx<pos-1)){
            idx += 1;
            temp = temp->next;
        }
    	if(temp!=NULL){
            // Because when we will be on last node and wants to delete
            // Node after the last node then at last node position temp will
            // not be null and we will try to acces (null->next) and will get
            // segmentation fault
        	if(temp->next!=NULL)
    			temp->next = (temp->next)->next;
    	//delete temp->next;
        }
    	return head;
    
}
// inserting a node to a given position (recursive)

void insertNode2(Node *temp1, int i, int data) {
    
    if(temp1==NULL){
        return;
    }
    
    if(i==1){
        Node * newNode = new Node(data);
        newNode->next = temp1->next;
        temp1->next = newNode;
        return;
        
    }
    insertNode2(temp1->next,i-1,data);
	// Write your code here
}

Node* insertNode(Node *head, int i, int data) {
    
  if(i==0){
        Node * newNode = new Node(data);
        newNode->next = head;
      	head = newNode;
        return head;
   }
   Node * temp = head;
   insertNode2(temp,i,data);
   return temp;
	// Write your code here
}


// deleting a node using at a given position recursive (recursive)


void deleteHelper(Node * temp , int pos){
    
    if(temp==NULL){
        return;
    }
    if(pos==1){
        if(temp->next == NULL){
            return;
		}
        Node * req = temp->next;
        temp->next = req->next;
        delete req;
        return;
    }
    deleteHelper(temp->next,pos-1);
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(pos==0){
        Node * req = head;
        head = head->next;
        delete req;
        return head;
    }
    deleteHelper(head,pos);
    return head;
	
}
 // finding a node  index with given data 
int findNode(Node *head, int n)
{	
    if(head==0){
        return -1;
    }
    Node * temp = head;
    bool isFound = true;
    int idx = 0;
    while(temp->data!= n){
        if(temp->next==NULL){
            isFound = false;
            break;
        }
        idx += 1;
        temp = temp->next;
    }
    if(isFound){
        return idx ;
    }else{
        return -1;
    }
    //Write your code here
}
int main(){
        
        Node * head =  takeInput();
        print(head);
        head = insertAtI(50,8,head);
        print(head);
        head = insertAtI(100,3,head);
        print(head);
        
    }
