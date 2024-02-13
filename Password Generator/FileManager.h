#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <fstream>
#include <string>


class FileManager
{
public:
	void WriteToFile(const std::string&, const std::string&);
	void Compare(const std::string&, const std::string&);
};


#endif // FILEMANAGER_H
