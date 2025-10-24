#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class RPNCalculator {
public:
    void push(double value) { stk.push(value); }
    double pop() {
        if (stk.empty()) throw std::runtime_error("栈空");
        double v = stk.top(); stk.pop(); return v;
    }
    void calculate(const std::string& op) {
        if (op=="+") { double b=pop(), a=pop(); push(a+b); }
        else if (op=="-") { double b=pop(), a=pop(); push(a-b); }
        else if (op=="*") { double b=pop(), a=pop(); push(a*b); }
        else if (op=="/") { double b=pop(), a=pop(); if(b==0) throw std::runtime_error("除零"); push(a/b); }
        else if (op=="pow"){ double b=pop(), a=pop(); push(std::pow(a,b)); }
        else if (op=="sqrt"){ double a=pop(); if(a<0) throw std::runtime_error("负数开方"); push(std::sqrt(a)); }
        else if (op=="sin") { double a=pop(); push(std::sin(a)); }
        else if (op=="cos") { double a=pop(); push(std::cos(a)); }
        else if (op=="tan") { double a=pop(); push(std::tan(a)); }
        else throw std::runtime_error("未知操作符");
    }
    void clear() { while(!stk.empty()) stk.pop(); }
    void showStack() const {
        if (stk.empty()) { std::cout << "【栈空】\n"; return; }
        std::stack<double> tmp = stk;
        std::vector<double> v;
        while(!tmp.empty()){ v.push_back(tmp.top()); tmp.pop(); }
        std::cout << "当前栈（顶→底）: ";
        for (auto it = v.rbegin(); it != v.rend(); ++it)
            std::cout << std::setprecision(12) << *it << ' ';
        std::cout << '\n';
    }
    double top() const { return stk.top(); }
private:
    std::stack<double> stk;
};

int main(){
    RPNCalculator calc;
    std::cout << "C++ RPN 计算器\n输入表达式 (例, '5 5 +'), 或 'q' 退出.\n";
    std::string line;
    while (std::cout << "> " && std::getline(std::cin, line) && line != "q") {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string token;
        try {
            while (iss >> token) {
                if (std::isdigit(token[0]) || (token[0]=='-' && token.size()>1 && std::isdigit(token[1])))
                    calc.push(std::stod(token));
                else
                    calc.calculate(token);
            }
            std::cout << "结果: " << calc.top() << "\n\n";
        } catch (const std::exception& ex) {
            std::cout << "错误: " << ex.what() << "\n\n";
            calc.clear();          // 出错后清栈，方便继续
        }
    }
    std::cout << "Bye.\n";
    return 0;
}
