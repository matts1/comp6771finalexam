#include <algorithm>

#include "office.h"


/*
 * makes the cell id into a sum cell.
 * If the cell already exists (only for erase and onwards), the cell must be cleared first
 */
void Spreadsheet::setSumCell(int id) {
    erase(id);
    cells.emplace(id, std::make_unique<SumCell>());
}

/*
 * makes the cell id into an integer cell with the value val
 * If the cell already exists (only for erase and onwards), the cell must be erased first
 */
void Spreadsheet::setIntCell(int id, int val) {
    erase(id);
    cells.emplace(id, std::make_unique<IntCell>(val));
}

/*
 * gets the value in the cell id, or throw std::out_of_range if the cell does not exist
 */
Cell& Spreadsheet::getCell(int id) {
    return *cells.at(id);
}

const Cell& Spreadsheet::getCell(int id) const {
    return *cells.at(id);
}

/*
 * ensures that the parent cell is now the sum of whatever cells it was previously plus the child cell
 * If either the parent or child cell does not exist, throw a std::out_of_range exception.
 * If the parent cell is not a sum, throw a std::bad_cast exception
 * If both exceptions would be thrown, throw the std::out_of_range
 */
void Spreadsheet::addChild(int parent, int child) {
    auto& childc = getCell(child);
    auto& parentc = dynamic_cast<SumCell&>(getCell(parent));
    parentc.addChild(childc);
}

/*
 * erases any value currently in the cell. Does nothing if the cell doesn't currently exist. Removes any references to the cell
 */
void Spreadsheet::erase(int id) {
    if (cells.find(id) == cells.end())
        return;
    auto& cell = getCell(id);
    cell.invalidate_parents();
    for (auto parent : cell.parents) {
        auto& children = parent->getChildren();
        children.erase(std::remove(children.begin(), children.end(), &cell), children.end());
    }
    cells.erase(id);
}

void SumCell::addChild(Cell& cell) {
    children.push_back(&cell);
    cell.parents.push_back(this);
    invalidate();
}

void IntCell::setValue(int value) {
    this->value = value;
    invalidate_parents();
}

int IntCell::eval() const {
    return value;
}

int SumCell::eval() const {
    if (!valid) {
        auto total = 0;
        for (const auto &child : children) {
            total += child->eval();
        }
        cache = total;
        valid = true;
    }
    return cache;
}

void Cell::invalidate_parents() {
    for (auto* parent : parents) {
        if (parent->valid)
            parent->invalidate();
    }
}