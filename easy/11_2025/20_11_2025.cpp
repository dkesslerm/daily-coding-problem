#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

// Daily Coding Problem: Problem #55 [Easy] - 20/11/25
//
// This problem was asked by Microsoft.
// Implement a URL shortener with the following methods:
//     shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
//     restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
// Hint: What if we enter the same URL twice?

const string CHARS = "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "0123456789";

class URLShortener {
private:
    unordered_map<string, string> shortToUrl;
    unordered_map<string, string> urlToShort;

    string generateShort() {
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<> dis(0, CHARS.size() - 1);

        string shortUrl;
        for (int i = 0; i < 6; i++) {
            shortUrl += CHARS[dis(gen)];
        }

        return shortUrl;
    }

public:
    string shorten(string url) {
        if (urlToShort.find(url) != urlToShort.end()) {
            return urlToShort[url];
        }

        string shortUrl;
        do {
            shortUrl = generateShort();
        } while (shortToUrl.find(shortUrl) != shortToUrl.end());

        shortToUrl[shortUrl] = url;
        urlToShort[url] = shortUrl;

        return shortUrl;
    }

    string restore(string shortUrl) {
        if (shortToUrl.find(shortUrl) != shortToUrl.end()) {
            return shortToUrl[shortUrl];
        }

        return ""; // we don't have it
    }
};

int main() {
    // Daily Coding Problem: Problem #55 [Easy] - 20/11/25
    URLShortener shortener;

    cout << "=== Test 1: Basic shorten and restore ===\n";
    string url1 = "https://www.microsoft.com";
    string short1 = shortener.shorten(url1);
    cout << "Original URL: " << url1 << endl;
    cout << "Shortened:    " << short1 << endl;
    cout << "Restored:     " << shortener.restore(short1) << endl;

    cout << "\n=== Test 2: Shorten same URL twice (hint case) ===\n";
    string short1_again = shortener.shorten(url1);
    cout << "First short:  " << short1 << endl;
    cout << "Second short: " << short1_again << endl;
    cout << "Same result?  " << (short1 == short1_again ? "YES" : "NO") << endl;

    cout << "\n=== Test 3: Multiple different URLs ===\n";
    string url2 = "https://www.google.com";
    string url3 = "https://github.com";

    string short2 = shortener.shorten(url2);
    string short3 = shortener.shorten(url3);

    cout << "URL 2: " << url2 << " -> " << short2 << endl;
    cout << "URL 3: " << url3 << " -> " << short3 << endl;

    cout << "Restore URL 2: " << shortener.restore(short2) << endl;
    cout << "Restore URL 3: " << shortener.restore(short3) << endl;

    cout << "\n=== Test 4: Restore non-existent short code ===\n";
    string fakeShort = "ABC123";
    string restored = shortener.restore(fakeShort);
    cout << "Restoring '" << fakeShort << "': "
        << (restored.empty() ? "null" : restored) << endl;

    return 0;
}
