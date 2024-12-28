#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>

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

std::string readFile(const std::string &filename) {
    std::ifstream inputFile(filename);
    std::string content;
    if (inputFile.is_open()) {
        char ch;
        while (inputFile.get(ch)) {
            content += ch;
        }
        inputFile.close();
    } else {
        std::cerr << "Nie mozna otworzyc pliku wejsciowego!" << std::endl;
    }
    return content;
}

void writeFile(const std::string &filename, const std::string &dataof) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << dataof;
        outputFile.close();
    } else {
        std::cerr << "Nie można otworzyć pliku wyjściowego!" << std::endl;
    }
}


int main(){
char choise;
std::string data,filename;

std::cout<<"Chcesz wprowadzic test wlasnorecznie?(T/t)"<<std::endl;
std::cin>> choise;
if(choise == 't' | choise == 'T'){
    std::cout<<"Podaj text"<< std::endl;
    std::cin>> data;}
else{
    std::cout<< "Podaj nazwe pliku wejsciowego: ";
    std::cin>>filename;
    if(!filename.empty()){
    data = readFile(filename);
    }
    else{
        return 0;
    }
}
std::string compresseddata = RunLenghtEncoding(data);
std::cout << std::endl << compresseddata << std::endl;
std::cout << "Stopien kompresji: " << CalculateCompressionRatio(data, compresseddata)<<std::endl;

writeFile("wyjscie.txt", compresseddata);


/*std::string text = "aaaaaaaabbbbbbbbbbbbbbbbbccvvvvvvcc";
std::string compresseds = RunLenghtEncoding(text);

std::cout<<text<<std::endl<<compresseds<<std::endl;
std::cout<<"Stopien kompresji: " << CalculateCompressionRatio(text,compresseds) << std::endl; 
*/
}