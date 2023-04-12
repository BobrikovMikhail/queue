// очередь.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};

struct queque {
	int len;
	node* head;
	node* tail;
};

void push(queque*& que, int val) {
	node* p = new node;
	p->data = val;
	p->next = nullptr;
	que->tail->next = p;
	que->tail = p;
	que->len++;
}

queque* makeQue(int n) {
	queque* que = new queque;
	node* first = new node;
	first->data = 1;
	first->next = nullptr;
	que->head = first;
	que->tail = first;
	que->len = 1;
	for (int i = 2; i <= n; i++) {
		push(que, i);
	}
	return que;
}

void printQue(queque* que) {
	node* a = que->head;
	if (a == nullptr) {
		cout << "список пуст";
		return;
	}
	while (a != nullptr) {
		cout << a->data << " ";
		a = a->next;
	}
}

int pop(queque* que) {
	node* p = que->head;
	int temp = p->data;
	que->head = que->head->next;
	que->len--;
	delete p;
	return temp;
}

void popEl(int k, int pos, queque*& que) {
	int data;
	int size = que->len;
	for (int i = 1; i < pos; i++) {
		data = pop(que);
		push(que, data);
	}
	for (int j = 1; j <= k; j++) {
		pop(que);
	}
	for (int i = 1; i <= size - pos - k + 1; i++) {
		data = pop(que);
		push(que, data);
	}
}

void Addval(queque*& que, int key, int number) {
	int data;
	bool flag = 1;
	int cnt = que->len;
	while (cnt > 0) {
		if (que->head->data == key) {
			push(que, number);
			data = pop(que);
			push(que, data);
			flag = 0;
			cnt--;
		}
		else {
			data = pop(que);
			push(que, data);
			cnt--;
		}
	}
	if (flag == 1) {
		cout << "Элемента с ключом " << key << " не найдено" << endl;
	}
}


int main() {
	setlocale(0, "ru");
	cout << "введите кол-во элементов: ";
	int n, k, pos, key, newkey;
	cin >> n;
	cout << "исходная очередь: ";
	queque* que = makeQue(n);
	printQue(que);
	cout << endl << endl;
	cout << "Введите номер, с которого удалять: "; cin >> pos;
	cout << "введите кол - во удаляемых элементов : "; cin >> k;
	popEl(k, pos, que);
	cout << "Очередь после удаления элементов: ";
	printQue(que);
	cout << endl << endl;
	cout << "Введите ключ, перед которым необходимо добавить элемент: "; cin >> key;
	cout << "Введите значение нового элемента: "; cin >> newkey;
	Addval(que, key, newkey);
	cout << "Очередь после добавления элемента: ";
	printQue(que);
	cout << endl;
	return 0;
}
