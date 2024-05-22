#include "sql_query_builder.h"
#include <iostream>
#include <string>
#include <cassert>

int main() {
    setlocale(LC_ALL, "Russian");

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string query = query_builder.BuildQuery();

    // Сравните с ожидаемым результатом
    std::string expected_query = "SELECT name, phone FROM students WHERE id='42' AND name='John';";
    assert(query == expected_query && "Ошибка: Запрос не соответствует ожидаемому результату.");
    std::cout << "Запрос успешно сформирован: " << query << std::endl;

    return 0;
}