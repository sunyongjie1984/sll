#include <exception>

class MyException: public std::exception {
public:
    MyException() throw(){ memset(m_str, 0, 256 * sizeof(char)); }
    MyException(char const * p) throw() { memset(m_str, 0, 256 * sizeof(char)); strcpy(m_str, p); }
    char const * what() const throw() { return "hi what what()"; /*std::cout << m_str << std::endl;*/ }
    ~MyException() throw() {}
private:
    char m_str[256];
};
