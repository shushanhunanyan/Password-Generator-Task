#include "FileManager.h"


#include <iostream>
#include <unordered_set>
#include <chrono>


void FileManager::WriteToFile(const std::string& filename, const std::string& str)
{
	std::ofstream file(filename, std::ios::out | std::ios::app);

	if (!file.is_open()) {
		std::cerr << "Error while opening the file." << std::endl;
		return;
	}

	file << str << '\n';
	file.close();
}


void FileManager::Compare(const std::string& file1, const std::string& file2)
{
	std::ifstream inputFile1(file1);

	if (!inputFile1.is_open()) {
		std::cerr << "Error while opening the" << file1 << " file." <<std::endl;
		return;
	}
	
	std::string line;
	std::unordered_set<std::string> map;
	auto start = std::chrono::high_resolution_clock::now();

	while (std::getline(inputFile1, line)) {
		map.insert(line);
	}


	std::ifstream inputFile2(file2);

	if (!inputFile2.is_open()) {
                std::cerr << "Error while opening the " << file2 << " file." <<std::endl;
                return;
        }

	
	while (std::getline(inputFile2, line)) {
                if (map.find(line) != map.end()) {
			std::cout << "REPEATED PASSWORD: " << line << std::endl;
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			std::cout << "Time taken to process: " << duration.count() << " microseconds." << std::endl;
			return;
		}
        }

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken to process: " << duration.count() << " microseconds." << std::endl;


	inputFile1.close();
	inputFile2.close();
}
