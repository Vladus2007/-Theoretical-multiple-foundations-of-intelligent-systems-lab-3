#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	//СОЗАДЕМ СООТВЕТСТВИЕ А
	int sizeX;
	cout << "Введите мощность X: ";
	cin >> sizeX;
	int* X = new int[sizeX];

	int sizeY;
	cout << "Введите мощность Y: ";
	cin >> sizeY;
	int* Y = new int[sizeY];

	int sizeG;
	cout << "Введите мощность G: ";
	cin >> sizeG;
	int** G = new int* [sizeG];
	for (int i = 0; i < sizeG; i++) {
		G[i] = new int[2];
	}

	cout << "Вводите значения X:\n";
	for (int i = 0; i < sizeX; i++) {
		cout << "Введите " << i + 1 << "-e значение: ";
		cin >> X[i];
	}

	cout << "Вводите значения Y:\n";
	for (int i = 0; i < sizeY; i++) {
		cout << "Введите " << i + 1 << "-e значение: ";
		cin >> Y[i];
	}

	cout << "вводите значения G:\n";
	for (int i = 0; i < sizeG; i++) {
		cout << "Введите " << i + 1 << "-ю пару: ";
		cin >> G[i][0];
		cin >> G[i][1];
	}


	//СОЗАДЕМ СООТВЕТСТВИЕ B
	int sizeU;
	cout << "Введите мощность U: ";
	cin >> sizeU;
	int* U = new int[sizeU];

	int sizeV;
	cout << "Введите мощность V: ";
	cin >> sizeV;
	int* V = new int[sizeV];

	int sizeF;
	cout << "Введите мощность F: ";
	cin >> sizeF;
	int** F = new int* [sizeF];
	for (int i = 0; i < sizeF; i++) {
		F[i] = new int[2];
	}

	cout << "Вводите значения U:\n";
	for (int i = 0; i < sizeU; i++) {
		cout << "Введите " << i + 1 << "-e значение: ";
		cin >> U[i];
	}

	cout << "Вводите значения V:\n";
	for (int i = 0; i < sizeV; i++) {
		cout << "Введите " << i + 1 << "-e значение: ";
		cin >> V[i];
	}

	cout << "вводите значения F:\n";
	for (int i = 0; i < sizeF; i++) {
		cout << "Введите " << i + 1 << "-ю пару: ";
		cin >> F[i][0];
		cin >> F[i][1];
	}


	//СОЗДАДИМ ОБЪЕДИНЕНИЕ А и В

	//ОБЪЕДИНЕНИЕ X и U
	cout << "-------ОБЪЕДИНЕНИЕ A и В-------\n       ОБЪЕДИНЕНИЕ X и U\n";
	bool flag = false;
	int* Ob1 = new int[sizeX+sizeU]; //Создаем множество объединения
	for (int i = 0; i < sizeX; i++) {
		cout << X[i] << " ";  //Записываем все элементы Х во множество
	}
	for (int i = 0; i < sizeU; i++) {
		for (int j = 0; j < sizeX; j++) {  //Проверяем элементы U и записываем их во множество
			if (X[j] == U[i]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << U[i] << " ";
		}
	}

	//ОБЪЕДИНЕНИЕ Y и V
	cout << "\n       ОБЪЕДИНЕНИЕ Y и V\n";
	flag = false;
	int* Ob2 = new int[sizeY + sizeV];  //Создзаем множество объединения
	for (int i = 0; i < sizeY; i++) {
		cout << Y[i] << " ";   //Записываем все элементы Y
	}
	for (int i = 0; i < sizeV; i++) {
		for (int j = 0; j < sizeY; j++) {  //Проверяем элементы V и тоже записываем их во множество
			if (Y[j] == V[i]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << V[i] << " ";
		}
	}

	//ОБЪЕДИНЕНИЕ G и F
	cout << "\n       ОБЪЕДИНЕНИЕ G и F\n";
	flag = false;
	int** Ob_Gr = new int* [sizeF + sizeG];
	for (int i = 0; i < sizeG; i++) {
		cout << "<" << G[i][0] << "," << G[i][1] << "> ";  //Записываем все пары G в объединение
	}
	for (int i = 0; i < sizeF; i++) {
		flag = true;
		for (int j = 0; j < sizeG; j++) {
			if ((F[i][0] == G[j][0]) && (F[i][1] == G[j][1])) {  //Проверяем пары F и тоже записываем их
				flag = false;
				break;
			}
			
		}
		if (flag) {
			cout << "<" << F[i][0] << "," << F[i][1] << "> ";
		}
	}


	//СОЗДАДИМ ПЕРЕСЕЧЕНИЕ А и В

	//ПЕРЕСЕЧЕНИЕ X и U
	cout << "\n\n-------ПЕРЕСЕЧЕНИЕ A и В-------\n       ПЕРЕСЕЧЕНИЕ X и U\n";
	int* Per1 = new int[sizeX + sizeU];
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeU; j++) {  //Находим совпадающие элементы в двух множествах
			if (X[i] == U[j]) {            //И записываем их
				cout << X[i] << " ";
				break;
			}
		}
	}

	//ПЕРЕСЕЧЕНИЕ Y и V
	cout << "\n       ПЕРЕСЕЧЕНИЕ Y и V\n";
	int* Per2 = new int[sizeY + sizeV];        //Также находим совпадающие элементы и записываем их
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeV; j++) {
			if (Y[i] == V[j]) {
				cout << Y[i] << " ";
				break;
			}
		}
	}

	//ПЕРЕСЕЧЕНИЕ G и F
	cout << "\n       ПЕРЕСЕЧЕНИЕ G и F\n";
	int** Per_Gr = new int* [sizeG + sizeF];
	for (int i = 0; i < sizeG; i++) {
		for (int j = 0; j < sizeF; j++) {
			if ((G[i][0] == F[j][0]) && (G[i][1] == F[j][1])) {  //Находим совпадающие пары и записываем их
				cout << "<" << G[i][0] << "," << G[i][1] << "> ";
			}
		}
	}

	//РАЗНОСТЬ В\А

	//ОБЛАСТЬ ОТПРАВЛЕНИЯ
	cout << "\n\n-------РАЗНОСТЬ B и A-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
	vector<int> FR1;
	for (int i = 0; i < sizeU; i++) {   //переписываем все элементы U
		flag = true;
		for (int j = 0; j < sizeX; j++) {
			if (U[i] == X[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			FR1.push_back(U[i]);
		}
	}
	for (int i = 0; i < FR1.size(); i++) {
		cout << FR1[i] << " ";
	}

	//ОБЛАСТЬ ПРИБЫТИЯ
	cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
	vector<int> SR1;
	for (int i = 0; i < sizeV; i++) {    //переписываем все элементы V
		flag = true;
		for (int j = 0; j < sizeY; j++) {
			if (V[i] == Y[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			SR1.push_back(V[i]);
		}
	}
	for (int i = 0; i < SR1.size(); i++) {
		cout << SR1[i] << " ";
	}

	//РАЗНОСТЬ F\G
	cout << "\n       РАЗНОСТЬ F\\G\n";
	vector<vector<int>> GR1;
	for (int i = 0; i < sizeF; i++) {
		flag = true;
		for (int j = 0; j < sizeG; j++) {
			if ((F[i][0] == G[j][0]) && (F[i][1] == G[j][1])) {        //Тоже проверяем на равенство элементов пар
				flag = false;
				break;               //Если равны, то не записываем пару
			}
		}
		if (flag) {
			GR1.push_back({});
			GR1[GR1.size() - 1].push_back(F[i][0]);
			GR1[GR1.size() - 1].push_back(F[i][1]);
		}
	}
	for (int i = 0; i < GR1.size(); i++) {
		cout << "<" << GR1[i][0] << "," << GR1[i][1] << "> ";
	}

	//РАЗНОСТЬ А\В

	//ОБЛАСТЬ ОТПРАВЛЕНИЯ
	cout << "\n\n-------РАЗНОСТЬ А и В-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
	vector<int> FR2;
	for (int i = 0; i < sizeX; i++) {   //переписываем все элементы U
		flag = true;
		for (int j = 0; j < sizeU; j++) {
			if (U[j] == X[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			FR2.push_back(X[i]);
		}
	}
	for (int i = 0; i < FR2.size(); i++) {
		cout << FR2[i] << " ";
	}

	//ОБЛАСТЬ ПРИБЫТИЯ
	cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
	vector<int> SR2;
	for (int i = 0; i < sizeY; i++) {    //переписываем все элементы V
		flag = true;
		for (int j = 0; j < sizeV; j++) {
			if (V[j] == Y[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			SR2.push_back(Y[i]);
		}
	}
	for (int i = 0; i < SR2.size(); i++) {
		cout << SR2[i] << " ";
	}

	//РАЗНОСТЬ G\F
	cout << "\n       РАЗНОСТЬ G\\F\n";
	vector<vector<int>> GR2;
	for (int i = 0; i < sizeG; i++) {
		flag = true;
		for (int j = 0; j < sizeF; j++) {
			if ((F[j][0] == G[i][0]) && (F[j][1] == G[i][1])) {        //Тоже проверяем на равенство элементов пар
				flag = false;
				break;               //Если равны, то не записываем пару
			}
		}
		if (flag) {
			GR2.push_back({});
			GR2[GR2.size() - 1].push_back(G[i][0]);
			GR2[GR2.size() - 1].push_back(G[i][1]);
		}
	}
	for (int i = 0; i < GR2.size(); i++) {
		cout << "<" << GR2[i][0] << "," << GR2[i][1] << "> ";
	}


	//СИММЕТРИЧЕСКАЯ РАЗНОСТЬ А и В

	//СИММЕТРИЧЕСКАЯ РАЗНОСТЬ X и U
	cout << "\n\n-------СИММЕТРИЧЕСКАЯ РАЗНОСТЬ А и В-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
	
	flag = false;
	int* FSim = new int[sizeX+sizeU];
	for (int i = 0; i < sizeX; i++) { //Находим объединение двух областей отправления соответствий
		cout << X[i] << " ";
	}
	for (int i = 0; i < sizeU; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (U[i] == X[j]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << U[i] << " ";
		}
	}

	cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
	flag = false;
	int* SSim = new int[sizeY+sizeV];  //Находим объединение двух областей прибытия соответствий
	for (int i = 0; i < sizeY; i++) {
		cout << Y[i] << " ";
	}
	for (int i = 0; i < sizeV; i++) {
		for (int j = 0; j < sizeY; j++) {
			if (V[i] == Y[j]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << V[i] << " ";
		}
	}

	cout << "\n       СИММЕТРИЧЕСКАЯ РАЗНОСТЬ G и F\n";
	//G\F
	flag = false;
	int** GSim = new int* [sizeG+sizeF];  //Находим сначала разность для графика G
	for (int i = 0; i < sizeG; i++) {
		for (int j = 0; j < sizeF; j++) {
			if ((G[i][0] == F[j][0]) && (G[i][1] == F[j][1])) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << "<" << G[i][0] << "," << G[i][1] << "> ";
		}
	}

	//F\G
	flag = false;
	for (int i = 0; i < sizeF; i++) {
		for (int j = 0; j < sizeG; j++) {
			if ((F[i][0] == G[j][0]) && (F[i][1] == G[j][1])) {  //Затем находим разность для графика F
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			cout << "<" << F[i][0] << "," << F[i][1] << "> "; //Выводим все найденные значения
		}
	}

	//ИНВЕРСИЯ А

	//ИНВЕРСИЯ ОБЛАСТИ ОТПРАВЛЕНИЯ
	cout << "\n\n-------ИНВЕРСИЯ А-------\n       ИНВЕРСИЯ ОБЛАСТИ ОТПРАВЛЕНИЯ\n";
	int* InvX = new int[sizeY];
	for (int i = 0; i < sizeY; i++) {  //записываем в область отправления множество Y
		cout << Y[i] << " ";
	}

	//ИНВЕРСИЯ ОБЛАСТИ ПРИБЫТИЯ
	cout << "\n       ИНВЕРСИЯ ОБЛАСТИ ПРИБЫТИЯ\n";
	int* InvY = new int[sizeX];                     //Записываем в область прибытия множество X
	for (int i = 0; i < sizeX; i++) {
		cout << X[i] << " ";
	}

	//ИНВЕРСИЯ ГРАФИКА
	vector<int> p;
	cout << "\n       ИНВЕРСИЯ ГРАФИКА\n";
	
	int** InvG = new int* [sizeG];
	for (int i = 0; i < sizeG; i++) {
		flag=true;
		for(int j=0;j<p.size();j=j+2){
			if(p[j]==G[i][1] && p[i+1]==G[i][0]){
				flag=false;
			}
		}
		if(flag){
			cout << "<" << G[i][1] << "," << G[i][0] << "> ";
			p.push_back(G[i][1]);
			p.push_back(G[i][0]);
		}
		 //Меняем местами первый и второй элемент каждой пары и выводим
	}


	//ИНВЕРСИЯ В

	//ИНВЕРСИЯ ОБЛАСТИ ОТПРАВЛЕНИЯ
	cout << "\n\n-------ИНВЕРСИЯ В-------\n       ИНВЕРСИЯ ОБЛАСТИ ОТПРАВЛЕНИЯ\n";
	int* InvU = new int[sizeV];
	for (int i = 0; i < sizeV; i++) {  //Записываем в область отправления множество V
		cout << V[i] << " ";
	}

	//ИНВЕРСИЯ ОБЛАСТИ ПРИБЫТИЯ
	cout << "\n       ИНВЕРСИЯ ОБЛАСТИ ПРИБЫТИЯ\n";
	int* InvV = new int[sizeU];
	for (int i = 0; i < sizeU; i++) {  //Записываем в область прибытия множество U
		cout << U[i] << " ";
	}
	vector<int> res;
	//ИНВЕРСИЯ ГРАФИКА
	cout << "\n       ИНВЕРСИЯ ГРАФИКА\n";
	int** InvF = new int* [sizeF];
	for (int i = 0; i < sizeF; i++) {
		flag=true;
		for(int j=0;j<res.size();j=j+2){
			if(res[j]==F[i][1] && res[j+1]==F[i][0]){
				flag=false;
			}
			
		}
		if(flag){
		res.push_back(F[i][1]);
		res.push_back(F[i][0]);
		cout << "<" << F[i][1] << "," << F[i][0] << "> ";
		}  //Меняем местами первый и второй элемент местами и выводим
	}

	//КОМПОЗИЦИЯ А*В

	//ОБЛАСТЬ ОТПРАВЛЕНИЯ
	cout << "\n\n-------КОМПОЗИЦИЯ А*В-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
	int *FK1 = new int[sizeX];
	for (int i = 0; i < sizeX; i++) { //Записываем в область отправления множество X
		cout << X[i] << " ";
	}

	//ОБЛАСТЬ ПРИБЫТИЯ
	cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
	int* SK1 = new int[sizeV];
	for (int i = 0; i < sizeV; i++) {  //Записываем в область прибытия множество V
		cout << V[i] << " ";
	}

	//ГРАФИК КОМПОЗИЦИИ
	cout << "\n       ГРАФИК КОМПОЗИЦИИ\n";
	flag = false;
	int** GK1 = new int* [sizeG + sizeF];
	for (int i = 0; i < sizeG + sizeF; i++) { //Создаем график композиции
		GK1[i] = new int[2];
	}
	int num = 0;
	for (int i = 0; i < sizeG; i++) {
		for (int j = 0; j < sizeF; j++) {
			if (G[i][1] == F[j][0]) {
				if (num == 0) {
					GK1[num][0] = G[i][0]; //Проверяем, чтобы второй элемент G совпадал с первым элементом F
					GK1[num][1] = F[j][1]; //Если совпадает, проверяем на включение
					num++;
				}
				else {
					for (int k = 0; k < num; k++) {
						if ((G[i][0] == GK1[k][0]) && (F[j][1] == GK1[k][1])) {  //Если такой пары еще нет, то запишем ее во множество
							flag = false;
							break;
						}
						flag = true;
					}
					if (flag) {
						GK1[num][0] = G[i][0];
						GK1[num][1] = F[j][1];
						num++;
					}
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		cout << "<" << GK1[i][0] << "," << GK1[i][1] << "> ";  //Выведем все пары
	}


	//КОМПОЗИЦИЯ B*A

	//ОБЛАСТЬ ОТПРАВЛЕНИЯ
	cout << "\n\n-------КОМПОЗИЦИЯ B*A-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
	int* FK2 = new int[sizeU];
	for (int i = 0; i < sizeU; i++) {  //Запишем в область отправления множество U
		cout << U[i] << " ";
	}

	//ОБЛАСТЬ ПРИБЫТИЯ
	cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
	int* SK2 = new int[sizeY];
	for (int i = 0; i < sizeY; i++) {  //Запишем в область прибытия множество Y
		cout << Y[i] << " ";
	}

	//ГРАФИК КОМПОЗИЦИИ
	cout << "\n       ГРАФИК КОМПОЗИЦИИ\n";
	flag = false;
	int** GK2 = new int* [sizeG + sizeF];
	for (int i = 0; i < sizeG + sizeF; i++) { //Создадим график композиции
		GK2[i] = new int[2];
	}
	num = 0;
	for (int i = 0; i < sizeF; i++) {
		for (int j = 0; j < sizeG; j++) {
			if (F[i][1] == G[j][0]) {
				if (num == 0) {
					GK2[num][0] = F[i][0];  //Првоерим, равен ли второй элемент G первому элементу F
					GK2[num][1] = G[j][1];
					num++;
				}
				else {
					for (int k = 0; k < num; k++) {
						if ((F[i][0] == GK2[k][0]) && (G[j][1] == GK2[k][1])) { //Если равен, то проверяем на повтор пары
							flag = false;
							break;
						}
						flag = true;
					}
					if (flag) {
						GK2[num][0] = F[i][0]; //Если такой пары еще нет, то записываем ее
						GK2[num][1] = G[j][1];
						num++;
					}
				}
			}
		}
	}
	for (int i = 0; i < num; i++) {
		cout << "<" << GK2[i][0] << "," << GK2[i][1] << "> "; //Выведем все пары композиции
	}
}