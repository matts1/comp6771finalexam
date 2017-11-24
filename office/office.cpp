#include <algorithm>

#include "office.h"


/*
 * makes the cell at cell id into a sum cell.
 * If the cell already exists (only for erase and onwards), the cell must be cleared first
 */
void Spreadsheet::setSumCell(int id) {
}

/*
 * makes the cell at cell id contain an integer cell with the value val
 * If the cell already exists (only for erase and onwards), the cell must be erased first
 */
void Spreadsheet::setIntCell(int id, int val) {
}

/*
 * gets the cell at cell id, or throw std::out_of_range if the cell does not exist
 */
Cell& Spreadsheet::getCell(int id) {
}

const Cell& Spreadsheet::getCell(int id) const {
}

/*
 * ensures that the parent cell is now the sum of whatever cells it was previously plus the child cell
 * If either the parent or child cell does not exist, throw a std::out_of_range exception.
 * If the parent cell is not a sum, throw a std::bad_cast exception
 * If both exceptions would be thrown, throw the std::out_of_range
 */
void Spreadsheet::addChild(int parent, int child) {
}

/*
 * erases the cell at cell id. Does nothing if there is no cell at cell id. Removes any references to the cell
 */
void Spreadsheet::erase(int id) {
}

const std::vector<Cell*>& SumCell::getChildren() const {
    return children;
}

void IntCell::setValue(int value) {
}

int Cell::eval() const {
    return 0;
}
