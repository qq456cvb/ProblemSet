#include <iostream>
#include <string>
using namespace std;

//int main () {
//    string s = "#include <iostream>@#include <string>@using namespace std;@@int main() {@    string s = %c%s%c;@    string ss = s;@    const char* str1 = ss.c_str();@    for (int i = 0; i < s.length(); i++) {@        if (s[i] == 64) {@            s[i] = 10;@        }@    }@    const char* str2 = s.c_str();@    printf(str2, str1);@}";
//    string ss = s;
//    const char* str1 = ss.c_str();
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] == 64) {
//            s[i] = 10;
//        }
//    }
//    const char* str2 = s.c_str();
//    // %s take the address printing its content and avoid loop
//    printf(str2, 34, str1, 34);
//}
