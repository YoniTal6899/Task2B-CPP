#include <iostream>
#include <string>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;


struct char_
{
    char ch = '_';
};

namespace ariel
{
    class Notebook{
        public:
        void write(int p, int row, int col, Direction dir, string const &text);
        void erase(int p, int row, int col, Direction dir, int len);
        string read(int p, int row, int col, Direction dir, int len);
        void show(int p);

        private:
        unordered_map< int, unordered_map< int, unordered_map< int, char_>>> data;
        unordered_map< int,  int> lr;
        
    };
}