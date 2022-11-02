#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (argc < 2) return 1;

  for (int i = 1; i < argc; ++i) {
    std::string input_path = argv[i];
    std::ifstream file;
    file.open(input_path, std::ios::in);
    if (file) {
      std::string line;
      bool format_started = false;
      std::cout << input_path << '\n';
      while (std::getline(file, line)) {
        if (format_started) {
          std::cout << line << '\n';
          format_started = false;
        }
        if (line.find(":Format:") != line.npos) {
          format_started = true;
        }
      }
    }
  }
}