
#include <iostream>
using namespace std;
// Структура - узел дерева
struct tnode
{
    int field;           // поле данных
    struct tnode *left;  // левый потомок
    struct tnode *right; // правый потомок
};
// Вывод узлов дерева (обход в инфиксной форме)
void treeprint(tnode *tree)
{
    if (tree != NULL) {      //Пока не встретится пустой узел
        treeprint(tree->left);  //Рекурсивная функция вывода левого поддерева
        cout << tree->field << " "; //Отображаем корень дерева
        treeprint(tree->right); //Рекурсивная функция вывода правого поддерева
    }
}
// Добавление узлов в дерево
struct tnode * addnode(int x, tnode *tree) {
    if (tree == NULL)     // Если дерева нет, то формируем корень
    {
        tree = new tnode; //память под узел
        tree->field = x;   //поле данных
        tree->left = NULL;
        tree->right = NULL; //ветви инициализируем пустотой
    }
    else     // иначе
        if (x < tree->field)   //Если элемент x меньше корневого, уходим влево
            tree->left = addnode(x, tree->left); //Рекурсивно добавляем элемент
        else  //иначе уходим вправо
            tree->right = addnode(x, tree->right); //Рекурсивно добавляем элемент
    return(tree);
}
//Освобождение памяти дерева
void freemem(tnode *tree)
{
    if (tree != NULL)    // если дерево не пустое
    {
        freemem(tree->left);   // рекурсивно удаляем левую ветку
        freemem(tree->right);  // рекурсивно удаляем правую ветку
        delete tree;           // удаляем корень
    }
}
// Тестирование работы
int main()
{
    struct tnode *root = 0;    // Объявляем структуру дерева
    system("chcp 1251");    // переходим на русский язык в консоли
    system("cls");
    int a;            // текущее значение узла
    // В цикле вводим 8 узлов дерева
    for (int i = 0; i < 8; i++)
    {
        cout << "Введите узел " << i + 1 << ": ";
        cin >> a;
        root = addnode(a, root); // размещаем введенный узел на дереве
    }
    treeprint(root);    // выводим элементы дерева, получаем отсортированный массив
    freemem(root);      // удаляем выделенную память
    cin.get();  cin.get();
    return 0;
}
