#ifndef CSAVEMANAGER_H
#define CSAVEMANAGER_H

#include <iostream>
#include <vector>

namespace CSaveManager
{
	int ReadFromFile(const char* filename, int* data);
	int SaveToFile(const char* filename, int* data);
	int GetSavesList(std::vector<std::string>&saves_list);
}

#endif