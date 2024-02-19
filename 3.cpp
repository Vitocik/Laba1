Дана последовательность скобок вида «(», «)», «[», «]», «{», «}». Правильными скобочными последовательностями называются пустая последовательность, а также «(P)», «[P]», «{P}», где P – некоторая правильная последовательность. Например «{}()[]» и «{[][()()]}()» – правильные скобочные последовательности, а «(]», «[()» и «({)}» – неправильные. Определите является ли заданная строка правильным скобочным выражением. Подсказка: обработайте по очереди все символы входной строки, помещая открывающие скобки в стек, а для закрывающих скобок извлекайте открывающую скобку из стека и проверяйте, соответствуют ли они друг другу.
Решение:
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
int n;
int main() {
    setlocale(LC_ALL, "Ru");
    int cnt = 0;
    cin >> s;
    n = (int)s.size();
    stack <char> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        else {
            if ((int)st.size() == 0) {
                cout << "Неправильное выражение\n";
                return 0;
            }
            if (s[i] == ')' && st.top() == '(') {
                st.pop();
            }
            else if (s[i] == '}' && st.top() == '{') {
                st.pop();
            }
            else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                cout << "no\n";
                return 0;
            }
        }
    }
    if ((int)st.size() == 0) {
        cout << "Правильное выражение\n";
    }
    else {
        cout << "Неправильное выражение\n";
    }
    return 0;
}