#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


template <typename T>
class List {
private:
    struct Node // объявление узла
    {
        T data; // данные узла
        Node* next; //указатель на следующий узел
    };
    Node* head; //указатель на начало списка

public:
    List(); // конструктор
    ~List(); // деструктор
    void Show(); // вывод списка на экран
    List& operator = (List const* list); // перегрузка операции присваивания
    void operator== (T i); // перегрузка операции сравнения
    List& operator -- (T element); // удаление последнего элемента
    List& operator + (T element); // добавление элемента в начало
};

template<typename T>
List<T>::List() : head(NULL) {} // конструктор

template<typename T>
List<T>::~List() {  // деструктор
    while (head) {  // последовательное удаление, начиная с головы
        Node* temp = head->next; // запоминаем адрес следующего узла
        delete head;
        head = temp; // делаем его первым узлом
    }
}

template <typename T>
void List<T>::Show() {  // вывод списка на экран
    cout << "Список:" << endl;
    Node* a = head;
    while (a) {
        cout << a->data << endl;
        a = a->next;
    }
}

template<typename T>
List<T>& List<T>::operator = (List const* list) {  // перегрузка операции присваивания
    Node* temp = new Node; //динамически выделяем память для нового узла
    temp = list->head;
    Node* newList = new Node;
    newList = head;
    if (newList == NULL) {
        Node* n = new Node;
        newList = n;
        newList->data = 0;
        newList->next = NULL;
        head = newList;
    }
    while (temp) {
        newList->data = temp->data;
        temp = temp->next;
        if ((newList->next == NULL) && (temp != NULL)) {
            Node* n = new Node;
            n->next = NULL;
            n->data = 0;
            newList->next = n;
        }
        newList = newList->next;
    }
    newList->next = NULL;
    return *this;
}

template<typename T>
List<T>& List<T>::operator--(T element) {  // удаление элементов с конца

    if (head->next == NULL) {
        head = NULL;
        delete head;
    }
    else {
        Node* current = head;
        Node* temp = current->next; // запоминаем адрес следующего узла
        while (temp->next) {  // пока следующий адрес не NULL, передвигаем указатель
            current = temp;
            temp = current->next;
        }
        if (temp->next == NULL) {
            current->next = NULL;//зануляем предпоследний указатель
            delete temp->next; //уничтожаем последний
        }
    }
    return *this;
}

template<typename T>
void List<T>:: operator== (T i) {  // перегрузка операции сравнения

    Node* temp = head;
    while (temp) {  // пока не конец
        if (temp->data != i) cout << temp->data << "!=" << i << endl;
        else cout << temp->data << "=" << i<<  endl;
        temp = temp->next;
    }
}

template<typename T>
List<T>& List<T>::operator+(T element) {  // добавление элементов в начало
    Node* node = new Node;
    node->data = element;
    if (head == NULL) {
        head = node;
        node->next = NULL;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
        node->next = NULL;
    }
    return *this;
}


int main() {
    int answer, item, key;
    bool flag = true;

    List<int> list;
    do {
        cout << "Введите элемент, добавляемый в начало списка: " << endl;
        cin >> item;
        list = list + item;
        cout << "Продолжить? \n 1) Да; 2) Нет" << endl;
        cin >> answer;
    } while (answer == 1);

    list.Show();
    cout << endl;

    while (flag) {
        cout << "С чем будем сравнивать:" << endl;
        cin >> key;
        list == key;
        cout << "Удалить последний элемент? \n 1) Да; 2) Нет (выйти из программы)" << endl;
        cin >> answer;
        if (answer == 1) {
            list = list--;
            list.Show();
        }

        if (answer == 2) flag = false;
        else continue;
    }

    return 0;
}
