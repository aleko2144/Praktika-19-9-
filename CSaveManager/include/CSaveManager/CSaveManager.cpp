#include "CSaveManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "windows.h"

namespace CSaveManager{
	
	int ReadFromFile(const char* filename, int* data){
		int file_id = 1163280723;
		int tempInt = 0;
		
		std::ifstream file(filename, std::ios::binary);
		
		file.read((char*)&tempInt, sizeof(tempInt));
		
		if (tempInt != file_id){
			std::cout << "CSaveManager::ReadFromFile error: appointed file is not save file!!!\n";
			return 0;
		}
		else{
			file.read((char*)&tempInt, sizeof(tempInt));
			
			if (sizeof(data) != tempInt){
				std::cout << "CSaveManager::ReadFromFile error: output array length != *.save array length!!!\n";
				return 0;
			}
			else{
				for (int i = 0; i < sizeof(data); i++){
					file.read((char*)&tempInt, sizeof(tempInt));
					data[i] = tempInt;
				}
			}
		}
		
		file.close();
		return 1;
	}
	
	int SaveToFile(const char* filename, int* data){
		int file_id = 1163280723;
		int dataLen = sizeof(data);
		
		std::ofstream file(filename, std::ios::binary);
		
		file.write((char*)&file_id, sizeof(file_id));
		file.write((char*)&dataLen, sizeof(dataLen));
		
		for (int i = 0; i < sizeof(data); i++){
			file.write((char*)&data[i], sizeof(data[i]));
		}
		
		file.close();
		
		return 1;
	}
	
	int GetSavesList(std::vector<std::string>&saves_list){
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind = FindFirstFile("*.save", &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do {
				saves_list.push_back(FindFileData.cFileName);
			} while (FindNextFile(hFind, &FindFileData));
			FindClose(hFind);
		}
		return 0;
	}
}
