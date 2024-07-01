#include <iostream>
#include <vector>

class MyString {
private:
    std::vector<char> data;

public:
    MyString() = default;

    MyString(const char* str) {
        while (*str) {
            data.push_back(*str++);
        }
    }

    void operator+=(char c) {
        data.push_back(c);
    }

    void operator+=(const char* str) {
        while (*str) {
            data.push_back(*str++);
        }
    }

    size_t size() const {
        return data.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        for (char c : str.data) {
            os.put(c);
        }
        return os;
    }
};

int main() {
    MyString s;
    s += "\0";
    s += "\0";
    s += '\0';
    s += "\0";
    s += "\0";
    s += "\0";
    std::cout << s << " " << s.size() << '\n';
    s += "abc";
    s += '\0';
    s += '\0';
    s += '\0';
    s += "ddc";
    std::cout << s << " " << s.size() << '\n';

    return 0;
}