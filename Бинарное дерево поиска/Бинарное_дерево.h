
//Создаем класс узла дерева
	class TreeElement
	{
	private:
		int data;
		TreeElement* left;	//левый потомок
		TreeElement* right;	//правый потомок
		TreeElement* back;	//родитель
	public:
		//Конструктор инициализации корня дерева
		TreeElement() :data(0), left(nullptr),right(nullptr), back(nullptr) {}

		//Конструктор инициализации узла дерева
		TreeElement(int d, TreeElement* l, TreeElement* r, TreeElement* b) :data(d), left(l), right(r), back(b) {}

		//Конструктор копирования
		TreeElement(TreeElement& t) :data(t.getData()),left(t.getLeft()), right(t.getRight()), back(t.getBack()) {}

		//функция занесения информационного поля узла
		void setData(int d) {
			data = d;
		}

		//функция, возвращающая информационное поле узла
		int getData() {
			return data;
		}

		//функция занесения левого потомка узла
		void setLeft(TreeElement* l) {
			left = l;
		}

		//функция, возвращающая левого потомка узла
		TreeElement* getLeft() {
			return left;
		}

		//функция занесения правого потомка узла
		void setRight(TreeElement* r) {
			right = r;
		}

		//функция, возвращающая правого потомка узла
		TreeElement* getRight() {
			return right;
		}

		//функция занесения родителя узла
		void setBack(TreeElement* b) {
			back = b;
		}

		//функция, возвращающая родителя узла
		TreeElement* getBack() {
			return back;
		}

	};

	//Создаем класс бинарное дерево поиска
	class BinaryTree
	{
		TreeElement* root;		//корень дерева
		TreeElement* findElement(int n);	//поиск узла по информационному полю
		TreeElement* recursiveFindElement(int n);	//поиск узла по информационному полю через рекурсию
		TreeElement* recursiveFindElement(TreeElement* r, int n);
		void recursiveRemove(int n, TreeElement* r);
	public:
		//Конструктор инициализации корня дерева
		BinaryTree() :root(nullptr) {};

		//Конструктор инициализации узла дерева
		BinaryTree(TreeElement* r) :root(r) {};

		//функция добавления узла
		void add(int current_n, int new_n);

		//функция удаления узла
		void remove(int n);

};

