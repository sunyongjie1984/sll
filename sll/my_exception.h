#include <exception>

class my_exception: public std::exception {
public:
    my_exception() throw(){ memset(m_str, 0, 256 * sizeof(char)); }
    my_exception(char const * p) throw() { memset(m_str, 0, 256 * sizeof(char)); strcpy(m_str, p); }
    char const * what() const throw() { return "hi what what()"; /*std::cout << m_str << std::endl;*/ }
    ~my_exception() throw() {}
private:
    char m_str[256];
};
