#include "doctest.h"
#include "Notebook.hpp"
#include <climits>
using namespace ariel;
using namespace std;

Direction horizontal = Direction::Horizontal;
Direction vertical = Direction::Vertical;

TEST_CASE("Good args")
{
    Notebook notebook;
    notebook.write(0, 0, 0, horizontal, "horizontal");
    notebook.write(1, 0, 0, vertical, "vertical");
    notebook.write(0, 1, 50, horizontal, "text for example");
    CHECK(notebook.read(0, 1, 50, horizontal, 3) == "tex");
    CHECK(notebook.read(0, 0, 0, horizontal, 10) == "horizontal");
    CHECK(notebook.read(1, 0, 0, vertical, 8) == "vertical");
    CHECK(notebook.read(6, 8, 9, horizontal, 3) == "___");
    CHECK(notebook.read(35, 32, 48, vertical, 10) == "__________");
}

TEST_CASE("Negative args"){
    Notebook notebook;
    CHECK_THROWS(notebook.write(-1, 0, 0, horizontal, "example"));
    CHECK_THROWS(notebook.write(0, -1, 0, horizontal, "example"));
    CHECK_THROWS(notebook.write(0, 0, -1, horizontal, "example"));  
    CHECK_THROWS(notebook.write(-1, -1, 0, horizontal, "example"));      
    CHECK_THROWS(notebook.write(1, -1, -1, horizontal, "example"));
    CHECK_THROWS(notebook.write(-1, 0, -1, horizontal, "example"));
    CHECK_THROWS(notebook.write(-1, -1, -1, horizontal, "example"));
    CHECK_THROWS(notebook.erase(-1, 0, 0, horizontal, 5));
    CHECK_THROWS(notebook.erase(0, -1, 0, horizontal, 5));
    CHECK_THROWS(notebook.erase(0, 0, -1, horizontal, 5));
    CHECK_THROWS(notebook.erase(-1, -1, 0, horizontal, 5));
    CHECK_THROWS(notebook.erase(0, -1, -1, horizontal, 5));
    CHECK_THROWS(notebook.erase(-1, 0, -1, horizontal, 5));
    CHECK_THROWS(notebook.erase(-1, -1, -1, horizontal, 5));
    CHECK_THROWS(notebook.read(-1, 0, 0, horizontal, 5));
    CHECK_THROWS(notebook.read(0, -1, 0, horizontal, 5));
    CHECK_THROWS(notebook.read(0, 0, -1, horizontal, 5));
    CHECK_THROWS(notebook.read(-1, -1, 0, horizontal, 5));
    CHECK_THROWS(notebook.read(0, -1, -1, horizontal, 5));
    CHECK_THROWS(notebook.read(-1, 0, -1, horizontal, 5));
    CHECK_THROWS(notebook.read(-1, -1, -1, horizontal, 5));
}


TEST_CASE("String too long")
{
    Notebook notebook;
    CHECK_THROWS(notebook.write(0, 1, 95, horizontal, "OutOfBounds....."));
    CHECK_THROWS(notebook.write(1, 21, 90, horizontal, "VeryVeryVery long text"));
}
