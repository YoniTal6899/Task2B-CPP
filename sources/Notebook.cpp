#include "Notebook.hpp"

using namespace std;
using namespace ariel;

int const ZERO = 0;
int const COL_LIMIT = 99;
int const LOW_LIMIT = 32;
int const HIGH_LIMIT = 126;
void Notebook::write(int p, int row, int col, Direction dir, string const &text)
{
    int len = text.size();   
    int tr = row;
    int tc = col; 
    this->lr[p] = row;    
    if (p<ZERO||row<ZERO||col<ZERO) {__throw_invalid_argument("Enter positive args");}
    if (col > COL_LIMIT) {__throw_invalid_argument("Out of bounds in row");}    
    if (dir == Direction::Horizontal)
    {
        if (len+col>COL_LIMIT) {__throw_invalid_argument("Out of bounds in row");}
    }
    for (char c: text)
    {
        if (c < LOW_LIMIT || c > HIGH_LIMIT || c == '~' || c== '\n') {__throw_invalid_argument("Invalid input");}
        if (this->data[p][tr][tc].ch != '_') {__throw_runtime_error("Unable to write in this location");}
            if (dir == Direction::Horizontal)
            {
                tc++;                
            }
            else
            {
                tr++;                
            }
    }
    for (char c : text)
    {
        this->data[p][row][col].ch = c;
        if (dir == Direction::Horizontal) 
        {                
            col++;
        } 
        else
        {
            row++;
        }    
    }
}

string Notebook::read(int p, int row, int col, Direction dir, int len)
{
    if(p<ZERO || row<ZERO || col<ZERO || len<ZERO) {__throw_invalid_argument("Enter positive args");}
    if (COL_LIMIT<col) {__throw_invalid_argument("Out of space in row");}
    if (dir == Direction::Horizontal)
    {
        if (len+col>COL_LIMIT+1) {__throw_invalid_argument("Out of bounds for row");}
    }
    string ans;
    for (int i = 0; i < len; i++)
    {
        char c = this->data[p][row][col].ch;
        ans.append(1, c);
        if (dir == Direction::Horizontal)
        {
            col++;
        }
        else
        {
            row++;
        }
    }
    return ans;
}

void Notebook::erase(int p, int row, int col, Direction dir, int len)
{
    if (p<ZERO||row<ZERO||col<ZERO||len<ZERO) {__throw_invalid_argument("Negetive args");}
    if (col > COL_LIMIT) {__throw_invalid_argument("Out of bounds for row");}
    if (dir == Direction::Horizontal)
    {
        if (len+col>COL_LIMIT) {__throw_invalid_argument("Out of bounds for row");}
    }

    this->lr[p] = row;
    for (int i = 0; i < len; i++)
    {
        this->data[p][row][col].ch = '~';
        if (dir == Direction::Horizontal)
        {
            col++;
        }
        else
        {
            row++;
        }
    }
}

void Notebook::show(int p)
{
    if (p<ZERO) {__throw_invalid_argument("Enter positive args");}
    int row = this->lr[p];
    Direction dir = Direction::Horizontal;
    int tr = row;
    if (row > 0)
    {
        for (int i = tr - 1; i <= row + 1; i++)
        {
            this->read(p, i, 0, dir, COL_LIMIT);
        }
    }
    else
    {
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j < row; j++)
            {
                cout << this->data[p][j][i].ch;
            }
            cout << endl;
        }
    }
}