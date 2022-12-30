#include <iostream> 
#include <string> 

using namespace std;

class Node {

public:

    int data;	//информационное поле

    Node* next;	//ссылка на следующий элемент



    Node(int data) : data(data), next(nullptr) {}	//конструктор инициализации

};
//класс списка
class List {

public:

    //класс элемента списка
    class Node {

    public:

        int data;	//информационное поле

        Node* next;	//ссылка на следующий элемент



        Node(int data) : data(data), next(nullptr) {}	//конструктор инициализации

    };



    Node* head;	//первый элемент списка

    int size;	//размер списка



public:

    List() : head(nullptr), size(0) {}	//конструктор создания списка

    void pushBack(int data) {		//вставка элемента списка

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


    int at(int index) {

        if (index < 0 || index >= size) {

            throw std::out_of_range("Index out of range");

        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {

            temp = temp->next;

        }

        return temp->data;

    }

    int find(int value) {		//поиск элемента списка

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
    friend ostream& operator<<(ostream& ofs, const List::Node& node) {



        ofs << node.data << '\n';


        return ofs;



    }

    int getSize() {			//получение размера списка

        return size;

    }
    Node* get_head()
    {
        return head;
    }

};

//осносная часть кода

int main() {

    setlocale(LC_ALL, "ru");

    List list;

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
    List::Node* head = list.get_head();
    List::Node* temp = head;

    while (temp != nullptr) {		//пока не дошли до конца списка
        
        cout << temp->data << " ";		//выводим элемент

        temp = temp->next;		//переходим к следующему элементу

    }

    cout << endl;


    list.popBack();		//удаление элемента списка

    List::Node* temp1 = head;

    while (temp1 != nullptr) {		//пока не дошли до конца списка

        cout << temp1->data << " ";		//выводим элемент

        temp1 = temp1->next;		//переходим к следующему элементу

    }

    return 0;

}