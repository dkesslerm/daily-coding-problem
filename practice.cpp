#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <chrono>

namespace fs = std::filesystem;

std::vector<fs::path> get_all_cpp_files(const fs::path& root) {
    std::vector<fs::path> cpp_files;
    for (auto const& entry : fs::recursive_directory_iterator(root)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            cpp_files.push_back(entry.path());
        }
    }
    return cpp_files;
}

void show_problem_statement(const fs::path& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "❌ Could not open file: " << file_path << "\n";
        return;
    }

    std::string line;
    bool started = false;   // have we found the start of the comments?
    bool stopped = false;   // have we left the comment block?

    std::cout << "==========================================\n";
    std::cout << " Daily Coding Problem Practice\n";
    std::cout << "==========================================\n\n";

    while (std::getline(file, line)) {
        std::string trimmed = line;
        trimmed.erase(0, trimmed.find_first_not_of(" \t"));

        if (!started) {
            if (trimmed.rfind("//", 0) == 0) {
                started = true;
            } else {
                continue; // skip until first // line
            }
        }

        if (started) {
            if (trimmed.rfind("//", 0) == 0) {
                std::string content = trimmed.substr(2);
                if (!content.empty() && content[0] == ' ')
                    content.erase(0, 1);
                std::cout << content << "\n";
            } else {
                stopped = true;
                break;
            }
        }

        if (stopped) break;
    }

    // std::cout << "\n(press Enter to reveal the filename)\n";
    // std::cin.get();
    // std::cout << "➡️  " << file_path.string() << "\n";
}

int main() {
    fs::path root = fs::current_path();  // run from repo root
    auto cpp_files = get_all_cpp_files(root);

    if (cpp_files.empty()) {
        std::cerr << "❌ No .cpp files found in " << root << "\n";
        return 1;
    }

    // Random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<size_t> dist(0, cpp_files.size() - 1);

    fs::path random_file = cpp_files[dist(gen)];
    show_problem_statement(random_file);

    return 0;
}
