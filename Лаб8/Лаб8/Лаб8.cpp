#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Items
{
	string name;
	int weight;
	int price;
};

int main ( )
{
	setlocale ( LC_ALL, "Russian" );
	int maxCapacity;
	cout << "Введите вместимость рюкзака: ";
	if ( !(cin >> maxCapacity) || maxCapacity <= 0 ) {
		cout << "Вместимость рюкзака неправильная \n";
		return 0;
	}

	int itemCount;
	cout << "Введите количество товаров: ";
	if ( !(cin >> itemCount) || itemCount <= 0 ) {
		cout << "Количество товаров неправильное\n";
		return 0;
	}

	Items* items = new Items[itemCount];
	for ( int i = 0; i < itemCount; i++ ) {
		cout << "Введите название товара " << i + 1 << ": ";
		if ( i == 0 ) cin.ignore ( );
		getline ( cin, items[i].name );
		cin.ignore ( );
		cout << "Введите вес товара " << i + 1 << ": ";
		if ( !(cin >> items[i].weight) || items[i].weight <= 0 ) {
			cout << "Вес товара неправильный\n";
			return 0;
		};

		cout << "Введите цену товара " << i + 1 << ": ";
		if ( !(cin >> items[i].price) || items[i].price <= 0 ) {
			cout << "Цена товара неправильная\n";
			return 0;
		};
		cin.ignore ( );
	}

	int** dpTable = new int* [itemCount + 1];
	for ( int i = 0; i <= itemCount; i++ ) {
		dpTable[i] = new int[maxCapacity + 1];
	}

	for ( int i = 0; i <= itemCount; i++ ) {
		for ( int j = 0; j <= maxCapacity; j++ ) {
			if ( i == 0 || j == 0 ) {
				dpTable[i][j] = 0;
			}
			else if ( items[i - 1].weight <= j ) {
				dpTable[i][j] = max (
					items[i - 1].price + dpTable[i - 1][j - items[i - 1].weight],
					dpTable[i - 1][j]
				);
			}
			else {
				dpTable[i][j] = dpTable[i - 1][j];
			}
		}
	}
	cout << "\nМаксимальная стоимость рюкзака: " << dpTable[itemCount][maxCapacity] << '\n';

	int totalWeight = 0;
	int currentCapacity = maxCapacity;
	cout << "Список предметов в рюкзаке: \n";

	for ( int i = itemCount; i > 0 && currentCapacity > 0; i-- ) {
		if ( dpTable[i][currentCapacity] != dpTable[i - 1][currentCapacity] ) {
			cout << items[i - 1].name
				<< ", цена: " << items[i - 1].price
				<< ", вес: " << items[i - 1].weight << '\n';

			totalWeight += items[i - 1].weight;
			currentCapacity -= items[i - 1].weight;
		}
	}
	cout << "Вес товаров, в которых поместился результат: " << totalWeight << '\n';

	for ( int i = 0; i <= itemCount; i++ ) {
		delete[] dpTable[i];
	}
	delete[] dpTable;
	delete[] items;

	return 0;
}