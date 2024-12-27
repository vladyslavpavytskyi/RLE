#include<iostream>
#include<vector>
#include<fstream>

std::string RunLenghtEncoding(const std::string & str){
    std::string letters;
    unsigned int n = str.size();
    for(int i = 0; i < n; i++){
    int counter = 1;
    while(str[i] == str[i+1]){
        counter ++;
        i++;
    }
    letters += std::to_string(counter);
    letters.push_back(str[i]);
}
return letters;
}

double CalculateCompressionRatio(const std::string& original, const std::string& compressed) {
    if (original.empty()) return 0.0;
    return static_cast<double>(compressed.size()) / original.size();
}

size_t getFileSize(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    return file.tellg(); // Rozmiar pliku w bajtach
}

int main(){
std::string text = "aaaaaaaabbbbbbbbbbbbbbbbbccvvvvvvcc";
std::string compresseds = RunLenghtEncoding(text);

std::cout<<text<<std::endl<<compresseds<<std::endl;
std::cout<<"Stopien kompresji: " << CalculateCompressionRatio(text,compresseds) << std::endl; 
}