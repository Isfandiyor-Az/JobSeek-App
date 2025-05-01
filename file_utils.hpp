#include <iostream>
#include "fstream"
using namespace std;

template <class T>
class FileUtils
{
public:
    static void write_new_user(T &t)
    {
        ofstream out("userdata.txt"); // txt for now, later we can switch to json
        if (out.is_open())
        {
            string appended_string = t.get_string_data() + ",\n";
            out << appended_string;
        }
        out.close();
    }
};