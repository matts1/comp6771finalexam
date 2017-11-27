#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <memory>
#include <vector>
#include <unordered_map>

class SumCell;

class Cell {
public:
    virtual int eval() const = 0;

    virtual ~Cell() = default;
    std::vector<SumCell*> parents;
    void invalidate_parents();
};

class SumCell: public Cell {
public:
    /*
     * Returns all the children of this cell, ordered by the order they were added
     */
    const std::vector<Cell*>& getChildren() const { return children; }
    std::vector<Cell*>& getChildren() { return children; }

    int eval() const override;
    void addChild(Cell& cell);
    void invalidate() {
        valid = false;
        invalidate_parents();
    }

    mutable bool valid = false;
private:
    std::vector<Cell*> children;
    mutable int cache;
};

class IntCell: public Cell {
public:
    int eval() const override;

    IntCell(int value): value{value} {}
    void setValue(int value);

private:
    int value;
};

class Spreadsheet {
public:
    /*
     * makes the cell id into a sum cell.
     * If the cell already exists (only for erase and onwards), the cell must be cleared first
     */
    void setSumCell(int id);

    /*
     * makes the cell id into an integer cell with the value val
     * If the cell already exists (only for erase and onwards), the cell must be erased first
     */
    void setIntCell(int id, int val);

    /*
     * gets the value in the cell id, or throw std::out_of_range if the cell does not exist
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
     * erases any value currently in the cell. Does nothing if the cell doesn't currently exist. Removes any references to the cell
     */
    void erase(int id);

private:
    std::unordered_map<int, std::unique_ptr<Cell>> cells;
};

#endif