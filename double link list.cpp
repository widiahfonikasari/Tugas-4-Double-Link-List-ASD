#include<iostream>
using namespace std;

//deklarasi double link list
struct Buku{
	string judul, pengarang;
	int tahun_terbit;
	
	Buku *prev;
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *afterNode ;

//create double linked list
void createDoubleLinkedList(string judul, string pengarang, int tahun_t){
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahun_terbit = tahun_t;
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}

// count Double Linked List
int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}

//insert first double linked list
void insertFirst(string judul, string pengarang, int tahun_t){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	}
}

//insert last double linked list
void insertLast(string judul, string pengarang, int tahun_t){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	newNode->prev = tail;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
	}
}

//insert after double linked list
void insertAfter(string judul, string pengarang, int tahun_t, int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	
	//transfersing
	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	afterNode = cur->next;
	newNode->prev = cur;
	newNode->next = afterNode;
	cur->next =newNode;
	afterNode->prev = newNode;
	}
}

//delete first double linked list
void deleteFirst(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
	  }else{
	del = head;
	head = head->next;
	head->prev = NULL;
	delete del;
	}
}

//delete last double linked list
void deleteLast(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	del = tail;
	tail = tail->prev;
	tail->next =NULL;
	delete del;
	}
}

//delete after double linked list
void deleteAfter(int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
 	 	if( posisi == 1 || posisi == countDoubleLinkedList() ){
      		cout << "Posisi bukan posisi tegah!" << endl;
   		}else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      		cout << "Posisi diluar jangkauan!" << endl;
   		}else{
			int nomor = 1;
			cur = head;
			while(nomor <= posisi -1){
				cur = cur->next;
				nomor++;
				}
			del = cur->next;
			afterNode = del->next;
			cur->next =afterNode;
			afterNode->prev = cur;
			delete del;
		}
	}
}

//print double linked list
void printDoubleLinkedList(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
    cout << "\nJumlah Data : " << countDoubleLinkedList() << endl;
    cout << "INFO DATA" << endl;
    cur = head;
    while( cur != NULL ){
     
      cout << "Data : " << cur->tahun_terbit << endl;
      
      cur = cur->next;
    }
  }
}

void searchNode(Buku **head, int tahun_t ){
    int currentTT = 2013;
    Buku*cur = *head;
    while (cur->next != 0 && currentTT != tahun_t)
    {
        cur = cur->next;
        currentTT++;
    }
    cout << cur->judul << " ditemukan pada tahun ke " << currentTT;
}

int main(){
	
	createDoubleLinkedList("Matematika","Ahmad Sutan",2013);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst("Bahasa Indonesia", "Susi Agustian", 2015);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast("Sejarah", "Dian Anwar", 2016);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Kebumian", "Ratna Harto", 2017, 3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Manusia", "Abimayu", 2014, 4);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	printDoubleLinkedList();
  	searchNode(&head, 3);
	return 0;
}
