#include <iostream> 
#include <string> 

using namespace std;

template <typename T>

//класс списка
class List {

private:

	//класс элемента списка
    class Node {

    public:

        T data;	//информационное поле

        Node* next;	//ссылка на следующий элемент



        Node(T data) : data(data), next(nullptr) {}	//конструктор инициализации

    };



    Node* head;	//первый элемент списка

    int size;	//размер списка



public:

    List() : head(nullptr), size(0) {}	//конструктор создания списка

    void pushBack(T data) {		//вставка элемента списка

        Node* newNode = new Node(data);	//создание элемента

        if (head == nullptr) {	//если список еще не создан

            head = newNode;	//сохраняем элемент как первый

        }

        else {

            Node* temp = head;		//иначе сохраняем его следующим после первого

            while (temp->next != nullptr) {

                temp = temp->next;

            }

            temp->next = newNode;

        }

        size++;	//увеличиваем размер

    }

    void popBack() {		//функция удаления

        if (head == nullptr) {	//если список итак пустой

            return;

        }

        else if (head->next == nullptr) {		//если сотался только первый элемент

            delete head;	//удаляем его

            head = nullptr;	//обнуляем 

            size--;	//уменьшаем размер

        }

        else {				//если список состоит больше чем из одного элемента

            Node* temp = head;

            while (temp->next->next != nullptr) {	//доходим до послденего элемента списка

                temp = temp->next;

            }

            delete temp->next;		//удаляем его

            temp->next = nullptr;	//обнуляем ссылку предыдущего элемента 

            size--;		//уменьшаем размер

        }

    }

    void display() {		//функция вывода списка

        Node* temp = head;

        while (temp != nullptr) {		//пока не дошли до конца списка

            std::cout << temp->data << " ";		//выводим элемент

            temp = temp->next;		//переходим к следующему элементу

        }

        std::cout << std::endl;

    }

    T at(int index) {

        if (index < 0 || index >= size) {

            throw std::out_of_range("Index out of range");

        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {

            temp = temp->next;

        }

        return temp->data;

    }

    int find(T value) {		//поиск элемента списка

        int index = 0;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == value) {

                return index;

            }

            temp = temp->next;

            index++;

        }

        return -1;

    }

    int getSize() {			//получение размера списка

        return size;

    }

};

//осносная часть кода

int main() {

    setlocale(LC_ALL, "ru");

    List<int> list;

    cout << "Введите кол-во элементов " << endl;

    int k, q;

    int n = 1;

    cin >> k;

    for (int i = 0; i < k; i++) {		//заполнение списка

        cout << "Введите данные элемента под номером: " << n << " " << endl;

        cin >> q;

        list.pushBack(q);		//добавление элемента списка 	

        n += 1;

    }

    list.display();		//вывод списка

    list.popBack();		//удаление элемента списка

	list.display();		//вывод списка

    return 0;

}