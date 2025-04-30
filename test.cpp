#include <iostream>
#include <clocale>
#include <cwchar>
#include <cstdlib>

const wchar_t testString[] = L"Hello, World! 你好，世界！😊👌";

int testLocale(const char* locale) {
    //std::cout << "Testing locale: " << locale << std::endl;
    if (setlocale(LC_ALL, locale) == nullptr) {
        std::cerr << "Failed to set locale: " << locale << std::endl;
        return 1;
    }
    std::cout << "Locale set to: " << setlocale(LC_ALL, nullptr) << std::endl;
    try {
        char buffer[256];
        size_t result = std::wcstombs(buffer, testString, sizeof(buffer));
        if (result == (size_t)-1) {
            std::cerr << "Failed to convert wide string to multibyte string." << std::endl;
            return 1;
        }
        buffer[result] = '\0';
        std::cout << "Converted string: " << buffer << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int main() {
    std::cout << "Testing setlocale..." << std::endl;
    std::cout << "Current locale: " << setlocale(LC_ALL, nullptr) << std::endl;
    
    const char* locales[] = {
        "en_US.UTF-8",
        "zh_CN.UTF-8",
        "zh_CN.GB2312",
        "zh_CN.GBK",
        "C",
        "POSIX",
        "C.UTF-8",
        "UTF-8",
        "wtf"
    };

    for (const char* locale : locales) {
        std::cout << std::endl;
        testLocale(locale);
    }

    std::cout << std::endl;
    std::cout << "Testing default (blank) locale..." << std::endl;

    testLocale(""); 

    std::cout << std::endl << "Test done." << std::endl;
}
