class LinkedList {
		class Node {
		public:
			int value;
			Node *next = nullptr;
		};
		Node *head = nullptr;
		Node *tail = nullptr;
		int size = 0;
public:
	LinkedList() {
	}

	int get(int index) {
		if (index < 0 || index >= size){
			return -1;
		}
		auto resultNode = head;

		for(int i =0; i < index; i++){
			resultNode = resultNode->next;
		}
		return resultNode->value;
	}

	void insertHead(int val) {
		auto *newNode = new Node();
		newNode->value = val;
		if (size == 0){
			tail = newNode;
			head = newNode;
		}else {
			newNode->next=head;
			head = newNode;
		}
		size += 1;

	}

	void insertTail(int val) {
		auto *newNode = new Node();
		newNode->value = val;
		if (size == 0){
			tail = newNode;
			head = newNode;
		}else {
			tail->next = newNode;
			tail = newNode;
		}
		size += 1;
	}

	bool remove(int index) {
		if (index >=size || index < 0){
			return false;
		}

		if (index == 0){
			auto *toDeleteNode = head;
			head = head->next;
			delete toDeleteNode;
			size--;
			return true;
		}
		
		if ( index == (size - 1)){
			auto *beforeTodeleteNode = head;

			for (int i =0; i < (index - 1); i++){
				beforeTodeleteNode =beforeTodeleteNode->next;
			}
			delete tail;
			tail = beforeTodeleteNode;
			beforeTodeleteNode->next = nullptr;
			size--;
			return true;
		}

		auto *beforeToDeleteNode = (size - index) >= size / 2? head : tail;

		for ( int i = 0; i < (index - 1); i++){
			beforeToDeleteNode = beforeToDeleteNode->next;
		}

		auto * toDeleteNode = beforeToDeleteNode->next;
		beforeToDeleteNode->next = toDeleteNode->next;

		delete toDeleteNode;
		size--;
		return true;
	}

	vector<int> getValues() {
		vector<int> vec;
		auto * iterator = head;
		while (iterator != nullptr){
			vec.push_back(iterator->value);
			iterator = iterator->next;
		}
		return vec;
	}
};
