
struct node
{
    int key_value; //ключ – значение узла, типа int
    node* left;    //указатель на левого потомка
    node* right;   //указатель на правого потомка
};
class btree
{
public:
    btree();                            	//Конструктор
    ~btree();                           	//Деструктор

    void insert(int key);               	//Функция вставки
    node* search(int key);			//Функция поиска
    void destroy_tree();               	//Функция удаления дерева

private:
void destroy_tree(node* leaf);		//Рекурсивная функция удаления 								//дерева
void insert(int key, node* leaf);	//Рекурсивная функция //добавления узла в дерево
node* search(int key, node* leaf);	//Рекурсивная функция поиска //узла дерева с заданным //ключевым значением

    node* root;					//Атрибут класса(Корневой узел)
};

btree::btree()
{
 		      root = NULL;	       // Корневой узел без дочерних элементов
}
btree::~btree()
{
destroy_tree(); 	//При удалении дерева, необходимо удалить все //элементы
}
void btree::destroy_tree(node *leaf)
{
      if(leaf!=NULL)				//Если узел дерева существует
      {						//Функция вызовет сама себя
          destroy_tree(leaf->left);	//сначала для левого потомка,
          destroy_tree(leaf->right);  	//после для правого потомка.
          delete leaf;			//Если потомков нет, она удалит
//Узел, полученный в качестве параметра //функции
void btree::insert(int key)     //Функция, доступная для элементов, которые не   являются членами класса
{					//Сначала проверит корневой элемент
  if(root!=NULL)			//Если он не инициализирован,
    insert(key, root);		//то вызовется рекурсивная функция
					//для добавления элемента.
 
  else				      //Иначе Функция поместит новое значение:
  {					
    root=new node;		      //инициализируется корневой элемент 
    root->key_value=key;	      //поместится ключевое значение
					//в соответствующую ячейку структуры. 
    root->left=NULL;		//Инициализируется указатель на левый
    root->right=NULL;		//и правый элемент как NULL
  }
}

//Рекурсивная функция для вставки элемента.
void btree::insert(int key, node* leaf)	//(Новое ключевое значение, указатель на //текущий узел)	
{							
if (key < leaf->key_value)  	//Если новое ключевое значение меньше чем //ключевое значение в узле
    {
        if (leaf->left != NULL)		//И если левый указатель узла инициализирован
            insert(key, leaf->left);		//Функция вызывает саму себя, для левого //узла потомка
else		//Иначе (если левый потомок не //инициализирован)
        {
            leaf->left = new node;		//Функция создаст и поместит новый элемент на //место левого потомка.
            leaf->left->key_value = key;	//Внесёт новое ключевое значение в элемент.
            leaf->left->left = NULL;    	//Установит левый дочерний указатель 
            leaf->left->right = NULL;   	//и правый дочерний указатель в NULL.
        }
    }
    else if (key >= leaf->key_value)		//Иначе Если новое ключевое значение не //меньше ключевого значения в узле 
    {
        if (leaf->right != NULL)		//И если правый указатель инициализирован,
            insert(key, leaf->right);		//То функция вызывает саму себя, для правого //потомка
else		//Иначе(если правый потомок не //инициализирован)
        {
            leaf->right = new node;		//Функция создаст и поместит новый элемент на //место правого потомка.
            leaf->right->key_value = key;	//Внесёт новое ключевое значение в элемент.
            leaf->right->left = NULL;  	//Установит левый дочерний указатель
            leaf->right->right = NULL;      //и правый дочерний указатель в NULL.
        }
    }
}
node* btree::search(int key, node* leaf)	//(Ключевое значение, //указатель ну узел)
{
if (leaf != NULL)	//Если узел //инициализирован
    {
        if (key == leaf->key_value)	//И ключевое значение //узла совпадает с //искомым ключевым //значением.
return leaf;	//Возвращается указатель на //найденный элемент.
if (key < leaf->key_value)	//Иначе, если 
//искомое ключевое //значение меньше //ключевого значения узла
return search(key, leaf->left);	//Вызывается эта же функция //для левого потомка.
        else							//Иначе
            return search(key, leaf->right);	//Вызывается эта же функция //для правого потомка.
    }
    else return NULL;					//Иначе возвращается NULL.
}