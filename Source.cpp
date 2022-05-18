#include <iostream>



class Item_Type {

public:
	

};


class Node {

public:

	Item_Type *data;
	Node* next;
	Node* ptr;


};


class linked_list {

private:
	Node* head;
	Node* tail;
	
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
    ~linked_list(){}

	void push_back(Item_Type &n) {
		Node* temp = new Node;
		temp->next = NULL;
		temp->data = &n;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	void remove_if(Item_Type& item) {

		Node * current= NULL, *next= NULL,* previous=NULL;
		current = head;

		while (current != nullptr)
		{
			if (current->data != &item){
				if (previous == NULL) {

					head = head->next;
					delete& current->data;
					current = head;
					previous = current;
					next = current->next;
					continue;
				}

				else if (next == NULL) {

					tail = current;
					delete& current->data;
					current = nullptr;
					continue;

				}

				else
				{
					delete& current->data;
					previous->next = current->next;
					if (next->next != NULL)
					{
						current->next = next->next;
						current = next;
						next = current->next;
						continue;
					}
					
					current = next;
					next = current->next;
					
					continue;
				}
				

				
			}
			previous = current;
			current = current->next;
			next = current->next;
			

		}
		delete current;

	}
	
	Item_Type operator[](int n)
	{
		Node* current = head;

		while (current != nullptr && n--> 0)
		{
			
			current =  current->next;

		}
		if (current == nullptr)
		{
			std::cout << "exitting, array out of boundaries";
			//exit();
		}
		else
		{

			return *current->data;
		}

	}
	
};





	int main() {

		linked_list array;
		Item_Type item1, item2, item3, item4, item5;
		array.push_back(item1);
		array.push_back(item2);
		array.push_back(item3);
		array.push_back(item4);
		array.push_back(item5);
		auto item = array[4];
		array.remove_if(item3);
		


	}


