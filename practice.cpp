#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
namespace fs = filesystem;

// ============================================
// FILTER CONFIGURATION
// ============================================
// Set to empty string "" to disable filtering
// Examples: "Google", "Amazon", "Meta", "Microsoft"
const string FILTER = "google";

vector<fs::path> get_all_cpp_files(const fs::path& root) {
    vector<fs::path> cpp_files;
    for (auto const& entry : fs::recursive_directory_iterator(root)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            cpp_files.push_back(entry.path());
        }
    }
    return cpp_files;
}

bool file_contains_company(const fs::path& file_path, const string& company) {
    if (company.empty()) return true; // no filter = include all

    ifstream file(file_path);
    if (!file.is_open()) return false;

    string line;
    string company_lower = company;
    transform(company_lower.begin(), company_lower.end(), company_lower.begin(), ::tolower);

    // Search through the comment block at the top
    bool in_comments = false;
    while (getline(file, line)) {
        string trimmed = line;
        trimmed.erase(0, trimmed.find_first_not_of(" \t"));

        if (trimmed.rfind("//", 0) == 0) {
            in_comments = true;
            // Convert line to lowercase for case-insensitive matching
            string line_lower = line;
            transform(line_lower.begin(), line_lower.end(), line_lower.begin(), ::tolower);

            if (line_lower.find(company_lower) != string::npos) {
                return true;
            }
        } else if (in_comments) {
            // We've left the comment block
            break;
        }
    }

    return false;
}

void show_problem_statement(const fs::path& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "❌ Could not open file: " << file_path << "\n";
        return;
    }
    string filename = "practice_implementation.cpp";
    ofstream out(filename);

    string line;
    bool started = false;   // have we found the start of the comments?
    bool stopped = false;   // have we left the comment block?

    out << "/*\n";
    out << "==========================================\n";
    out << " Daily Coding Problem Practice\n";
    out << "==========================================\n\n";

    while (getline(file, line)) {
        string trimmed = line;
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
                string content = trimmed.substr(2);
                if (!content.empty() && content[0] == ' ')
                    content.erase(0, 1);
                out << content << "\n";
            } else {
                stopped = true;
                break;
            }
        }

        if (stopped) break;
    }

    out << "*/\n\n";

    out << "class Solution {\n\n";
    out << "};\n\n";

    out << "int main() {\n";
    out << "\tSolution s;\n\n";
    out << "\treturn 0;\n}";
}

int main() {
    fs::path root = fs::current_path();  // run from repo root
    auto all_cpp_files = get_all_cpp_files(root);

    if (all_cpp_files.empty()) {
        cerr << "❌ No .cpp files found in " << root << "\n";
        return 1;
    }

    // Filter by company if specified
    vector<fs::path> cpp_files;
    for (const auto& file : all_cpp_files) {
        if (file_contains_company(file, FILTER)) {
            cpp_files.push_back(file);
        }
    }

    if (cpp_files.empty()) {
        if (!FILTER.empty()) {
            cerr << "❌ No .cpp files found matching filter: \""
                 << FILTER << "\"\n";
        } else {
            cerr << "❌ No .cpp files found\n";
        }
        return 1;
    }

    // Display filter status
    if (!FILTER.empty()) {
        cout << "🔍 Filtering by: \"" << FILTER << "\"\n";
        cout << "📁 Found " << cpp_files.size() << " matching file(s)\n\n";
    } else {
        cout << "📁 Found " << all_cpp_files.size() << " total file(s)\n\n";
    }

    // Random seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<size_t> dist(0, cpp_files.size() - 1);

    fs::path random_file = cpp_files[dist(gen)];
    cout << "✅ Selected: " << random_file.filename() << "\n";

    show_problem_statement(random_file);

    return 0;
}
