#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cassert>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string from_table;
    std::vector<std::string> where;
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        from_table = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        where.push_back(column + "='" + value + "'");
        return *this;
    }

    std::string BuildQuery() const {
        if (from_table.empty() || columns.empty()) {
            return "";
        }

        std::ostringstream query;

        // SELECT
        query << "SELECT ";
        for (size_t i = 0; i < columns.size(); ++i) {
            if (i > 0) query << ", ";
            query << columns[i];
        }
        query << " ";

        // FROM
        query << "FROM " << from_table << " ";

        // WHERE
        if (!where.empty()) {
            query << "WHERE ";
            for (size_t i = 0; i < where.size(); ++i) {
                if (i > 0) query << " AND ";
                query << where[i];
            }
        }

        query << ";";

        return query.str();
    }
};