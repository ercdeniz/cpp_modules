#include "replace.hpp"

void Replace::replaceInFile()
{
    std::string line;
    bool fileIsEmpty = true;
    bool s1Found = false;

    std::ifstream inputFile(_filename.c_str());
    if (!inputFile) {
        std::cerr << RED << "Error opening file: " << _filename << RESET << std::endl;
        return;
    }

    std::string outputFilename = _filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << RED << "Error creating output file: " << outputFilename << RESET << std::endl;
        return;
    }

    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(_s1, pos)) != std::string::npos) {//s1 in konumunu ara
            line.erase(pos, _s1.length());//s1 i sil
            line.insert(pos, _s2);//s2 yi ekle
            pos += _s2.length();
            if (!s1Found)
                s1Found = true;
        }
        outputFile << line << std::endl;
        fileIsEmpty = false;
    }

    if (fileIsEmpty) {
        std::cerr << RED << "Error: Input file is empty." << RESET << std::endl;
        outputFile.close();
        std::remove(outputFilename.c_str());//.replace dosyasını sil
        return;
    }

    if (!s1Found) {
        std::cerr << RED << "Error: Word not found in the file." << RESET << std::endl;
        outputFile.close();
        std::remove(outputFilename.c_str());
        return;
    }

    std::cout << GREEN << "Replacement completed. Output file: " << CYAN << outputFilename << RESET << std::endl;
}
