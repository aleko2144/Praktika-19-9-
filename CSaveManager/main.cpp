#include <iostream>
#include "windows.h"
#include "locale.h"

#include "include\CSaveManager\CSaveManager.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	setlocale(0, "");
	
	int inv[8] = { 1, 0, 1, 0, 0, 0, 0, 0 };
	
	//CSaveManager::SaveToFile(".//test.save", inv);

	int inv1[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	CSaveManager::ReadFromFile(".//test.save", inv1);
	
	std::vector<std::string> save_list;
	
	CSaveManager::GetSavesList(save_list);
	
	for (int i=0; i < save_list.size(); i++){
		cout << save_list[i] << "\n";
	}
	//cout << "да\n";
	system("pause");
	return 0;
}
