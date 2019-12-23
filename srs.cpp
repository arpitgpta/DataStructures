#include "MakeCodeAwsome.cpp"

struct table{
  int data;
  struct table * link;
};


int main(){
  
  int num,pos;
  struct table  *head = NULL,*temp = NULL,*node1 = NULL,*temp1 = NULL,*temp2 = NULL,*temp3 = NULL,*newnode = NULL,*search = NULL;
  
  head = NULL;
  temp = (struct table*)malloc(sizeof(struct table));
  deb(temp);
  scanf("%d",&temp->data);
  head = temp;
  head->link = NULL;
  deb(head);
  for(int i=0;i<9;i++)
  {
    // deb(head);
    node1 = (struct table*)malloc(sizeof(struct table));
    scanf("%d",&node1->data);
    node1->link = head;
    head = node1;
    deb(node1);
    // deb(head);
    // write();
  }

  temp1 = head;
  int i = 0;
  while(temp1 != NULL && i < 20){
	printf("%d ", temp1->data);
    temp1 = temp1->link;
    i++;
    deb(temp1);
  }



//  while(temp2->data!=3){
//  	temp2 = temp2->link;
//  }
//  newnode = (struct table*)malloc(sizeof(struct table));
//  newnode->data = 4;
//  newnode->link = temp2->link;
//  temp2->link = newnode;
//  temp3 = head;
//   while(temp3 != NULL){
// 		printf("%d", temp3->data);
//     temp3 = temp3->link; // to make pointer to point to next node
//   }
  
}






