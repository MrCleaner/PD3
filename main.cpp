#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* next;             //struktūra, jei nežinai kas yra struktūra įpisk alaus
};
void initNode(struct Node *head,int n){         //veikia tik įvedant pirmą elementą
	head->data = n;             //inveda pyrmų elementų, jei invedei 5 tai čia bus tas 5
	head->next =NULL;           //parodo, kad sekančio elemento adresas NULL, kad atrinktum kur inked listo šikna
}
void addNode(struct Node *head, int n) {        //inveda visus kitus elementus (veda į galą)
	Node *newNode = new Node;                   // sukuria naują įrašą, nežimau kaip oficialiai vadinasi, todėl bus įrašas
	newNode->data = n;                          // inveda 2,3 ir t.t. elementus
	newNode->next = NULL;                       // ir parodo, kad sekantis bus null

	Node *cur = head;
	while(cur) {                                //ieško kur šikna
		if(cur->next == NULL) {
			cur->next = newNode;                //ir kai randa inpisa įrašą
			return;
		}
		cur= cur->next;                         //pereina prie kito elemento, piktojo while paskutinė eilutė
	}
}
void insertFront(struct Node **head, int n) {      //inpisa elementą in priekį
	Node *newNode = new Node;                       //vėl susikuria naują įrašą
	newNode->data = n;                              //padaro magiją, perstumia galvą ir in priekį, o naująja galva tampa naujai įvestas įrašas
	newNode->next = *head;
	*head = newNode;
}

void display(struct Node *head) {
	Node *list = head;                      //krč išveda į ekraną
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main()
{   struct Node *head = new Node;
	struct Node *newHead;
    int k;

    cin>>k;                     //iveda pirma
    initNode(head,k);

	do                          //iveda iprastai (i gala)
	{cin>>k;
	if (k!=0)
    addNode(head,k);
	}
	while (k!=0);

	cin>>k;                     //iveda i pradþià
	insertFront(&head,k);
	display(head);

	struct Node *tmp;            //iðtrina pirmà
	tmp=head;
	head = head ->next;
	tmp=NULL;

    display(head);
	return 0;
}
