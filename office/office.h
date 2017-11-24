#ifndef OFFICE_H
#define OFFICE_H

#include <vector>

class Cell {
public:
    int eval() const;

    virtual ~Cell() = default;
};

class SumCell: public Cell {
public:
    /*
     * Returns all the children of this cell, ordered by the order they were added
     */
    const std::vector<Cell*>& getChildren() const;

private:
    std::vector<Cell*> children;
};

class IntCell: public Cell {
public:
    IntCell(int value): value{value} {}
    void setValue(int value);

private:
    int value;
};

class Spreadsheet {
public:
    /*
     * makes the cell at cell id into a sum cell.
     * If the cell already exists (only for erase and onwards), the cell must be cleared first
     */
    void setSumCell(int id);

    /*
     * makes the cell at cell id contain an integer cell with the value val
     * If the cell already exists (only for erase and onwards), the cell must be erased first
     */
    void setIntCell(int id, int val);

    /*
     * gets the cell at cell id, or throw std::out_of_range if the cell does not exist
     */
    const Cell& getCell(int id) const;
    Cell& getCell(int id);

    /*
     * ensures that the parent cell is now the sum of whatever cells it was previously plus the child cell
     * If either the parent or child cell does not exist, throw a std::out_of_range exception.
     * If the parent cell is not a sum, throw a std::bad_cast exception
     * If both exceptions would be thrown, throw the std::out_of_range
     */
    void addChild(int parent, int child);

    /*
     * erases the cell at cell id. Does nothing if there is no cell at cell id. Removes any references to the cell
     */
    void erase(int id);

private:
};

#endif
