# include <iostream>
# include <cstdio>
using namespace std;

bool isMatch(string t, string p) {

    int len = t.length() - p.length();
    for(int i = 0; i <= len; i++) {
        int counter = 0;
        for(int j = i; j <= p.length(); j++) {
            if(t[j] == p[counter]) {
                counter++;
                if(counter == p.length()) return true;
                continue;
            } else {
                break;
            }
        }
    }
    return false;
}

int main() {
    string t = "abcdef";
    string p = "acde";
    if(isMatch(t, p)) {
        printf("match\n");
    } else {
        printf("not match\n");
    }
}
